/*
 * Player.hpp
 * Othello
 * Caleb Davis
 * CISC 260 - Dr. Yarrington
 */

#include <string>
#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {

	std::string name;
	char piece;

public:
	Player();
	Player(std::string name, char c);
};

#endif
