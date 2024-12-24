#include<bits/stdc++.h>
using namespace std;

int main()
{
    /**
     * This is how you can allocate Pool using direct pointer
     * you have to segment it afterwards
     */
    void* pool = malloc(sizeof(int)*3);
    int *a=new(&((int*)pool)[0]) int();
    int *b=new(&((int*)pool)[1]) int();
    int *c=new(&((int*)pool)[2]) int();
    *a=12;
    *b=13;
    *c=67;
    printf("a=%d b=%d c=%d",*a,*b,*c);

    return 0;
}