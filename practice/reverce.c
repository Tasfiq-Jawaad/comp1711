#include <stdio.h>
int length(char str[])
{
    int length = 0;
    for (int i = 0; i <= '\0'; i++)
    {
        length++;
    }
    return length;
}

void main()
{
    char str[15], rvrc_string[15];
    scanf("%s", str);
    length(str);
}
