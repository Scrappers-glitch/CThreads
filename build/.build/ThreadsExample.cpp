#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;
/**
* Ahead Compilation of codebase(header like)
*/
extern "C" void *run1(void *);
extern "C" void *run2(void *);
extern "C" void *run3(void *);
/**
* Run method for thread1
* @param void* arg the thread passed argument
*/
void *run1(void* arg) {
      cout << "Thread 1\n" << endl;
      //sleep 10 secs
      sleep(10);
      pthread_exit(NULL); 
  return NULL;
}
/**
* Run method for thread2
* @param void* arg the thread passed argument
*/
void *run2(void* arg) {
      cout << "Thread 2\n" << endl;
      //sleep 10 secs
      sleep(10);
      pthread_exit(NULL); 
  return NULL;
}
/**
* Run main Thread
* @return the status of the run
*/
int main () {
   //the main thread is task0
   cout << "Thread 0\n" << endl;
   //sleep 10 secs
   sleep(10);
   int id1 = '1';
   //create thread 1
   pthread_t* thread1 = new pthread_t();
   //start thread 1
   int state1 = pthread_create(thread1, nullptr, run1, &id1); 
   void** status1 = NULL;
   //make the thread wait until the execution of the previous one
   pthread_join(*thread1, status1);
   int id2 = '2';
   //create thread 2
   pthread_t* thread2 = new pthread_t();
   //start thread 2
   int state2 = pthread_create(thread2, NULL, run2, &id2); 
   void** status2 = NULL;
   //make the thread wait until the execution of the previous one
   pthread_join(*thread2, status2);   
   //exit the main thread to register others into the Processors Registers
   pthread_exit(NULL);
 return 0;
}
