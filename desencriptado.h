#ifndef DESENCRIPTADO_H
#define DESENCRIPTADO_H

#include <string>
using namespace std;

string abrirArchivoDesencriptacion(string narch);
string desencriptarMetodo1(string bin, int n);
string desencriptarMetodo2(string bin, int n);
string crearArchivoDesencriptado(string bin, bool mode, string narch = "1");

#endif // DESENCRIPTADO_H
