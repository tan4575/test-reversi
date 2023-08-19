#pragma once
#include "player.h"

class movestep {
public:
    /**
     * @brief init instance object
     * 
     * @return movestep& 
     */
    static movestep& instance() {
        if (!_instance)
        {
            _instance = new movestep();
        }
        return *_instance;
    }

    /**
     * @brief show tips
     * 
     * @param boardObj 
     */
    void showTips(algoMove_t* boardObj);

    /**
     * @brief update player
     * 
     * @param p1 
     * @param p2 
     */
    void updatePlayer(string p1, string p2);

    /**
     * @brief loop
     * 
     * @param boardObj 
     */
    void loop(algoMove_t* boardObj);

private:
    /**
     * @brief Construct a new movestep object
     * 
     */
    movestep():draw(DRAWBOARD) {
    };

    /**
     * @brief Destroy the movestep object
     * 
     */
    ~movestep() {};

    /**
     * @brief convert string
     * 
     * @return string 
     */
    string toUpper(const string);

    /**
     * @brief randomize 1 or 2
     * 
     * @return uint8_t 
     */
    uint8_t random();

    /**
     * @brief Get the Player Tile object
     * 
     * @return TILE 
     */
    TILE getPlayerTile() {
        return players[playerKey]->getTile();
    }

    static movestep *_instance;
    drawboard &draw;
    string turn;
    string playerKey;
    unordered_map<string,base *> players = {};

};

#define MOVESTEP movestep::instance()