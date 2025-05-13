#include <iostream>
#include <bitset>
#include <string>

#include "cajero.h"
#include "encriptado.h"
#include "desencriptado.h"

using namespace std;

string cargarArchivoCajero(string nArchivo){
    string data = abrirArchivoDesencriptacion(nArchivo);
    data = desencriptarMetodo1(data,4);
    data = crearArchivoDesencriptado(data,0);
    return data;
}

bool validarUsuario(string nArchivo, string cedula, string clave){
    string data = cargarArchivoCajero(nArchivo);

    size_t posCedula = 0;
    posCedula = data.find(cedula);
    if (posCedula != string::npos) {
        size_t posFinal = data.find(',', posCedula + 12);
        string claveAlmacenada = data.substr(posCedula + 12, (posFinal - (posCedula + 12)));
        if(claveAlmacenada == clave)
            return true;
    }
    return false;
}
void nStringArchivo(string nString, string nArchivo){
    string bin = "";
    for(unsigned int i = 0; i < nString.length(); i++)
    {
        string bit = bitset<8>(int(nString[i])).to_string();
        bin += bit;
    }
    nString = encriptacionMetodo1(bin,4);
    crearArchivoEncriptado(nString,nArchivo);
}
void registrarUsuario(string nArchivo, string cedula, string clave, string saldo){
    string nString = cargarArchivoCajero(nArchivo) + "\n" + cedula + ", " + clave + ", " + saldo;
    nStringArchivo(nString,nArchivo);
}

string validarCedula(){
    string cedula;
    do{
        cout << "Ingrese la cedula: ";
        cin >> cedula;
    }while(cedula.length() != 10);
    return cedula;
}


string validarClave(){
    string clave;
    bool hola = false;
    do{
        hola = false;
        cout << "Ingrese la clave (no debe contener ,): ";
        cin >> clave;
        for(unsigned int i = 0; i < clave.length();i++){
            if(clave[i] == ','){
                hola = true;
                break;            }
        }

    }while(hola == true);

    return clave;
}

string validarSaldo(){
    int saldo = 0;
    do{
        cout << "Ingrese el saldo o monto a retirar: ";
        cin >> saldo;
    }while(saldo<0);

    return to_string(saldo);
}

bool cedulaExiste(string cedula){
    string data = cargarArchivoCajero("../../data/sudo.txt");

    size_t posCedula = 0;
    posCedula = data.find(cedula, posCedula);
    if (posCedula != string::npos) {
        return true;
    }

    data = cargarArchivoCajero("../../data/users.txt");
    posCedula = 0;

    posCedula = data.find(cedula, posCedula);
    if (posCedula != string::npos) {
        return true;
    }
    return false;
}

string obtenerSaldoString(string cedula,size_t& posFinal, size_t &posInicial){
    string data = cargarArchivoCajero("../../data/users.txt") + "\n";
    posFinal = data.find(cedula);
    if (posFinal != string::npos) {
        posInicial = data.find(',', posFinal + 12);
        posFinal = data.find('\n', posInicial + 1);
        string saldo = data.substr(posInicial+2, ((posFinal -2)- (posInicial)));
        return saldo;
    }
    return "1";
}

void actualizarSaldo(string saldo,size_t posFinal, size_t posInicial, string nArchivo, string retiro){
    string data = cargarArchivoCajero("../../data/users.txt") + "\n";
    saldo = to_string(stoi(saldo) - stoi(retiro));
    data.erase(posInicial+2, ((posFinal -2)- (posInicial)));
    data.insert(posInicial+2,saldo);
    nStringArchivo(data,nArchivo);
}
