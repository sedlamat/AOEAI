/*
 * File:	Ai.cpp
 */

#include <string>
#include <map>
#include "Ai.h"

using namespace std;

Ai::Ai() : _currentReward(-99) {}

Ai::~Ai() {}

void Ai::importStates(int* state) {
	_state = *state;
}

void Ai::importActions(map<string,bool> actions) {
	_actions = actions;
}

map<string,bool> Ai::exportActions() {
	return _actions;
}

void Ai::importReward(const int reward) {
	_currentReward = reward;
}
