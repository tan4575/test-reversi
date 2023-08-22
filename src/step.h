#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <cmath>
using namespace std;

typedef struct _position
{
    int x = 0;
    int y = 0;
}position_t;

class step {
public:
    /**
     * @brief Construct a new step object
     * 
     */
    step() {};

    /**
     * @brief Destroy the step object
     * 
     */
    virtual ~step() {};


    virtual void pre() = 0;
    virtual void execute() = 0;
    virtual void post() = 0;

    /**
     * @brief Get the Position object
     * 
     * @return position_t 
     */
    virtual position_t getPosition() const = 0;

};
