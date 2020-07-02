#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/*
 * exec() lets you run a different program in your process. 
 * Here, the word count program is run in our current process which a
 * wrapper for it.
 * exec() loads the code and static data from the 'wc' executable and
 * overwrites the current code segment, and static data with it. It doesn't
 * create a new process, it transforms the currently running program.
 */
int main() {
  printf("hello world (pid:%d)\n", (int) getpid());
  int rc = fork();
  if (rc < 0) {
    exit(1);
  } else if (rc == 0) {
    printf("hello, I am child (pid: %d)\n", (int) getpid());
    char* myargs[3];
    myargs[0] = strdup("wc"); //program:  word count
    myargs[1] = strdup ("p3.c"); // argument: file to count
    myargs[2] = NULL; // end of array sentinel
    execvp(myargs[0], myargs); // runs word count
    printf("this shouldn't print out");
  } else {
    int rc_wait = wait(NULL);
    printf("hello, I am the parent of %d (rc_wait:%d) (pid:%d)\n",
          rc, rc_wait, (int) getpid());
  }
  return 0;
}
