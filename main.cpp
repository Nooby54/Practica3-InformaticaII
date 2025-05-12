#include <bitset>
#include <iostream>
#include <fstream>
#include <sstream>

#include "encriptado.h"

using namespace std;

int main()
{
    string bin = abrirArchivo("../../base.txt");

    int semilla = 0;
    cout << "Ingrese la semilla: ";
    cin >> semilla;
    if(semilla < 0 || semilla > bin.length())
        cout << "La semilla debe ser mayor que 0 y menor que " << bin.length() << endl;
    imprimir(bin);
    cout << endl << "metodo1" << endl;
    imprimir(metodo1(bin,semilla));
    cout << endl << "metodo2" << endl;
    imprimir(metodo2(bin,semilla));
    return 0;
}



