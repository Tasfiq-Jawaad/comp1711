#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){
    char homeRow[] ={'a', 's', 'd', 'f', 'j', 'k', 'l', ';'};
    int numOfWords = 4;

    int numOfWordsFixed = numOfWords;

    // L:
    int ch;
    scanf("%d", &ch);
    char words[numOfWords][ch];

    while(numOfWords+1){
        for(int j=0; j<ch; j++){
            int idx = rand()%9;
            if (idx == 0)
                idx = 0;
            words[numOfWordsFixed-numOfWords][j] = idx;
            printf("%c", homeRow[idx]);
        }
        printf(" ");
        numOfWords--;
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            printf("%c", words[i][j]);
        }
        printf("\n");
    }
}