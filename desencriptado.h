#ifndef DESENCRIPTADO_H
#define DESENCRIPTADO_H

#include <string>
using namespace std;

string abrirArchivoDesencriptacion(string narch);
string desencriptarMetodo1(string bin, int n);
string desencriptarMetodo2(string bin, int n);
void crearArchivoDesencriptado(string bin,string narch);
#endif // DESENCRIPTADO_H
