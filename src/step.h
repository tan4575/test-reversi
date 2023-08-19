#pragma once
#include <iostream>
#include "drawboard.h"

using namespace std;

typedef struct _position
{
    int x = 0;
    int y = 0;
}position_t;

class step {
public:
    step() {};
    virtual ~step() {};

    virtual void pre() = 0;
    virtual void execute() = 0;
    virtual void post() = 0;

    virtual position_t getPosition() const {
        position_t pos;
        return pos;
    };

};
