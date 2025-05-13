#ifndef CAJERO_H
#define CAJERO_H

#include <string>
using namespace std;

string cargarArchivoCajero(string nArchivo);
bool validarUsuario(string nArchivo, string cedula, string clave);
void nStringArchivo(string nString, string nArchivo);
void registrarUsuario(string nArchivo, string cedula, string clave, string saldo);
string validarCedula();
string validarClave();
string validarSaldo();
bool cedulaExiste(string cedula);
string obtenerSaldoString(string cedula,size_t& posFinal, size_t &posInicial);
void actualizarSaldo(string saldo,size_t posFinal, size_t posInicial, string nArchivo, string retiro="1000");

#endif // CAJERO_H
