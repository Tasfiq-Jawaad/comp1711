#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

FILE *open_file(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("");
        exit(1);
    }
    return file;
}

int checkFile(char line_buffer[], int buffer_size, FILE *file){
    int dataCounter = 0;
    while (fgets(line_buffer, buffer_size, file) != NULL)
    {
        //collecting the total number of record
        dataCounter++;

        char tempDate[11];
        char tempTime[6];
        int tempSteps[1];

        tokeniseRecord(line_buffer, ',', tempDate, tempTime, tempSteps);
        // printf("date: %s\ntime: %s\nsteps: %ls\n", tempDate, tempTime, tempSteps2);
        printf("date: %s\ntime: %s\nsteps: %d", tempDate, tempTime, tempSteps[0]);
        printf("\n");
    }
}

int main() {
    printf("Enter filename: ");
    char filename [100];
    // scanf("%s", filename);
    FILE *file = open_file("FitnessData_2023.csv", "r"); // change the fine name

    int buffer_size = 100;
    char line_buffer[buffer_size];

    checkFile(line_buffer, buffer_size, file);

    fclose(file);
    return 0;
}
