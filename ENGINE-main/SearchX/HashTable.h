#ifndef HASHTABLE_H
#define HASHTABLE_H

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
// HASH TABLE
// =========================================================

class HashTable
{
private:

    static const int TABLE_SIZE = 101;

    WordNode* table[TABLE_SIZE];


    int hashFunction(string word);

    WordNode* findWord(string word);

    void addDocument(
        WordNode* wordNode,
        string fileName);


public:

    HashTable();

    ~HashTable();


    void insert(
        string word,
        string fileName);


    bool search(string word);


    void displayWord(string word);


    int getDocumentCount(string word);


    int getFrequency(
        string word,
        string fileName);
};

#endif
