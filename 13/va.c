#include <stdio.h>
#include <stdlib.h>

/*
 * Every address the programmer can see is a virtual address
 * Only the OS knows the true address in physical memory. These
 * Hex key's are reference to the process' virtual address space
 */

int main(int argc, char *argv[]) {
  printf("location of code: %p\n", (void *) main);
  printf("location of heap: %p\n", (void *) malloc(1));
  int x = 0;
  printf("location of stack: %p\n", (void *) &x);
  return x;
}
