#pragma once
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vi;
typedef vector<char> vii;

typedef struct _algoMove
{
    vector<vii> board;
    uint8_t x = 0;
    uint8_t y = 0;
    uint8_t tile = 0;
}algoMove_t;

const char OTHELLO[] = {'X','O',' ', '.'};

class drawboard{
public:
    drawboard();
    virtual ~drawboard();

    static drawboard& instance() {
        if (!_instance)
        {
            _instance = new drawboard();
        }
        return *_instance;
    }

    void draw(vector<vii> board);

    void clear(vector<vii>&board);

    void restart(vector<vii>&board);

private:
    static drawboard* _instance;



};

#define DRAWBOARD drawboard::instance()