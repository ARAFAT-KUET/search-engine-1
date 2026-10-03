
#include "Graph.h"

#include <iostream>

using namespace std;

Graph::Graph(int numberOfVertices)
{
    vertices = numberOfVertices;

    vertexNames =
        new string[vertices];

    adjacency =
        new EdgeNode*[vertices];

    for (int i = 0;
         i < vertices;
         i++)
    {
        adjacency[i] = NULL;
    }
}

Graph::~Graph()
{
    for (int i = 0;
         i < vertices;
         i++)
    {
        EdgeNode* current =
            adjacency[i];

        while (current != NULL)
        {
            EdgeNode* temp =
                current;

            current =
                current->next;

            delete temp;
        }
    }

    delete[] adjacency;
    delete[] vertexNames;
}

void Graph::setVertexName(
    int vertex,
    string name)
{
    if (vertex < 0 ||
        vertex >= vertices)
    {
        return;
    }

    vertexNames[vertex] =
        name;
}

void Graph::addEdge(
    int source,
    int destination,
    int weight)
{
    if (source < 0 ||
        source >= vertices ||
        destination < 0 ||
        destination >= vertices)
    {
        return;
    }

    EdgeNode* newNode =
        new EdgeNode(
            destination,
            weight);

    newNode->next =
        adjacency[source];

    adjacency[source] =
        newNode;

    EdgeNode* reverseNode =
        new EdgeNode(
            source,
            weight);

    reverseNode->next =
        adjacency[destination];

    adjacency[destination] =
        reverseNode;
}

void Graph::displayGraph()
{
    cout << endl;

    cout << "========================================"
         << endl;

    cout << "             DOCUMENT GRAPH"
         << endl;

    cout << "========================================"
         << endl;

    for (int i = 0;
         i < vertices;
         i++)
    {
        cout << vertexNames[i]
             << " -> ";

        EdgeNode* current =
            adjacency[i];

        while (current != NULL)
        {
            cout << vertexNames[
                current->vertex];

            cout << "("
                 << current->weight
                 << ")";

            if (current->next != NULL)
            {
                cout << " -> ";
            }

            current =
                current->next;
        }

        cout << endl;
    }

    cout << "========================================"
         << endl;
}

void Graph::BFS(int start)
{
    if (start < 0 ||
        start >= vertices)
    {
        return;
    }

    bool* visited =
        new bool[vertices];

    int* queue =
        new int[vertices];

    for (int i = 0;
         i < vertices;
         i++)
    {
        visited[i] = false;
    }

    int front = 0;
    int rear = 0;

    visited[start] = true;

    queue[rear] =
        start;

    rear++;

    cout << endl;

    cout << "BFS Traversal:"
         << endl;

    while (front < rear)
    {
        int currentVertex =
            queue[front];

        front++;

        cout << vertexNames[
            currentVertex]
             << " ";

        EdgeNode* current =
            adjacency[currentVertex];

        while (current != NULL)
        {
            int nextVertex =
                current->vertex;

            if (!visited[nextVertex])
            {
                visited[nextVertex] =
                    true;

                queue[rear] =
                    nextVertex;

                rear++;
            }

            current =
                current->next;
        }
    }

    cout << endl;

    delete[] visited;
    delete[] queue;
}

void Graph::dfsRecursive(
    int vertex,
    bool visited[])
{
    visited[vertex] = true;

    cout << vertexNames[vertex]
         << " ";

    EdgeNode* current =
        adjacency[vertex];

    while (current != NULL)
    {
        int nextVertex =
            current->vertex;

        if (!visited[nextVertex])
        {
            dfsRecursive(
                nextVertex,
                visited);
        }

        current =
            current->next;
    }
}

void Graph::DFS(int start)
{
    if (start < 0 ||
        start >= vertices)
    {
        return;
    }

    bool* visited =
        new bool[vertices];

    for (int i = 0;
         i < vertices;
         i++)
    {
        visited[i] = false;
    }

    cout << endl;

    cout << "DFS Traversal:"
         << endl;

    dfsRecursive(
        start,
        visited);

    cout << endl;

    delete[] visited;
}

void Graph::shortestPath(
    int start,
    int destination)
{
    if (start < 0 ||
        start >= vertices ||
        destination < 0 ||
        destination >= vertices)
    {
        return;
    }

    bool* visited =
        new bool[vertices];

    int* parent =
        new int[vertices];

    int* queue =
        new int[vertices];

    for (int i = 0;
         i < vertices;
         i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }

    int front = 0;
    int rear = 0;

    visited[start] = true;

    queue[rear] =
        start;

    rear++;

    while (front < rear)
    {
        int currentVertex =
            queue[front];

        front++;

        if (currentVertex ==
            destination)
        {
            break;
        }

        EdgeNode* current =
            adjacency[currentVertex];

        while (current != NULL)
        {
            int nextVertex =
                current->vertex;

            if (!visited[nextVertex])
            {
                visited[nextVertex] =
                    true;

                parent[nextVertex] =
                    currentVertex;

                queue[rear] =
                    nextVertex;

                rear++;
            }

            current =
                current->next;
        }
    }

    cout << endl;

    if (!visited[destination])
    {
        cout << "No path exists."
             << endl;
    }
    else
    {
        int* path =
            new int[vertices];

        int pathSize = 0;

        int current =
            destination;

        while (current != -1)
        {
            path[pathSize] =
                current;

            pathSize++;

            current =
                parent[current];
        }

        cout << "Shortest Path:"
             << endl;

        for (int i = pathSize - 1;
             i >= 0;
             i--)
        {
            cout << vertexNames[
                path[i]];

            if (i != 0)
            {
                cout << " -> ";
            }
        }

        cout << endl;

        cout << "Number of edges: "
             << pathSize - 1
             << endl;

        delete[] path;
    }

    delete[] visited;
    delete[] parent;
    delete[] queue;
}
