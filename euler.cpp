#include "euler.h"

euler::euler()
{

    void Euler(double* position, double* velocity, double* force, int mass, int n);

        for(int i=0; i < m; i++) {

            position[i] += velocity[i]*h;
            velocity[i] += 0.5*force[i]/mass*h*h;


}

