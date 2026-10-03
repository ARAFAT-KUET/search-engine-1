
#include "HashTable.h"

#include <iostream>

using namespace std;


// =========================================================
// CONSTRUCTOR
// =========================================================

HashTable::HashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = NULL;
    }
}


// =========================================================
// HASH FUNCTION
// =========================================================

int HashTable::hashFunction(string word)
{
    unsigned long hash = 0;

    for (int i = 0; i < word.length(); i++)
    {
        hash = hash * 31 + word[i];
    }

    return hash % TABLE_SIZE;
}


// =========================================================
// FIND WORD
// =========================================================

WordNode* HashTable::findWord(string word)
{
    int index = hashFunction(word);

    WordNode* current = table[index];

    while (current != NULL)
    {
        if (current->word == word)
        {
            return current;
        }

        current = current->next;
    }

    return NULL;
}


// =========================================================
// ADD DOCUMENT
// =========================================================

void HashTable::addDocument(
    WordNode* wordNode,
    string fileName)
{
    DocumentNode* current =
        wordNode->documents;


    // Check whether document already exists
    while (current != NULL)
    {
        if (current->fileName == fileName)
        {
            current->frequency++;
            return;
        }

        current = current->next;
    }


    // Document does not exist
    DocumentNode* newDocument =
        new DocumentNode(fileName);


    // Insert at beginning
    newDocument->next =
        wordNode->documents;

    wordNode->documents =
        newDocument;
}


// =========================================================
// INSERT WORD
// =========================================================

void HashTable::insert(
    string word,
    string fileName)
{
    int index = hashFunction(word);


    WordNode* current =
        table[index];


    // Check whether word already exists
    while (current != NULL)
    {
        if (current->word == word)
        {
            addDocument(current, fileName);
            return;
        }

        current = current->next;
    }


    // Create new word
    WordNode* newWord =
        new WordNode(word);


    // Add document
    addDocument(newWord, fileName);


    // Insert word into bucket
    newWord->next =
        table[index];

    table[index] =
        newWord;
}


// =========================================================
// SEARCH WORD
// =========================================================

bool HashTable::search(string word)
{
    return findWord(word) != NULL;
}


// =========================================================
// DISPLAY WORD INFORMATION
// =========================================================

void HashTable::displayWord(string word)
{
    WordNode* wordNode =
        findWord(word);


    if (wordNode == NULL)
    {
        cout << "Word not found." << endl;
        return;
    }


    cout << endl;
    cout << "Word: " << wordNode->word << endl;

    cout << "Documents:" << endl;


    DocumentNode* current =
        wordNode->documents;


    while (current != NULL)
    {
        cout << "  "
             << current->fileName
             << " -> "
             << current->frequency
             << " time(s)"
             << endl;

        current = current->next;
    }
}


// =========================================================
// DOCUMENT COUNT
// =========================================================

int HashTable::getDocumentCount(string word)
{
    WordNode* wordNode =
        findWord(word);


    if (wordNode == NULL)
    {
        return 0;
    }


    int count = 0;

    DocumentNode* current =
        wordNode->documents;


    while (current != NULL)
    {
        count++;

        current = current->next;
    }


    return count;
}


// =========================================================
// GET FREQUENCY
// =========================================================

int HashTable::getFrequency(
    string word,
    string fileName)
{
    WordNode* wordNode =
        findWord(word);


    if (wordNode == NULL)
    {
        return 0;
    }


    DocumentNode* current =
        wordNode->documents;


    while (current != NULL)
    {
        if (current->fileName == fileName)
        {
            return current->frequency;
        }

        current = current->next;
    }


    return 0;
}


// =========================================================
// DESTRUCTOR
// =========================================================

HashTable::~HashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        WordNode* current =
            table[i];


        while (current != NULL)
        {
            WordNode* nextWord =
                current->next;


            DocumentNode* document =
                current->documents;


            while (document != NULL)
            {
                DocumentNode* nextDocument =
                    document->next;

                delete document;

                document =
                    nextDocument;
            }


            delete current;

            current =
                nextWord;
        }


        table[i] = NULL;
    }
}
