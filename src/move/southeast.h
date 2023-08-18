#pragma once
#include "../step.h"

class southeast : public step {

public:
    southeast();
    virtual ~southeast();

    static southeast& instance() {
        if (!_instance)
        {
            _instance = new southeast();
        }
        return *_instance;
    }

    void pre();
    void execute();
    void post();

private:
    static southeast* _instance;

};
