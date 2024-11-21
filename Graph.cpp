#include "Graph.h"

Graph::Graph(int numOfVer) {
    this-> numOfVer = numOfVer;
}

void Graph::addEdge(int verticeOne, int verticeTwo) {
    adjacent[verticeOne].push_back(verticeTwo);
    adjacent[verticeTwo].push_back(verticeOne);
}
