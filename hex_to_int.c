#include <stdio.h>

/** hexadecimal to integer */
int htoi(char hex[]) {
    int x = 0;

    for(int i = 0; hex[i] != '\0'; i++) {
        int digit = hex[i];
        printf("x=%d digit=%c \n",x,digit);
        if(digit >= '0' && digit <= '9') {
            x = (x << 4) | (digit - '0');
        }
        else if(digit >= 'A' && digit <= 'F') {
            x = (x << 4) | ((digit - 'A') + 10);
        }
        else if(digit >= 'a' && digit <= 'f') {
            x = (x << 4) | ((digit - 'a') + 10);
        }
    }
    return x;
}

/** Octal to integer */
int otoi(char oct[]) {
    int x=0;
    for(int i=0;oct[i]!='\0';i++){
        if(oct[i]>='0'&&oct[i]<='7'){
            x = (x << 4) | (oct[i]-'0');
        }
    }
    return x;
}


int main() {
    printf("Result: %d\n", htoi("a0")); // 160
    printf("Result: %d\n", htoi("FF")); // 255
}