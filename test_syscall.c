/*
 * Test the page cache knob syscall (#446)
 */
#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

/*
 * Put your syscall number here.
 */
#define SYS_pagecacheknob 446

int main(int argc, char **argv)
{
  long res = syscall(SYS_pagecacheknob, 1);
  printf("Page Cache should now be allocated to NUMA node 1\n");
  sleep(1);
  FILE *file = NULL;
  unsigned char buffer[1024];  // array of bytes, not pointers-to-bytes
  size_t bytesRead = 0;

  file = fopen("/var/cache/apt/pkgcache.bin", "rb");   

  if (file != NULL)    
  {
      // read up to sizeof(buffer) bytes
      while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0)
      {
          // do not need to do anything
      }
  }
  return res;
}
