#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    
    int f[10];
    
    for(int i=0;i<10;i++){f[i]=0;}
    
    char c[1000];
    
    scanf("%s", c);
    
    for(int i=0; i< strlen(c); i++)
    {
        if(isdigit(c[i]))
        {
            f[c[i]-'0']++;
        }
    }
    
    for(int i = 0; i < 9; i++)
    {
        printf("%d ", f[i]);
    }
    
    printf("%d\n", f[9]);
    
    return 0;
}
