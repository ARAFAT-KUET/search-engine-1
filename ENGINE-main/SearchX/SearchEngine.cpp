
#include "SearchEngine.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;


// =========================================================
// CONSTRUCTOR
// =========================================================

SearchEngine::SearchEngine()
{
    fileNames[0] = "dsa.txt";
    fileNames[1] = "cpp.txt";
    fileNames[2] = "algorithms.txt";
    fileNames[3] = "database.txt";

    documentCount = 4;

    documentGraph = NULL;
}


// =========================================================
// DESTRUCTOR
// =========================================================

SearchEngine::~SearchEngine()
{
    if (documentGraph != NULL)
    {
        delete documentGraph;

        documentGraph = NULL;
    }
}


// =========================================================
// BUILD SEARCH INDEX
// =========================================================

void SearchEngine::buildIndex()
{
    searchIndex.buildIndex(
        fileNames,
        documentCount);

    buildDocumentGraph();
}


// =========================================================
// SEARCH
// =========================================================

void SearchEngine::search(string query)
{
    TextProcessor processor;

    vector<string> queryWords =
        processor.processQuery(query);


    if (queryWords.empty())
    {
        UI::showMessage(
            "No valid search words found.");

        return;
    }


    // Store search history
    history.push(query);


    // Store recent search
    recentSearches.pushBack(query);


    MaxHeap resultHeap;

    bool found = false;


    for (int i = 0;
         i < documentCount;
         i++)
    {
        int totalScore = 0;


        for (int j = 0;
             j < queryWords.size();
             j++)
        {
            int frequency =
                searchIndex.getFrequency(
                    queryWords[j],
                    fileNames[i]);


            totalScore += frequency;
        }


        if (totalScore > 0)
        {
            SearchResult result(
                fileNames[i],
                totalScore);


            resultHeap.insert(result);

            found = true;
        }
    }


    UI::showHeader(
        "SEARCH RESULTS");


    cout << "Query: "
         << query
         << endl;


    cout << "Cleaned words: ";


    for (int i = 0;
         i < queryWords.size();
         i++)
    {
        cout << queryWords[i];


        if (i + 1 < queryWords.size())
        {
            cout << ", ";
        }
    }


    cout << endl;


    UI::showLine();


    if (!found)
    {
        cout << endl;

        cout << "No documents found."
             << endl;

        UI::showLine();

        return;
    }


    int resultNumber = 1;


    while (!resultHeap.empty())
    {
        SearchResult result =
            resultHeap.extractMax();


        cout << endl;

        cout << resultNumber
             << ". "
             << result.fileName
             << endl;


        cout << "   Score: "
             << result.score
             << endl;


        resultNumber++;
    }


    cout << endl;

    UI::showLine();
}


// =========================================================
// SHOW VOCABULARY
// =========================================================

void SearchEngine::showVocabulary()
{
    UI::showHeader(
        "SEARCHX VOCABULARY");


    cout << endl;


    cout << "Total unique words: "
         << searchIndex.vocabularySize()
         << endl;


    cout << endl;


    cout << "Words in alphabetical order:"
         << endl;


    UI::showLine();


    searchIndex.displayVocabulary();


    UI::showLine();


    UI::pause();
}


// =========================================================
// SEARCH ALGORITHM MENU
// =========================================================

