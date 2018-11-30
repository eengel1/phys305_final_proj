/*  Ethan Engel, Michael Klein
mass_calc.c
This program will calculate the radius of a white dwarf star and compare the radius to the mass of a dwarf star
To compile use gcc radius_calc.c -o radius_calc -lm
To run use ./radius_calc
*/

// System headers
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi M_PI
#define G 6.67e-8                                  // universal gravitational constant in CGS units
#define gamma 5/3                                  // the calculated gamma from the degrees of freedom (using n = 1.5)
#define K 3.15e12                                  // the calculated K for the non-relativistic case

float rhs_1(float r, float rho)
{
    return 4*pi*pow(r, 2)*rho;                     // hydrostatic balance equation for M
}

float rhs_2(float r, float M, float rho)
{
    return -(G*M*rho)/pow(r, 2);                   // hydrostatic balance equation for pressure
}

float pcalc(float rho)
{
    return K*pow(rho, gamma);                      // analytical pressure relation
}

float Rcalc(float m)
{
    return pow((9.0*pow(K, 3.0))/(2.0*pow(pi, 2.0)*pow(G, 3.0)*m), 0.333333); // relation between mass and radius of a white dwarf star
}

int main()
{
    float mass;
    float radius;

    for (mass = 2.00e32; mass < 2.88e33; mass += 0.01e32)                     // lower limit 0.2 solar masses, upper limit Chandrasekhar limit (1.44 solar masses)
    {
        radius = Rcalc(mass);
        printf("%e %e\n", mass, radius);
    }
    return 0;
}
