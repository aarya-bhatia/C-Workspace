#include <stdio.h>

int isWhite(int c) {
    if(c == ' '||c=='\n'||c=='\t') {
        return 1;
    }
    return 0;
}
int main() {
    int c; // input characters
    int ctr = 0; // counter
    int freq[10]; // stores the number of words of length 0 - 10 in corr index

    for(int i =0; i < 10; i++) {
        freq[i] =0;
    }

    while((c = getchar()) != EOF) {
        if(!isWhite(c)) {
            ctr++;
        }
        else if(ctr != 0) {
            // word found
            if(ctr >= 9) { ctr = 9; }
            freq[ctr]++;
            printf("Word: %d\n", ctr);
            ctr = 0;
        }
    }

    // draw historgram horizontal
    printf("HISTOGRAM\n");
    
    for(int i = 0; i < 10; i++) {
        if(i == 9) {
            printf("9+:");
        }
        else {
            printf("%d:",i);
        }

        int f = freq[i];

        for(int j = 0; j < f; j++) {
            printf("x");
        }
        printf("(%d)\n",f);
    }

    return 0;
}
