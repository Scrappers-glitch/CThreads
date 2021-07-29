/**
* C/C++ POSIX Unix Threads.
* 2021-2022
* @author pavl_g.
*/
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <SynchronousThreading.h>
#include <AsynchronousThreading.h>
#include <SyncMutex.h>
using namespace std;

//ahead compilation
/**
* Runs an example for 2 Synchronous threads running in series 
* using join() or wait().
*/
extern void runSynchronousExample();

/**
* Runs an example for 2 Synchronous threads running in series 
* using mutex object based events.
*/
extern void runMutexEventsExample();

/**
* Runs an example for 2 Asynchronous threads running in parallel.
*/
extern void runAsyncThreadsExample();

void* mainThreadStatus = NULL;

void runSynchronousExample(){
       //sleep 5 secs
       sleep(5);
       int id1 = '1';
       //create thread 1
       pthread_t* thread1 = new pthread_t();
       //start thread 1
       int state1 = pthread_create(thread1, nullptr, run1, &id1); 
       void** status1 = NULL;
       //make the calling thread(main thread) wait until the execution of the identified thread(thread1) is over
       pthread_join(*thread1, status1);
       int id2 = '2';
       //create thread 2
       pthread_t* thread2 = new pthread_t();
       //start thread 2
       int state2 = pthread_create(thread2, NULL, run2, &id2); 
       void** status2 = NULL;
       //make the calling thread(main thread) wait until the execution of the identified thread(thread2) is over
       pthread_join(*thread2, status2);  
   return;
}

void runMutexEventsExample(){
       int id1 = 'm';
       pthread_t* mutexThread1= new pthread_t();
       //start thread 1
       pthread_create(mutexThread1, NULL, mutexEvent1, &id1); 
        
       int id2 = 'M';
       pthread_t* mutexThread2= new pthread_t();
       //start thread 2
       pthread_create(mutexThread2, NULL, mutexEvent2, &id2); 
   return;
}

void runAsyncThreadsExample(){
       int id1 = 'a';
       pthread_t* asyncThread1= new pthread_t();
       //start async 1
       pthread_create(asyncThread1, NULL, async1, &id1); 
        
       int id2 = 'A';
       pthread_t* asyncThread2= new pthread_t();
       //start thread 2
       pthread_create(asyncThread2, NULL, async2, &id2); 
   return;
}

/**
* Run main Thread
* @return the status of the run
*/
int main () {
      //the main thread is task0
      cout << "Main Thread joined" << endl;
      //run the examples
      runAsyncThreadsExample(); 
      runSynchronousExample();
      runMutexEventsExample();
      pthread_exit(NULL);
    return 0;
}
