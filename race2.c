#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>

#define LOCK_ENABLED 1

// create a mutex - part 2 only

// shared variable here

void 
inc( void ) {
  	// increment the shared variable
}

void 
dec( void ) {
  	// decrement the variable
}

void
lock(void)
{
		// your code here
}

void
unlock(void)
{
		// your code here
}

void *
thread_fn(void *arg)
{
		while (1) {
				lock();
				inc();
				dec();
				assert(var == 0);
				unlock();
		}

		return NULL;
}

int
main(void)
{
		pthread_t thread1, thread2;

		// initialize the lock - part 2 only

		// Create the threads

		// wait for the threads to join

		// clean up the mutex - part 2 only
}






















