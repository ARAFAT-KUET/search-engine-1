#include "LinkedList.h"

#include <iostream>

using namespace std;


// =========================================================
// CONSTRUCTOR
// =========================================================

LinkedList::LinkedList()
{
    head = NULL;
}


// =========================================================
// DESTRUCTOR
// =========================================================

LinkedList::~LinkedList()
{
    Node* current = head;

    while (current != NULL)
    {
        Node* nextNode = current->next;

        delete current;

        current = nextNode;
    }

    head = NULL;
}


// =========================================================
// INSERT
// =========================================================

void LinkedList::insert(string value)
{
    Node* newNode = new Node(value);

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
        return;
    }


    // Go to the last node
    Node* current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }


    // Insert at the end
    current->next = newNode;
}


// =========================================================
// SEARCH
// =========================================================

bool LinkedList::search(string value)
{
    Node* current = head;

    while (current != NULL)
    {
        if (current->data == value)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}


// =========================================================
// DISPLAY
// =========================================================

void LinkedList::display()
{
    Node* current = head;

    while (current != NULL)
    {
        cout << current->data;

        if (current->next != NULL)
        {
            cout << " -> ";
        }

        current = current->next;
    }

    cout << endl;
}


// =========================================================
// SIZE
// =========================================================

int LinkedList::size()
{
    int count = 0;

    Node* current = head;

    while (current != NULL)
    {
        count++;

        current = current->next;
    }

    return count;
}
