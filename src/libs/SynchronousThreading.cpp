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

void** thread1Status = NULL;
void** thread2Status = NULL;
/**
* Run method for thread1
* @param void* arg the thread passed argument
*/
void *run1(void* arg) {
      cout << "Thread 1" << endl;
      //sleep 500 m secs
      sleep(5);
      //check for the termination & save the status in a void pointer 
      if(pthread_tryjoin_np(pthread_self(), thread1Status) > 0){
            cout <<  pthread_self() << " (Thread 1) has been detached & terminated" << endl;
            //detach the thread -- & release memory
            pthread_detach(pthread_self());
            pthread_exit(NULL); 
      }
  return NULL;
}
/**
* Run method for thread2
* @param void* arg the thread passed argument
*/
void *run2(void* arg) {
      cout << "Thread 2" << endl;
      //sleep 500 m secs
      sleep(5);
      //check for the termination & save the status in a void pointer 
      if(pthread_tryjoin_np(pthread_self(), thread2Status) > 0){
            cout <<  pthread_self() << " (Thread 2) has been detached & terminated" << endl;
            //detach the thread -- & release memory
            pthread_detach(pthread_self());
            pthread_exit(NULL); 
      }
  return NULL;
}

