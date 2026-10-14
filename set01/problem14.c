//Write a program to add n fractions.
#include<stdio.h>
struct fraction
{
    int numerator, denominator;
};
typedef struct fraction fraction;
fraction input(int n, fraction f[n])
{
    for(int i = 0; i < n; i++)
    {
        fraction temp = f[i];
        printf("Enter numerator and denominator for fraction %d: ", i + 1);
        scanf("%d/%d", &f[i].numerator, &f[i].denominator);
        if(f[i].denominator != temp.denominator && f[i].denominator == 0)
            return input(n, f);
        else if(f[i].denominator < 0)
        {
            f[i].numerator = -f[i].numerator;
            f[i].denominator = -f[i].denominator;
        }
        if(f[i].denominator == temp.denominator)
            f[i].denominator = 1; 
    }
    return f[n];
}
int find_gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return find_gcd(b, a % b);
}
fraction add_fractions(int n, fraction f[n])
{
    fraction result;
    result.numerator = 0;
    result.denominator = 1;
    for(int i = 0; i < n; i++)
    {
        result.numerator = result.numerator * f[i].denominator + f[i].numerator * result.denominator;
        result.denominator *= f[i].denominator;
        int gcd = find_gcd(result.numerator, result.denominator);
        result.numerator /= gcd;
        result.denominator /= gcd;
    }
    return result;
}
void output(int n, fraction f[n], fraction result)
{
    printf("The sum: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d/%d", f[i].numerator, f[i].denominator);
        if(i != n - 1)
            printf(" + ");
    }
    if(result.denominator == 1)
        printf(" = %d\n", result.numerator);
    else
        printf(" = %d/%d\n", result.numerator, result.denominator);
}
int main()
{
    int n;
    printf("Enter the number of fractions: ");
    scanf("%d", &n);
    fraction f[n];
    input(n, f);
    fraction result = add_fractions(n, f);
    output(n, f, result);
    return 0;
}
