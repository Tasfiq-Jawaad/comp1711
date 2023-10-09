#include <stdio.h>
int main(){
    char name[15];
    printf("Hello please enter your name\n");

    scanf("%s", name);

    printf("Hi, %s\n", name);

    int age;
    scanf("%d", &age); 
    printf("%p", &age);
}