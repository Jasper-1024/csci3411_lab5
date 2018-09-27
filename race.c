#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_ITS 1000
#define FILENAME "out"

FILE * fp;

int ready1 = 0;
int ready2 = 0;

static void *
thread1_fn(void *arg)
{
  int i = 0;
  ready1 = 1;
  while(!ready2) usleep(1);

  while(1) {

    fprintf( fp, "hello\n" );
    fprintf( fp, "world\n" );

    if( i++ > MAX_ITS ) break;
  }

  return NULL;
}

static void *
thread2_fn(void *arg)
{
  int i = 0;
  ready2 = 1;
  while(!ready1) usleep(1);

  while(1) {

    fprintf( fp, "foo\n" );
    fprintf( fp, "bar\n" );

    if( i++ > MAX_ITS ) break;
 }

  return NULL;
}

int
main(int argc, char *argv[])
{
    pthread_t thread1, thread2;
    fp = fopen( FILENAME, "w" );

    if( pthread_create( &thread1, NULL, &thread1_fn, NULL ) != 0 ) {
      //error
    }
    if( pthread_create( &thread2, NULL, &thread2_fn, NULL ) != 0 ) {
      //error
    }

    if( pthread_join(thread1, NULL) != 0 ) {
      //error
    }
    if( pthread_join(thread2, NULL) != 0 ) {
      //error
    }

    fclose( fp );

    return 0;
}

