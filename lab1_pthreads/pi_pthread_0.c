#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

//array size
#define STEPS 100000000
#define STEP_SIZE 1.0/STEPS
#define THREADS 3

struct pthread_args
{
	double lower;
	double upper;
	double local_sum;
};

void * pi_thread(void *ptr)
{
	double low = 0.5 * STEP_SIZE + ((struct pthread_args*)ptr)->lower;
	double upp = ((struct pthread_args*)ptr)->upper;
	double tsum = 0;

	while(low < upp)
	{
		tsum += sqrt(1-low*low) * STEP_SIZE;
		low += STEP_SIZE;
	}
	((struct pthread_args*)ptr)->local_sum = tsum;

	return NULL;
}

int64_t millis()
{
    struct timespec now;
    timespec_get(&now, TIME_UTC);
    return ((int64_t) now.tv_sec) * 1000 + ((int64_t) now.tv_nsec) / 1000000;
}

void main()
{
	long num_threads = 2;
    double sum = 0;
	pthread_t *thread;
    struct pthread_args *thread_arg;

	thread = malloc((unsigned long)num_threads * sizeof(*thread));
	thread_arg = malloc((unsigned long)num_threads * sizeof(*thread_arg));

    //calculating time taken
        int64_t start = millis();

	for (int i = 0; i < num_threads; i++)
	{
		thread_arg[i].lower = (i+0) * (1.0 / (double)num_threads);
		thread_arg[i].upper = (i+1) * (1.0 / (double)num_threads);
		pthread_create(thread + i, NULL, &pi_thread, thread_arg + i);
	}

	for (int i = 0; i < num_threads; i++)
	{
		pthread_join(thread[i], NULL );
		sum += 4 * thread_arg[i].local_sum;
	}

        int64_t end = millis();

	printf("Reference PI = %.10lf Computed PI = %.10lf\n", M_PI, sum);
	printf("Difference to Reference is %.10lf\n", M_PI - sum);

	double time_elapsed = (end - start);
    printf("Time: %f ms\n ", time_elapsed);
}
