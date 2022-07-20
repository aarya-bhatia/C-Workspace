#include <stdio.h>

unsigned long int next = 1;

int rand(void); /** Return psuedo random integer in [0,32767] */

int main() {
    for(int i = 0; i < 50; i++) {
        printf("%d\n",rand());
    }
}

int rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int) (next/65536) % 32767;
}
