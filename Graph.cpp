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

vector<string> Graph::getList(string key) {
    if (adjacent.find(key) != adjacent.end()) {
        return adjacent[key];
    }
    return {};
}

void Graph::ordenarIPS(vector<string>& ipIzq, vector<string>& ipDer){
    //vector<string> tempIP;
}

void Graph::print(vector<string> ipIzq, vector<string> ipDer){
    vector<string> tempIP;

    for (int i = 0; i < ipIzq.size(); ++i) {
        tempIP.clear();
        tempIP = this->getList(ipIzq[i]);
        if(true){
            cout << "La IP '"<< ipIzq[i] << "' cuenta con " << tempIP.size() << " vertices" << endl;
        }
    }
}
