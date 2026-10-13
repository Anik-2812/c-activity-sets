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
    Fraction temp = f;
    scanf("%d/%d", &f.numerator, &f.denominator);
    if(f.numerator == 0 && f.denominator == temp.denominator)
        f.denominator = 1;
    if(f.denominator == 0)
        return input();
    else if(f.denominator < 0)
    {
        f.numerator = -f.numerator;
        f.denominator = -f.denominator;
        return f;
    }
    else
    {
        return f;
    }
}
int find_gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return find_gcd(b, a % b);
}
Fraction add_fractions(Fraction f1, Fraction f2, Fraction f3)
{
    Fraction result;
    result.denominator = f1.denominator * f2.denominator * f3.denominator;
    result.numerator = f1.numerator * f2.denominator * f3.denominator + f2.numerator * f1.denominator * f3.denominator + f3.numerator * f1.denominator * f2.denominator;
    int gcd = find_gcd(result.numerator, result.denominator);
    result.numerator /= gcd;
    result.denominator /= gcd;
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