#pragma once
#include "../step.h"

class westsouth : public step {

public:
    westsouth();
    virtual ~westsouth();

    static westsouth& instance() {
        if (!_instance)
        {
            _instance = new westsouth();
        }
        return *_instance;
    }

    void pre();
    void execute();
    void post();

    position_t getPosition() const { return pos; };

private:
    static westsouth* _instance;
    const position_t pos = {1,-1};
};
