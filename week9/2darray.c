#include <stdlib.h>
#include <stdio.h>

int main()
{
    int** array_2d;
    int num_of_rows = 10;
    int num_of_cols = 100;

    array_2d = malloc(num_of_rows * sizeof(int*));
    for(int i = 0; i<num_of_rows; i++)
    {
        array_2d[i] = malloc(num_of_cols*sizeof(int));
    }

    
}