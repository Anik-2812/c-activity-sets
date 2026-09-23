//3. Write a program find the square root of a number using babylonian method.
#include<stdio.h>
#include<math.h>
void input(int *a) //to take input
{
    printf("Enter an integer: ");
    scanf("%d",a);
}
float square_root(int a)
{
    float guess = a / 2.0f;
    float next_guess = (guess + a/guess)/2;
    while(fabsf(next_guess - guess) > 0.00001f) //babylonian method loop
    {
        guess = next_guess;
        next_guess = (guess + a/guess)/2;
    }
    return next_guess;
}
int main()
{
    int a;
    input(&a);
    printf("Square root: %.4f\n", square_root(a));
    return 0;
}