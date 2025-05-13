#ifndef CAJERO_H
#define CAJERO_H

#include <string>
using namespace std;

bool validarUsuario(string nArchivo, string cedula, string clave);
void registrarUsuario(string nArchivo, string cedula, string clave, string saldo);
string validarCedula();
string validarClave();
string validarSaldo();
bool cedulaExiste(string cedula);
#endif // CAJERO_H
