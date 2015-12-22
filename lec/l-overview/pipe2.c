#include <stdio.h>

#define BUFSIZE 128
char buf[BUFSIZE];
int fds[2];

int main(void) {
  int n;
  pipe(fds);
  int pid = fork();
  if (pid > 0) {
    n = read(0, buf, BUFSIZE);
    write(fds[1], buf, n);
  } else {
    n = read(fds[0], buf, sizeof(buf));
    printf("read: %s\n", buf);
  }
}
