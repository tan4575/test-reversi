#include "movestep.h"
#include <string.h>
movestep *movestep::_instance = nullptr;

/**
 * @brief loop
 * 
 * @param boardObj 
 */
void movestep::loop(algoMove_t* boardObj)
{
    if (callback != nullptr) 
        callback(boardObj);
}

/**
 * @brief update player info
 * 
 * @param p1 
 * @param p2 
 */
void movestep::updatePlayer(const string p1, const string p2)
{

    unordered_map<string,base *> makeplayer = {};
    TILE t;

    string _p1 = toUpper(p1);
    string _p2 = toUpper(p2);

    if (random() == 0)
        turn = _p1;
    else
        turn = _p2;
    
    player* instance1 = new player(); //p1
    player* instance2 = new player(); //p2

    
    instance1->setkeys(_p2);
    instance2->setkeys(_p1);

    makeplayer[_p1] = instance1;
    makeplayer[_p2] = instance2;

    if (_p1.compare("COMPUTER") != 0)
    {
        instance1->setPlayer(PLAYERTYPE::HUMAN);
        instance2->setPlayer(PLAYERTYPE::COMPUTER);
        t = instance1->updatePlayertile(_p1);
        instance2->setTile(t);
        playerKey = _p1;
    }
    else{
        if (_p2.compare("COMPUTER") == 0)
        {
            instance1->setPlayer(PLAYERTYPE::HUMAN);
            instance2->setPlayer(PLAYERTYPE::COMPUTER);
        }
        else
        {
            instance1->setPlayer(PLAYERTYPE::COMPUTER);
            instance2->setPlayer(PLAYERTYPE::HUMAN);
        }
        t = instance2->updatePlayertile(_p2);
        instance1->setTile(t);
        playerKey = _p2;
    }

    players = makeplayer;
}

/**
 * @brief show tips
 * 
 * @param boardObj 
 */
void movestep::showTips(algoMove_t* boardObj)
{
    boardObj->tile = MOVESTEP.getPlayerTile();
    algoMove_t *copyBoard = new algoMove_t;
    copyBoard = ALGO.getBoardWithValidMoves(boardObj);
    DRAWBOARD.draw(copyBoard->board);
    delete copyBoard;
}

/**
 * @brief change string to upper
 * 
 * @param s 
 * @return string 
 */
string movestep::toUpper(const string s){
    string ret = "";
    for (int i=0; i < s.length(); i++)
    {
        ret += toupper(s[i]);
    }
    return ret;
}

/**
 * @brief random value between 1 or 2
 * 
 * @return uint8_t 
 */
uint8_t movestep::random(){

    srand(static_cast<unsigned>(time(nullptr)));

    return rand() % 2;
}


/**
 * @brief palyer init
 * 
 * @param boardObj 
 */
void movestep::playerInit(algoMove_t* boardObj){
    updatePlayer("COMPUTER","player");
    showTips(boardObj);
    setStateCallbackFunc(start, this);
}

/**
 * @brief game start
 * 
 * @param boardObj 
 */
void movestep::start(algoMove_t* boardObj){
    cout << "Is: " << turn << " turn" <<endl;
    boardObj->tile = players[turn]->getTile();
    position_t pos = players[turn]->input(boardObj);
    if (players[turn]->makeMove(boardObj,pos.x,pos.y))
    {
        turn = players[turn]->getkeys();
        showTips(boardObj);
    }
    cout << "X - score: " << to_string(boardObj->xCount) << endl;
    cout << "O - score: " << to_string(boardObj->oCount) << endl;
}


/**
 * @brief set callback function
*/
void movestep::setStateCallbackFunc(funcCallBack_t callback)
{
    this->callback = callback;
}
