#include <iostream>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include "planet.h"

using namespace std;

//We wish to simulate the solar system, using Runge-Kutta 4.
//Applying Newton's second law of motion, we get a set of differential equations.
//These we rewrite into two separate first order


int main(int argc, char* argv[]) {

    //Takes in a vector A, containing position and velocity of each planet
    //r which is the distance between each planet, and M, the masses.

    /*fstream inFile;
    inFile.open("distance_from_sun_1.dat", ios::out);
    inFile.close();*/


    int n = atoi(argv[1]);          //Number of planets
    double t_max = atof(argv[2]);   //Number of years
    int k = atoi(argv[3]);          //Case
    int N = 10000;
    double dt;
    dt = t_max/N;
    //int m = 2*n;
    cout << dt << endl;
    double pi;
    pi = atan(1)*4;
    double t_0 = 0;
    double h = (t_max - t_0)/N;
    double position = new double[2*n];
    double velocity = new double[2*n];
    double mass = new double[n];
    double force = new double[2*n];
    Planet Earth = Planet(1.0, 0.0, 0.0, 2*pi, 3.0e-6);
    Planet Sun = Planet(0.0, 0.0, 0.0, 0.0, 1.0);  // Jupiter: -0.0026585, All: -0.003332
    Planet Moon = Planet(0.995, 0.0, 0.0, 2.1*pi, 3.69e-8);
    Planet Venus = Planet(0.727, 0.0, 0.0, 7.385, 2.45e-6);
    Planet Mercury = Planet(0.3548, 0.0, 0.0, 10.107, 1.66e-7);
    Planet Mars = Planet(1.642, 0.0, 0.0, 5.085, 3.23e-7);
    Planet Jupiter = Planet(5.168, 0.0, 0.0, 2.764, 9.55e-4); // 10: 9.55e-3, 1000: 9.55e-1
    Planet Saturn = Planet(9.883, 0.0, 0.0, 2.047, 2.86e-4);
    Planet Uranus = Planet(20.06, 0.0, 0.0, 1.435, 4.36e-5);
    Planet Neptune = Planet(30.04, 0.0, 0.0, 1.139, 5.17e-5);
    Planet Pluto = Planet(52.36, 0.0, 0.0, 0.992, 6.61e-9);
    Planet B[n];

    switch(k) {

    case 1:
        B[0] = Earth;
        B[1] = Sun;
        break;

    case 2:
        B[0] = Earth;
        B[1] = Sun;
        B[2] = Moon;
        break;

    case 3:
        B[0] = Earth;
        B[1] = Sun;
        B[2] = Venus;
        B[3] = Mercury;
        B[4] = Mars;
        B[5] = Jupiter;
        B[6] = Saturn;
        B[7] = Uranus;
        B[8] = Neptune;
        B[9] = Pluto;
        break;

    case 4:
        B[0] = Earth;
        B[1] = Sun;
        B[2] = Jupiter;
        break;

    }

    // Initial conditions
    for (int i=0; i < n; i++){

        position[2*i] = B[i].x0;     // xi
        position[2*i+1] = B[i].y0;   // yi
        velocity[2*i] = B[i].vx0;    // vxi
        velocity[2*i+1] = B[i].vy0;  // vyi
        force[2*i] = 0;              // Fx
        force[2*i+1] = 0;            // Fy
        mass[i] = B[i].M;
        //cout << M[i] << endl;
    }


    double new_position = new double[2*n];
    double new_velocity = new double[2*n];


    fstream newFile;
    newFile.open("data.dat", ios::out);
    //newFile << n << endl;
    //newFile << t_max << endl;
    //newFile << k << endl;

    for (int t=0; t < N; t++) {

        for(int i=0; i < n; i++){
            newFile << position[2*i] << " " << position[2*i+1] << " ";

        }
        newFile << endl;


        f(position, new_position, velocity, new_velocity, mass, force, n);


        for(int i=0; i < m; i++){

                Euler(new_position, new_velocity, force, mass);



        }
    }


    newFile.close();
    return 0;

}





