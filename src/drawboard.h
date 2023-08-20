#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <cmath>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vi;
typedef vector<char> vii;

enum class TILE : uint8_t
{
    X = 0,
    O = 1,
    NONE = 2,
    TIPS = 3,
};

enum class WINNER : uint8_t
{
    NONE = 0,
    PLAYER1 = 1,
    PLAYER2 = 2,
};

typedef struct _algoMove
{
    vector<vii> board;
    uint8_t xCount  = 0;
    uint8_t oCount  = 0;
    TILE tile       = TILE::X;
    WINNER runner   = WINNER::NONE;
}algoMove_t;


const char OTHELLO[] = {'X','O',' ', '.'};

class drawboard{
public:
    /**
     * @brief Construct a new drawboard object
     * 
     */
    drawboard();

    /**
     * @brief Destroy the drawboard object
     * 
     */
    virtual ~drawboard();

    static drawboard& instance() {
        if (!_instance)
        {
            _instance = new drawboard();
        }
        return *_instance;
    }

    /**
     * @brief draw board
     * 
     * @param board 
     */
    void draw(vector<vii> board);

    /**
     * @brief clear board
     * 
     * @param boardobj 
     */
    void clear(algoMove_t &boardobj);

    /**
     * @brief restart the game
     * 
     * @param boardobj 
     */
    void restart(algoMove_t &boardobj);

    void update();

private:
    static drawboard* _instance;

};

#define DRAWBOARD drawboard::instance()