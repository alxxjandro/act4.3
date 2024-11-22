#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph() {}

void Graph::addEdge(string& verticeOne, string& verticeTwo) {
    for(string vertice : adjacent[verticeOne]){
       if (verticeTwo == vertice){
           return; //para q no se agregue la misma adyacencia dos veces
       }
    }
    adjacent[verticeOne].push_back(verticeTwo);
}

