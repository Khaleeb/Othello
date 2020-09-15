/*
 * Othello.hpp
 * Othello
 * Caleb Davis
 * CISC 260 - Dr. Yarrington
 */

class Othello {
	char[8][8] board;
	int boardsize;
	Player p1;
	Player p2;
	int numplayer;

public:
	Othello();
	Othello(string, char);
	Othello(string, char, string, char);

	void makemat();
	void printmat();

	void playGame();
};
