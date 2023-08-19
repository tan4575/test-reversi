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
    position_t getPosition() const { return pos; };

private:
    static east* _instance;
    const position_t pos = {0,1};
};
