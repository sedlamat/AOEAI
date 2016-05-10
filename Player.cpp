/*
 * File:	Player.cpp
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "Player.h"
#include "GameObject.h"
#include "DataStructures.h"
#include "TechTreeItem.h"

using namespace std;

Player::Player() {
    _resources.setIntValues(0, 0, 0, 0);
    _currentAge = 1;
    _population = 0;
    _populationLimit = 0;
    _ownedObjects.assign(NUMBER_OF_OBJECT_TYPES, vector<GameObject*>());
    _techTree.assign(NUMBER_OF_OBJECT_TYPES, TechTreeItem());
}

Player::~Player() {
    for (auto vect : _ownedObjects) {
        for (auto pointer : vect) {
            delete pointer;
        }
    }
}

void Player::startSetup() {
    _resources.setIntValues(200, 200, 100, 200);
    addToOwnedObjects(new GameObject(VILLAGER, this));
    addToOwnedObjects(new GameObject(VILLAGER, this));
    addToOwnedObjects(new GameObject(VILLAGER, this));
    addToOwnedObjects(new GameObject(TOWN_CENTER, this));
}

void Player::addToOwnedObjects(GameObject* newObject) {
    _ownedObjects[newObject->getObjectType()].push_back(newObject);
    if (newObject->getObjectCategory() == UNIT) _population += 1;
    if (newObject->getObjectType() == TOWN_CENTER or newObject->getObjectType() == HOUSE) _populationLimit += 5;
}

void Player::removeFromOwnedObjects(GameObject* object) {
    ObjectType type = object->getObjectType();
    if (object->getObjectCategory() == UNIT) --_population;
    if (type == TOWN_CENTER or type == HOUSE) _populationLimit -= 5;
    auto position = find(_ownedObjects[type].begin(), _ownedObjects[type].end(), object);
    if (position != _ownedObjects[type].end()) {
        delete object;
        _ownedObjects[type].erase(position);
    } else {
        cout << "Unable to erase GameObject" << endl;
    }
}

void Player::updateObjects() {
    for (auto vect : _ownedObjects) {
        for (auto object : vect) {
            object->update();
        }
    }
}

void Player::executeAllActions(vector<unsigned int> actions) {
    for (auto action : actions) {
        executeAction(action);
    }
}

void Player::executeAction(unsigned int action) {
    if (action < NUMBER_OF_OBJECT_TYPES) { // is one of the MAKE_something actions (units, buildings, techs)
        initiateCreation(ObjectType(action));
    } else { // is some kind of unit action (SEND_TO_WOOD, ..., ATTACK, ...)
        switch (action) {
            case SEND_TO_WOOD: case SEND_TO_FOOD: case SEND_TO_GOLD: case SEND_TO_STONE:
                // TODO - implement	1. check if there is an idle villager
                //			2. if so, change his state to gathering wood/food/gold/stone
                break;
            case SEND_FROM_WOOD_TO_FOOD:
                // TODO - implement	1. check if there is a villager gathering wood
                //			2. if so, change his state to gathering food
                break;
                // TODO - implement the of the cases (actions SEND_FROM_X_TO_Y)

            default:
                cout << "Action " << action << " has not been defined/implemented yet!" << endl;
                break;
        }
    }
}

bool Player::canMake(ObjectType type) {
    TechTreeItem item = _techTree[type];
    // TODO - implement 0. check that there is enough resources (plus all conditions below must also be satisfied)
    //					1. find (in TechTree) where it is created, ObjectType createdIn (VILLAGER, TOWN_CENTER, STABLES, ...)
    //					2. check if there is an GameObject instance createdIn that is IDLE (or VILLAGER not in state BUILDING), get pointer to it
    //					3. check if other conditions are satisfied (age, tech necessary, other buildings necessary)
    //					4. if the object to be created is of category UNIT, then check that pop is under pop limit
    
    if (_resources - item.getCost() > 0) // is there enough res
    {
        if (item.getCategory() == ObjectCategory.UNIT && _population>=_populationLimit){ // poplimit?
            return false;
        }
        if (_ownedObjects[item.getCreatedIn()].empty()){
            return false;               // no object to be created in
        }
        else{
            for(vector<GameObject*>::iterator it = _ownedObjects[item.getCreatedIn()].begin(); it < _ownedObjects[item.getCreatedIn()].end(); ++it ){
                if (_ownedObjects[item.getCreatedIn()][it]->getState() == IDLE or (item.getCreatedIn() == VILLAGER and _ownedObjects[item.getCreatedIn()][it]->getState() != BUILDING)){
                    // TODO - check other dependencies
                }
            }
        }
    }
    return 0;
}

void Player::initiateCreation(ObjectType type) {
    if (canMake(type)) {
        // TODO - implement: Set the state of the GameObject where it will be created to CREATING and set what it will be creating
    }
}

void Player::finalizeCreation(ObjectType type) {
    // this method will be called by any object where creation is finished (creationProgres >= 100)
    // TODO - implement 0. if the created object is of category UNIT or BUILDING then just create the corresponding GameObject and
    //					   add it to the players' objects
    //					1. if the created object is of category TECH, than call something like executeTech(ObjectType type)
    //					2. implement executeTech(ObjectType type) where there will be switch-case for LOOM, FEUDAL_AGE, ...
    //					   which will execute individual techs.
    //					3. Make sure that when executing individual techs, other corresponding techs/buildings/units are set
    //					   isAvailable to true (in techTree), and the executed tech is set to isAvailable to false
}

void Player::fillTechTree() {
    TechTreeItem item = _techTree[VILLAGER];

    _techTree[VILLAGER].setAll(VILLAGER, UNIT, false, 40, 3, 0, 25.f, Resources(0.388f, 0.31f, 0.379f, 0.359f),
            Resources(0, 50, 0, 0), TOWN_CENTER, vector<State> {
        IDLE}, 1, vector<ObjectType>{});
    // TODO - implement: set techTreeItems for the rest of the ObjectTypes
}

vector<TechTreeItem> Player::getTechTree() {
    return _techTree;
}
