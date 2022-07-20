#pragma once

class MyHashSet
{
private:
    struct Node
    {
        int key;
        Node* left;
        Node* right;
        bool exists;

        Node(int key = 0, Node *left = nullptr, Node *right = nullptr, bool exists = true):
            key(key),
            left(left),
            right(right),
            exists(exists)
        {

        }
    };

public:
    MyHashSet()
    {
        root = nullptr;
    }

    ~MyHashSet()
    {
        clear(root);
    }

    void add(int key)
    {
        root = add(root, key);
    }

    void remove(int key)
    {
        remove(root, key);
    }

    bool contains(int key)
    {
        return contains(root, key);
    }

private:
    Node *root;

    Node *add(Node* current, int key)
    {
        if(!current)
        {
            return new Node(key);
        }

        if(key < current->key)
        {
            current->left = add(current->left, key);
        }
        else if(key > current->key)
        {
            current->right = add(current->right, key);
        }
        else
        {
            current->exists = true;
        }
        
        return current;
    }

    void remove(Node* current, int key)
    {
        if (!current)
        {
            return;
        }

        if (key < current->key)
        {
            remove(current->left, key);
        }
        else if (key > current->key)
        {
            remove(current->right, key);
        }
        else
        {
            current->exists = false;
        }
    }

    bool contains(Node* current, int key)
    {
        if(!current)
        {
            return false;
        }

        if(key < current->key)
        {
            return contains(current->left, key);
        }
        else if(key > current->key)
        {
            return contains(current->right, key);
        }
        
        return current->exists;
    }

    void clear(Node *current)
    {
        if(current != nullptr)
        {
            clear(current->left);
            clear(current->right);
            delete current;
        }
    }

};