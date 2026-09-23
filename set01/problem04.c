//4. Write a program to find the largest of three numbers using 4 functions.
#include <stdio.h>
void input(int *a, int *b, int *c)
{
    printf("Input:\n1st number: ");
    scanf("%d", a);
    printf("2nd number: ");
    scanf("%d", b);
    printf("3rd number: ");
    scanf("%d", c);
}
int compare(int a, int b, int c)
{
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}
int main()
{
    int a, b, c;
    input(&a, &b, &c);
    printf("Largest number is: %d\n", compare(a, b, c));
    return 0;
}