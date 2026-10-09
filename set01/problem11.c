// Write a program to find the total area of n circles.
#include <stdio.h>
struct circle
{
    float radius, area;
};
typedef struct circle Circle;
void input(int n,Circle cir[])
{
    for(int i = 0; i < n; i++)
    {
        printf("Enter the radius of %dth circle: ", i+1);
        scanf("%f", &cir[i].radius);
    }
}
void compute_area(Circle *cir)
{
    cir -> area = 3.14 * cir -> radius * cir -> radius;
}
void compute_area_n(int n, Circle c[])
{
    for(int i = 0; i < n; i++)
    {
        compute_area(&c[i]);
    }
}
float total_area(int n, Circle cir[])
{
    float total = 0;
    for(int i = 0; i < n; i++)
    {
        total += cir[i].area;
    }
    return total;
}
void show(int n, Circle cir[])
{
    printf("The area of the circles are: \n");
    for(int i = 0; i < n; i++)
    {
        printf("Area of %dth circle: %.2f\n", i+1, cir[i].area);
    }
    printf("Total area of all circles: %.2f\n", total_area(n, cir));
}
int main()
{
    int n;
    printf("Enter the number of circles: ");
    scanf("%d", &n);
    Circle cir[n];
    input(n, cir);
    compute_area_n(n, cir);
    show(n, cir);
    return 0;
}