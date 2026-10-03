#ifndef BST_H
#define BST_H

#include <string>
#include <vector>

using namespace std;

struct BSTNode
{
    string word;

    BSTNode* left;
    BSTNode* right;

    BSTNode(string value)
    {
        word = value;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:

    BSTNode* root;

    BSTNode* insertNode(
        BSTNode* node,
        string word);

    bool searchNode(
        BSTNode* node,
        string word);

    void inorderTraversal(
        BSTNode* node);

    void inorderToVector(
        BSTNode* node,
        vector<string> &words);

    int countNodes(
        BSTNode* node);

    void destroyTree(
        BSTNode* node);

public:

    BST();

    ~BST();

    void insert(string word);

    bool search(string word);

    void displayInorder();

    vector<string> getVocabulary();

    int size();
};

#endif
