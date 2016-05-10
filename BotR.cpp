/*
 * File:	BotR.cpp
 */
#include <iostream>
#include "BotR.h"
#include <map>
#include <time.h>
#include <stdlib.h>  

using namespace std;

BotR::BotR() {
    _decisionHistory = "";
    _currentReward = 0;
    _oneGameReward = 0;
}

BotR::~BotR() {
}

map<string, bool> BotR::exportActions() {
//    map<string, bool>m;
//    double rnd = rand();
//    if (_state["VillagerCount"]>x) {
//
//        m["Wait"] = true;
//        _decisionHistory += "Wait ";
//        return m;
//    } else {
//        m["MakeVillager"] = true;
//        _decisionHistory += "MakeVill ";
//        return m;
//    }
}

void BotR::importReward(int reward) {
    if (reward == 0) {
        _postupy.insert(pair<int, string>(_oneGameReward, _decisionHistory));

        int highest = -100;
        string best = "";
        multimap<int, string>::iterator it;
        for (it = _postupy.begin(); it != _postupy.end(); it++) {
            if (it->first > highest) {
                highest = it->first;
                best = it->second;
            }
            cout << it->first << " => " << it->second << endl;
        }

        _oneGameReward = 0;
        _decisionHistory = "";
    } else {
        _oneGameReward += reward;

    }


}

void BotR::importActions(map<string, bool> actions) {
    _actions = actions;
}

void BotR::importStates(int* states) {
    _state = *states;
}


