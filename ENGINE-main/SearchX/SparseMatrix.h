#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <string>
#include <vector>

using namespace std;


struct SparseNode
{
    int row;
    int column;
    int value;

    SparseNode* next;


    SparseNode(
        int r,
        int c,
        int v)
    {
        row = r;
        column = c;
        value = v;

        next = NULL;
    }
};


class SparseMatrix
{
private:

    SparseNode* head;

    int rows;
    int columns;

public:

    SparseMatrix(
        int numberOfRows,
        int numberOfColumns);

    ~SparseMatrix();

    void insert(
        int row,
        int column,
        int value);

    int getValue(
        int row,
        int column);

    void display();

    void displayNamed(
        vector<string> rowNames,
        vector<string> columnNames);

    int nonZeroCount();
};

#endif
