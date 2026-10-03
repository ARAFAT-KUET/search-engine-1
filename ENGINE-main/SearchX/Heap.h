
#ifndef HEAP_H
#define HEAP_H

#include <vector>

#include "SearchResult.h"

using namespace std;


// =========================================================
// MAX HEAP
// =========================================================

class MaxHeap
{
private:

    vector<SearchResult> heap;


    void heapifyUp(int index);

    void heapifyDown(int index);


public:

    bool empty();

    int size();

    void insert(SearchResult result);

    SearchResult extractMax();
};

#endif
