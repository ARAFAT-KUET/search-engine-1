#include "SearchAlgorithms.h"

using namespace std;

bool SearchAlgorithms::linearSearch(
    vector<string> data,
    string target,
    int &comparisons)
{
    comparisons = 0;

    for (int i = 0;
         i < data.size();
         i++)
    {
        comparisons++;

        if (data[i] == target)
        {
            return true;
        }
    }

    return false;
}

bool SearchAlgorithms::binarySearch(
    vector<string> data,
    string target,
    int &comparisons)
{
    comparisons = 0;

    int left = 0;
    int right = data.size() - 1;

    while (left <= right)
    {
        int middle =
            (left + right) / 2;

        comparisons++;

        if (data[middle] == target)
        {
            return true;
        }

        if (target < data[middle])
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }

    return false;
}

void SearchAlgorithms::sortData(
    vector<string> &data)
{
    for (int i = 0;
         i < data.size() - 1;
         i++)
    {
        for (int j = 0;
             j < data.size() - i - 1;
             j++)
        {
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
