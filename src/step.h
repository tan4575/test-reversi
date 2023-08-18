#pragma once
#include <iostream>
using namespace std;

class step {
public:
    step() {};
    virtual ~step() {};

    virtual void pre() = 0;
    virtual void execute() = 0;
    virtual void post() = 0;
};
