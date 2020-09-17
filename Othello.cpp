/*
 * Othello.cpp
 * Othello
 * Caleb Davis
 * CISC 260 - Dr. Yarrington
 */

#include <string>
#include <iostream>
#include <stdlib.h>
#include "Othello.hpp"
#include "Player.hpp"
#include "Player.cpp"
using namespace std;


Othello::Othello(){
	boardsize = 8;
	numplayers = 0;
	p2.name = "computer2";
	p2.piece = 'O';

}

Othello::Othello(string st1, char c){
	boardsize = 8;
	numplayers = 1;
	p1.name = st1;
	p1.piece = c;
	if (c == 'B'){
		p2.name = "computer";
		p2.piece = 'O';
	}
}

Othello::Othello(string st1, char c, string st2, char c2){
	boardsize = 8;
	numplayers = 2;
	p1.name = st1;
	p1.piece = c;
	p2.name = st2;
	p2.piece = c2;
}

void Othello::makemat(){
	for (int r = 0; r < boardsize; r++){
		for (int c = 0; c < boardsize; c++){
			board[r][c] = '_';
		}
	}
	board[3][3] = 'B';
	board[4][4] = 'B';
	board[3][4] = 'O';
	board[4][3] = 'O';
}

void Othello::printmat(){
	for (int r = 0; r < boardsize+1; r++){
		for (int c = 0; c < boardsize+1; c++){
			if (c == 0){
				if (r == 0){
					cout << "  ";
				}
				if (r != 0){
					cout << r - 1 << " ";
				}
			} else if(r == 0){
				cout << c - 1 << " ";
			} else {
				cout << board[r-1][c-1] << " ";
			}
		}
		cout << endl;
	}
}

void Othello::placepiece(Player curPlayer, char curColor){
	int x, y;
	bool valid = false;
	while (!valid){
		cout << "Enter the x coordinate on the board: ";
		cin >> x;
		cout << "Enter the y coordinate on the board: ";
		cin >> y;
		if (x >= 0 && x < boardsize && y >= 0 && y < boardsize && board[y][x] == '_'){
			valid = true;
		} else {
			cout << "Invalid coordinates. Try again." << endl;
		}
	}
	board[y][x] = curColor;
	if (!countandflippieces(x, y, curPlayer, true)){
		cout << "Player forfeits turn" << endl;
		board[y][x] = '_';
	}
}

int Othello::countandflippieces(int c, int r, Player curPlayer, bool flip){
	int cT, rT, tF;          // colTemp, rowTemp, totalFlipped
	char opp;
	if (curPlayer.piece == 'B'){
		opp = 'O';
	} else {
		opp = 'B';
	}
	tF = 0;

	// Left
	if (c != 0 && board[r][c-1] == opp){
		cT = c - 1;
		while (cT >= 0){
			if (board[r][cT] == curPlayer.piece){
				for(int i = cT; i < c; i++){
					if (flip){
						board[r][i] = curPlayer.piece;
					}
					tF++;
				}
				break;
			}
			if (board[r][cT] == '_') {
				break;
			}
			if (board[r][cT] == opp){
				cT -= 1;
			}
		}
	}

	// Right
	if (c != (boardsize-1) && board[r][c+1] == opp){
		cT = c + 1;
		while (cT < boardsize){
			if (board[r][cT] == curPlayer.piece){
				for(int i = cT; i > c; i--){
					if (flip){
						board[r][i] = curPlayer.piece;
					}
					tF++;
				}
				break;
			}
			if (board[r][cT] == '_') {
				break;
			}
			if (board[r][cT] == opp){
				cT += 1;
			}
		}
	}

	// Up
	if (r != 0 && board[r-1][c] == opp){
		rT = r - 1;
		while (rT >= 0){
			if (board[rT][c] == curPlayer.piece){
				for(int i = rT; i < r; i++){
					if (flip){
						board[i][c] = curPlayer.piece;
					}
					tF++;
				}
				break;
			}
			if (board[rT][c] == '_') {
				break;
			}
			if (board[rT][c] == opp){
				rT -= 1;
			}
		}
	}

	// Down
	if (c != (boardsize-1) && board[r+1][c] == opp){
		rT = r + 1;
		while (rT < boardsize){
			if (board[rT][c] == curPlayer.piece){
				for(int i = rT; i > r; i--){
					if (flip){
						board[i][c] = curPlayer.piece;
					}
					tF++;
				}
				break;
			}
			if (board[rT][c] == '_') {
				break;
			}
			if (board[rT][c] == opp){
				rT += 1;
			}
		}
	}

	// UpLeft
	if (r != 0 && c!= 0 && board[r-1][c-1] == opp){
		rT = r - 1;
		cT = c - 1;
		while (rT >= 0 && cT >= 0){
			if (board[rT][cT] == curPlayer.piece){
				int j = cT;
				for(int i = rT; i < r && j < c; i++, j++){
					if (flip){
						board[i][j] = curPlayer.piece;
					}
					tF++;
				}
				break;
			}
			if (board[rT][cT] == '_') {
				break;
			}
			if (board[rT][cT] == opp){
				rT -= 1;
				cT -= 1;
			}
		}
	}

	//UpRight
	if (r != 0 && c!= (boardsize-1) && board[r-1][c+1] == opp){
		rT = r - 1;
		cT = c + 1;
		while (rT >= 0 && cT < boardsize){
			if (board[rT][cT] == curPlayer.piece){
				int j = cT;
				for(int i = rT; i < r && j > c; i++, j--){
					if (flip){
						board[i][j] = curPlayer.piece;
					}
					tF++;
				}
				break;
			}
			if (board[rT][cT] == '_') {
				break;
			}
			if (board[rT][cT] == opp){
				rT -= 1;
				cT += 1;
			}
		}
	}


	//DownLeft
	if (r != (boardsize-1) && c!= 0 && board[r-1][c-1] == opp){
		rT = r + 1;
		cT = c - 1;
		while (rT < boardsize && cT >= 0){
			if (board[rT][cT] == curPlayer.piece){
				int j = cT;
				for(int i = rT; i > r && j < c; i--, j++){
					if (flip){
						board[i][j] = curPlayer.piece;
					}
					tF++;
				}
				break;
			}
			if (board[rT][cT] == '_') {
				break;
			}
			if (board[rT][cT] == opp){
				rT += 1;
				cT -= 1;
			}
		}
	}

	//DownRight
	if (r != (boardsize-1) && c!= (boardsize-1) && board[r-1][c-1] == opp){
		rT = r + 1;
		cT = c + 1;
		while (rT < boardsize && cT < boardsize){
			if (board[rT][cT] == curPlayer.piece){
				int j = cT;
				for(int i = rT; i > r && j > c; i--, j--){
					if (flip){
						board[i][j] = curPlayer.piece;
					}
					tF++;
				}
				break;
			}
			if (board[rT][cT] == '_') {
				break;
			}
			if (board[rT][cT] == opp){
				rT += 1;
				cT += 1;
			}
		}
	}
	return tF;
}

