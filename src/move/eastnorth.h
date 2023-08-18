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
private:
    static eastnorth* _instance;

};
