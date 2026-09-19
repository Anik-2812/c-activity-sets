//2. Write a C program to add two numbers.
#include<stdio.h>
void input(int *a, int *b)
{
    printf("INPUT:\na= ");
    scanf("%d",a);
    printf("b= ");
    scanf("%d",b);
}
int add(int a, int b)
{
    return a+b;
}
int main()
{
    int a,b,sum;
    input(&a,&b);
    sum=add(a,b);
    printf("OUTPUT:\n%d + %d = %d\n",a,b,sum);
    return 0;
}