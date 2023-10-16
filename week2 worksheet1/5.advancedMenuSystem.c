#include <stdio.h>
void main()
{
    int option;

    printf("Select a menu: \n1: Home\n2: About\n3: Option\n4: Contact us\n5: Log in\n");
L:
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("Welcome to Home");
        break;
    case 2:
        printf("Lets talk about us");
        break;
    case 3:
        printf("You dont have any option!! JUST DO IT!");
        break;
    case 4:
        printf("We are very busy, sorry!");
        break;
    case 5:
        printf("You don't exist");
        break;
    default:
        printf("Can you not follow a simple instruction?!! TRY AGAIN\n");
        goto L;
    }
}