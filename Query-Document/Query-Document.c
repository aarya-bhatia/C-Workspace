#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "split-string.h"

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
#define MIN_ARRAY_SIZE 16

// Document contains paragraphs separated by '\n'
// Paragraphs contains sentences separated by '.'
// Sentences contains words separated by ' '

void get_document(char *text)
{
    // list *paragraphs = split_string(text, '\n');

    // for(node *itr = paragraphs->head->next; itr != paragraphs->tail; itr++)
    // {
    //     list *sentences = split_string((char *)itr->data, '.');

    //     for(node *itr2 = sentences->head->next; itr2 != sentences->tail; itr2++)
    //     {
    //         list *words = split_string((char *)itr2->data, ' ');
    //     }
    // }

    return NULL;
}

char *file_read(const char *filepath)
{
    FILE *fptr = fopen(filepath, "r");
    if (!fptr)
        return NULL;

    fseek(fptr, 0, SEEK_END);
    long file_size = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    char *text = (char *)malloc(file_size);
    int i = 0;
    int c;

    while ((c = fgetc(fptr)) != EOF)
    {
        text[i++] = c;
    }

    fclose(fptr);

    return text;
}

void print_sentence(char **sentence)
{
    printf("-- BEGIN SENTENCE --\n");

    for (char **ptr = sentence; *ptr; ptr++)
    {
        printf("%s", *ptr);
        printf(" ");
    }

    printf("\n");

    printf("-- END SENTENCE --\n");
}

void print_paragraph(char ***paragraph)
{
    printf("--- BEGIN PARAGRAPH ---\n");

    for (char ***ptr = paragraph; *ptr; ptr++)
    {
        print_sentence(*ptr);
    }

    printf("--- END PARAGRAPH ---\n");
}

void print_document(char ****document)
{
    printf("---- BEGIN DOCUMENT ----\n");

    for (char ****ptr = document; *ptr; ptr++)
    {
        print_paragraph(*ptr);
    }

    printf("---- END DOCUMENT ----\n");
}

int main()
{
    char *text = file_read("/Users/aarya/Development/C-Workspace/Query-Document/res/document.txt");

    if (!text)
    {
        fprintf(stderr, "Error reading document.txt\n");
        return 1;
    }

    free(text);

    // char ****document = get_document(text);
    // print_document(document);

}
