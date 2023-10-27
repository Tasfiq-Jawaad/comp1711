#include <stdio.h>

typedef unsigned char mark_t;
typedef struct {
    char name [20];
    // the last index is reserved for '0' or '/0'
    char student_id [11]; //assuming 10 digits
    unsigned char marks; //?
} student;

int main () {
    student new_student = {
        // .<fieldname> is a designator
        .name = "Name Surname abcdefg",
        .student_id = "28932123",
        .marks = 35
    };

    printf("%s", new_student.name);
    for(int i=0; i<20; i++){
        // if(new_student.name[i] != '\0')
            printf("%c\n", new_student.name[i]);
        
        // else{
            printf("%d", i);
        //     break;
        
        // } 

    }


    return 0;
}