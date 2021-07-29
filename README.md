# CThreads

## Let's dive into CThreads Interface aka `POSIX Threads` which isn't shipped natively with C, it's based on Unix :
https://www.ibm.com/docs/en/zos/2.4.0?topic=files-pthreadh-thread-interfaces

### Resources for POSIX Threads of Unix :
https://www.ibm.com/docs/en/i/7.1?topic=ssw_ibm_i_71/apis/concept8.htm
<br/>
https://www.geeksforgeeks.org/thread-functions-in-c-c/

### Mutex -- Mutually Exclusive -- Synchronized -- Object :
https://www.ibm.com/docs/en/zos/2.3.0?topic=functions-pthread-mutex-init-initialize-mutex-object

### struct timespec --used by the Mutex System of `pthread.h` in C method :
```c
#include <bits/types/struct_timespec.h>
/* Wait until lock becomes available, or specified time passes. */
extern int pthread_mutex_timedlock (pthread_mutex_t *__restrict __mutex,
				    const struct timespec *__restrict__abstime);
``` 
				    
https://en.cppreference.com/w/c/chrono/timespec


# To Build, use shell command/terminal : 

```bash
┌─[twisted@parrot]─[~/GradleProjects/CThreads/build]
└──╼ $./compile.sh 
Compiling the project
Successfully Compiled
```
# To run :

```bash
┌─[twisted@parrot]─[~/GradleProjects/CThreads/output]
└──╼ $./ThreadsTest.exec
Main Thread joined
Async 2 joined
139843706689280 Aysnc 2 Terminated
Thread 1
Async 1 joined
139843715081984 Aysnc 1 Terminated
139843698296576 (Thread 1) has been detached & terminated
Thread 2
139843698296576 (Thread 2) has been detached & terminated
mutex_initialized & property settled to NORMAL single lock mutually events
mutex object obtained by Event 1 -- Event 1 execution starts
mutex_locked to this Event 1, concurrent threads will wait until unlock occurs
mutex object obtained by Event 2 -- Event 2 execution starts
mutex_locked to this Event 2, concurrent threads will wait until unlock occurs
```

### Tips : You can open the code on vscode, use c++ code completion, syntax highlighting.

