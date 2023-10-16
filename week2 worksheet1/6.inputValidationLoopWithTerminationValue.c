#include <stdio.h>
void main()
{
    int num;
    while (num != -1)
    {
        printf("Enter a number between 0-100\n");
        scanf("%d", &num);
        if ((num < 0 || num > 100) && num != -1)
            printf("Enter a valid number!!\n");
        else
            printf("You entered %d\n", num);
    }
    printf("Programme terminated!");
}