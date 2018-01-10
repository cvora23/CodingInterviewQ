/*
 * ForkVsExec.cpp
 *
 *  Created on: Jan 2, 2018
 *      Author: chivora
 */

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

/*
 *Difference between fork() and exec()
2
Every application(program) comes into execution through means of process, process is a running instance of a program.
Processes are created through different system calls, most popular are fork() and exec()

fork()

pid_t pid = fork();
fork() creates a new process by duplicating the calling process, The new process, referred to as child,
is an exact duplicate of the calling process, referred to as parent, except for the following :

The child has its own unique process ID, and this PID does not match the ID of any existing process group.
The child’s parent process ID is the same as the parent’s process ID.
The child does not inherit its parent’s memory locks and semaphore adjustments.
The child does not inherit outstanding asynchronous I/O operations from its parent nor does it inherit any asynchronous I/O contexts from its parent.
Return value of fork()
On success, the PID of the child process is returned in the parent, and 0 is returned in the child. On failure, -1
is returned in the parent, no child process is created, and errno is set appropriately.
Detailed article on fork system call

exec()

The exec() family of functions replaces the current process image with a new process image. It loads the program into
the current process space and runs it from the entry point.

The exec() family consists of following functions, I have implemented execv() in following C program, you can try rest as an exercise

int execl(const char *path, const char *arg, ...);
int execlp(const char *file, const char *arg, ...);
int execle(const char *path, const char *arg, ...,
                               char * const envp[]);
int execv(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);
int execvpe(const char *file, char *const argv[],
                              char *const envp[]);
fork vs exec

fork starts a new process which is a copy of the one that calls it, while exec replaces the current process image with another (different) one.
Both parent and child processes are executed simultaneously in case of fork() while Control never returns
to the original program unless there is an exec() error.
// C program to illustrate  use of fork() &
// exec() system call for process creation

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main(){
   pid_t  pid;
   int ret = 1;
   int status;
   pid = fork();
   if (pid == -1){

      // pid == -1 means error occured
      printf("can't fork, error occured\n");
      exit(EXIT_FAILURE);
   }
   else if (pid == 0){

      // pid == 0 means child process created
      // getpid() returns process id of calling process
      printf("child process, pid = %u\n",getpid());

      // the argv list first argument should point to
      // filename associated with file being executed
      // the array pointer must be terminated by NULL
      // pointer
      char * argv_list[] = {"ls","-lart","/home",NULL};

      // the execv() only return if error occured.
      // The return value is -1
      execv("ls",argv_list);
      exit(0);
   }
   else{
      // a positive number is returned for the pid of
      // parent process
      // getppid() returns process id of parent of
      // calling process
      printf("parent process, pid = %u\n",getppid());

        // the parent process calls waitpid() on the child
        // waitpid() system call suspends execution of
        // calling process until a child specified by pid
        // argument has changed state
        // see wait() man page for all the flags or options
        // used here
        if (waitpid(pid, &status, 0) > 0) {

            if (WIFEXITED(status) && !WEXITSTATUS(status))
              printf("program execution successfull\n");

            else if (WIFEXITED(status) && WEXITSTATUS(status)) {
                if (WEXITSTATUS(status) == 127) {

                    // execv failed
                    printf("execv failed\n");
                }
                else
                    printf("program terminated normally,"
                       " but returned a non-zero status\n");
            }
            else
               printf("program didn't terminate normally\n");
        }
        else {
           // waitpid() failed
           printf("waitpid() failed\n");
        }
      exit(0);
   }
   return 0;
}
Run on IDE
Output:

parent process, pid = 11523
child process, pid = 14188
Program execution successfull
 *
 */


int main(){


	return 0;

}
