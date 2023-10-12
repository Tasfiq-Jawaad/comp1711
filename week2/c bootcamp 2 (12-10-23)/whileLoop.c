#include <stdio.h>
void main()
{
    int a = 0;

    while (a < 5)
    {
        printf("a is equal to %d\n", a);
        a++;
    }
    printf("I've finished the loop and a is equal to %d\n", a);
}