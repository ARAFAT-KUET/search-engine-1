#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <string>

#include "SearchIndex.h"
#include "Heap.h"
#include "SearchAlgorithms.h"
#include "SortingAlgorithms.h"
#include "Graph.h"
#include "SearchHistory.h"
#include "RecentSearchDeque.h"
#include "UI.h"

using namespace std;

class SearchEngine
{
private:

    SearchIndex searchIndex;

    SearchAlgorithms algorithms;

    SortingAlgorithms sorter;

    string fileNames[4];

    int documentCount;

    Graph* documentGraph;

    SearchHistory history;

    RecentSearchDeque recentSearches;

public:

    SearchEngine();

    ~SearchEngine();

    void buildIndex();

    void search(string query);

    void showVocabulary();

    void searchAlgorithmMenu();

    void sortingAlgorithmMenu();

    void buildDocumentGraph();

    void graphMenu();

    void historyMenu();

    void recentSearchMenu();

    void sparseMatrixMenu();
};

#endif
