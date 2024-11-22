#include <iostream>
#include <vector>
#include "Graph.h"
#include "Tools.h"
using namespace std;

int main() {

    /* Con esta funcion creamos "BitacoraRandom.txt", y esa fue la base para la lista de adyacencia
     * si descomenta esa linea, cada que corra el codigo se hace un nuevo documento con dif ip's */
    //Tools::randomizarBitacora();

    //cargar el doc con las ips random y separarlas en dif vectores
    vector<string> ips;
    vector<string> ipIzq, ipDer;
    Tools::almacenarVector("../BitacoraRandom.txt", ips);

    //dividir la ip de entrada y salida
    for (string ip : ips){
        Tools::splitIPS(ip,ipIzq,ipDer);
    }

    //crear un grafo y agregar todas las ips
    Graph test;
    for (int i = 0; i < ips.size(); ++i) {
        test.addEdge(ipIzq[i],ipDer[i]);
    }

    test.print(ipIzq,ipDer);
}





