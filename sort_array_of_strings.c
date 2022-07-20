#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **s1, char **s2)
{

}

int lexicographic_sort(const char *a, const char *b)
{
}

int lexicographic_sort_reverse(const char *a, const char *b)
{
}

int sort_by_number_of_distinct_characters(const char *a, const char *b)
{
}

int sort_by_length(const char *a, const char *b)
{
    return strlen(a) - strlen(b);
}

void string_sort(char **arr, const int len, int (*cmp_func)(const char *a, const char *b))
{
    int i, j, min_idx;

    for(i = 0; i < len-1; i++)
    {
        min_idx = i;

        for(j = i+1; j < len; j++)
        {
            if(cmp_func(arr[j], arr[min_idx]) < 0)
            {
                min_idx = j;
            }
        }

        swap(&arr[min_idx], &arr[i]);
    }
}
