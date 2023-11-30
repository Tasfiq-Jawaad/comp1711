
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// declaring this value so I can use it in different places
#define buffer_size 100

/**
 * @brief Struct to hold reading, contains the date as a string,
 *        the time as string and steps as int.
 *
 */
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

/**
 * @brief Opens the file in the correct mode
 *
 * @param filename the name of the file to open
 * @param mode the mode (r/w/a/r+/w+/a+)
 * @return FILE* The file object to store the opened file in.
 */
FILE *open_file(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("Error: could not open file\n");
        exit(1);
    }
    return file;
}

/**
 * @brief tokeniseRecord function
 *        
 *
 * @param input the line of the file to be split
 * @param delimiter what character it should split on
 * @param date the place where the date will be stored
 * @param time the place where the time will be stored.
 * @param steps the place where the steps will be stored.
 */

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

/**
 * @brief collects all the data
 *
 * @param line the line
 * @param bufferSize the buffer size
 * @param file the file pointer
 * @return 
 */
float collectData(char line[], char bufferSize, FILE *file, FITNESS_DATA data[], int * record)
{
    int totalSteps=0;

    int tempLongestPeriod= 0, longestPeriod = 0;

    char tempLongestStartDate [11];
    char tempLongestStartTime [6];
    int longestStepStarted = 0;

    char tempLongestEndDate [11];
    char tempLongestEndTime [6];

    while (fgets(line, buffer_size, file) != NULL)
    {
        //collecting the total number of record
        ++*record;

        char tempDate[11];
        char tempTime[6];
        char tempSteps[8];
        
        int tempStepsInt;

        tokeniseRecord(line, ",", tempDate, tempTime, tempSteps);
        tempStepsInt = atoi(tempSteps);
        totalSteps += tempStepsInt;
        

        if(tempStepsInt<data[0].steps)
        {
            data[0].steps = tempStepsInt;
            strcpy(data[0].date, tempDate);
            strcpy(data[0].time, tempTime);
        }

        if(tempStepsInt>data[1].steps)
        {
            data[1].steps = tempStepsInt;
            strcpy(data[1].date, tempDate);
            strcpy(data[1].time, tempTime);
        }

        if(tempStepsInt>500 && longestStepStarted == 1)
        {
            strcpy(tempLongestEndDate, tempDate);
            strcpy(tempLongestEndTime, tempTime);
            tempLongestPeriod += 15;
        }

        else if(tempStepsInt>500 && longestStepStarted == 0)
        {
            longestStepStarted = 1;

            strcpy(tempLongestStartDate, tempDate);
            strcpy(tempLongestStartTime, tempTime);

            strcpy(tempLongestEndDate, tempDate);
            strcpy(tempLongestEndTime, tempTime);
            
            tempLongestPeriod += 15;
        }

        else if(tempStepsInt<=500 && longestStepStarted == 1)
        {
            if(tempLongestPeriod>longestPeriod)
            {
                strcpy(data[2].date, tempLongestStartDate);
                strcpy(data[2].time, tempLongestStartTime);
                
                strcpy(data[3].date, tempLongestEndDate);
                strcpy(data[3].time, tempLongestEndTime);
                longestPeriod = tempLongestPeriod;
                
            }
            tempLongestPeriod = 0;
            longestStepStarted = 0;
        }
        // else
        // {
        //     strcpy(tempLongestStartDate, tempDate);
        //     strcpy(tempLongestStartTime, tempTime);
        // }
    }

    if(tempLongestPeriod>longestPeriod)
        {
            strcpy(data[2].date, tempLongestStartDate);
            strcpy(data[2].time, tempLongestStartTime);
            
            strcpy(data[3].date, tempLongestEndDate);
            strcpy(data[3].time, tempLongestEndTime);
            longestPeriod = tempLongestPeriod;
            
        }

    float mean = (float) totalSteps / *record;
    return mean;
}




/**
 * @brief prints all the options
 *
 */
int printOption()
{
    printf("A: Specify the filename to be imported – you need to check that the file opened correctly.\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the data and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Exit\n");
}

#endif // FITNESS_DATA_STRUCT_H
