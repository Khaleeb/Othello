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
	Player p1;
	Player p2("computer2", 'O');

}

Othello::Othello(string st1, char c){
	boardsize = 8;
	numplayers = 1;
	Player p1(st1, c);
	if (c == 'B'){
		Player p2("computer", 'O');
	} else {
		Player p2;
	}
}

Othello::Othello(string st1, char c, string st2, char c2){
	boardsize = 8;
	numplayers = 2;
	Player p1(st1, c);
	Player p2(st2, c2);
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
	if (!countandflippieces(x, y, curPlayer)){
		cout << "Player forfeits turn" << endl;
		board[y][x] = '_';
	}
}

int Othello::countandflippieces(int c, int r, Player curPlayer){
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
					board[r][i] = curPlayer.piece;
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
					board[r][i] = curPlayer.piece;
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
					board[i][c] = curPlayer.piece;
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
					board[i][c] = curPlayer.piece;
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
	return tF;
}


//playGame Method:
void Othello::playGame(){
	makemat();
	printmat();
	/*
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
			placepiece(p);
		}
		else if ((numplayers == 0) || ((numplayers == 1) && (turn == false))){
			compplacepiece(p);
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
	ckwin();
	*/
}
