#include "drawboard.h"

const char *LABEL = "    0   1   2   3   4   5   6   7";
const char *HLINE = "  +---+---+---+---+---+---+---+---+";
const char *VLINE = "  |   |   |   |   |   |   |   |   |";
#define BOARD_SIZE  (8u)
#define POS1        (floor((float)(BOARD_SIZE+1)/2) - 1)
#define POS2        (ceil((float)(BOARD_SIZE+1)/2) - 1)

drawboard *drawboard::_instance = nullptr; 

/**
 * @brief Construct a new drawboard::drawboard object
 * 
 */
drawboard::drawboard()
{

}

/**
 * @brief Destroy the drawboard::drawboard object
 * 
 */
drawboard::~drawboard()
{

}

/**
 * @brief draw
 * 
 * @param board 
 */
void drawboard::draw(vector<vii> board)
{
    cout << LABEL << endl;
    cout << HLINE << endl;
    for (int y=0; y < BOARD_SIZE; y++)
    {
        cout << VLINE << endl;
        cout << y <<  OTHELLO[(uint8_t)TILE::NONE];
        for (int x=0; x < BOARD_SIZE; x++)
        {
            cout << "| " << board[x][y] << OTHELLO[(uint8_t)TILE::NONE];
        }
        cout << "|" << y << endl;
        cout << VLINE << endl;
        cout << HLINE << endl;
    }
    cout << LABEL << endl;
}

/**
 * @brief clear
 * 
 * @param board 
 */
void drawboard::clear(algoMove_t &boardobj)
{
    boardobj.board.assign(BOARD_SIZE, vii());
    boardobj.oCount = 0;
    boardobj.xCount = 0;
    for (int j=0; j < BOARD_SIZE;j++)
    {
        for (int i=0; i < BOARD_SIZE;i++)
            boardobj.board[j].emplace_back(OTHELLO[(uint8_t)TILE::NONE]);
    }

}

/**
 * @brief restart
 * 
 * @param board 
 */
void drawboard::restart(algoMove_t &boardobj)
{
    for (int j=0; j < BOARD_SIZE;j++)
    {
        for (int i=0; i < BOARD_SIZE;i++)
            boardobj.board[j][i] = OTHELLO[(uint8_t)TILE::NONE];
    }

    boardobj.board[POS1][POS1] = OTHELLO[(uint8_t)TILE::X];
    boardobj.board[POS1][POS2] = OTHELLO[(uint8_t)TILE::O];
    boardobj.board[POS2][POS1] = OTHELLO[(uint8_t)TILE::O];
    boardobj.board[POS2][POS2] = OTHELLO[(uint8_t)TILE::X];

    boardobj.oCount = 2;
    boardobj.xCount = 2;
}

/**
 * @brief upate??
 * 
 */
void drawboard::update()
{

}
