
#ifndef UI_H
#define UI_H

#include <string>

using namespace std;


class UI
{
public:

    static void clearScreen();

    static void pause();

    static void showHeader(
        string title);

    static void showMainHeader();

    static void showLine();

    static void showMessage(
        string message);
};

#endif
