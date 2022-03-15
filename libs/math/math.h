#ifndef MATH_H
#define MATH_H

#include <cmath>
#include <random>

double PI = 3.14159265358979;

double max(double x, double y);

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


#endif