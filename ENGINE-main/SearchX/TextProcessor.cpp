#include "TextProcessor.h"

#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

string TextProcessor::cleanWord(string word)
{
    string cleaned = "";

    for (int i = 0; i < word.length(); i++)
    {
        char ch = word[i];

        ch = tolower(ch);

        if (isalnum(ch))
        {
            cleaned += ch;
        }
    }

    return cleaned;
}

vector<string> TextProcessor::processDocument(string filePath)
{
    ifstream file(filePath);

    vector<string> words;

    if (!file)
    {
        return words;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string word;

        while (ss >> word)
        {
            string cleaned = cleanWord(word);

            if (cleaned != "")
            {
                words.push_back(cleaned);
            }
        }
    }

    file.close();

    return words;
}

vector<string> TextProcessor::processQuery(string query)
{
    vector<string> words;

    stringstream ss(query);

    string word;

    while (ss >> word)
    {
        string cleaned = cleanWord(word);

        if (cleaned != "")
        {
            words.push_back(cleaned);
        }
    }

    return words;
}
