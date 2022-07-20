#pragma once

/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct List
{
    ListNode *head;
    ListNode *tail;

    List()
    {
        head = nullptr;
        tail = nullptr;
    }

    ~List()
    {
        ListNode *itr = head;

        while (itr)
        {
            ListNode *tmp = itr->next;
            delete itr;
            itr = tmp;
        }
    }

    bool empty()
    {
        return !head && !tail;
    }

    void insertFront(int val)
    {
        if (empty())
        {
            head = tail = new ListNode(val);
        }
        else
        {
            ListNode *node = new ListNode(val);
            node->next = head;
            head = node;
        }
    }

    void insertBack(int val)
    {
        if (empty())
        {
            head = tail = new ListNode(val);
        }
        else
        {
            ListNode *node = new ListNode(val);
            tail->next = node;
            tail = node;
        }
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *i = l1;
        ListNode *j = l2;
        List res;
        
        int sum = 0;
        int carry = 0;
        
        while(i && j)
        {
            sum = i->val + j->val + carry;
            carry = sum/10;
            int digit = sum % 10;
            
            i = i->next;
            j = j->next;
            
            res.insertBack(digit);
        }
        
        while(i)
        {
            sum = i->val + carry;
            carry = sum/10;
            int digit = sum % 10;
            i = i->next;
            res.insertBack(digit);
        }
        
        while(j)
        {
            sum = j->val + carry;
            carry = sum/10;
            int digit = sum % 10;
            j = j->next;
            res.insertBack(digit);
        }
        
        if(carry)
        {
            res.insertBack(carry);
        }
        
        return res.head;
    }
};