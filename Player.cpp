/*
 * Player.cpp
 * Othello
 * Caleb Davis
 * CISC 260 - Dr. Yarrington
 */

#include "Player.hpp"

Player::Player() {
	name = "computer";
	piece = 'B';
}

Player::Player(string name, char piece){
	this.name = name;
	this.piece = piece;
}
