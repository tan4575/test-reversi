#include "drawboard.h"
#include <iostream>
#include <cmath>
using namespace std;

const char *LABEL = "    1   2   3   4   5   6   7   8";
const char *HLINE = "  +---+---+---+---+---+---+---+---+";
const char *VLINE = "  |   |   |   |   |   |   |   |   |";
#define BOARD_SIZE  (8u)
#define POS1        (floor((float)(BOARD_SIZE+1)/2) - 1)
#define POS2        (ceil((float)(BOARD_SIZE+1)/2) - 1)

drawboard *drawboard::_instance = nullptr; 

drawboard::drawboard()
{

}

drawboard::~drawboard()
{

}


void drawboard::draw(vector<vii> board)
{
    cout << LABEL << endl;
    cout << HLINE << endl;
    for (int y=0; y < BOARD_SIZE; y++)
    {
        cout << VLINE << endl;
        cout << y+1 <<  OTHELLO[2];
        for (int x=0; x < BOARD_SIZE; x++)
        {
            cout << "| " << board[x][y] << OTHELLO[2];
        }
        cout << "|" << endl;
        cout << VLINE << endl;
        cout << HLINE << endl;
    }


}

void drawboard::clear(vector<vii> &board)
{
    board.assign(BOARD_SIZE, vii());

    for (int j=0; j < BOARD_SIZE;j++)
    {
        for (int i=0; i < BOARD_SIZE;i++)
            board[j].emplace_back(OTHELLO[2]);
    }

}

void drawboard::restart(vector<vii> &board)
{
    for (int j=0; j < BOARD_SIZE;j++)
    {
        for (int i=0; i < BOARD_SIZE;i++)
            board[j][i] = OTHELLO[2];
    }

    board[POS1][POS1] = OTHELLO[0];
    board[POS1][POS2] = OTHELLO[1];
    board[POS2][POS1] = OTHELLO[1];
    board[POS2][POS2] = OTHELLO[0];

}
