#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
        int shmid;
        shmid = shmget(ftok(“.”,1234), getpagesize(), IPC_CREAT | IPC_EXCL | 0666);
        //getpagesize() return 4096.
        if(shmid == -1)
        {
                perror("shmget error:");
                exit(EXIT_FAILURE);
        }
        printf("shmid=%d\n",shmid); //在此我们打印创建的内存表识ID
        return 0;
}
