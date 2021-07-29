/**
* C/C++ POSIX Unix Threads.
* 2021-2022
* @author pavl_g.
*/
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <SynchronousThreading.h>
using namespace std;

void* mainThreadStatus = NULL;

void runSynchronousExample(){
       //sleep 500 m secs
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
/**
* Run main Thread
* @return the status of the run
*/
int main () {
       //the main thread is task0
       cout << "Thread 0" << endl;
       //run the synchronus example
       runSynchronousExample();
       //check for the termination & save the status in a void pointer 
       if(pthread_tryjoin_np(pthread_self(), &mainThreadStatus) > 0){
            cout <<  pthread_self() << " (main Thread) has been detached & terminated" << endl;
            //detach the thread -- & release memory
            pthread_detach(pthread_self());
            //exit the main thread to register others into the Processors Registers
            pthread_exit(NULL); 
       }
    return 0;
}
