#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
 * Parent receives return code of PID of creted child process,
 * whereas child receives return code of 0 from fork() call. Note that
 * created child doesn't run from main - it runs as if it had called fork
 * itself
 */

int main(int argc, char *argv[]) {
  printf("hello world (pid:%d)\n", (int) getpid());
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {// child (new process)
    printf("hello, I am child (pid:%d)\n", (int) getpid());
  } else {
    printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
  }
  return 0;
}
