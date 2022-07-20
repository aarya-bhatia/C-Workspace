#include <stdio.h>
#include <stdlib.h>
#include <string>

/*

Queries
----------
1 x y : Insert a book with y pages at the end of the xth shelf.
2 x y : Print the number of pages in the yth book on the xth shelf.
3 x : Print the number of books on the xth shelf.

The first line contains an integer total_number_of_shelves, the number of shelves in the library.
The second line contains an integer total_number_of_queries, the number of requests.
Each of the following total_number_of_queries lines contains a request in one of the three specified formats.
*/

struct node{
    struct node *next;
    int val;
};

struct list{
    struct node *head;
    int size;
};

int num_shelves;
int num_query;

int main()
{
    scanf("%d", &num_shelves);
    scanf("%d", &num_query);

    struct list * shelves = malloc(sizeof(struct list *) * num_shelves);

    for(int i = 0; i < num_query; i++)
    {
        char qid;
        scanf("%c", &qid);
        int x, y;

        scanf("%d", &x);

        if(qid == '3') {
            
        }
        else {
            

            if(qid == '2'){
            }else{
            }
        }     
    }
}