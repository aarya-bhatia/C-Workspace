#include <stdio.h>

void countChar();
void countLines();
void copyChar();

int main(){
    int c;
    printf("Type 1 to count characters.\nType 2 to count lines.\nType 3 to copy input.\n");
    scanf("%d",&c);
    if(c == 1) {
        countChar();
    }
    else if(c == 2) {
        countLines();
    }
    else if(c == 3) {
        copyChar();
    }

    return 0;
}

void copyChar() {
    int c;
    while((c = getchar()) != EOF) {
        putchar(c);
    }
    printf("END: %d", c); // -1 
}

void countChar() {
    long nc = 0;
    while(getchar() != -1) {
        nc++;
    }
    printf("Character count: %ld\n",nc);
}
 
void countLines() {
    int c,nl=0;
    while((c = getchar()) != -1) {
        if(c== '\n'){
            nl++;
        }
    }
    printf("Line count: %d\n",nl);
}