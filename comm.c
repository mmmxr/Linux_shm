#include "comm.h"


int commshm(int size,int flgs)
{
    key_t key=ftok(PATHNAME,PROJ_ID);
    if(key<0)
    {
        perror("ftok");
        return -1;
    }
    int shmid=shmget(key,size,flgs);
    if(shmid<0)
    {
        perror("shmget");
        return -2;
    }
    return shmid;
}


int DestroyShm(int shmid)
{
    if(shmctl(shmid,IPC_RMID,NULL)<0)
    {
        perror("shmctl");
        return -1;
    }
    return 0;
}

int CreatShm(int size)
{
    return commshm(size,IPC_CREAT|IPC_EXCL|0644);
}
int Getshm(int size)
{
    return commshm(size,IPC_CREAT);
}
