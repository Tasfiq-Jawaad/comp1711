#include <stdio.h>
void main()
{
    float sum = 1;
    for (float i = 1; i <= 99999; i++)
    {
        sum = sum + (1 / (i * i));
        // printf("1/%d +  ", i * i);
    }
    printf("%f", sum);
}