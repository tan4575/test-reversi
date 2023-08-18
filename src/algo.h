#pragma once
#include "north.h"
#include "east.h"
#include "west.h"
#include "south.h"
#include "westsouth.h"
#include "northwest.h"
#include "southeast.h"
#include "eastnorth.h"

class algo{
public:
    algo();
    virtual ~algo();

    static algo& instance() {
        if (!_instance)
        {
            _instance = new algo();
        }
        return *_instance;
    }

    void find();

    north n;
    east e;
    west w;
    south s;
    westsouth ws;
    northwest nw;
    southeast se;
    eastnorth en;

private:
    static algo* _instance;



};

#define ALGO algo::instance()
