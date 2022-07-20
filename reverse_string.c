#include <stdio.h>

void reverse(char s[], int len);

int main() {
    char c[] = "HELLO";
    reverse(c, 5);
    return 0;
}

void reverse(char s[], int len) {
    char r[len];
    for(int i = 0; i < len; i++) {
        r[i] = s[len-i-1];
    }
    printf("Original word: %s\n", s);
    printf("Reverse: %s", r);
}

