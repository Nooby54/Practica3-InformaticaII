#include <iostream>

#include "encriptado.h"
#include "desencriptado.h"
#include "cajero.h"

using namespace std;

int main()
{
    // Seleccionar encriptador, desencriptador o cajero
    unsigned int modoPrincipal = 0;
    cout << "Ingrese 1 si quiere encriptar, 2 si quiere desencriptar o 3 si quiere usar el cajero: ";
    cin >> modoPrincipal;
    string nombreArchivo = "";
    string bin = "";

    if(modoPrincipal == 1){
        do{
            cout << "Ingrese el nombre del archivo a codificar: ";
            cin >> nombreArchivo;
            bin = abrirArchivoEncriptacion(nombreArchivo);
        }while(bin == "1");
        unsigned int semilla = 0;
        while (semilla <= 0 || semilla > bin.length())
        {
            cout << "Ingrese la semilla: ";
            cin >> semilla;
            if (semilla <= 0 || semilla > bin.length())
                cout << "La semilla debe ser mayor que 0 y menor que " << bin.length() << endl;
        }
        unsigned short int modo = 0;
        do{
            cout << "1: Operaciones especiales \n2: Rotacion de cada bloque\nIngrese el metodo que quiere usar para codificar (debe ser 1 o 2): ";
            cin >> modo;
        }while(modo < 1 || modo > 2);

        if(modo == 1){
            bin = encriptacionMetodo1(bin, semilla);
        }
        else{
            bin = encriptacionMetodo2(bin, semilla);
        }
        cout << "Ingrese el nombre del archivo donde se guardara la codificacion: ";
        cin >> nombreArchivo;
        crearArchivoEncriptado(bin,nombreArchivo);
    }
    else if(modoPrincipal == 2){
        do{
            cout << "Ingrese el nombre del archivo a decodificar: ";
            cin >> nombreArchivo;
            bin = abrirArchivoDesencriptacion(nombreArchivo);
        }while(bin == "1");
        unsigned int semilla = 0;
        while (semilla <= 0 || semilla > bin.length())
        {
            cout << "Ingrese la semilla: ";
            cin >> semilla;
            if (semilla <= 0 || semilla > bin.length())
                cout << "La semilla debe ser mayor que 0 y menor que " << bin.length() << endl;
        }
        unsigned short int modo = 0;
        do{
            cout << "Ingrese el metodo que uso para codificar (debe ser 1 o 2): ";
            cin >> modo;
        }while(modo < 1 || modo > 2);

        if(modo == 1){
            bin = desencriptarMetodo1(bin, semilla);
        }
        else{
            bin = desencriptarMetodo2(bin, semilla);
        }
        cout << "Ingrese el nombre del archivo donde se guardara la decodificacion: ";
        cin >> nombreArchivo;
        crearArchivoDesencriptado(bin,true,nombreArchivo);}
    else if(modoPrincipal == 3){
        string cedula = validarCedula(), clave = validarClave();
        if(validarUsuario("../../data/sudo.txt", cedula, clave)){
            cout << "Bienvenido, a continuacion debera registrar al usuario" << endl;
            string nuevaCedula = validarCedula(), nuevaClave = validarClave(), saldo = validarSaldo();
            if(not cedulaExiste(nuevaCedula)){
                cout << "Usuario registrado exitosamente";
                registrarUsuario("../../data/users.txt",nuevaCedula,nuevaClave,saldo);
            }
        }
        else if(validarUsuario("../../data/users.txt", cedula, clave)){
            unsigned short int modo = 0;
            do{
                cout << "Ingrese 1 para consultar saldo o 2 para hacer un retiro: ";
                cin >> modo;
            }while(modo < 1 || modo > 2);
            size_t posInicial = 0, posFinal = 0;
            string saldo = obtenerSaldoString(cedula, posFinal, posInicial);
            if(saldo == "1"){
                cout << "Ocurrio un error al obtener la informacion del archivo";
            }else{
                if(modo == 1){
                    if(stoi(saldo)<1000)
                        cout << "Saldo insuficiente" << endl;
                    else{
                        cout << saldo;
                        actualizarSaldo(saldo,posFinal,posInicial,"../../data/users.txt");}}
                else{
                    string retiro = validarSaldo();
                    if(stoi(saldo) < (stoi(retiro)+1000)){
                        cout << "Saldo insuficiente";
                    }
                    else{
                        actualizarSaldo(saldo,posFinal,posInicial,"../../data/users.txt", to_string(stoi(retiro) + 1000));
                    }
                }}
        }
        else{
            cout << "El usuario no existe";
        }
    }
    else{
        cout << "Ingresaste un modo incorrecto";
    }
    return 0;
}
