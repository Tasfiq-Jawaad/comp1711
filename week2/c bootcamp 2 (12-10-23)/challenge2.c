#include <stdio.h>
#include <math.h>
void main()
{
    double sum = 0;
    for (double i = 1; i <= 999999999; i++)
    {
        sum = sum + (1 / (i * i));
        // printf("1/%d +  ", i * i);
    }
    double x = 6 * sum;
    double pi = pow(x, 0.5);
    printf("%lf", pi);
}