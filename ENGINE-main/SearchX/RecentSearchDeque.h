
#ifndef RECENTSEARCHDEQUE_H
#define RECENTSEARCHDEQUE_H

#include <string>

using namespace std;


struct DequeNode
{
    string query;

    DequeNode* next;
    DequeNode* previous;

    DequeNode(string value)
    {
        query = value;

        next = NULL;
        previous = NULL;
    }
};


class RecentSearchDeque
{
private:

    DequeNode* front;
    DequeNode* rear;

    int count;

public:

    RecentSearchDeque();

    ~RecentSearchDeque();

    void pushFront(string query);

    void pushBack(string query);

    string popFront();

    string popBack();

    string getFront();

    string getBack();

    bool empty();

    int size();

    void display();
};

#endif
