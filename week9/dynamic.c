#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    printf("An int is size: %ld\n", sizeof(int));

    printf("An int is size: %ld\n", sizeof(double));

    printf("An int is size: %ld\n", sizeof(char));

    char* name = "Jonathonadsfadsfgdsfdsfa";
    printf("The word %s is size: %ld\n", name, sizeof(name)); // its not the size of the string, its the size of the pointer

    // malloc(size_t) // size_t = space_to_allocate
    // size_t = a data type used to specify sizes, C woll accept int

    // create an array of 200 chars called address
    // an array of 70 ints called 'data'
    // get the user to input the size of an arrau of doubles called 'samples'
    char *address = malloc(200*sizeof(char));
    int *data = malloc(70*sizeof(int));
    //now its like data[100]; all normal stuff that we can do with a normal array, we can do those with data;
    int size_of_double;
    scanf("%d", &size_of_double);
    double* samples = malloc(size_of_double*sizeof(double));
    if(!samples){
        printf("its too big...thats what she said");
    }

}