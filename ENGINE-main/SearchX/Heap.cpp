#include "Heap.h"

using namespace std;

void MaxHeap::heapifyUp(int index)
{
    while (index > 0)
    {
        int parent =
            (index - 1) / 2;

        if (heap[parent].score >=
            heap[index].score)
        {
            break;
        }

        SearchResult temp =
            heap[parent];

        heap[parent] =
            heap[index];

        heap[index] =
            temp;

        index = parent;
    }
}

void MaxHeap::heapifyDown(int index)
{
    int n = heap.size();

    while (true)
    {
        int left =
            2 * index + 1;

        int right =
            2 * index + 2;

        int largest =
            index;

        if (left < n &&
            heap[left].score >
            heap[largest].score)
        {
            largest = left;
        }

        if (right < n &&
            heap[right].score >
            heap[largest].score)
        {
            largest = right;
        }

        if (largest == index)
        {
            break;
        }

        SearchResult temp =
            heap[index];

        heap[index] =
            heap[largest];

        heap[largest] =
            temp;

        index = largest;
    }
}

void MaxHeap::insert(SearchResult result)
{
    heap.push_back(result);

    heapifyUp(heap.size() - 1);
}

SearchResult MaxHeap::extractMax()
{
    SearchResult result;

    if (heap.empty())
    {
        return result;
    }

    result = heap[0];

    heap[0] =
        heap[heap.size() - 1];

    heap.pop_back();

    if (!heap.empty())
    {
        heapifyDown(0);
    }

    return result;
}

bool MaxHeap::empty()
{
    return heap.empty();
}

int MaxHeap::size()
{
    return heap.size();
}
