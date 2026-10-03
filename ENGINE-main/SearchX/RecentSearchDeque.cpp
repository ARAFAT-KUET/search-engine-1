
#include "RecentSearchDeque.h"

#include <iostream>

using namespace std;


RecentSearchDeque::RecentSearchDeque()
{
    front = NULL;

    rear = NULL;

    count = 0;
}


RecentSearchDeque::~RecentSearchDeque()
{
    while (front != NULL)
    {
        DequeNode* temp =
            front;

        front =
            front->next;

        delete temp;
    }

    rear = NULL;

    count = 0;
}


void RecentSearchDeque::pushFront(string query)
{
    DequeNode* newNode =
        new DequeNode(query);

    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        newNode->next =
            front;

        front->previous =
            newNode;

        front =
            newNode;
    }

    count++;
}


void RecentSearchDeque::pushBack(string query)
{
    DequeNode* newNode =
        new DequeNode(query);

    if (rear == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        newNode->previous =
            rear;

        rear->next =
            newNode;

        rear =
            newNode;
    }

    count++;
}


string RecentSearchDeque::popFront()
{
    if (front == NULL)
    {
        return "";
    }

    DequeNode* temp =
        front;

    string query =
        front->query;

    front =
        front->next;

    if (front == NULL)
    {
        rear = NULL;
    }
    else
    {
        front->previous =
            NULL;
    }

    delete temp;

    count--;

    return query;
}


string RecentSearchDeque::popBack()
{
    if (rear == NULL)
    {
        return "";
    }

    DequeNode* temp =
        rear;

    string query =
        rear->query;

    rear =
        rear->previous;

    if (rear == NULL)
    {
        front = NULL;
    }
    else
    {
        rear->next =
            NULL;
    }

    delete temp;

    count--;

    return query;
}


string RecentSearchDeque::getFront()
{
    if (front == NULL)
    {
        return "";
    }

    return front->query;
}


string RecentSearchDeque::getBack()
{
    if (rear == NULL)
    {
        return "";
    }

    return rear->query;
}


bool RecentSearchDeque::empty()
{
    return front == NULL;
}


int RecentSearchDeque::size()
{
    return count;
}


void RecentSearchDeque::display()
{
    cout << endl;

    cout << "========================================"
         << endl;

    cout << "          RECENT SEARCHES"
         << endl;

    cout << "========================================"
         << endl;

    if (front == NULL)
    {
        cout << "No recent searches."
             << endl;
    }
    else
    {
        DequeNode* current =
            front;

        int position = 1;

        while (current != NULL)
        {
            cout << position
                 << ". "
                 << current->query
                 << endl;

            current =
                current->next;

            position++;
        }
    }

    cout << "========================================"
         << endl;
}
