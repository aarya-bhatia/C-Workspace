#pragma once

class LinkedList
{
public:
    struct Node
    {
        int key;
        int value;
        Node* next;

        Node(int key, int value, Node *next):
            key(key),
            value(value),
            next(next)
        {
        }
    };

    LinkedList()
    {
        head_ = nullptr;
        size_ = 0;
    }

    ~LinkedList()
    {
        clear();
    }

    void clear()
    {
        Node *current = head_;

        while(current)
        {
            Node *tmp = current->next;
            delete current; 
            current = nullptr;
            current = tmp;
        }

        head_ = nullptr;
        size_ = 0;
    }

    bool empty() const
    {
        return head_ == nullptr && size_ == 0;
    }

    unsigned size() const
    {
        return size_;
    }

    void insert(int key, int value)
    {
        head_ = new Node(key, value, head_);
        size_++;
    }

    void insert(const LinkedList &other)
    {
        Node *current = other.head_;

        while(current)
        {
            insert(current->key, current->value);
            current = current->next;
        }
    }

    Node *find(int key)
    {
        Node *current = head_;

        while(current)
        {
            if(current->key == key)
            {
                return current;
            }

            current = current->next;
        } 

        return nullptr;
    }

    bool remove(int key)
    {
        if(!head_)
        {
            return false;
        }

        if(head_->key == key)
        {
            head_ = head_->next;
            size_--;
            return true;
        }

        Node *prev = head_;
        Node *current = head_;

        while(current)
        {
            if(current->key == key)
            {
                Node *tmp = current;
                prev->next = current->next;
                delete tmp;
                tmp = nullptr;
                size_--;
                return true;
            }

            prev = current;
            current = current->next;
        }

        return false;
    }

private:
    Node *head_;
    unsigned size_;
};