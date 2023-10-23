#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *filename = "data.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // buffer_size is the number of char we will read per line. 100 is a pretty good number.
    int buffer_size = 100;
    // a string which will hold each line as it's read in
    char line_buffer[buffer_size];

    while (fgets(line_buffer, buffer_size, file) != NULL)
    {
        printf("%d\n", atoi(line_buffer));
    }

    fclose(file);
    return 0;
}