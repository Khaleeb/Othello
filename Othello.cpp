/*
 * Othello.cpp
 * Othello
 * Caleb Davis
 * CISC 260 - Dr. Yarrington
 */

#include "Othello.hpp"
#include "Player.hpp"
#include <string>

#include <iostream>
#include <stdlib.h>
using namespace std;


Othello::Othello(){
	numplayer = 0;
	p1 = new Player();
	p2 = new Player("computer2", "O");

}

Othello::Othello(string st1, char c){
	numplayer = 1;
	p1 = new Player(st1, c);
	if (c == "B"){
		p2 = new Player("computer", "O");
	} else {
		p2 = new Player();
	}
}

Othello::Othello(string st1, char c, string st2, char c2){
	numplayer = 2;
	p1 = new Player(st1, c);
	p2 = new Player(st2, c2);
}

void Othello::makemat(){
	for (int r = 0; r < boardsize; r++){
		for (int c = 0; c < boardsize; c++){
			board[r][c] = '_';
		}
	}
	board[3][3] = "B";
	board[4][4] = "B";
	board[3][4] = "O";
	board[4][3] = "O";
}

void Othello::printmat(){
	for (int r = 0; r < boardsize+1; r++){
		for (int c = 0; c < boardsize+1; c++){
			if (c == 0){
				if (r != 0){
					cout << c - 1 << " ";
				}
			}
			if(r == 0){
				cout << c - 1 << " ";
			} else {
				cout << board[r-1][c-1] << " ";
			}
		}
		cout << endl;
	}
}




//playGame Method:
void Othello::playGame(){
	makemat();
	printmat();
	bool play = true;
	int fullsqrs = 0;
	player p = p1;
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
}
