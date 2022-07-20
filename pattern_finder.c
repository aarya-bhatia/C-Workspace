#include <stdio.h>
#define MAXLINE 200 /* Maximum input line length */

int get_line(char[], int);
int str_index(char[], char[]); 

char pattern[] = "ould"; /* Search for this */

int main(){
    char line[MAXLINE];
    int found = 0;

    while(get_line(line, MAXLINE) > 0){
        if(str_index(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }

    printf("%d matches were found.\n",found);
    return 0;
}

/* get_line: read line into s, return length */
int get_line(char s[], int lim) {
    int c,i=0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++]=c;
    }
    if(c == '\n') {
        s[i++] = '\n';
    }
    s[i] = '\0';
    return i;
}

/* str_index: return index of t in s, -1 if none */
int str_index(char s[], char t[]) {
    for(int i = 0; s[i] != '\0'; i++) {
        int k = 0;
        for(int j = i; t[k] != '\0' && s[j] == t[k]; j++, k++);
        if(k > 0 && t[k] == '\0') {
            return i;
        }
    }
    return -1;
}