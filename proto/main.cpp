#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <chrono>

#include "libs/math/math.h"

// GNC Math
struct EulerAngles
{
    double x;
    double y;
    double z;
};

// Flight Specific
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

// Rocket Class
class dof6_body
{
private:
    EulerAngles rates;
    EulerAngles forces;
    EulerAngles torques;

public:
    dof6_body(EulerAngles _rates, EulerAngles _forces, EulerAngles _torques) { };

    void update(EulerAngles _rates, EulerAngles _forces, EulerAngles _torques)
    {
        rates.x = _rates.x;
        rates.y = _rates.y;
        rates.z = _rates.z;
    }

};

// Simulation
class Simulation
{
private:
    double length;
    double time;
    double dt;
    long int iterations;

public:
    Simulation(double _length, double _time, double _dt, long int _iterations) { };

    void calcTM(); // calculates thrust and mass
    void applyTorque();
    void applyForce();
    void update(double dt);

};

class IMU
{
private:
    EulerAngles rates;

    double noise;

    long sampTime;

    UniformRandomDouble rand { -1, 1 };

public:
    double setNoise(double _noise) { noise = _noise; }
    long setSampTime(long _sampTime) { sampTime = _sampTime; }

    double x() { return rates.x; }
    double y() { return rates.y; }
    double z() { return rates.z; }

    void update(double dr_x, double dr_y, double dr_z) // dr_x dynamics rates x
    { 
        rates.x = dr_x + noise;
        rates.y = dr_y + noise;
        rates.z = dr_z + noise;

        // should sampling be done in the loop? 
        // i.e. adding extra lag 
    };
    
};

// Declarations
EulerAngles rocket_rates;
EulerAngles rocket_ori; // might need to be changed to quats for easy ori

Simulation sim;

IMU imu;
FlightState state;

int main()
{
    while (1)
    {

        

    }

    return 0;
}
