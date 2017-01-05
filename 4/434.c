#include <stdio.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdlib.h>
#define MSGKEY 75
struct msgform
{
        long mtype;
        char mtext[1030];
} msg;
int msgqid,i;
void client()
{
        int i;
        // 创建或者读取一个消息队列
        msgqid=msgget(MSGKEY,0777);
        // 向队列中添加十条消息
        for(i=10; i>=0; i--)
        {
                msg.mtype=i;
                printf("(client)sent\n");
                msgsnd(msgqid,&msg,1024,0);
        }
        exit(0);
}
void server()
{
        msgqid=msgget(MSGKEY,0777|IPC_CREAT);
        do
        {
                msgrcv(msgqid,&msg,1030,0,0);
                printf("(server)receive\n");
        } while(msg.mtype!=1);
        msgctl(msgqid,IPC_RMID,0);
        exit(0);
}
void main()
{
        if(fork()) server();
        else client();
        wait(0);
        wait(0);
}
