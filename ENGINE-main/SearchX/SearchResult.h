#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include <string>

using namespace std;

struct SearchResult
{
    string fileName;
    int score;

    SearchResult()
    {
        fileName = "";
        score = 0;
    }

    SearchResult(string name, int value)
    {
        fileName = name;
        score = value;
    }
};

#endif
