#include "verlet.h"

verlet::verlet()
{   

    void Verlet(double* position, double* velocity, double* force, int mass, int n);

        for(int i=0; i < m; i++) {

            position[i] += velocity[i]*h + 0.5*force[i]/mass*h*h;
            velocity[i] += 0.5*force[i]/mass*h + force[i]/mass;


}
