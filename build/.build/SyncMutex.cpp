/**
* C/C++ POSIX Unix Threads -- Mutex Examples.
* 2021-2022
* @author pavl_g.
*/
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <SyncMutex.h>
using namespace std;

/*redefine a mutex object pointer*/
struct POSIXMutex{
    typedef pthread_mutex_t ThreadObject;
    typedef pthread_mutexattr_t ObjectProperty;
};

POSIXMutex::ThreadObject object;
POSIXMutex::ObjectProperty objProperty;

/**
* Initializes the mutex POSIX shared object, this object controls 
* threads behaviors along the threads life cyle, locking a mutex object in a thread
* blocks out other threads defined by pthread_mutex_timedlock(&object, time),
* until this object is released from lockage then feeded into the timedlock in the new thread
* if the object get unlocked then #pthread_mutex_timedlock() would return 0 
* & the synchronus action would execute.
*/
void* initializePOSIXMutex(){
        if(pthread_mutex_init(&object, &objProperty) < 0) {                                    
          perror("mutex_initialize_stopped with errno EINVAL\n");                                                       
          exit(1);                                                                    
        }else{
          pthread_mutexattr_settype(&objProperty, PTHREAD_MUTEX_DEFAULT);
          printf("mutex_initialized & property settled to NORMAL single lock mutually events\n");
        }
    return NULL;
}
/**
* First mutex based thread event.
* @param void* a pointer of void type.
* @return a pointer of void type describing the thread status.
*/
void* mutexEvent1(void*){
        initializePOSIXMutex();
        if(pthread_mutex_lock(&object) < 0){
             perror("mutex lock failed with EAGAIN");                                                       
             exit(1);
        }else{
             printf("mutex object obtained by Event 1 -- Event 1 execution starts\n");
             printf("mutex_locked to this Event 1, concurrent threads will wait until unlock occurs\n");
             sleep(8);    
             //unlock the mutex Object for the other threads
             pthread_mutex_unlock(&object);
             pthread_exit(NULL);
        }
    return NULL;
}
/**
* Function execution, delegated by the sync based mutex event 2.
* @params msg the message.
* @return function id.
*/
int executeSyncJob(string msg){
         int id = 222;
         //synchronization of tasks goes here
         cout <<  msg << endl;
         printf("mutex_locked to this Event 2, concurrent threads will wait until unlock occurs\n");
     return id;
}

/**
* Second mutex based thread event, runs in series with the first one.
* @param void* a pointer of void type.
* @return a pointer of void type describing the thread status.
*/
void* mutexEvent2(void*){
        //counter to call the mutex event if & only if the event object is released to this thread
        timespec* time = new timespec();
        time->tv_sec = 0;
        if(pthread_mutex_timedlock(&object, time) < 0){
            return NULL;
        }else{
            //lock the mutexObject to this thread(obtain the object to this event)
            //=> once obtained the synchronized work(exclusive actions execute
            if(pthread_mutex_lock(&object) < 0){
                 perror("mutex lock failed with EAGAIN");                                                       
                 exit(1);
            }else{
                 executeSyncJob("mutex object obtained by Event 2 -- Event 2 execution starts");
            }
             //unlock the mutex Object for the other threads
             pthread_mutex_unlock(&object);               
             pthread_mutex_destroy(&object);
             pthread_exit(NULL);
        }
    return NULL;
}


