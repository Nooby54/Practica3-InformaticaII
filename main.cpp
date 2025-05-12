#include <bitset>
#include <iostream>
#include <fstream>
#include <sstream>

#include "encriptado.h"
#include "desencriptado.h"

using namespace std;

int main()
{
    string bin = abrirArchivoEncriptacion("../../base.txt");

    unsigned int semilla = 0;
    while (semilla <= 0 || semilla > bin.length())
    {
        cout << "Ingrese la semilla: ";
        cin >> semilla;
        if (semilla <= 0 || semilla > bin.length())
            cout << "La semilla debe ser mayor que 0 y menor que " << bin.length() << endl;
    }
    cout << bin;
    cout << endl << "metodo1" << endl;
    cout << "\n\n" << encriptacionMetodo1(bin, semilla) << endl;
    cout << endl << "metodo2" << endl << (encriptacionMetodo2(bin, semilla));

    crearArchivoEncriptado(encriptacionMetodo1(bin, semilla));

    cout << endl << "Des met 2" << endl;
    cout << (desencriptarMetodo2(bin, semilla));

    return 0;
}
