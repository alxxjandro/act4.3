#ifndef ACT4_3_GRAPH_H
#define ACT4_3_GRAPH_H
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Graph {
private:
    unordered_map<string, vector<string>> adjacent;

public:
    Graph();
    void addEdge(string& verticeOne, string& verticeTwo);
    vector<string> getList(string key);
    void print(vector<string> ipIzq, vector<string> ipDer);
    void ordenarIPS(vector<string>& ipIzq, vector<string>& ipDer);
};


#endif
