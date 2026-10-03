
#include "UI.h"

#include <iostream>
#include <cstdlib>

using namespace std;


void UI::clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void UI::pause()
{
    cout << endl;

    cout << "Press Enter to continue...";

    string input;

    getline(cin, input);
}


void UI::showLine()
{
    cout << "============================================="
         << endl;
}


void UI::showHeader(
    string title)
{
    cout << endl;

    showLine();

    cout << "              "
         << title
         << endl;

    showLine();
}


void UI::showMainHeader()
{
    cout << endl;

    showLine();

    cout << "                 SEARCHX"
         << endl;

    cout << "          C++ MINI SEARCH ENGINE"
         << endl;

    showLine();
}


void UI::showMessage(
    string message)
{
    cout << endl;

    cout << message
         << endl;
}
