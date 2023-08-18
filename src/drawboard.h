#pragma once
#include <vector>
#include <string>
using namespace std;

typedef vector<char> vii;

const char OTHELLO[] = {'X','O',' '};

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