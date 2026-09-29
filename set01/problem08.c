//8. Write a program to read and print the points of a polygon
#include <stdio.h>
struct point
{
    float x;
    float y;
};
typedef struct point Point;
struct hexagon
{
    Point points[6];
};
typedef struct hexagon Hexagon; 
Hexagon input()
{
    Hexagon h;
    for(int i=0; i<6; i++)
    {
        printf("Enter coordinates of point %d: ", i+1);
        scanf("%f%f", &h.points[i].x, &h.points[i].y);
    }
    return h;
}
void output(Hexagon h)
{
    printf("The points in the hexagon\n");
    for(int i=0;i<6;i++)
    {
       
        printf("(%.2f,%.2f)\n",h.points[i].x, h.points[i].y);
    }
}
int main()
{
    Hexagon h;
    h = input();
    output(h);
    return 0;
}