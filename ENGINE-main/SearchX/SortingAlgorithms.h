
#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include <string>
#include <vector>

using namespace std;

class SortingAlgorithms
{
public:

    void bubbleSort(
        vector<string> &data,
        int &comparisons);

    void selectionSort(
        vector<string> &data,
        int &comparisons);

    void insertionSort(
        vector<string> &data,
        int &comparisons);
};

#endif
