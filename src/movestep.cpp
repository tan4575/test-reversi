#include "movestep.h"
#include <string.h>
movestep *movestep::_instance = nullptr;

/**
 * @brief loop
 * 
 * @param boardObj 
 */
bool movestep::loop(algoMove_t* boardObj)
{
    if (callback != nullptr) 
        callback(boardObj);
    else{
        return false;
    }
    return true;
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

    instance1->name = _p1;
    instance2->name = _p2;

    instance1->setkeys(_p2);
    instance2->setkeys(_p1);


    makeplayer[_p1] = instance1;
    makeplayer[_p2] = instance2;

    if (_p1.compare("COMPUTER") != 0)
    {
        if (_p2.compare("COMPUTER") == 0)
        {
            instance1->setPlayer(PLAYERTYPE::HUMAN);
            instance2->setPlayer(PLAYERTYPE::COMPUTER);
        }
        else{
            instance1->setPlayer(PLAYERTYPE::HUMAN);
            instance2->setPlayer(PLAYERTYPE::HUMAN);
        }

        t = instance1->updatePlayertile(_p1);
        instance2->setTile(t);
        playerKey = _p1;
    }
    else{
        if (_p2.compare("COMPUTER") == 0)
        {
            instance1->setPlayer(PLAYERTYPE::HUMAN);
            instance2->setPlayer(PLAYERTYPE::HUMAN);
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
    boardObj->tile = getPlayerTile();
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
    updatePlayer("player1","COMPUTER");
    showTips(boardObj);
    setStateCallbackFunc(&movestep::start, this);
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
    if (pos.x >= 0 && pos.y >= 0)
    {
        if (players[turn]->makeMove(boardObj,pos.x,pos.y))
        {
            turn = players[turn]->getkeys();
            showTips(boardObj);
        }
        else{
            if (haveWinner(boardObj))
            {
                setStateCallbackFunc(&movestep::end, this);
            }
        }

        cout << "X - score: " << to_string(boardObj->xCount) << endl;
        cout << "O - score: " << to_string(boardObj->oCount) << endl;
    }
    else{
        cout << "Invalid Input!" << endl;
    }

}

/**
 * @brief find winner if yes return true else false
 * 
 * @param boardObj 
 * @return true 
 * @return false 
 */
bool movestep::haveWinner(algoMove_t* boardObj)
{
    vi validMoves = ALGO.pathFinding(boardObj);
    if (validMoves.size() == 0)
        return true;
    return false;
}

/**
 * @brief end
 * 
 * @param boardObj 
 * @return true 
 * @return false 
 */
void movestep::end(algoMove_t* boardObj)
{
    char c;
    TILE winTile;
    cout << "We have a winner!!!" << endl;
    if (boardObj->oCount != boardObj->xCount)
    {
        if (boardObj->oCount > boardObj->xCount)
        {
            winTile = TILE::O;
        }
        else
        {
            winTile = TILE::X;
        }
        
        if (winTile == players[turn]->getTile())
        {
            cout << "Winner is " << turn << endl;
        }
        else{
            cout << "Winner is " << players[turn]->getkeys() << endl;
        }
    }
    else{
        cout << "Tie " << endl;
    }
    
    cout << "Hit enter to restart." << endl;
    while ((c = getchar()) != '\n');
    setStateCallbackFunc(&movestep::restart,this);
}

void movestep::restart(algoMove_t* boardObj)
{
    draw.clear(*boardObj);
    draw.restart(*boardObj);
    vector<string> toDelete;
    for (auto itr = players.begin(); itr != players.end(); ++itr)
    {
        toDelete.push_back(itr->first);
    }

    if (toDelete.size()!=0)
    {
        for (auto a: toDelete)
        {
            auto it = players.find(a);
            delete players[a];
            players.erase(it);
        }
    }
    setStateCallbackFunc(&movestep::playerInit, this);
}

/**
 * @brief set callback function
*/
void movestep::setStateCallbackFunc(funcCallBack_t cb)
{
    this->callback = cb;
}
