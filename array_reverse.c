#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;

    scanf("%d", &num);

    arr = (int *)malloc(num * sizeof(int));

    for (i = 0; i < num; i++)
    {
        scanf("%d", arr + i);
    }

    /* Write the logic to reverse the array. */
    for(int i = 0; i < num/2; i++)
    {
        int j = (num - i - 1);
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    for (i = 0; i < num; i++)
    {
        printf("%d ", *(arr + i));
    }

    free(arr);

    return 0;
}