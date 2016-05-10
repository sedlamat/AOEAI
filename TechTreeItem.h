/*
 * TechTree.h
 */

#ifndef TECHTREEITEM_H_
#define TECHTREEITEM_H_

#include <vector>
#include "DataStructures.h"

using namespace std;

class TechTreeItem {
public:
    TechTreeItem(){
    };
    ~TechTreeItem(){
    };
    // TODO - implement: methods setAll, a get a set metody pro vsechny private promenne - bude to potreba

    int getHitPoints() {
        return _hitPoints;
    }

    ObjectCategory getCategory() {
        return _category;
    }

    void setAll(ObjectType type,
            ObjectCategory category,
            bool wasResearched,
            int hitPoints,
            int attack,
            int armor,
            float creationSpeed,
            Resources gatheringSpeed,
            Resources cost,
            ObjectType createdIn,
            vector<State> requiredState,
            int requiredAge,
            vector<ObjectType> otherRequiredObjects) {
    }
    
    Resources getCost();
    ObjectType getCreatedIn();
private:
    // characteristics
    ObjectType _type;
    ObjectCategory _category;
    bool _wasResearched; // for tech
    // there is no isAvailable/canBeMade, for this there must be a boolean function (in Player), because
    // availability changes all the time, so no reason to store such fast changing information.
    int _hitPoints;
    int _attack;
    int _armor;
    float _creationSpeed;
    Resources _gatheringSpeed;

    // creation dependencies
    Resources _cost;
    ObjectType _createdIn; // one of ObjectTypes: TOWN_CENTER, STABLES, ..., VILLAGER (for buildings)
    vector<State> _requiredState; // IDLE (if created in a building) or IDLE/GATHERING_../ if it is created in VILLAGER
    int _requiredAge;
    vector<ObjectType> _otherRequiredObjects; // it can be buildings or techs - then one can check if the given buildings have
    // been build (check _ownedbjects or some _stats) or if the given tech was
    // researched (check _wasResearched for the given tech).
};

#endif /* TECHTREEITEM_H_ */
