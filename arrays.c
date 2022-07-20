#include <stdio.h>

#define MAXLINE 20
#define null '\0'
#define end '\n'

int getNextLine(char line[]);
void copy(char from[], char to[]);

/* Program to print the longest line of input */
int main() {

    int len = 0; /* Current line length */
    int max = 0; /* maximum length so far */
    char line[MAXLINE]; /* Current input line */
    char longest[MAXLINE]; /* longest line saved here */

    while((len = getNextLine(line)) > 0) {
        if(len > max) {
            max = len;
            copy(line, longest);
        }
    }

    if(max > 0) {
        if(max >= MAXLINE) {
            printf("Longest Line [Truncated] : %s...\n", longest);
        }
        else {
            printf("Longest Line : %s\n", longest);
        }
        printf("Length: %d\n", max);
    }

    return 0;
}

/** reads a line into s[] and returns it's length */
int getNextLine(char s[]) {
    int i = 0;
    int c;
    // only stores some of the letters but counts all
    while((c = getchar()) != EOF && c != end) {
        if(i < MAXLINE) {
            s[i] = c; 
        }
        i++; 
    }

    if(i < MAXLINE) {
        s[i] = null; /* Marks the end in the array */
    }
    
    return i;
}

/** Copies the values of from[] to to[] */
void copy(char from[], char to[]) {
    for(int i = 0; i < MAXLINE && from[i] != null; i++) {
        to[i] = from[i];
    }
}