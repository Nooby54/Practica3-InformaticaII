#ifndef ENCRIPTADO_H
#define ENCRIPTADO_H

#include <string>
using namespace std;

string abrirArchivoEncriptacion(string narch);
string encriptacionMetodo1(string bin, int n);
string encriptacionMetodo2(string bin, int n);
void crearArchivoEncriptado(string bin,string narch);

#endif // ENCRIPTADO_H
