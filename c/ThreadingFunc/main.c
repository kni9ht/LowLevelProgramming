#include<stdio.h>

typedef struct Args
{
    int a;
    float b;
    char c;
} ARGS, *PARGS;

void 
threadFunc(void (*f)(void*), void* args)
{
    f(args);
}

void
workerFunction(void* args)
{
    printf("1_arg = %d 2_arg = %.2f 3_arg = '%c'", ((PARGS)args)->a, ((PARGS)args)->b, ((PARGS)args)->c);
}

int 
main()
{
    ARGS args = {1, 2.0, 'a'};
    threadFunc(workerFunction, &args);
    return 0;
}
