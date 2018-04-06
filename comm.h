#pragma once
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>


#define PATHNAME "."
#define PROJ_ID 0x6666

int CreatShm(int size);
int DestroyShm(int shmid);
int Getshm(int size);


