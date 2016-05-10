/*
 * File:	main.cpp
 */

#include <iostream>
#include "Ai.h"
#include "Game.h"
#include "BotM.h"
#include "BotR.h"

using namespace std;

int main(int argc, char** argv) {
	const int numberOfPlayers = 1;
	const int numberOfGames = 100;

	Ai** const bot = new Ai* [numberOfPlayers];
	for (int ii = 0; ii < numberOfPlayers; ++ii) {
		bot[ii] = new BotM;
	}

	for (int gameCount = 0; gameCount < numberOfGames; ++gameCount) {
		cout << "Game number " << gameCount << ":"<< endl;
		Game game(numberOfPlayers, bot);
		game.startSetup();
		int time = 0;
		while (!game.isGameOver() and time < 100) {
			game.sendStates();
			game.sendActions();
			game.executeActions();
			game.updateGameVariables();
			game.sendRewards();
			game.displayStats();
			++time;
		}
	}

	for (int ii = 0; ii < numberOfPlayers; ++ii) {
		delete bot[ii];
	}
	delete [] bot;

	return 0;
}

