#pragma once
#include "player.h"
#include <functional>

typedef function<void(algoMove_t*)> funcCallBack_t;


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
    bool loop(algoMove_t* boardObj);

private:
    /**
     * @brief Construct a new movestep object
     * 
     */
    movestep():draw(DRAWBOARD) {
        setStateCallbackFunc(&movestep::playerInit, this);
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

    /**
     * @brief init player
     * 
     * @param boardObj 
     */
    void playerInit(algoMove_t* boardObj);

    /**
     * @brief start
     * 
     * @param boardObj 
     */
    void start(algoMove_t* boardObj);

    /**
     * @brief Get the Score object
     * 
     * @param boardObj 
     */
    bool haveWinner(algoMove_t* boardObj);

    /**
     * @brief end game
     * 
     * @param boardObj 
     * @return true 
     * @return false 
     */
    void end(algoMove_t* boardObj);

    /**
     * @brief restart
     * 
     * @param boardObj 
     */
    void restart(algoMove_t* boardObj);
    /**
     * @brief set state callback function
    */
    template <typename T>
    void setStateCallbackFunc(void (T::*callback)(algoMove_t *), T *instance=nullptr);

    void setStateCallbackFunc(funcCallBack_t cb);

    static movestep *_instance;
    drawboard &draw;
    string turn;
    string playerKey;
    unordered_map<string,base *> players = {};
    funcCallBack_t callback = nullptr;

};

template <typename T>
void movestep::setStateCallbackFunc(void (T::*callback)(algoMove_t *), T *instance){
    setStateCallbackFunc(bind(callback, instance, placeholders::_1));
}

#define MOVESTEP movestep::instance()