#include <stdio.h>
#include <unistd.h>
int main() {
  int p1, p2;
  // 创建子进程1
  while ((p1 = fork()) == -1);
  if (p1 == 0) {
    printf("i am the child process, my process id is %d\n",getpid());
  } else {
    // 创建子进程2
    while ((p2 = fork()) == -1);
    if (p2 == 0) {
      printf("i am the child process, my process id is %d\n",getpid());
    } else {
      printf("i am the parent process, my process id is %d\n",getpid());
    }
  }
  return 0;
}
