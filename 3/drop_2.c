#include <stdio.h>
#include <unistd.h>
int main() {
  int p1, p2;
  // 创建子进程1
  while ((p1 = fork()) == -1);
  if (p1 == 0) {
    for (int i = 0; i < 50; i++) {
      printf("son%d\n", i);
    }
  } else {
    // 创建子进程2
    while ((p2 = fork()) == -1);
    if (p2 == 0) {
      for (int i = 0; i < 50; i++) {
        printf("daughter%d\n", i);
      }
    } else {
      for (int i = 0; i < 50; i++) {
        printf("parent%d\n", i);
      }
    }
  }
  return 0;
}
