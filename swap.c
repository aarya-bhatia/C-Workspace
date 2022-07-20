#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *s1 = malloc(5);
    char *s2 = malloc(10);

    strcpy(s1, "4321");
    s1[5] = 0;

    strcpy(s2, "123456789");
    s2[10] = 0;

    printf("s1: %s (%lu), s2: %s (%lu)\n", s1, strlen(s1), s2, strlen(s2));

    size_t len = strlen(s1);
    char *tmp = malloc(len + 1);
    memcpy(tmp, s1, len);
    tmp[len] = 0;

    s1 = realloc(s1, 10);
    strcpy(s1, s2);
    s1[10] = 0;

    s2 = realloc(s2, 5);
    strcpy(s2, tmp);
    s2[5] = 0;

    printf("s1: %s (%lu), s2: %s (%lu)\n", s1, strlen(s1), s2, strlen(s2));

    free(s1);
    free(s2);
    free(tmp);

    return 0;
}