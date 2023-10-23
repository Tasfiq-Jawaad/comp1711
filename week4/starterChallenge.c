#include <stdio.h>
float sum(float arr[10])
{
    float mean = 0;
    for (int i = 0; i < 10; i++)
    {
        mean += arr[i];
    }
    mean /= 10;
    return mean;
}

float *arrange(float *arr) //
{
    float sortArray[10];
    sortArray[0] = arr[0];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (sortArray[i] < arr[j])
            {
                sortArray[i] = arr[j];
            }
        }
    }
    return sortArray;
}

void main()
{
    float arr[10];
    printf("Please enter 10 numbers");
    for (int i = 0; i < 10; i++)
    {
        scanf("%f", &arr[i]);
    }
    float mean = sum(arr);
    printf("The mean is %f", mean);
    // float sortArray = arrange(arr);
}