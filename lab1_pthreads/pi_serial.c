#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STEPS 1000000000
#define STEP_SIZE 1.0/STEPS

double calculate_pi()
{
    double lower = 0.5 * STEP_SIZE; 
    double higher = 1; //1/N, 2/N... N/N--->1
    double sum = 0;

    //while fraction is less than 1 
    while(lower < higher)
    {
        sum = sum + (STEP_SIZE * sqrt(1 - lower*lower));
        lower = lower + STEP_SIZE;
    }

    return sum*4;

}

int main()
{





}