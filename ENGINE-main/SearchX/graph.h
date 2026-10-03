
#ifndef GRAPH_H
#define GRAPH_H

#include <string>

using namespace std;

struct EdgeNode
{
    int vertex;
    int weight;

    EdgeNode* next;

    EdgeNode(int v, int w)
    {
        vertex = v;
        weight = w;
        next = NULL;
    }
};

class Graph
{
private:

    int vertices;

    string* vertexNames;

    EdgeNode** adjacency;

    void dfsRecursive(
        int vertex,
        bool visited[]);

public:

    Graph(int numberOfVertices);

    ~Graph();

    void setVertexName(
        int vertex,
        string name);

    void addEdge(
        int source,
        int destination,
        int weight);

    void displayGraph();

    void BFS(int start);

    void DFS(int start);

    void shortestPath(
        int start,
        int destination);
};

#endif
