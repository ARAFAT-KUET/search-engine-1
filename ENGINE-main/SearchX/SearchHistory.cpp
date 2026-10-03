
#include "SearchHistory.h"

#include <iostream>

using namespace std;


SearchHistory::SearchHistory()
{
    top = NULL;

    count = 0;
}


SearchHistory::~SearchHistory()
{
    while (top != NULL)
    {
        HistoryNode* temp =
            top;

        top =
            top->next;

        delete temp;
    }
}


void SearchHistory::push(string query)
{
    HistoryNode* newNode =
        new HistoryNode(query);

    newNode->next =
        top;

    top =
        newNode;

    count++;
}


string SearchHistory::pop()
{
    if (top == NULL)
    {
        return "";
    }

    HistoryNode* temp =
        top;

    string query =
        top->query;

    top =
        top->next;

    delete temp;

    count--;

    return query;
}


string SearchHistory::peek()
{
    if (top == NULL)
    {
        return "";
    }

    return top->query;
}


bool SearchHistory::empty()
{
    return top == NULL;
}


int SearchHistory::size()
{
    return count;
}


void SearchHistory::display()
{
    cout << endl;

    cout << "========================================"
         << endl;

    cout << "             SEARCH HISTORY"
         << endl;

    cout << "========================================"
         << endl;

    if (top == NULL)
    {
        cout << "No search history."
             << endl;
    }
    else
    {
        HistoryNode* current =
            top;

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
