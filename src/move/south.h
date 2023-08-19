#pragma once
#include "../step.h"

class south : public step {

public:
    south();
    virtual ~south();

    static south& instance() {
        if (!_instance)
        {
            _instance = new south();
        }
        return *_instance;
    }

    void pre();
    void execute();
    void post();
    position_t getPosition() const { return pos; };

private:
    static south* _instance;
    const position_t pos = {1,0};

};
