#include <stdio.h>

int sum(int a, int b)
{
    // a and b are local variable
    int answer;
    answer = a + b;
    return answer;
}

void main()
{
    int y = 2;
    int z = sum(10, 7); // calling new function

    printf("The sum of %d and %d is %d \n", y, z);
}