void Othello::ckwin(){
	int p1Points = 0;
	int p2Points = 0;
	for (int r = 0; r < boardsize; r++){
		for (int c = 0; c < boardsize; c++){
			if (board[r][c] == p1.piece){
				p1Points++;
			} else if (board[r][c] == p2.piece){
				p2Points++;
			}
		}
	}
	if (p1Points > p2Points){
		cout << p1.name << " won with: " << p1Points << " versus " << p2Points << endl;
	} else if (p2Points > p1Points){
		cout << p2.name << " won with: " << p2Points << " versus " << p1Points << endl;
	} else {
		cout << "Tied game: " << p1Points << " versus " << p2Points << endl;
	}
}

void Othello::compplacepiece(Player p){
	int arr[2];
	arr[2] = 0;
	for(int r = 0; r < boardsize; r++){
		for (int c = 0; c < boardsize; c++){
			if(countandflippieces(c, r, p, false) > arr[2]){
				arr[0] = c;
				arr[1] = r;
				arr[2] = countandflippieces(c, r, p, false);
			} else if (countandflippieces(c, r, p, false) != 0 && countandflippieces(c, r, p, false) == arr[2]){
				if ((rand() % 10) > 5){
					arr[0] = c;
					arr[1] = r;
					arr[2] = countandflippieces(c, r, p, false);
				}
			}
		}
	}
	if(arr[2] == 0){
		cout << "no valid placement";
	} else {
		countandflippieces(arr[0], arr[1], p, true);
	}
}


//playGame Method:
void Othello::playGame(){
	makemat();
	printmat();
	bool play = true;
	int fullsqrs = 0;
	Player p = p1;
	bool whichp = true;
	bool turn = true;

	if (rand()%2 == 0) { // p1 plays first
		p = p2;
		turn = false;
		whichp = false;
	}
	while ((play) && (fullsqrs < 64)){
		cout << endl << p.name <<" ("<<p.piece<<") choose your square: "<<endl;
		if ((numplayers == 2) || ((numplayers == 1) && turn)){
			placepiece(p, p.piece);
		}
		else if ((numplayers == 0) || ((numplayers == 1) && (turn == false))){
			//compplacepiece(p);
		}
		turn = !turn;
		printmat();
		if (whichp) {
			p = p2;
			whichp = false;
		}
		else {
			p=p1;
			whichp = true;
		}
		fullsqrs+=1;
	}
	//ckwin();
}
