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
};


#endif
