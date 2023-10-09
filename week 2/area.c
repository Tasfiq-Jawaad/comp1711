#include <stdio.h>
int main(){
    float length, width, area;
    printf("Enter the length and width\n");
    scanf("%f%f", &length, &width);

    area = length * width;

    printf("Area is %f", area);

    return 0;
}