/*
 * Player.cpp
 * Othello
 * Caleb Davis
 * CISC 260 - Dr. Yarrington
 */

#include <string>
#include "Player.hpp"
#include <iostream>
using namespace std;

Player::Player() {
	name = "computer";
	piece = 'B';
}

Player::Player(std::string name, char piece){
	this->name = name;
	this->piece = piece;
}
