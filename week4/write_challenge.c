#include <stdio.h>

int main()
{
    char *filename = "data.txt";

    FILE *file = fopen(filename, "w"); // or "a", "w+", "a+"
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int number;
    printf("How many numbers do you want to write?: ");
    int num_lines;
    scanf("%d", &num_lines);
    printf("Type %d numbers: ", num_lines);
    int total = 0;

    for (int i = 0; i < num_lines; i++)
    {
        scanf("%d", &number);
        total += number;
        fprintf(file, "%d\n", number);
        // atoi?
    }
    float mean = (float)total / num_lines;
    fprintf(file, "mean of all the number is %f\n", mean);

    char ch[100];
    printf("Enter a string: ");
    scanf("%s", ch);
    fprintf(file, "%s\n", ch);

    fclose(file);
    return 0;
}