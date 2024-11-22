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

//necesitamos cambiar el bubble sort este por quicksort ajajajaj
void Graph::ordenarIPS(vector<string>& ipIzq, vector<string>& ipDer) {
    for (size_t i = 0; i < ipIzq.size() - 1; ++i) {
        for (size_t j = 0; j < ipIzq.size() - i - 1; ++j) {

            int sizeA = this->getList(ipIzq[j]).size();
            int sizeB = this->getList(ipIzq[j + 1]).size();

            if (sizeA < sizeB) {
                swap(ipIzq[j], ipIzq[j + 1]);
            }
        }
    }
}

void Graph::print(vector<string> ipIzq, vector<string> ipDer, int amount) {

    if (amount > ipIzq.size()){
        amount = ipIzq.size();
    }

    vector<string> procesadas; //pa no imprimirlas 2 veces
    vector<string> tempIP;

    for (int i = 0; i < ipIzq.size(); ++i) {
        if (find(procesadas.begin(), procesadas.end(), ipIzq[i]) == procesadas.end()) {
            tempIP.clear();
            tempIP = this->getList(ipIzq[i]);
            cout << "La IP '" << ipIzq[i] << "' cuenta con " << tempIP.size() << " vertices" << endl;
            procesadas.push_back(ipIzq[i]); //ya no jala
            amount -= 1;
            if (amount == 0){
                break;
            }
        }
    }
}

