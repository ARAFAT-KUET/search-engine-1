#include "BST.h"

#include <iostream>

using namespace std;

BST::BST()
{
    root = NULL;
}

BSTNode* BST::insertNode(
    BSTNode* node,
    string word)
{
    if (node == NULL)
    {
        return new BSTNode(word);
    }

    if (word < node->word)
    {
        node->left =
            insertNode(
                node->left,
                word);
    }
    else if (word > node->word)
    {
        node->right =
            insertNode(
                node->right,
                word);
    }

    return node;
}

void BST::insert(string word)
{
    root =
        insertNode(
            root,
            word);
}

bool BST::searchNode(
    BSTNode* node,
    string word)
{
    if (node == NULL)
    {
        return false;
    }

    if (word == node->word)
    {
        return true;
    }

    if (word < node->word)
    {
        return searchNode(
            node->left,
            word);
    }

    return searchNode(
        node->right,
        word);
}

bool BST::search(string word)
{
    return searchNode(
        root,
        word);
}

void BST::inorderTraversal(
    BSTNode* node)
{
    if (node == NULL)
    {
        return;
    }

    inorderTraversal(
        node->left);

    cout << node->word << endl;

    inorderTraversal(
        node->right);
}

void BST::displayInorder()
{
    inorderTraversal(root);
}

void BST::inorderToVector(
    BSTNode* node,
    vector<string> &words)
{
    if (node == NULL)
    {
        return;
    }

    inorderToVector(
        node->left,
        words);

    words.push_back(
        node->word);

    inorderToVector(
        node->right,
        words);
}

vector<string> BST::getVocabulary()
{
    vector<string> words;

    inorderToVector(
        root,
        words);

    return words;
}

int BST::countNodes(
    BSTNode* node)
{
    if (node == NULL)
    {
        return 0;
    }

    return 1
         + countNodes(node->left)
         + countNodes(node->right);
}

int BST::size()
{
    return countNodes(root);
}

void BST::destroyTree(
    BSTNode* node)
{
    if (node == NULL)
    {
        return;
    }

    destroyTree(node->left);

    destroyTree(node->right);

    delete node;
}

BST::~BST()
{
    destroyTree(root);

    root = NULL;
}
