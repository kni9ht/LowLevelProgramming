#include "./lib/ipc.h"
#include <stdio.h>
#include <unistd.h>

void
job(int id)
{
    Signal();
    Wait();
    printf("[ Proc A ] ==> Working on task %d\n",id);
    sleep(5);
}

int 
main()
{
    for(int i=1;i<=5;i++)
    {
        job(i);
    }
    return 0;
}