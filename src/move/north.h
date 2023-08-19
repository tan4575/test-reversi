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
    position_t getPosition() const { return pos; };

private:
    static north* _instance;
    const position_t pos = {-1,0};

};
