#ifndef SEARCHINDEX_H
#define SEARCHINDEX_H

#include <string>
#include <vector>

#include "InvertedIndex.h"
#include "TextProcessor.h"
#include "BST.h"
#include "SparseMatrix.h"

using namespace std;


class SearchIndex
{
private:

    InvertedIndex index;

    TextProcessor processor;

    BST vocabulary;


public:

    SearchIndex();

    void addDocument(
        string fileName);

    void buildIndex(
        string fileNames[],
        int documentCount);

    void searchWord(
        string word);

    bool contains(
        string word);

    int getFrequency(
        string word,
        string fileName);

    void displayVocabulary();

    int vocabularySize();

    vector<string> getVocabulary();

    void buildSparseMatrix(
        string fileNames[],
        int documentCount);

    void displaySparseMatrix(
        string fileNames[],
        int documentCount);
};

#endif
