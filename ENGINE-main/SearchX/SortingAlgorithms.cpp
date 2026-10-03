
#include "SortingAlgorithms.h"

using namespace std;

void SortingAlgorithms::bubbleSort(
    vector<string> &data,
    int &comparisons)
{
    comparisons = 0;

    for (int i = 0;
         i < data.size() - 1;
         i++)
    {
        for (int j = 0;
             j < data.size() - i - 1;
             j++)
        {
            comparisons++;

            if (data[j] > data[j + 1])
            {
                string temp =
                    data[j];

                data[j] =
                    data[j + 1];

                data[j + 1] =
                    temp;
            }
        }
    }
}

void SortingAlgorithms::selectionSort(
    vector<string> &data,
    int &comparisons)
{
    comparisons = 0;

    for (int i = 0;
         i < data.size() - 1;
         i++)
    {
        int minimum = i;

        for (int j = i + 1;
             j < data.size();
             j++)
        {
            comparisons++;

            if (data[j] < data[minimum])
            {
                minimum = j;
            }
        }

        if (minimum != i)
        {
            string temp =
                data[i];

            data[i] =
                data[minimum];

            data[minimum] =
                temp;
        }
    }
}

void SortingAlgorithms::insertionSort(
    vector<string> &data,
    int &comparisons)
{
    comparisons = 0;

    for (int i = 1;
         i < data.size();
         i++)
    {
        string key =
            data[i];

        int j = i - 1;

        while (j >= 0)
        {
            comparisons++;

            if (data[j] <= key)
            {
                break;
            }

            data[j + 1] =
                data[j];

            j--;
        }

        data[j + 1] =
            key;
    }
}
