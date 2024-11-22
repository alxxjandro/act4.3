#ifndef ACT4_3_GRAPH_H
#define ACT4_3_GRAPH_H
#include <list>
#include <map>
using namespace std;

class Graph {
private:
    int numOfVer;
    list<int>* adjacent;
public:
    Graph(int numOfVer);
    void addEdge(int verticeOne,int verticeTwo);
};


#endif