void SearchEngine::searchAlgorithmMenu()
{
    vector<string> vocabulary =
        searchIndex.getVocabulary();


    if (vocabulary.empty())
    {
        UI::showMessage(
            "Vocabulary is empty.");

        return;
    }


    while (true)
    {
        UI::showHeader(
            "SEARCH ALGORITHMS");


        cout << "1. Linear Search"
             << endl;

        cout << "2. Binary Search"
             << endl;

        cout << "3. Hash Search"
             << endl;

        cout << "4. Back"
             << endl;


        UI::showLine();


        string choice;

        cout << "Enter choice: ";

        getline(cin, choice);


        if (choice == "4")
        {
            return;
        }


        if (choice != "1" &&
            choice != "2" &&
            choice != "3")
        {
            cout << endl;

            cout << "Invalid choice."
                 << endl;

            UI::pause();

            continue;
        }


        string word;


        cout << "Enter word: ";

        getline(cin, word);


        TextProcessor processor;


        word =
            processor.cleanWord(word);


        if (word == "")
        {
            cout << endl;

            cout << "Invalid word."
                 << endl;

            UI::pause();

            continue;
        }


        // -------------------------------------------------
        // LINEAR SEARCH
        // -------------------------------------------------

        if (choice == "1")
        {
            int comparisons = 0;


            bool found =
                algorithms.linearSearch(
                    vocabulary,
                    word,
                    comparisons);


            cout << endl;


            cout << "Algorithm: Linear Search"
                 << endl;


            cout << "Result: ";


            if (found)
            {
                cout << "Found"
                     << endl;
            }
            else
            {
                cout << "Not Found"
                     << endl;
            }


            cout << "Comparisons: "
                 << comparisons
                 << endl;


            UI::pause();
        }


        // -------------------------------------------------
        // BINARY SEARCH
        // -------------------------------------------------

        else if (choice == "2")
        {
            int comparisons = 0;


            vector<string> sortedVocabulary =
                vocabulary;


            algorithms.sortData(
                sortedVocabulary);


            bool found =
                algorithms.binarySearch(
                    sortedVocabulary,
                    word,
                    comparisons);


            cout << endl;


            cout << "Algorithm: Binary Search"
                 << endl;


            cout << "Result: ";


            if (found)
            {
                cout << "Found"
                     << endl;
            }
            else
            {
                cout << "Not Found"
                     << endl;
            }


            cout << "Comparisons: "
                 << comparisons
                 << endl;


            UI::pause();
        }


        // -------------------------------------------------
        // HASH SEARCH
        // -------------------------------------------------

        else if (choice == "3")
        {
            bool found =
                searchIndex.contains(word);


            cout << endl;


            cout << "Algorithm: Hash Search"
                 << endl;


            cout << "Result: ";


            if (found)
            {
                cout << "Found"
                     << endl;
            }
            else
            {
                cout << "Not Found"
                     << endl;
            }


            cout << "Average Time: O(1)"
                 << endl;


            UI::pause();
        }
    }
}


// =========================================================
// SORTING ALGORITHM MENU
// =========================================================

void SearchEngine::sortingAlgorithmMenu()
{
    vector<string> vocabulary =
        searchIndex.getVocabulary();


    if (vocabulary.empty())
    {
        UI::showMessage(
            "Vocabulary is empty.");

        return;
    }


    while (true)
    {
        UI::showHeader(
            "SORTING ALGORITHMS");


        cout << "1. Bubble Sort"
             << endl;

        cout << "2. Selection Sort"
             << endl;

        cout << "3. Insertion Sort"
             << endl;

        cout << "4. Back"
             << endl;


        UI::showLine();


        string choice;

        cout << "Enter choice: ";

        getline(cin, choice);


        if (choice == "4")
        {
            return;
        }


        if (choice != "1" &&
            choice != "2" &&
            choice != "3")
        {
            cout << endl;

            cout << "Invalid choice."
                 << endl;

            UI::pause();

            continue;
        }


        vector<string> data =
            vocabulary;


        int comparisons = 0;


        // -------------------------------------------------
        // BUBBLE SORT
        // -------------------------------------------------

        if (choice == "1")
        {
            sorter.bubbleSort(
                data,
                comparisons);


            cout << endl;


            cout << "Algorithm: Bubble Sort"
                 << endl;
        }


        // -------------------------------------------------
        // SELECTION SORT
        // -------------------------------------------------

        else if (choice == "2")
        {
            sorter.selectionSort(
                data,
                comparisons);


            cout << endl;


            cout << "Algorithm: Selection Sort"
                 << endl;
        }


        // -------------------------------------------------
        // INSERTION SORT
        // -------------------------------------------------

        else if (choice == "3")
        {
            sorter.insertionSort(
                data,
                comparisons);


            cout << endl;


            cout << "Algorithm: Insertion Sort"
                 << endl;
        }


        cout << "Comparisons: "
             << comparisons
             << endl;


        cout << endl;


        cout << "Sorted vocabulary:"
             << endl;


        UI::showLine();


        for (int i = 0;
             i < data.size();
             i++)
        {
            cout << i + 1
                 << ". "
                 << data[i]
                 << endl;
        }


        UI::showLine();


        UI::pause();
    }
}


// =========================================================
// BUILD DOCUMENT GRAPH
// =========================================================

