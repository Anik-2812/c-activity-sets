//Write a program to find the sum of three fraction
#include<stdio.h>
struct fraction
{
    int numerator, denominator;
};
typedef struct fraction Fraction;
Fraction input()
{
    Fraction f;
    scanf("%d/%d", &f.numerator, &f.denominator);
    if(f.numerator == 0)
        f.denominator = 1;
    if(f.denominator == 0)
        return input();
    else if(f.denominator < 0)
    {
        f.numerator = -f.numerator;
        f.denominator = -f.denominator;
    }
    else
        return f;
}
Fraction add_fractions(Fraction f1, Fraction f2, Fraction f3)
{
    Fraction result;
    if(f1.denominator == f2.denominator)
    {
        Fraction temp = f2;
        f2 = f3;
        f3 = temp;
    }
    result.denominator = f1.denominator * f2.denominator;
    result.numerator = f1.numerator*f2.denominator + f2.numerator*f1.denominator;
    if(result.denominator % f3.denominator == 0)
        result.numerator += f3.numerator * (result.denominator / f3.denominator);
    else
    {
        result.denominator *= f3.denominator;
        result.numerator = result.numerator * f3.denominator + f3.numerator * result.denominator;
    }
    if(result.denominator == result.numerator)
    {
        result.numerator = 1;
        result.denominator = 1;
    }
    return result;
}
void output(Fraction f1, Fraction f2, Fraction f3, Fraction result)
{
    if(result.denominator == 1 ||result.denominator == 0)
        printf("The sum: %d/%d + %d/%d + %d/%d = %d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator,  f3.numerator, f3.denominator, result.numerator);
    else
        printf("The sum: %d/%d + %d/%d + %d/%d = %d/%d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator, f3.numerator, f3.denominator, result.numerator, result.denominator);
}
int main()
{
    printf("Enter the first fraction: ");
    Fraction f1 = input();
    printf("Enter the second fraction: ");
    Fraction f2 = input();
    printf("Enter the third fraction: ");
    Fraction f3 = input();
    Fraction result = add_fractions(f1, f2, f3);
    output(f1, f2, f3, result);
    return 0;
}