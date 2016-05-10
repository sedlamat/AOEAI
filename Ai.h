/*
 * File:	Ai.h
 */

#ifndef AI_H_
#define AI_H_

#include <string>
#include <map>

using namespace std;

class Ai {
public:
	Ai();
	virtual ~Ai();
	virtual void importStates(int* state);
	virtual void importActions(map<string,bool> actions);
	virtual map<string,bool> exportActions();
	virtual void importReward(int reward);
protected:
	map<string,bool> _actions;
	int _state;
	int _currentReward;
};

#endif /* AI_H_ */
