#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char *s;
    s = malloc(1024);

    scanf("%[^\n]", s);

    int len = strlen(s);

    s = realloc(s, len + 1);
    s[len] = 0;

    char *pch;
    
    pch = strtok(s, " ");

    while (pch != NULL)
    {
        printf("%s\n", pch);
        pch = strtok(NULL, " ");
    }

    return 0;
}