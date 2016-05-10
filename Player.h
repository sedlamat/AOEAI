/*
 * File:	Player.h
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include <map>
#include "DataStructures.h"
#include "TechTreeItem.h"
#include "GameObject.h"

using namespace std;

class GameObject;

class Player {
public:
    Player();
    ~Player();

    void startSetup();
    void addToOwnedObjects(GameObject* newObject);
    void removeFromOwnedObjects(GameObject* object);

    void executeAllActions(vector<unsigned int> actions);
    void executeAction(unsigned int action);
    void initiateCreation(ObjectType type);
    void finalizeCreation(ObjectType type);

    bool canMake(ObjectType type);

    void updateObjects();

    void fillTechTree();
    vector<TechTreeItem> getTechTree();


private:
    Resources _resources;
    int _currentAge;
    int _population;
    int _populationLimit;
    vector<Action> _actions;
    vector< vector<GameObject*> > _ownedObjects;
    vector<TechTreeItem> _techTree;
};
#endif /* PLAYER_H_ */
