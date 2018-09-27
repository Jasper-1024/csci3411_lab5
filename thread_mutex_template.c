#include <pthread.h>
#include <unistd.h>
#include <stdio.h>


pthread_mutex_t lock;
volatile int shared_data = 0;

void *
thread_fn(void *arg)
{
		int i;

		for (int i = 0; i < 1024; ++i) {
			// acdess shared data
			pthread_mutex_lock(&lock);
			shared_data++;
			pthread_mutex_unlock(&lock);
		}

		return NULL;
}

int
main(void)
{
		pthread_t thread_id;
		void *exit_status;
		int i;

		// initialize the lock before using it
		pthread_mutex_init(&lock, NULL);

		// create the thread
		pthread_create(&thread_id, NULL, thread_fn, NULL);

		// access the shared data and read from it
		for (int i = 0; i < 10; ++i) {
			sleep(1);
			pthread_mutex_lock(&lock);
			printf("%d\n", shared_data);
			pthread_mutex_unlock(&lock);
		}

		// wait for the thread to return
		pthread_join(thread_id, &exit_status);

		// clean up the mutex
		pthread_mutex_destroy(&lock);

		return 0;
}