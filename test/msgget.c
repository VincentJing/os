#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>
#define MYMSG_KEY 6666
int main(int argc ,char *argv[])
{
        int msgid;
        msgid=msgget(ftok(".",100),IPC_CREAT | 0644);
        //msgid=msg(MYMSG_KEY,IPC_CREAT | 0644);
        printf("msgid=%d\n",msgid);
        if(msgid==-1)
        {
                perror("msgget error :");
                exit(EXIT_FAILURE);
        }

        return 0;
}
