#include<stdio.h>

struct argumentList
{
    int a;
    int b;
    char c;
};

void func(void* args){
    printf("a=%d b=%d and c=%c",((struct argumentList*)args)->a,((struct argumentList*)args)->b,((struct argumentList*)args)->c);
}

void threadFunc(void (*f)(void*), void* args){
    f(args);
}

int main(){
    struct argumentList arg={12,10,'y'};
    threadFunc(func, &arg);
    return 0;
}