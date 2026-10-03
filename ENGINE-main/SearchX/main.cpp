#include <iostream>
#include <string>

#include "SearchEngine.h"
#include "UI.h"

using namespace std;


int main()
{
    SearchEngine searchEngine;


    UI::clearScreen();

    UI::showMainHeader();


    cout << endl;

    cout << "Building search index..."
         << endl;


    searchEngine.buildIndex();


    cout << "Search index built successfully."
         << endl;


    UI::pause();


    while (true)
    {
        UI::clearScreen();

        UI::showMainHeader();


        cout << endl;

        cout << "1. Search"
             << endl;

        cout << "2. Show Vocabulary"
             << endl;

        cout << "3. Search Algorithms"
             << endl;

        cout << "4. Sorting Algorithms"
             << endl;

        cout << "5. Document Graph"
             << endl;

        cout << "6. Search History"
             << endl;

        cout << "7. Recent Searches"
             << endl;

        cout << "8. Sparse Matrix"
             << endl;

        cout << "9. Exit"
             << endl;


        UI::showLine();


        string choice;

        cout << "Enter your choice: ";

        getline(cin, choice);


        if (choice == "1")
        {
            UI::clearScreen();

            UI::showHeader(
                "SEARCH");


            string query;

            cout << "Enter search query: ";

            getline(cin, query);


            searchEngine.search(query);


            UI::pause();
        }


        else if (choice == "2")
        {
            UI::clearScreen();

            searchEngine.showVocabulary();
        }


        else if (choice == "3")
        {
            UI::clearScreen();

            searchEngine.searchAlgorithmMenu();
        }


        else if (choice == "4")
        {
            UI::clearScreen();

            searchEngine.sortingAlgorithmMenu();
        }


        else if (choice == "5")
        {
            UI::clearScreen();

            searchEngine.graphMenu();
        }


        else if (choice == "6")
        {
            UI::clearScreen();

            searchEngine.historyMenu();
        }


        else if (choice == "7")
        {
            UI::clearScreen();

            searchEngine.recentSearchMenu();
        }


        else if (choice == "8")
        {
            UI::clearScreen();

            searchEngine.sparseMatrixMenu();
        }


        else if (choice == "9")
        {
            UI::clearScreen();

            UI::showMainHeader();

            cout << endl;

            cout << "Thank you for using SearchX!"
                 << endl;

            cout << endl;

            break;
        }


        else
        {
            cout << endl;

            cout << "Invalid choice."
                 << endl;

            UI::pause();
        }
    }


    return 0;
}
