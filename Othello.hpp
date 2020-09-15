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
	Othello(string st1, char c);
	Othello(string st1, char c, string st2, char c2);

	void makemat();
	void printmat();
};
