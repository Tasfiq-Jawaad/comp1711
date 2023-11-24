#include "FitnessDataStruct.h"
#include <math.h>


int main() {
    FITNESS_DATA data[4];
    // 0 for the fewest steps
    data[0].steps = 9999;
    // 1 for the largest steps
    data[1].steps = 0;
    // 2 for the logest period start
    data[2].steps = 0;
    // 3 for the longest period end
    data[3].steps = 0;

    int record = 0;
    float mean = 0;
    int *r = &record;

    char line[buffer_size];
    char filename[buffer_size];

    

    
    char option;

    while(1){
        printOption();
        option = getchar();
        while (getchar() != '\n');
        
        switch (option)
        {
        case 'A':
        case 'a':
            printf("Input filename: ");
            fgets(line, buffer_size, stdin);
            sscanf(line, " %s ", filename);
            FILE *file = open_file(filename, "r");
            mean = collectData(line, buffer_size, file, data, r);
            fclose(file);
            break;

        case 'B':
        case 'b':
            printf("Total records: %d\n", record);
            break;

        case 'C':
        case 'c':
            printf("Fewest steps: %s %s\n", data[0].date, data[0].time);
            break;

        case 'D':
        case 'd':
            printf("Largest steps: %s %s\n", data[0].date, data[0].time);
            break;

        case 'E':
        case 'e':
            printf("Mean step count: %.0f\n", mean);
            break;

        case 'F':
        case 'f':
            printf("Longest period start: %s %s\n", data[2].date, data[2].time);
            printf("Longest period end: %s %s\n", data[3].date, data[3].time);
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}









