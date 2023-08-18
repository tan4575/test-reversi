#pragma once
#include "../step.h"

class west : public step {

public:
    west();
    virtual ~west();

    static west& instance() {
        if (!_instance)
        {
            _instance = new west();
        }
        return *_instance;
    }

    void pre();
    void execute();
    void post();

private:
    static west* _instance;

};
