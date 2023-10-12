#include <stdio.h>
void main()
{
    int my_array[15];
    for (int i = 1; i <= 15; i++)
    {
        my_array[i - 1] = i;
    }
    for (int i = 0; i < 15; i++)
    {
        printf("%d\n", my_array[i]);
    }
}