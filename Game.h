/*
 * File:	Game.h
 */

#ifndef GAME_H_
#define GAME_H_

#include <iostream>

using namespace std;

class Ai;
class Player;

class Game {
public:
	Game(const int numberOfPlayers, Ai* const * const bot);
	~Game();
	void startSetup();
	void sendStates();
	void sendActions();
	void executeActions();
	void updateGameVariables();
	void sendRewards();
	bool isGameOver();
	void displayStats();
private:
	const int _numberOfPlayers;
	Ai* const * const _bot;
	Player* const _player;
};

#endif /* GAME_H_ */
