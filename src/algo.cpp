#include "algo.h"
#include <string>
#include <unordered_map>

algo *algo::_instance = nullptr; 

static unordered_map<string,step *> movement ={
    {"NORTH"    , &ALGO.n},
    {"WEST"     , &ALGO.w},
    {"SOUTH"    , &ALGO.s},
    {"EAST"     , &ALGO.e},
    {"WESTSOUTH", &ALGO.ws},
    {"NORTHWEST", &ALGO.nw},
    {"SOUTHEAST", &ALGO.se},
    {"EASTNORTH", &ALGO.en},
};

algo::algo()
{

}

algo::~algo()
{

}

void algo::find()
{
    for (const auto& [key, instance] : movement)
        instance->execute();
}
