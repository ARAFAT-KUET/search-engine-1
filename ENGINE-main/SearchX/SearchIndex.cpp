#include "SearchIndex.h"

#include <iostream>
#include <vector>

using namespace std;


SearchIndex::SearchIndex()
{
}


void SearchIndex::addDocument(
    string fileName)
{
    string path =
        "documents/" + fileName;


    vector<string> words =
        processor.processDocument(path);


    for (int i = 0;
         i < words.size();
         i++)
    {
        index.insert(
            words[i],
            fileName);


        vocabulary.insert(
            words[i]);
    }
}


void SearchIndex::buildIndex(
    string fileNames[],
    int documentCount)
{
    for (int i = 0;
         i < documentCount;
         i++)
    {
        addDocument(
            fileNames[i]);
    }
}


void SearchIndex::searchWord(
    string word)
{
    index.displayWord(word);
}


bool SearchIndex::contains(
    string word)
{
    return index.search(word);
}


int SearchIndex::getFrequency(
    string word,
    string fileName)
{
    return index.getFrequency(
        word,
        fileName);
}


void SearchIndex::displayVocabulary()
{
    vocabulary.displayInorder();
}


int SearchIndex::vocabularySize()
{
    return vocabulary.size();
}


vector<string> SearchIndex::getVocabulary()
{
    return vocabulary.getVocabulary();
}


void SearchIndex::buildSparseMatrix(
    string fileNames[],
    int documentCount)
{
    vector<string> words =
        vocabulary.getVocabulary();


    SparseMatrix matrix(
        documentCount,
        words.size());


    for (int i = 0;
         i < documentCount;
         i++)
    {
        for (int j = 0;
             j < words.size();
             j++)
        {
            int frequency =
                getFrequency(
                    words[j],
                    fileNames[i]);


            if (frequency > 0)
            {
                matrix.insert(
                    i,
                    j,
                    frequency);
            }
        }
    }


    vector<string> rowNames;


    for (int i = 0;
         i < documentCount;
         i++)
    {
        rowNames.push_back(
            fileNames[i]);
    }


    matrix.displayNamed(
        rowNames,
        words);


    cout << endl;

    cout << "Total non-zero elements: "
         << matrix.nonZeroCount()
         << endl;

    cout << "Documents: "
         << documentCount
         << endl;

    cout << "Vocabulary terms: "
         << words.size()
         << endl;
}


void SearchIndex::displaySparseMatrix(
    string fileNames[],
    int documentCount)
{
    buildSparseMatrix(
        fileNames,
        documentCount);
}
