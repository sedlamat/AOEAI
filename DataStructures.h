/*
 * File:	DataStructures.h
 */

#ifndef DATASTRUCTURES_H_
#define DATASTRUCTURES_H_

enum ObjectType {
    // Units
    VILLAGER,
    MILITIA,
    SPEARMAN,
    ARCHER,
    SCOUT,
    // Buildings
    HOUSE,
    LUMBER_CAMP,
    MINING_CAMP,
    MILL,
    FARM,
    BARRACKS,
    MARKET,
    BLACKSMITH,
    ARCHERY_RANGE,
    STABLE,
    TOWN_CENTER,
    // Technologies
    LOOM,
    FEUDAL_AGE,
    CASTLE_AGE,

    NUMBER_OF_OBJECT_TYPES
};

enum ObjectCategory {
    UNIT,
    BUILDING,
    TECH,

    NUMBER_OF_OBJECT_CATEGORIES
};

enum Action { // actions have to mirror ObjectType in MAKE_units/buildings/techs
    // Making units
    MAKE_VILLAGER,
    MAKE_MILITIA,
    MAKE_SPEARMAN,
    MAKE_ARCHER,
    MAKE_SCOUT,
    // Making buildings
    MAKE_HOUSE,
    MAKE_LUMBER_CAMP,
    MAKE_MINING_CAMP,
    MAKE_MILL,
    MAKE_FARM,
    MAKE_BARRACKS,
    MAKE_MARKET,
    MAKE_BLACKSMITH,
    MAKE_ARCHERY_RANGE,
    MAKE_STABLE,
    MAKE_TOWN_CENTER,
    // Making technologies
    MAKE_LOOM,
    MAKE_FEUDAL_AGE,
    MAKE_CASTLE_AGE,
    // Other
    SEND_TO_WOOD,
    SEND_TO_FOOD,
    SEND_TO_GOLD,
    SEND_TO_STONE,
    SEND_FROM_WOOD_TO_FOOD,
    SEND_FROM_WOOD_TO_GOLD,
    SEND_FROM_WOOD_TO_STONE,
    SEND_FROM_FOOD_TO_WOOD,
    SEND_FROM_FOOD_TO_GOLD,
    SEND_FROM_FOOD_TO_STONE,
    SEND_FROM_GOLD_TO_WOOD,
    SEND_FROM_GOLD_TO_FOOD,
    SEND_FROM_GOLD_TO_STONE,
    SEND_FROM_STONE_TO_WOOD,
    SEND_FROM_STONE_TO_FOOD,
    SEND_FROM_STONE_TO_GOLD,
    ATTACK,

    NUMBER_OF_ACTIONS
};

enum State {
    IDLE,
    CREATING,
    GATHERING,
    ATTACKING,

    NUMBER_OF_STATES
};

struct Resources {
    float _wood;
    float _food;
    float _gold;
    float _stone;

    Resources(){
    };

    Resources(int w, int f, int g, int s) :
    _wood(w),
    _food(f),
    _gold(g),
    _stone(s) {
    }

    Resources(float w, float f, float g, float s) :
    _wood(w),
    _food(f),
    _gold(g),
    _stone(s) {
    }
    ~Resources(){
    };

    void setIntValues(int w, int f, int g, int s) {
        _wood = w;
        _food = f;
        _gold = g;
        _stone = s;
    }
    
    
};
Resources operator - (Resources a, Resources b){
    return Resources(a._wood-b._wood, a._food-b._food, a._gold - b._gold, a._stone - b._stone);
}
bool operator > (Resources a, Resources b){
    if (a._wood>b._wood && a._food>b._food && a._gold > b._gold && a._stone > b._stone){
        return true;
    }
    else 
        return false;
}
bool operator > (Resources a, int b){
    if (a._wood>b && a._food>b && a._gold > b && a._stone > b){
        return true;
    }
    else 
        return false;
}

#endif /* DATASTRUCTURES_H_ */
