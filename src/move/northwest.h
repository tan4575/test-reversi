#pragma once
#include "../step.h"

class northwest : public step {

public:
    northwest();
    virtual ~northwest();

    static northwest& instance() {
        if (!_instance)
        {
            _instance = new northwest();
        }
        return *_instance;
    }

    void pre();
    void execute();
    void post();

private:
    static northwest* _instance;

};
