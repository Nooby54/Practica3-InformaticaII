#include <fstream>
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
    posCedula = data.find(cedula, posCedula);
    if (posCedula != string::npos) {
        size_t posFinal = data.find(',', posCedula + 12);
        string claveAlmacenada = data.substr(posCedula + 12, (posFinal - (posCedula + 12)));
        if(claveAlmacenada == clave)
            return true;
        else
            return false;
    }
    return false;
}

void registrarUsuario(string nArchivo, string cedula, string clave, string saldo){
    string nString = "\n" + cedula + ", " + clave +", " + saldo;
    string bin = "";
    for(unsigned int i = 0; i < nString.length(); i++)
    {
        string bit = bitset<8>(int(nString[i])).to_string();
        bin += bit;
    }
    nString = abrirArchivoDesencriptacion(nArchivo) + encriptacionMetodo1(bin, 4);

    crearArchivoEncriptado(nString,nArchivo);
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
        cout << "Ingrese el saldo: ";
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
