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
    cout << bin << endl;
    metodo2(bin,semilla);
    return 0;
}



