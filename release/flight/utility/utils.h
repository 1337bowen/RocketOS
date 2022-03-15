#ifndef UTILS_H
#define UTILS_H

#include <iostream> // command line logging
#include <stdint.h> // specific types and macros
#include <stdio.h>
#include <chrono> // time



enum FlightState 
{
    PAD_TEST = 0,
    PAD_READY = 1,
    ACTIVE_ASCENT = 2,
    PASSIVE_ASCENT = 3,
    PASSIVE_DESCENT = 4,
    CHUTE_DESCENT = 5,
    LANDED = 6
};

class Simulation
{
private:
    double length;
    double time;
    double dt;
    long int iterations;

public:
    

};

#endif