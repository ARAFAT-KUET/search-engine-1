#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <string>
#include <vector>

using namespace std;

class TextProcessor
{
public:

    string cleanWord(string word);

    vector<string> processDocument(string filePath);

    vector<string> processQuery(string query);
};

#endif
