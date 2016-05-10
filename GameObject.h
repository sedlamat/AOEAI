/* 
 * File:	Object.h
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include "DataStructures.h"

using namespace std;

class Player;

class GameObject {
public:
    GameObject(ObjectType type, Player *player);
    ~GameObject();

    ObjectType getObjectType();
    ObjectCategory getObjectCategory();
    State getState();

    void setState(State s);

    void update();
private:
    Player* _owner;
    ObjectType _type;
    ObjectCategory _category;
    State _state;
    ObjectType _objectTypeInCreation;
    int _creationProgress;
    int _hitPoints; // other characteristics/properties (attack, armor, gathering speed, ...) can change from moment to moment, so no reason
    // to keep local copy, instead will always fetch in _techTree for the most recent values
};

#endif /* OBJECT_H */

