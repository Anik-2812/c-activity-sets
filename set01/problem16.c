//Write a program to find the number of 1 bits 
#include<stdio.h>
void input(int *a)
{
    printf("Enter a number x: ");
    scanf("%d", a);
}
int count_bits(int n, int bin[])
{
    int count = 0;
    for(int i = 0; i < sizeof(n)*8; i++)
    {
        bin[i] = n & 0x1;
        if(n & 0x1 == 0x1)
            count ++;
        n >>= 1;
    }
    return count;
}
void output(int n, int count, int bin[])
{

    printf("The number of bits of 1 in %d (", n);
    for(int i = sizeof(n) * 8 - 1; i >= 0; i--) 
    {
        if(bin[i] == 0 && bin[i-1] != 1 && (i > 3))
            continue;
        else
             printf("%d", bin[i]);
    }
    printf(") is %d", count);
}
int main()
{
    int n;
    input(&n);
    int bin[sizeof(n) * 8];
    output(n, count_bits(n, bin), bin);
    return 0;
}