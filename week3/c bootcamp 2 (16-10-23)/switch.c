#include <stdio.h>

int main()
{
L:
    int a;
    scanf("%d", &a);

    switch (a)
    {
    case 0:
        printf("Option 0 has been selected\n");
        break;

    case 1:
        printf("Option 1 has been selected\n");
        break;

    case 2:
        printf("Option 2 has been selected\n");
        break;

    case 3:
        printf("Op]tion 3 has been selected\n");
        break;

    default:
        printf("Invalid number, plz try again\n");
        goto L;
    }
}