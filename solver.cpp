#include <iostream>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include "planet.h"

using namespace std;

//We wish to simulate the solar system, using Euler and Verlet.
//Applying Newton's second law of motion, we get a set of differential equations.
//These we rewrite into two separate first order


void f(double* P, double* new_P, double* V, double* new_V, double* M, double* F, int n) {

    // Defining constants
    double pi;
    pi = atan(1)*4;
    double G = 4*pi*pi; // 6.67428e-11;
    double r, L;
    double x, y, L_x, L_y;

    for(int i=0; i < m; i++){

        new_P[i] = 0;         //


    //ofstream outFile;
    //outFile.open("distance_from_sun_1.dat", ios::app);

    for(int i=0; i < n; i++){

        new_P[2*i] = V[2*i];      // dxi/dt = vx_old
        new_P[2*i+1] = V[2*i+1];  // dyi/dt = vy_old


        for (int j=0; j < n; j++){
            if(j!=i){

                L_x = P[2*i];
                L_y = P[2*i+1];
                x = P[2*i] - P[2*j];
                y = P[2*i+1] - P[2*j+1];
                r = sqrt(x*x + y*y);
                L = sqrt(L_x*L_x + L_y*L_y);
                //outFile << L << endl;
                //cout << r << endl;
                new_V[2*i] += -(G*M[j]*(x)/(r*r*r));       // vx_new
                new_V[2*i+1] += -(G*M[j]*(y)/(r*r*r));     // vy_new
                F[i] = G*M[j]/(r*r);

                cout << M[j] << endl;
            }
        }
    }

    //outFile.close();

}

