//Write a program to print the score card
#include<stdio.h>
struct player
{
    char name[100];
    int runs, balls, fours, sixs;
    float sr;
};
typedef struct player Player;
Player input()
{
    Player p;
    scanf("%s\t\t%d\t\t%d\t\t%d\t\t%d", p.name, &p.runs, &p.balls, &p.fours, &p.sixs);
    if(p.runs < (p.sixs * 6 + p.fours * 4) || p.balls < p.sixs + p.fours)
    {
        printf("Wrong input\n");
        printf("NAME\t\tRUNS\t\tBALLS\t\t4s\t\t6s\n");
        return input();
    }
    else
        return p;
}
void input_players(int n, Player details[n])
{
    printf("NAME\t\tRUNS\t\tBALLS\t\t4s\t\t6s\n");
    for(int i = 0; i < n; i++)
    {
        details[i] = input();
    }
}
void calculate_sr(Player *p)
{
    p -> sr = p -> runs * 100.0 / p -> balls;
}
void calculate_sr_players(int n, Player p[n])
{
    for(int i = 0; i < n; i++)
        calculate_sr(&p[i]);
}
void output(int n, Player p[n])
{
    printf("NAME\t\tRUNS\t\tBALLS\t\t4s\t\t6s\t\tSR\n");
    for(int i = 0; i < n; i++)
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%.2f\n", p[i].name, p[i].runs, p[i].balls, p[i].fours, p[i].sixs, p[i].sr);
}
int main()
{
    int n;
    printf("Enter the number of players: ");
    scanf("%d", &n);
    Player p[n];
    input_players(n, p);
    calculate_sr_players(n, p);
    output(n, p);
    return 0;
}