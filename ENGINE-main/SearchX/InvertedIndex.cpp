#include "InvertedIndex.h"

#include <iostream>
#include <cctype>

using namespace std;


// =========================================================
// CONSTRUCTOR
// =========================================================

InvertedIndex::InvertedIndex()
{
    for (int i = 0; i < GROUP_COUNT; i++)
    {
        wordLists[i] = NULL;
    }
}


// =========================================================
// GET ARRAY INDEX
// =========================================================

int InvertedIndex::getIndex(string word)
{
    if (word == "")
    {
        return 26;
    }

    char firstCharacter =
        tolower(word[0]);


    // a - z
    if (firstCharacter >= 'a' &&
        firstCharacter <= 'z')
    {
        return firstCharacter - 'a';
    }


    // Numbers or other characters
    return 26;
}


// =========================================================
// FIND WORD
// =========================================================

WordNode* InvertedIndex::findWord(string word)
{
    int index = getIndex(word);

    WordNode* current =
        wordLists[index];


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

void InvertedIndex::addDocument(
    WordNode* wordNode,
    string fileName)
{
    DocumentNode* current =
        wordNode->documents;


    // Document already exists
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

void InvertedIndex::insert(
    string word,
    string fileName)
{
    int index =
        getIndex(word);


    WordNode* current =
        wordLists[index];


    // Check whether word already exists
    while (current != NULL)
    {
        if (current->word == word)
        {
            addDocument(
                current,
                fileName);

            return;
        }

        current = current->next;
    }


    // Word does not exist
    WordNode* newWord =
        new WordNode(word);


    // Add document information
    addDocument(
        newWord,
        fileName);


    // Insert word at beginning
    newWord->next =
        wordLists[index];

    wordLists[index] =
        newWord;
}


// =========================================================
// SEARCH WORD
// =========================================================

bool InvertedIndex::search(string word)
{
    return findWord(word) != NULL;
}


// =========================================================
// DISPLAY WORD INFORMATION
// =========================================================

void InvertedIndex::displayWord(string word)
{
    WordNode* wordNode =
        findWord(word);


    if (wordNode == NULL)
    {
        cout << "Word not found."
             << endl;

        return;
    }


    cout << endl;

    cout << "Word: "
         << wordNode->word
         << endl;

    cout << "Documents:"
         << endl;


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

int InvertedIndex::getDocumentCount(
    string word)
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

int InvertedIndex::getFrequency(
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

InvertedIndex::~InvertedIndex()
{
    for (int i = 0;
         i < GROUP_COUNT;
         i++)
    {
        WordNode* current =
            wordLists[i];


        while (current != NULL)
        {
            WordNode* nextWord =
                current->next;


            // Delete document list
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


            // Delete word node
            delete current;

            current =
                nextWord;
        }


        wordLists[i] = NULL;
    }
}
