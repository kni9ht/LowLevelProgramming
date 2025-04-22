#include "./lib/ipc.h"
#include <stdio.h>
#include <unistd.h>

void
job(int id)
{
    Wait();
    printf("[ Proc B ] ==> Working on task %d\n", id);
    sleep(5);
    Signal();
}

int 
main()
{
    for(int i=5;i>0;i--)
    {
        job(i);
    }
    return 0;
}