#ifndef INVERTEDINDEX_H
#define INVERTEDINDEX_H

#include <string>

using namespace std;


// =========================================================
// DOCUMENT FREQUENCY NODE
// =========================================================

struct DocumentNode
{
    string fileName;
    int frequency;

    DocumentNode* next;

    DocumentNode(string name)
    {
        fileName = name;
        frequency = 1;
        next = NULL;
    }
};


// =========================================================
// WORD NODE
// =========================================================

struct WordNode
{
    string word;

    DocumentNode* documents;

    WordNode* next;

    WordNode(string value)
    {
        word = value;
        documents = NULL;
        next = NULL;
    }
};


// =========================================================
// INVERTED INDEX
// ARRAY + LINKED LIST
// =========================================================

class InvertedIndex
{
private:

    // 0 - 25  = a - z
    // 26      = other characters / numbers
    static const int GROUP_COUNT = 27;

    // Each position stores the head
    // of a linked list of words
    WordNode* wordLists[GROUP_COUNT];


    // Convert first character of a word
    // into an array index
    int getIndex(string word);


    // Find a word inside the
    // appropriate linked list
    WordNode* findWord(string word);


    // Add a document to a word
    // or increase its frequency
    void addDocument(
        WordNode* wordNode,
        string fileName);


public:

    // Constructor
    InvertedIndex();


    // Destructor
    ~InvertedIndex();


    // Insert a word and document
    void insert(
        string word,
        string fileName);


    // Search for a word
    bool search(string word);


    // Display word information
    void displayWord(string word);


    // Get number of documents
    // containing the word
    int getDocumentCount(string word);


    // Get frequency of a word
    // inside a specific document
    int getFrequency(
        string word,
        string fileName);
};

#endif
