#include <iostream>

#include "encriptado.h"
#include "desencriptado.h"

using namespace std;

int main()
{
    // Seleccionar encriptador, desencriptador o cajero
    unsigned int modoPrincipal = 0;
    cout << "Ingrese 0 si quiere encriptar, 1 si quiere desencriptar o 2 si quiere usar el cajero: ";
    cin >> modoPrincipal;
    string nombreArchivo = "";
    string bin = "";
    if(modoPrincipal == 0){
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
            cout << "Ingrese el metodo que quiere usar para codificar (debe ser 1 o 2): ";
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
    else if(modoPrincipal == 1){
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
        crearArchivoDesencriptado(bin,nombreArchivo);}
    else{
        //Cajero
        cout << "Cajero";
    }
    return 0;
}
