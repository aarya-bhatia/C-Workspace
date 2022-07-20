#include <stdio.h>

#define IN 1 
#define OUT 0

int main() {
    int c, nLine, n_word, nChar, state;
    state = OUT;
    nLine = n_word = nChar = 0;
    while((c=getchar()) != EOF) {
        ++nChar;
        if(c=='\n') {
            ++nLine;
        }

        if(c==' '||c=='\n'||c=='\t') {
            state = OUT;
        } else if(state == OUT) {
            state = IN;
            ++n_word;
        }
    }

    printf("Lines: %d\tWords: %d\tCharacters: %d\n", nLine, n_word, nChar);
    return 0;
}