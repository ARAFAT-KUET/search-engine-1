#include "SparseMatrix.h"

#include <iostream>

using namespace std;


SparseMatrix::SparseMatrix(
    int numberOfRows,
    int numberOfColumns)
{
    head = NULL;

    rows = numberOfRows;

    columns = numberOfColumns;
}


SparseMatrix::~SparseMatrix()
{
    while (head != NULL)
    {
        SparseNode* temp =
            head;

        head =
            head->next;

        delete temp;
    }
}


void SparseMatrix::insert(
    int row,
    int column,
    int value)
{
    if (value == 0)
    {
        return;
    }


    if (row < 0 ||
        row >= rows ||
        column < 0 ||
        column >= columns)
    {
        return;
    }


    SparseNode* current =
        head;


    while (current != NULL)
    {
        if (current->row == row &&
            current->column == column)
        {
            current->value = value;

            return;
        }

        current =
            current->next;
    }


    SparseNode* newNode =
        new SparseNode(
            row,
            column,
            value);


    if (head == NULL)
    {
        head = newNode;

        return;
    }


    SparseNode* previous =
        NULL;

    current =
        head;


    while (current != NULL &&
           (current->row < row ||
           (current->row == row &&
            current->column < column)))
    {
        previous =
            current;

        current =
            current->next;
    }


    if (previous == NULL)
    {
        newNode->next =
            head;

        head =
            newNode;
    }
    else
    {
        newNode->next =
            current;

        previous->next =
            newNode;
    }
}


int SparseMatrix::getValue(
    int row,
    int column)
{
    SparseNode* current =
        head;


    while (current != NULL)
    {
        if (current->row == row &&
            current->column == column)
        {
            return current->value;
        }

        current =
            current->next;
    }


    return 0;
}


void SparseMatrix::display()
{
    cout << endl;

    cout << "========================================"
         << endl;

    cout << "             SPARSE MATRIX"
         << endl;

    cout << "========================================"
         << endl;


    if (head == NULL)
    {
        cout << "Matrix is empty."
             << endl;
    }
    else
    {
        SparseNode* current =
            head;


        cout << "Row\tColumn\tValue"
             << endl;

        cout << "----------------------------------------"
             << endl;


        while (current != NULL)
        {
            cout << current->row
                 << "\t"
                 << current->column
                 << "\t"
                 << current->value
                 << endl;


            current =
                current->next;
        }
    }


    cout << "========================================"
         << endl;
}


void SparseMatrix::displayNamed(
    vector<string> rowNames,
    vector<string> columnNames)
{
    cout << endl;

    cout << "========================================"
         << endl;

    cout << "        DOCUMENT-TERM SPARSE MATRIX"
         << endl;

    cout << "========================================"
         << endl;


    if (head == NULL)
    {
        cout << "Matrix is empty."
             << endl;

        cout << "========================================"
             << endl;

        return;
    }


    SparseNode* current =
        head;


    while (current != NULL)
    {
        cout << "Document: ";

        if (current->row >= 0 &&
            current->row < rowNames.size())
        {
            cout << rowNames[current->row];
        }
        else
        {
            cout << current->row;
        }


        cout << " | Word: ";


        if (current->column >= 0 &&
            current->column < columnNames.size())
        {
            cout << columnNames[current->column];
        }
        else
        {
            cout << current->column;
        }


        cout << " | Frequency: "
             << current->value
             << endl;


        current =
            current->next;
    }


    cout << "========================================"
         << endl;
}


int SparseMatrix::nonZeroCount()
{
    int count = 0;


    SparseNode* current =
        head;


    while (current != NULL)
    {
        count++;

        current =
            current->next;
    }


    return count;
}
