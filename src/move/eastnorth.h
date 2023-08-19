#pragma once
#include "../step.h"

class eastnorth : public step {

public:
    eastnorth();
    virtual ~eastnorth();

    static eastnorth& instance() {
        if (!_instance)
        {
            _instance = new eastnorth();
        }
        return *_instance;
    }

    void pre();
    void execute();
    void post();

    position_t getPosition() const { return pos; };

private:
    static eastnorth* _instance;
    const position_t pos = {-1,1};

};
