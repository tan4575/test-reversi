#pragma once
#include "../step.h"

class north : public step {

public:
    north();
    virtual ~north();

    static north& instance() {
        if (!_instance)
        {
            _instance = new north();
        }
        return *_instance;
    }

    void pre();
    void execute();
    void post();

private:
    static north* _instance;

};
