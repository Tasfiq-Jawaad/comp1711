#include <stdio.h>
int main(){
    float a;
    float b = 3.6;
    int c;

    a = 2.6;
    c = a + b; //if we store float data in and int after calculating, it will first add in float, then take the int. so it will be 6.2, then chop the float. its called truncating

    printf("sum of %f and %f is %i", a, b, c);
    return 0;
}