#pragma once
#include "../step.h"

class east : public step {

public:
    east();
    virtual ~east();

    static east& instance() {
        if (!_instance)
        {
            _instance = new east();
        }
        return *_instance;
    }

    void pre();
    void execute();
    void post();

private:
    static east* _instance;

};
