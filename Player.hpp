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

public:
	std::string name;
	char piece;
	Player();
	Player(std::string name, char c);
};

#endif
