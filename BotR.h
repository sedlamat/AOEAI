/*
 * File:	BotR.h
 */

#ifndef BOTR_H_
#define BOTR_H_

#include "Ai.h"

class BotR: public Ai {
public:
	BotR();
	~BotR();
        map<string,bool> exportActions();
        void importReward(int reward);
        void importStates(int* states);
        void importActions(map<string,bool> actions);
private:
    int _oneGameReward;
    string _decisionHistory;
    multimap<int, string> _postupy;
            
};

#endif /* BOTR_H_ */