void SearchEngine::buildDocumentGraph()
{
    if (documentGraph != NULL)
    {
        delete documentGraph;

        documentGraph = NULL;
    }


    documentGraph =
        new Graph(documentCount);


    TextProcessor processor;


    vector<string> documents[4];


    for (int i = 0;
         i < documentCount;
         i++)
    {
        string path =
            "documents/" + fileNames[i];


        documents[i] =
            processor.processDocument(path);


        documentGraph->setVertexName(
            i,
            fileNames[i]);
    }


    for (int i = 0;
         i < documentCount;
         i++)
    {
        for (int j = i + 1;
             j < documentCount;
             j++)
        {
            int commonWords = 0;


            for (int a = 0;
                 a < documents[i].size();
                 a++)
            {
                bool alreadyCounted =
                    false;


                for (int previous = 0;
                     previous < a;
                     previous++)
                {
                    if (documents[i][previous] ==
                        documents[i][a])
                    {
                        alreadyCounted =
                            true;

                        break;
                    }
                }


                if (alreadyCounted)
                {
                    continue;
                }


                for (int b = 0;
                     b < documents[j].size();
                     b++)
                {
                    if (documents[i][a] ==
                        documents[j][b])
                    {
                        commonWords++;

                        break;
                    }
                }
            }


            if (commonWords > 0)
            {
                documentGraph->addEdge(
                    i,
                    j,
                    commonWords);
            }
        }
    }
}


// =========================================================
// GRAPH MENU
// =========================================================

void SearchEngine::graphMenu()
{
    if (documentGraph == NULL)
    {
        UI::showMessage(
            "Document graph is not available.");

        return;
    }


    while (true)
    {
        UI::showHeader(
            "DOCUMENT GRAPH MENU");


        cout << "1. Display Graph"
             << endl;

        cout << "2. BFS"
             << endl;

        cout << "3. DFS"
             << endl;

        cout << "4. Shortest Path"
             << endl;

        cout << "5. Back"
             << endl;


        UI::showLine();


        string choice;

        cout << "Enter choice: ";

        getline(cin, choice);


        // -------------------------------------------------
        // DISPLAY GRAPH
        // -------------------------------------------------

        if (choice == "1")
        {
            documentGraph->displayGraph();

            UI::pause();
        }


        // -------------------------------------------------
        // BFS
        // -------------------------------------------------

        else if (choice == "2")
        {
            cout << endl;

            cout << "Starting document:"
                 << endl;


            for (int i = 0;
                 i < documentCount;
                 i++)
            {
                cout << i + 1
                     << ". "
                     << fileNames[i]
                     << endl;
            }


            cout << "Enter choice: ";


            string input;

            getline(cin, input);


            int start;


            try
            {
                start =
                    stoi(input) - 1;
            }
            catch (...)
            {
                cout << endl;

                cout << "Invalid document choice."
                     << endl;

                UI::pause();

                continue;
            }


            if (start < 0 ||
                start >= documentCount)
            {
                cout << endl;

                cout << "Invalid document choice."
                     << endl;

                UI::pause();

                continue;
            }


            documentGraph->BFS(start);

            UI::pause();
        }


        // -------------------------------------------------
        // DFS
        // -------------------------------------------------

        else if (choice == "3")
        {
            cout << endl;

            cout << "Starting document:"
                 << endl;


            for (int i = 0;
                 i < documentCount;
                 i++)
            {
                cout << i + 1
                     << ". "
                     << fileNames[i]
                     << endl;
            }


            cout << "Enter choice: ";


            string input;

            getline(cin, input);


            int start;


            try
            {
                start =
                    stoi(input) - 1;
            }
            catch (...)
            {
                cout << endl;

                cout << "Invalid document choice."
                     << endl;

                UI::pause();

                continue;
            }


            if (start < 0 ||
                start >= documentCount)
            {
                cout << endl;

                cout << "Invalid document choice."
                     << endl;

                UI::pause();

                continue;
            }


            documentGraph->DFS(start);

            UI::pause();
        }


        // -------------------------------------------------
        // SHORTEST PATH
        // -------------------------------------------------

        else if (choice == "4")
        {
            cout << endl;

            cout << "Available documents:"
                 << endl;


            for (int i = 0;
                 i < documentCount;
                 i++)
            {
                cout << i + 1
                     << ". "
                     << fileNames[i]
                     << endl;
            }


            cout << endl;


            string first;

            string second;


            cout << "Enter starting document: ";

            getline(cin, first);


            cout << "Enter destination document: ";

            getline(cin, second);


            int start;

            int destination;


            try
            {
                start =
                    stoi(first) - 1;

                destination =
                    stoi(second) - 1;
            }
            catch (...)
            {
                cout << endl;

                cout << "Invalid document choice."
                     << endl;

                UI::pause();

                continue;
            }


            if (start < 0 ||
                start >= documentCount ||
                destination < 0 ||
                destination >= documentCount)
            {
                cout << endl;

                cout << "Invalid document choice."
                     << endl;

                UI::pause();

                continue;
            }


            documentGraph->shortestPath(
                start,
                destination);


            UI::pause();
        }


        // -------------------------------------------------
        // BACK
        // -------------------------------------------------

        else if (choice == "5")
        {
            return;
        }


        else
        {
            cout << endl;

            cout << "Invalid choice."
                 << endl;

            UI::pause();
        }
    }
}


