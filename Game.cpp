/*
 * File:	Game.cpp
 */

#include "Game.h"
#include "Ai.h"
#include "Player.h"

Game::Game(const int numberOfPlayers, Ai * const * const bot) :
	_numberOfPlayers(numberOfPlayers),
	_bot(bot),
	_player(new Player [numberOfPlayers]) {}

Game::~Game() {
	delete [] _player;
}

void Game::startSetup() {
	for (int ii = 0; ii < _numberOfPlayers; ++ii) {
		_player[ii].startSetup();
	}
}

void Game::sendStates() {
	for(int ii = 0; ii < _numberOfPlayers; ++ii) {
		//_bot[ii]->importStates(_player[ii].getStats());
	}
}

void Game::sendActions() {
	for(int ii = 0; ii < _numberOfPlayers; ++ii) {
		//_bot[ii]->importActions(_player[ii].getActions());
	}
}

void Game::executeActions() {
	for(int ii = 0; ii < _numberOfPlayers; ++ii) {
		//_player[ii].executeActions(_bot[ii]->exportActions());
	}
}

void Game::updateGameVariables() {
	for(int ii = 0; ii < _numberOfPlayers; ++ii) {
		//_player[ii].updateObjectsAndVariables();
	}
}

void Game::sendRewards() {
	for(int ii = 0; ii < _numberOfPlayers; ++ii) {
		//_bot[ii]->importReward(_player[ii].getReward());
	}
}

bool Game::isGameOver() {
	for(int ii = 0; ii < _numberOfPlayers; ++ii) {
		//if (_player[ii].isGameOver()) return 1;
	}
	return 0;
}

void Game::displayStats() {
	for(int ii = 0; ii < _numberOfPlayers; ++ii) {
		cout << "Player " << ii+1 <<": ";
		//_player[ii].displayStats();
	}
}


