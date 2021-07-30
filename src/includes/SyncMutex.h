/**
* Mutual Exclusive events using POSIX threads Mutex pointers.
* @Note synchronized(statefulObject) in java & deadlocks(threads locking on an object).   
* @author pavl_g.
*/
#ifndef _SYNC_MUTEX
#define _SYNC_MUTEX     

/*ahead compilation*/
extern "C" void* mutexEvent1(void*);
extern "C" void* mutexEvent2(void*);
extern "C" void* mutexEvent3(void*);


#endif 
