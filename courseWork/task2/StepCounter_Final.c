#include "FitnessDataStruct.h"


int main() {
    FITNESS_DATA data[4];
    // 0 for the fewest steps
    data[0].steps = 0;
    // 1 for the largest steps
    data[1].steps = 0;
    // 2 for the logest period start
    data[2].steps = 0;
    // 3 for the longest period end
    data[3].steps = 0;

    int record = 0;
    int *r = &record;

    float mean = 0;

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
            fgets(line, buffer_size, stdin);
            sscanf(line, " %s ", filename);
            FILE *file = open_file(filename, "r");
            mean = collectData(line, buffer_size, file, data, r);
            // while (fgets(line, buffer_size, input))
            // {
            //     // split up the line and store it in the right place
            //     // using the & operator to pass in a pointer to the bloodIron so it stores it
            //     tokeniseRecord(line, ",", daily_readings[counter].date, &daily_readings[counter].bloodIron);
            //     counter++;
            // }
            // for (int i = 0; i < counter; i++)
            // {
            //     printf("%s - Blood iron: %.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
            // }
            // fclose(input);
            break;

        case 'B':
        case 'b':
            printf("Total records: %d\n", record);
            // counter = 0;
            // while (fgets(line, buffer_size, input))
            // {
            //     // split up the line and store it in the right place
            //     // using the & operator to pass in a pointer to the bloodIron so it stores it
            //     tokeniseRecord(line, ",", daily_readings[counter].date, &daily_readings[counter].bloodIron);
            //     mean += daily_readings[counter].bloodIron;
            //     counter++;
            // }
            // mean /= counter;
            // printf("Your average blood iron was %.2f\n", mean);
            // fclose(input);
            break;

        case 'C':
        case 'c':
            return 0;
            break;

        case 'D':
        case 'd':
            return 0;
            break;

        case 'E':
        case 'e':
            return 0;
            break;

        case 'F':
        case 'f':
            return 0;
            break;

        case 'G':
        case 'g':
            return 0;
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









