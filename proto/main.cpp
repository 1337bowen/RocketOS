#include <iostream>
#include <random>
#include <stdint.h>
#include <stdio.h>
#include <chrono>

// Random Math
// Returns random double in half-open range [low, high).
class UniformRandomDouble
{
    std::random_device _rd{};
    std::mt19937 _gen{_rd()};
    std::uniform_real_distribution<double> _dist;

    public:

        UniformRandomDouble() {
            set(1.0, 10.0);
        }
        
        UniformRandomDouble(double low, double high) {
            set(low, high);
        }

        // Update the distribution parameters for half-open range [low, high).
        void set(double low, double high) {
            std::uniform_real_distribution<double>::param_type param(low, high);
            _dist.param(param);
        }

        double get() {
            return _dist(_gen);
        }
};

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

// Simulation
class Simulation
{
private:
    double length;
    double time;
    double dt;
    long int iterations;

public:
    

};

class IMU
{
private:
    EulerAngles rates;

    double noise;

    long sampTime;

    UniformRandomDouble rand { 0, 1 };

public:
    double setNoise(double _noise) { noise = _noise; }
    long setSampTime(long _sampTime) { sampTime = _sampTime; }

    double x() { return rates.x; }
    double y() { return rates.y; }
    double z() { return rates.z; }

    void update() 
    { 
        
    };
    
};

int main()
{
    FlightState vehicleState;

    while (1)
    {

        

    }

    return 0;
}
