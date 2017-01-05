#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define SHMKEY 75
int shmid,i;
int *addr;
void client()
{
        int i;
        shmid=shmget(SHMKEY,getpagesize(),0777); /*获取共享区，长度为 getpagesize()*/
        addr=shmat(shmid,0,0); /*共享区起始地址为 addr */
        for(i=9; i >=0; i--)
        {
                while (*addr!=-1) ;
                printf("(client)sent\n"); /*打印(client)sent */
                *addr=i;
        }
        exit(0);
}
void server()
{
        shmid=shmget(SHMKEY,getpagesize(),0777 | IPC_CREAT); /*创建共享区*/
        addr=shmat(shmid,0,0); /*共享区起始地址为 addr */
        do {
                *addr=-1;
                while (*addr==-1) ;
                printf("(server)received\n"); /*服务进程使用共享区 */
        } while (*addr);
        shmctl(shmid,IPC_RMID,0);
        exit(0);
}
int main()
{
        while ((i=fork())==-1) ;
        if (!i) server();
        while ((i=fork())==-1) ;
        if (!i) client();
        wait(0);
        wait(0);
        return 0;
}
