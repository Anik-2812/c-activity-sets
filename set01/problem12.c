//Write a program to add two fractions.
#include<stdio.h>
struct fraction
{
    int numerator, denominator;
};
typedef struct fraction Fraction;
Fraction input()
{
    Fraction f;
    scanf("%d / %d", &f.numerator, &f.denominator);
    if(f.denominator == 0)
    {
        printf("Invalid denominator! Please enter a non-zero value: ");
        return input();
    }
    else if(f.denominator < 0)
    {
        f.numerator = -f.numerator;
        f.denominator = -f.denominator;
    }
    else
        return f;
}
Fraction add_fractions(Fraction f1, Fraction f2)
{
    Fraction result;

    result.numerator = (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator);
    result.denominator = f1.denominator * f2.denominator;
    if(f1.numerator == 0)
        result = f2;
    else if(f2.numerator == 0)
        result = f1;
    else if(result.denominator == result.numerator)
    {
        result.numerator = 1;
        result.denominator = 1;
    }
    return result;
}
void output(Fraction f1, Fraction f2, Fraction result)
{
    if(result.denominator == 1)
        printf("The sum: %d/%d + %d/%d = %d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator, result.numerator);
    else
        printf("The sum: %d/%d + %d/%d = %d/%d\n", f1.numerator, f1.denominator, f2.numerator, f2.denominator, result.numerator, result.denominator);
}
int main()
{
    printf("Enter the first fraction: ");
    Fraction f1 = input();
    printf("Enter the second fraction: ");
    Fraction f2 = input();
    Fraction result = add_fractions(f1, f2);
    output(f1, f2, result);
    return 0;
}