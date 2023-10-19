#include <stdio.h>

float sum(int a, int b)
{
    float answer;
    answer = a + b;
    return answer;
}

void main()
{
    float y = 2;
    float z = sum(5, y);

    printf("The sum of 5 and %f is %d \n", y, z);
}