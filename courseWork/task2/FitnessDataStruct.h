
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
        perror("");
        exit(1);
    }
	else
		printf("success");
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
 * @param bufferSize 
 * @param file  
 * @return 
 */
void collectData(char line[], char bufferSize, FILE *file, FITNESS_DATA data[], int * record, float * mean)
{
    int totalSteps=0;

    while (fgets(line, buffer_size, file) != NULL)
    {
        //collecting the total number of record
        *record++;

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


    }

    *mean = totalSteps / *record;
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

// /**
//  * @brief Reads the data from the input file into an array of structs
//  *
//  * @param inputFile the open file object
//  * @param dataArray the array of readings
//  * @return int Returns the number of readings from the file
//  */
// int read_file(FILE *inputFile, reading *dataArray)
// {
//     // to do
// }

// /**
//  * @brief Checks that there was data for each part of each reading in the file
//  *
//  * @param dataArray The array of data from the file
//  * @param numReadings The number of readings in the array
//  * @return int Return 0 if there are no errors, 1 if you find an error.
//  */
// int data_checker(reading *dataArray, int numReadings)
// {
//     // to do
// }

#endif // FITNESS_DATA_STRUCT_H



// SUGGESTED FUNCTIONS








// /**
//  * @brief Calculates and returns the mean of the readings in the array
//  * 
//  * @param dataArray The array of data from the file
//  * @param numReadings The number of readings in the array
//  * @return float The mean of the readings.
//  */
// float find_mean(reading* dataArray, int numReadings)
// {
//     // to do
// }

// /**
//  * @brief Finds and returns the highest blood iron reading
//  * 
//  * @param dataArray The array of data from the file
//  * @param numReadings The number of readings in the array
//  * @return float The highest blood iron reading
//  */
// float find_highest(reading* dataArray, int numReadings)
// {
//     // to do
// }

// /**
//  * @brief Finds and returns the lowest blood iron reading
//  * 
//  * @param dataArray The array of data from the file
//  * @param numReadings The number of readings in the array
//  * @return float The lowest blood iron reading
//  */
// float find_lowest(reading* dataArray, int numReadings)
// {
//     // to do
// }


// /**
//  * @brief Ask the user for the month to find, and then print out all readings containing that month.
//  * 
//  * @param dataArray The array of data from the file
//  * @param numReadings The number of readings in the array
//  */
// void monthly_iron(reading* dataArray, int numReadings)
// {
//     // to do
// }