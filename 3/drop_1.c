#include <stdio.h>
#include <unistd.h>
int main() {
  int p1, p2;
  // 创建子进程1
  while ((p1 = fork()) == -1);
  if (p1 == 0) {
    putchar('b');
  } else {
    // 创建子进程2
    while ((p2 = fork()) == -1);
    if (p2 == 0) {
      putchar('c');
    } else {
      putchar('a');
    }
  }
  return 0;
}
