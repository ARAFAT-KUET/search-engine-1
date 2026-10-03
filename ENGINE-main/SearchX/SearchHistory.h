
#ifndef SEARCHHISTORY_H
#define SEARCHHISTORY_H

#include <string>

using namespace std;

struct HistoryNode
{
    string query;

    HistoryNode* next;

    HistoryNode(string value)
    {
        query = value;
        next = NULL;
    }
};

class SearchHistory
{
private:

    HistoryNode* top;

    int count;

public:

    SearchHistory();

    ~SearchHistory();

    void push(string query);

    string pop();

    string peek();

    bool empty();

    int size();

    void display();
};

#endif
