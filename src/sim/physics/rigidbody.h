#ifndef RIGIDBODY_H
#define RIGIDBODY_H


class RigidBody 
{
private:
    double length;
    double time;
    double dt;
    long int iterations;

public:
    RigidBody (double length, double time, double dt, long int iterations) { }; // basic declaration

    void calcTM(); // calculates thrust and mass
    void applyTorque();
    void applyForce();
    void update(double dt);

    /* calculates
    update:
        ang vel
        ori
        euler
        global acc
        vel
        pos
        RESET (acc, ang vel)
    */

};


#endif