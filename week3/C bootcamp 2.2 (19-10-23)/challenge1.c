#include <stdio.h>
int sum(int a)
{
    if (a != 0)
        return (a + sum(a - 1));
}

void main()
{
    int a, count = 0;
    scanf("%d", &a);
    int total = sum(a);
    printf("%d", total);
}