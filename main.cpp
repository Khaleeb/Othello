/*
 * main.cpp
 * Othello
 * Caleb Davis
 * CISC 260 - Dr. Yarrington
 */

#include <iostream>
#include <stdlib.h>
#include "Othello.cpp"
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));
	Othello game("b1",'B',"s1",'O');
	Othello game2("b1",'B');
	Othello game3;

	int gamemode = 0;
	cout << "Number of computer players: ";
	cin >> gamemode;

	if (gamemode == 0){
		game.playGame();
	} else if(gamemode == 1){
		game2.playGame();
	} else if(gamemode == 2){
		game3.playGame();
	} else {
		cout << "invalid input" << endl;
	}
}
