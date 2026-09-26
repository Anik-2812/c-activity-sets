//6. Write a program to find the lenght of a string.
#include<stdio.h>
void input_string(char str[])
{
    printf("Enter a string: ");
    scanf("%s", str);
}
int string_length(char str[])
{
    int length = 0;
    while(str[length] != '\0')
        length++;
    return length;
}
void output(char str[], int length)
{
    printf("The length of the string \"%s\" is: %d\n", str, length);
}
int main()
{
    char str[100];
    input_string(str);
    int length = string_length(str);
    output(str, length);
    return 0;
}