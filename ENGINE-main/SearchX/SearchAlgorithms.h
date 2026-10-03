#ifndef SEARCHALGORITHMS_H
#define SEARCHALGORITHMS_H

#include <string>
#include <vector>

using namespace std;

class SearchAlgorithms
{
public:

    bool linearSearch(
        vector<string> data,
        string target,
        int &comparisons);

    bool binarySearch(
        vector<string> data,
        string target,
        int &comparisons);

    void sortData(
        vector<string> &data);
};

#endif
