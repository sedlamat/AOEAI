/* 
 * File:   Object.cpp
 */

#include <iostream>
#include "GameObject.h"
#include "Player.h"
#include "DataStructures.h"


using namespace std;

GameObject::GameObject(ObjectType type, Player *player) {
    _owner = player;
    _type = type;
    _category = player->getTechTree()[type].getCategory();
    _state = IDLE;
    _objectTypeInCreation = NUMBER_OF_OBJECT_TYPES; // irrelevant if _creationProgress set to -1.
    _creationProgress = -1; // -1 means that no creation in progress
    _hitPoints = player->getTechTree()[type].getHitPoints();
}

GameObject::~GameObject() {

}

ObjectType GameObject::getObjectType() {
    return _type;
}

ObjectCategory GameObject::getObjectCategory() {
    return _category;
}

State GameObject::getState() {
	return _state;
}

void GameObject::setState(State s) {
    _state = s;
}

void GameObject::update() {

}





