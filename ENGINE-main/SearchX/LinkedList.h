#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;


// =========================================================
// NODE
// =========================================================

struct Node
{
    string data;
    Node* next;

    Node(string value)
    {
        data = value;
        next = NULL;
    }
};


// =========================================================
// LINKED LIST
// =========================================================

class LinkedList
{
private:

    Node* head;

public:

    LinkedList();

    ~LinkedList();

    void insert(string value);

    bool search(string value);

    void display();

    int size();
};

#endif
