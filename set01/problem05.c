//5. Write a program to find the sum of n different numbers.
#include<stdio.h>
int input_size()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    return n;
}
void input_numbers(int n, int a[])
{
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}
int sum_numbers(int n, int a[])
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}
void print_sum_numbers(int n, int a[], int sum)
{
    printf("The sum of numbers are:\n");
    for(int i = 0; i < n - 1; i++)
        printf("%d + ", a[i]);
    printf("%d = %d\n", a[n-1], sum);
}
int main()
{
    int n = input_size();
    int a[n];
    input_numbers(n, a);
    print_sum_numbers(n, a, sum_numbers(n, a));
    return 0;
}