#include <stdio.h>
void main()
{
    printf("\n");
    // for (int i = 1; i <= 12; i++)
    // {
    //     for (int j = 1; j <= 12; j++)
    //     {
    //         printf("%d x %d = %d\n", i, j, i * j);
    //     }
    //     printf("\n");
    // }

    // for (int i = 1; i <= 12; i++)
    // {
    //     for (int j = 1; j <= 12; j++)
    //     {
    //         printf("%d\t", i * j);
    //     }
    //     printf("\n");
    // }

    int j = 0;

    for (int i = 1; i <= 27; i += 2)
    {
        j += i;
        printf("%d\t%d\n", i, j);
    }
}