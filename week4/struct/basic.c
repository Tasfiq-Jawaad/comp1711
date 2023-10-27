#include <stdio.h>

struct student {
    char name [20];
    // the last index is reserved for '0' or '/0'
    char student_id [11]; //assuming 10 digits
    unsigned marks; //?
};

int main () {
    struct student new_student = {
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

    // asdf jkl; asdf jkl; a s d f j k l ; a s d f j k l ; a j s k f l a j s k d l f ; a ; l s d k j f a s d f j k l ; A J S K D L F : 

    return 0;
}