/**
* C/C++ POSIX Unix Threads.
* 2021-2022
* @author pavl_g.
*/
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <AsynchronousThreading.h>

using namespace std;

/**
* Run method for thread1
* @param void* arg the thread passed argument
*/
void* async1(void* arg) {
      //sleep 8 secs
      sleep(8);
      cout << "Async 1 joined" << endl;
      cout <<  pthread_self() << " Aysnc 1 Terminated" << endl;
      //detach the thread -- & release memory
      pthread_detach(pthread_self());
      pthread_exit(NULL); 
  return NULL;
}
/**
* Run method for thread2
* @param void* arg the thread passed argument
*/
void* async2(void* arg) {
      //sleep 5 secs
      sleep(5);
      cout << "Async 2 joined" << endl;
      cout <<  pthread_self() << " Aysnc 2 Terminated" << endl;
      //detach the thread -- & release memory
      pthread_detach(pthread_self());
      pthread_exit(NULL);       
  return NULL;
}

