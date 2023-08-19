#pragma once
#include "drawboard.h"
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

    void find(algoMove_t* boardObj);

    algoMove_t* getBoardWithValidMoves(algoMove_t* boardObj);

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

    vi pathFinding(algoMove_t* boardObj);

    vi* isValidMove(const algoMove_t* boardObj, uint8_t x, uint8_t y);

    bool checkBoundary(const algoMove_t* boardObj, uint8_t x, uint8_t y)
    {
        return (x >= 0 && x < boardObj->board.size() && 
        y >= 0 && y < boardObj->board.size());
    }

    algoMove_t* duplicateBoard(const algoMove_t* boardObj);

};

#define ALGO algo::instance()
