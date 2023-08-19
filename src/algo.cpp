#include "algo.h"

algo *algo::_instance = nullptr; 

// map
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

/**
 * @brief Construct a new algo::algo object
 * 
 */
algo::algo()
{

}

/**
 * @brief Destroy the algo::algo object
 * 
 */
algo::~algo()
{

}

/**
 * @brief path finding
 * 
 * @param boardObj 
 * @return vi 
 */
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
            tilesToFlip = getValidMove(boardObj,i,j);
            if (tilesToFlip != NULL)
            {
                // if found the path push back
                validMoves.push_back({i,j});
            }
            delete tilesToFlip;
        }
    }

    return validMoves;
}

/**
 * @brief get valid move
 * 
 * @param boardObj 
 * @param x 
 * @param y 
 * @return vi* 
 */
vi * algo::getValidMove(const algoMove_t* boardObj, uint8_t x, uint8_t y)
{
    vector<vii> board = boardObj->board;
    position_t pos ={};
    vi *tilesToFlip = new vi;
    int xStart,yStart;
    char otherTile;

    // check is it in within the boundary and not empty
    if (!checkBoundary(boardObj, x, y)|| board[x][y] != ' ' )
    {
        delete tilesToFlip;
        return NULL;
    }

    // assume that current position is correct position then iterrate
    // through all the possible solutions
    // very slow?? 
    board[x][y] = OTHELLO[(uint8_t)boardObj->tile];

    // to see if you are my enermy?
    if (boardObj->tile == TILE::X)
        otherTile =  OTHELLO[1];
    else
        otherTile =  OTHELLO[0];

    // iterate thought E/SE/S/SW/W/NW/N/NE
    for (const auto& [key, instance] : movement)
    {
        pos = instance->getPosition();
        if (pos.x==0 && pos.y==0) continue;
        xStart = x;
        yStart = y;
        xStart += pos.x;
        yStart += pos.y;
        //check if the it is other tile
        if (checkBoundary(boardObj,xStart,yStart) && 
        board[xStart][yStart] == otherTile)
        {
            xStart += pos.x;
            yStart += pos.y;
            if (!checkBoundary(boardObj,xStart,yStart)) continue;

            // loop until it see a different tile
            while (board[xStart][yStart] == otherTile)
            {
                xStart += pos.x;
                yStart += pos.y;
                if (!checkBoundary(boardObj,xStart,yStart)) break;
            }
            if (!checkBoundary(boardObj,xStart,yStart)) continue;

            // if the tile is belong to same tile
            if (board[xStart][yStart] == OTHELLO[(uint8_t)boardObj->tile])
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

/**
 * @brief get all valid moves
 * 
 * @param boardObj 
 * @return algoMove_t* 
 */
algoMove_t* algo::getBoardWithValidMoves(algoMove_t* boardObj)
{
    
    vi validMoves;
    algoMove_t* copyBoard = duplicateBoard(boardObj); //deep copy

    // path finding
    validMoves = pathFinding(copyBoard);
    if (validMoves.size() != 0)
    {
        for (auto &[x,y]: validMoves)
        {
            copyBoard->board[x][y] = OTHELLO[(uint8_t)TILE::TIPS];
        }
    }
    return copyBoard;
}

/**
 * @brief deep copy
 * 
 * @param boardObj 
 * @return algoMove_t* 
 */
algoMove_t* algo::duplicateBoard(const algoMove_t* boardObj)
{
    algoMove_t *copyBoard = new algoMove_t;

    // copy
    copy(boardObj->board.begin(), boardObj->board.end(), back_inserter(copyBoard->board));
    copyBoard->tile = boardObj->tile;
    return copyBoard;
}
