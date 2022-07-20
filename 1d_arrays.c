#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;

    fscanf(stdin, "%d", &n);

    int *arr = malloc(n * sizeof(int));

    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        fscanf(stdin, "%d", &arr[i]);
        sum += arr[i];
    }

    fprintf(stdout, "%d\n", sum);

    free(arr);
    
    return 0;
}