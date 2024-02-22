#include<stdio.h>
#include<stdlib.h>

int add(int a, int b){return a+b;}
int sub(int a, int b){return a-b;}
int mul(int a, int b){return a*b;}
int divi(int a, int b){return a/b;}

int main(int argc, char const *argv[])
{
    int (*fn[])(int, int) ={&add, &sub, &mul, &divi};
    int n,a,b;
    printf("Enter the number\n\t1.Addition\n\t2.Subtraction\n\t3.Multiplication\n\t4.Division\n>>> ");
    scanf("%d",&n);
    printf("Enter number 1st\n>>> ");
    scanf("%d",&a);
    printf("Enter number 2nd\n>>> ");
    scanf("%d",&b);
    printf("%d",fn[n-1](a,b));
    return 0;
}
