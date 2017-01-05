#include <stdio.h>
#include <signal.h>
// 定义signal_handler类型为 返回值为void 参数类型为int 的函数指针
typedef void(* signal_handler)(int);

void signal_handler_fun( int signal_num ) {
  printf("catch signal %d\n",  signal_num);
}
int main(int argc, char const *argv[]) {
  // signal(SIGINT, SIG_IGN);
  // 将p_signal 的指向处理函数 signal_handler_fun()
  signal_handler p_signal = signal_handler_fun;
  signal(SIGINT, p_signal);
  for(;;);
  return 0;
}

// 信号的处理程序是一个指向  返回值为viod  参数类型为int函数的 指针
// signal(参数a, 参数b)；
// 参数a 表示的是我们需要进行处理的信号
// 参数b表示的时用户自定义的对于信号的处理程序  是一个指针
// 返回的是这个信号的以前的处理程序的指针
