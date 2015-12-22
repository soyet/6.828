#include <stdio.h>

#define BUFSIZE 128
char buf[BUFSIZE];
int fds[2];

int main(void) {
  int n;

  pipe(fds);
  write(fds[1], "hello", 5);
  n = read(fds[0], buf, sizeof(buf));
  printf("read: %s\n", buf);
  
}
