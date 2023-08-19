#pragma once
#include "base.h"

/**
 * @brief class enum for player type
 * 
 */
enum class PLAYERTYPE : uint8_t
{
    HUMAN = 0,
    COMPUTER = 1,
};

class player : public base{
public:

    position_t input(algoMove_t* boardObj);

    /**
     * @brief update tile
     * 
     * @return TILE 
     */
    TILE updatePlayertile(const string);

    /**
     * @brief Get the Tile object
     * 
     * @return TILE 
     */
    TILE getTile(){
        return tile;
    };

    /**
     * @brief Set the Tile object
     * 
     */
    void setTile(const TILE);

    /**
     * @brief Set the Player object
     * 
     * @param p 
     */
    void setPlayer(const PLAYERTYPE p){
        playerType = p;
    };

    /**
     * @brief Get the Player object
     * 
     * @return PLAYERTYPE 
     */
    PLAYERTYPE getPlayer(){
        return playerType;
    };

    /**
     * @brief make move
     * 
     * @param boardObj 
     * @param x 
     * @param y 
     * @return true 
     * @return false 
     */
    bool makeMove(algoMove_t* boardObj, uint8_t x, uint8_t y);

    /**
     * @brief update score
     * 
     * @param boardObj 
     * @param x 
     * @param y 
     */
    void updateScore(algoMove_t* boardObj, uint8_t x, uint8_t y);

    /**
     * @brief Construct a new player object
     * 
     */
    player():
    algo(ALGO)
    {

    }
    
    /**
     * @brief Destroy the player object
     * 
     */
    ~player();
private:
    TILE tile;
    algo &algo;
    PLAYERTYPE playerType;

    /**
     * @brief getchar input
     * 
     * @return position_t 
     */
    position_t humanInput();

    /**
     * @brief simulate input
     * 
     * @param boardObj 
     * @return position_t 
     */
    position_t AIInput(algoMove_t* boardObj);


    /**
     * @brief get oponent tile
     * 
     */
    TILE getOponentTile(TILE t);
};