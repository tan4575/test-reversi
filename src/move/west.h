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
    position_t getPosition() const { return pos; };

private:
    static west* _instance;
    const position_t pos = {0,-1};

};
