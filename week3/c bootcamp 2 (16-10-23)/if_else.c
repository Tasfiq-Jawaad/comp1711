#include <stdio.h>
void main()
{
    int mark;

    while (mark < 0 || mark > 100) // using a while will make sure it will never get an invalid value
    {
        printf("Enter the mark: ");
        scanf("%d", &mark);
    }

    // printf("%d\n", mark);
    if (!(mark >= 0 && mark <= 100))
        printf("Please enter a valid mark");
    else if (mark > 70)
        printf("The mark of %d is a first class", mark);
    else if (mark > 60)
        printf("The mark of %d is a 2:1\n", mark);
    else if (mark > 40)
        printf("The mark of %d is a pass\n", mark);
    else if (mark == 0)
        printf("The mark of %d is zero\n", mark);
    else
        printf("The mark of %d is a fail\n", mark);
}