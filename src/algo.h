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
    /**
     * @brief Construct a new algo object
     * 
     */
    algo();

    /**
     * @brief Destroy the algo object
     * 
     */
    virtual ~algo();

    static algo& instance() {
        if (!_instance)
        {
            _instance = new algo();
        }
        return *_instance;
    }

    /**
     * @brief path finding
     * 
     * @param boardObj 
     * @return vi 
     */
    vi pathFinding(algoMove_t* boardObj);

    /**
     * @brief Get the Board With Valid Moves object
     * 
     * @param boardObj 
     * @return algoMove_t* 
     */
    algoMove_t* getBoardWithValidMoves(algoMove_t* boardObj);

    /**
     * @brief Get the Valid Move object
     * 
     * @param boardObj 
     * @param x 
     * @param y 
     * @return vi* 
     */
    vi* getValidMove(const algoMove_t* boardObj, uint8_t x, uint8_t y);

    /**
     * @brief intances for position
     * 
     */
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

    /**
     * @brief check for boundary
     * 
     * @param boardObj 
     * @param x 
     * @param y 
     * @return true 
     * @return false 
     */
    bool checkBoundary(const algoMove_t* boardObj, uint8_t x, uint8_t y) const
    {
        return x < boardObj->board.size() && y < boardObj->board.size();
    }

    /**
     * @brief deep copy
     * 
     * @param boardObj 
     * @return algoMove_t* 
     */
    algoMove_t* duplicateBoard(const algoMove_t* boardObj);

};

#define ALGO algo::instance()
