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
int tokeniseRecord(char *record, char delimiter, char *date, char *time, char *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        char *checkDate = strstr(ptr, "-");
        if(checkDate){

            checkDate = strstr(&checkDate[1], "-");
            if(!checkDate){
                return 1;
            }
        }
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            char *checkTime = strstr(ptr, ":");
            if(!checkDate){
                return 1;
            }
            strcpy(time, ptr);

            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL && (strstr(ptr, "0")||strstr(ptr, "1")||strstr(ptr, "2")||strstr(ptr, "3")||strstr(ptr, "4")||strstr(ptr, "5")||strstr(ptr, "6")||strstr(ptr, "7")||strstr(ptr, "8")||strstr(ptr, "9"))) {
                strcpy(steps, ptr);
                return 0;
            }
            else{
                return 1;
            }
            
        }
    }
}

FILE *open_file(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("Error: invalid file");
        exit(1);
    }
    return file;
}

int checkFile(char line_buffer[], int buffer_size, FILE *file){
    int dataCounter = 0;
    char tempDate[11];
    char tempTime[6];
    char tempSteps[8];

    while (fgets(line_buffer, buffer_size, file) != NULL)
    {
        //collecting the total number of record
        dataCounter++;


        int validity = tokeniseRecord(line_buffer, ',', tempDate, tempTime, tempSteps);
        if(validity){
            return -1;
        }
    }
    return dataCounter;
}

void storeData(char line_buffer[], int buffer_size, FILE *file, FitnessData data[]){
    int dataCounter = 0;
    while (fgets(line_buffer, buffer_size, file) != NULL)
    {
        char tempSteps[8];

        tokeniseRecord(line_buffer, ',', data[dataCounter].date, data[dataCounter].time, tempSteps);
        data[dataCounter].steps = atoi(tempSteps);
        dataCounter++;
    }
}

void bubbleSort(FitnessData *data, int dataCounter){
    for(int i = 0; i<dataCounter; i++){
        for(int j=0; j<dataCounter; j++){
            if(data[i].steps < data[j].steps){
                FitnessData temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

int main() {
    printf("Enter filename: ");
    char filename [100];
    scanf("%s", filename);
    FILE *file = open_file(filename, "r"); // change the fine name
    // FILE *file = open_file("FitnessData_2023.csv", "r"); // change the fine name

    int buffer_size = 100;
    char line_buffer[buffer_size];

    int dataCounter = checkFile(line_buffer, buffer_size, file);
    if(dataCounter==-1){
        printf("Error: invalid file\n");
        return 1;
    }
    FitnessData data[dataCounter];

    fseek(file, 0, SEEK_SET);
    storeData(line_buffer, buffer_size, file, data);
    fclose(file);

    bubbleSort(data, dataCounter);    

    for(int i = dataCounter-1; i>=0; i--){
        printf("%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
    }

    char ext[] = ".tsv";

    int newSize = strlen(filename) + strlen(ext) +1;
    char newFileName[newSize];
    strcpy(newFileName, filename);
    strcat(newFileName, ext);

    FILE *newFile = open_file(newFileName, "w");

    for(int i = dataCounter-1; i>=0; i--){
        fprintf(file, "%s\t%s\t%d\n", data[i].date, data[i].time, data[i].steps);
    }

    fclose(newFile);

    return 0;
}
