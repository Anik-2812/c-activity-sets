//7. Write a program to find distance between two points.
#include <stdio.h>
#include <math.h>
struct point
{
    float x;
    float y;
};
typedef struct point Point;
Point input()
{
    Point p;
    scanf("%f%f", &p.x, &p.y);
    return p;
}
float distance(Point p1, Point p2)
{
    float distance = sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
    return distance;
}
void print(Point p1, Point p2, float d)
{
    printf("The distance between (%f, %f) & (%f, %f) is %f\n", p1.x, p1.y, p2.x, p2.y, d);
}
int main()
{
    Point p1, p2;
    printf("Enter coordinates of p1: ");
    p1 = input();
    printf("Enter coordinates of p2: ");
    p2 = input();
    float d = distance(p1, p2);
    print(p1, p2, d);
    return 0;
}