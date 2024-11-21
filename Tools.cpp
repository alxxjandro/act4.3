#include "Tools.h"
#include <iostream>
#include <fstream>
using namespace std;

// ~ ~ ~ Esta parte del codigo es nomas para generar una bitacora con pares de IP's random

void Tools::randomizarBitacora() {
    srand(time(0)); //poner la semillita para el index random
    vector<string> documento; // para guardar las ips solas
    vector<string> documentoFinal; // para guardar pares de ip's random

    Tools::almacenarVector("../bitacora.txt", documento);
    int size = documento.size();

    //dejar  solamenta las ip's
    for (string &line : documento) {
        getIP(line);
    }

    for (string &line : documento) {
        string newLine = line + " - " + setRandomPair(line, documento);
        documentoFinal.push_back(newLine);
    }
    crearArchivo(documentoFinal);
}

string Tools::setRandomPair(string& IP, vector<string> documento){
    string randomIP;
    do {
        randomIP = documento[getRandomIndex(documento.size())];
    } while (randomIP == IP);

    return randomIP;
}

int Tools::getRandomIndex(int size){
    return rand() % size + 1;
}


string Tools::getIP(string &linea){
    char *ptrAux = &linea[0];
    int contador = 0;
    string lineaTemp;

    for (int i = 0; i < linea.length(); ++i) {
        if (*ptrAux == ' '){
            contador++;
            if (contador == 3){
                lineaTemp = linea.substr(i+1);
                break;
            }
        }
        ptrAux++;
    }
    linea = lineaTemp.substr(0, Tools::devolverIndexToken(lineaTemp));
    return linea;
}

int Tools::devolverIndexToken(string &linea) {
    char *ptrAux = &linea[0];
    for (int i = 0; i < linea.length(); ++i) {
        if (*ptrAux == ':'){
            return i;
        }
        ptrAux++;
    }
    return -1;
}

void Tools::almacenarVector(string rutaDocumento,vector<string>& almacen ) {
    ifstream archivo(rutaDocumento);
    string linea;
    while(getline(archivo,linea)){
        almacen.push_back(linea);
    }
    archivo.close();
}

void Tools::crearArchivo(vector<string> documento){
    ofstream result("../BitacoraRandom.txt");
    for (string line : documento) {
        result << line  << endl;
    }
}