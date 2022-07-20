#pragma once

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* function prototypes */
ListNode *SortedMerge(ListNode *a, ListNode *b);

void FrontBackSplit(ListNode *source, ListNode **frontRef, ListNode **backRef);

/* sorts the linked list by changing next pointers (not val) */
void MergeSort(ListNode **headRef)
{
    ListNode *head = *headRef;
    ListNode *a;
    ListNode *b;

    /* Base case -- length 0 or 1 */
    if ((head == nullptr) || (head->next == nullptr))
    {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);

    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);

    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}

ListNode *SortedMerge(ListNode *a, ListNode *b)
{
    ListNode *result = nullptr;

    /* Base cases */
    if (a == nullptr)
        return (b);
    else if (b == nullptr)
        return (a);

    /* Pick either a or b, and recur */
    if (a->val <= b->val)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go in the front list.
    Uses the fast/slow pointer strategy. */
void FrontBackSplit(ListNode *source,
                    ListNode **frontRef, ListNode **backRef)
{
    ListNode *fast;
    ListNode *slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

/* Function to print nodes in a given linked list */
void printList(ListNode *node)
{
    while (node != nullptr)
    {
        cout << node->val << " ";
        node = node->next;
    }
}