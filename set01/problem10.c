#include<stdio.h>
struct Triangle
{
    float height, base, area;
};
typedef struct Triangle T;
T input()
{
    T t;
    printf("Enter the height of the triangle: ");
    scanf("%f", &t.height);
    printf("Enter the base of the triangle: ");
    scanf("%f", &t.base);
    return t;
}
float area(T *t)
{
    t -> area = 0.5 * t -> height * t -> base;
    return t -> area;
}
T compare(T t1, T t2, T t3)
{
    float area1 = area(&t1);
    float area2 = area(&t2);
    float area3 = area(&t3);
    if(area1 > area2 && area1 > area3)
        return t1;
    else if(area2 > area1 && area2 > area3)
        return t2;
    else
        return t3;
}
void output(T t1, T t2, T t3)
{
    float max_area = compare(t1, t2, t3).area;
    float max_height = compare(t1, t2, t3).height;
    float max_base = compare(t1, t2, t3).base;
    printf("For Maximum area: \nBase\tHeight\tArea\n%.2f\t%.2f\t%.2f", max_base, max_height, max_area);
}
int main()
{
    T t1, t2, t3;
    t1 = input();
    t2 = input();
    t3 = input();
    output(t1, t2, t3);
    return 0;
}