// =========================================================
// SEARCH HISTORY MENU
// =========================================================

void SearchEngine::historyMenu()
{
    while (true)
    {
        UI::showHeader(
            "SEARCH HISTORY MENU");


        cout << "1. Show History"
             << endl;

        cout << "2. Remove Latest Search"
             << endl;

        cout << "3. Show Latest Search"
             << endl;

        cout << "4. Show History Size"
             << endl;

        cout << "5. Back"
             << endl;


        UI::showLine();


        string choice;

        cout << "Enter choice: ";

        getline(cin, choice);


        if (choice == "1")
        {
            history.display();

            UI::pause();
        }


        else if (choice == "2")
        {
            if (history.empty())
            {
                cout << endl;

                cout << "Search history is empty."
                     << endl;
            }
            else
            {
                string removed =
                    history.pop();


                cout << endl;

                cout << "Removed search: "
                     << removed
                     << endl;
            }


            UI::pause();
        }


        else if (choice == "3")
        {
            if (history.empty())
            {
                cout << endl;

                cout << "Search history is empty."
                     << endl;
            }
            else
            {
                cout << endl;

                cout << "Latest search: "
                     << history.peek()
                     << endl;
            }


            UI::pause();
        }


        else if (choice == "4")
        {
            cout << endl;

            cout << "Number of searches: "
                 << history.size()
                 << endl;


            UI::pause();
        }


        else if (choice == "5")
        {
            return;
        }


        else
        {
            cout << endl;

            cout << "Invalid choice."
                 << endl;

            UI::pause();
        }
    }
}


// =========================================================
// RECENT SEARCH MENU
// =========================================================

void SearchEngine::recentSearchMenu()
{
    while (true)
    {
        UI::showHeader(
            "RECENT SEARCHES");


        cout << "1. Show Recent Searches"
             << endl;

        cout << "2. Remove Oldest Search"
             << endl;

        cout << "3. Remove Latest Search"
             << endl;

        cout << "4. Show Recent Search Count"
             << endl;

        cout << "5. Back"
             << endl;


        UI::showLine();


        string choice;

        cout << "Enter choice: ";

        getline(cin, choice);


        if (choice == "1")
        {
            recentSearches.display();

            UI::pause();
        }


        else if (choice == "2")
        {
            if (recentSearches.empty())
            {
                cout << endl;

                cout << "Recent search list is empty."
                     << endl;
            }
            else
            {
                cout << endl;

                cout << "Removed oldest search: "
                     << recentSearches.popFront()
                     << endl;
            }


            UI::pause();
        }


        else if (choice == "3")
        {
            if (recentSearches.empty())
            {
                cout << endl;

                cout << "Recent search list is empty."
                     << endl;
            }
            else
            {
                cout << endl;

                cout << "Removed latest search: "
                     << recentSearches.popBack()
                     << endl;
            }


            UI::pause();
        }


        else if (choice == "4")
        {
            cout << endl;

            cout << "Recent search count: "
                 << recentSearches.size()
                 << endl;


            UI::pause();
        }


        else if (choice == "5")
        {
            return;
        }


        else
        {
            cout << endl;

            cout << "Invalid choice."
                 << endl;

            UI::pause();
        }
    }
}


// =========================================================
// SPARSE MATRIX MENU
// =========================================================

void SearchEngine::sparseMatrixMenu()
{
    UI::showHeader(
        "DOCUMENT-TERM SPARSE MATRIX");


    searchIndex.displaySparseMatrix(
        fileNames,
        documentCount);


    UI::pause();
}

