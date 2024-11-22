#ifndef ACT4_3_TOOLS_H
#define ACT4_3_TOOLS_H
#include <string>
#include <vector>
using namespace std;

class Tools {
public:
    void static randomizarBitacora();
    void static almacenarVector(string rutaDocumento, vector<string>& almacen);
    void static splitIPS(string origen, vector<string>& izq, vector<string>& der);
private:
    string static getIP(string& line);
    int static devolverIndexToken(string &linea);
    int static getRandomIndex(int size);
    string static setRandomPair(string& IP, vector<string> documento);
    void static crearArchivo(vector<string> documento);

};


#endif
