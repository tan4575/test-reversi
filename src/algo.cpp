#include "algo.h"
#include<algorithm>
algo *algo::_instance = nullptr; 

static unordered_map<string,step *> movement ={
    {"NORTH"    , &ALGO.n},
    {"WEST"     , &ALGO.w},
    {"SOUTH"    , &ALGO.s},
    {"EAST"     , &ALGO.e},
    {"WESTSOUTH", &ALGO.ws},
    {"NORTHWEST", &ALGO.nw},
    {"SOUTHEAST", &ALGO.se},
    {"EASTNORTH", &ALGO.en},
};

algo::algo()
{

}

algo::~algo()
{

}

void algo::find(algoMove_t* boardObj)
{
    pathFinding(boardObj);
}

vi algo::pathFinding(algoMove_t* boardObj)
{
    vector<vii> board = boardObj->board;
    vi *tilesToFlip = NULL;
    vi validMoves = {};

    // o(n^2) can be improve?
    for (int i= 0; i < board.size(); i++)
    {
        for (int j= 0; j < board[i].size(); j++)
        {
            tilesToFlip = isValidMove(boardObj,i,j);
            if (tilesToFlip != NULL)
            {
                validMoves.push_back({i,j});
            }
            delete tilesToFlip;
        }
    }

    return validMoves;
}

vi * algo::isValidMove(const algoMove_t* boardObj, uint8_t x, uint8_t y)
{
    vector<vii> board = boardObj->board;
    position_t pos ={};
    vi *tilesToFlip = new vi;
    int xStart,yStart;
    char otherTile;

    if (board[x][y] != ' ' || !checkBoundary(boardObj, x, y))
    {
        delete tilesToFlip;
        return NULL;
    }

    board[x][y] = OTHELLO[boardObj->tile];

    if (boardObj->tile == 0)
        otherTile =  OTHELLO[1];
    else
        otherTile =  OTHELLO[0];

    for (const auto& [key, instance] : movement)
    {
        pos = instance->getPosition();
        if (pos.x==0 && pos.y==0) continue;
        xStart = x;
        yStart = y;
        xStart += pos.x;
        yStart += pos.y;
        if (checkBoundary(boardObj,xStart,yStart) && 
        board[xStart][yStart] == otherTile)
        {
            xStart += pos.x;
            yStart += pos.y;
            if (!checkBoundary(boardObj,xStart,yStart)) continue;
            while (board[xStart][yStart] == otherTile)
            {
                xStart += pos.x;
                yStart += pos.y;
                if (!checkBoundary(boardObj,xStart,yStart)) break;
            }
            if (!checkBoundary(boardObj,xStart,yStart)) continue;
            if (board[xStart][yStart] == OTHELLO[boardObj->tile])
            {
                while (true)
                {
                    xStart -= pos.x;
                    yStart -= pos.y;
                
                    if (x == xStart && y == yStart) break;
                    tilesToFlip->push_back({xStart, yStart});
                }
            }
        }
    }
    board[x][y] = OTHELLO[2];
    if (tilesToFlip->size() == 0)
        return NULL;
    return tilesToFlip;
}

algoMove_t* algo::getBoardWithValidMoves(algoMove_t* boardObj)
{
    
    vi validMoves;
    algoMove_t* copyBoard = duplicateBoard(boardObj);
    validMoves = pathFinding(copyBoard);
    if (validMoves.size() != 0)
    {
        for (auto &[x,y]: validMoves)
        {
            copyBoard->board[x][y] = OTHELLO[3];
        }
    }
    return copyBoard;
}

algoMove_t* algo::duplicateBoard(const algoMove_t* boardObj)
{
    algoMove_t *copyBoard = new algoMove_t;
    copy(boardObj->board.begin(), boardObj->board.end(), back_inserter(copyBoard->board));
    copyBoard->tile = boardObj->tile;
    copyBoard->x = boardObj->x;
    copyBoard->y = boardObj->y;
    return copyBoard;
}
