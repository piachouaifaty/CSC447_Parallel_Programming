#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//array size
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


int64_t millis()
{
    struct timespec now;
    timespec_get(&now, TIME_UTC);
    return ((int64_t) now.tv_sec) * 1000 + ((int64_t) now.tv_nsec) / 1000000;
}

int main()
    {
        //calculating time taken
        int64_t start = millis();
        double sum = calculate_pi();
        int64_t end = millis();

        printf("Reference PI = %.10lf Computed PI = %.10lf\n", M_PI, sum);
        printf("Difference to Reference is %.10lf\n", M_PI - sum);

//getting time elapsed in ms

        double time_elapsed = (end - start);
        printf("Time: %f ms\n", time_elapsed);

    }


