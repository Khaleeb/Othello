/*
 * Othello.hpp
 * Othello
 * Caleb Davis
 * CISC 260 - Dr. Yarrington
 */

#ifndef OTHELLO_HPP
#define OTHELLO_HPP

#include "Player.hpp"

class Othello {
public:
	char board [8][8];
	int boardsize;
	Player p1;
	Player p2;
	int numplayers;

	Othello();
	Othello(std::string, char);
	Othello(std::string, char, std::string, char);

	void makemat();
	void printmat();
	void placepiece(Player, char);
	int countandflippieces(int, int, Player);
	void ckwin();

	void playGame();
};

#endif
