#pragma once
#include "algo.h"

class base {
public:
    /**
     * @brief virtual input
     * 
     * @param boardObj 
     * @return position_t 
     */
    virtual position_t input(algoMove_t* boardObj) = 0;

    /**
     * @brief update player tile
     * 
     * @return TILE 
     */
    virtual TILE updatePlayertile(const string) = 0;

    /**
     * @brief Get the Tile object
     * 
     * @return TILE 
     */
    virtual TILE getTile() = 0;

    /**
     * @brief make move
     * 
     * @param boardObj 
     * @param x 
     * @param y 
     * @return true 
     * @return false 
     */
    virtual bool makeMove(algoMove_t* boardObj, uint8_t x, uint8_t y) {return false;};

    /**
     * @brief set keys
     * 
     * @param k 
     */
    void setkeys(string k) {
        Oponentkey = k;
    }

    /**
     * @brief get keys
     * 
     * @return string 
     */
    string getkeys() {
        return Oponentkey;
    }

    /**
     * @brief Construct a new base object
     * 
     */
    base() {};

    /**
     * @brief Destroy the base object
     * 
     */
    virtual ~base() {};

    string name;
private:
    string Oponentkey = "";
};