// Write a program to find the area of a Triangle
struct Triangle
{
    float height, base;
};
typedef struct Triangle T;
#include <stdio.h>
void input(T *t)
{
    printf("Enter the height of the triangle: ");
    scanf("%f", &t->height);
    printf("Enter the base of the triangle: ");
    scanf("%f", &t->base);
}
float area_Triangle(T *t)
{
    float area = 0.5 * t -> height * t -> base;
    return area;
}
int main()
{
    T t;
    input(&t);
    float area = area_Triangle(&t);
    printf("The area of the triangle is: %.2f\n", area);
    return 0;
}
>>>>>>> 5b998a6 (Structures)
