#include <cmath>
#include <fstream>

#include "desencriptado.h"

using namespace std;

string abrirArchivoDesencriptacion(string narch)
{
    ifstream file;
    file.open(narch);
    if (!file.is_open())
        return "1";
    string bin = "";
    while (file.good())
    {
        char bit = char(file.get());
        if (file.good())
            bin += bit;
    }
    file.close();
    return bin;
}

string desencriptarMetodo1(string bin, int n)
{
    string nString = "";
    for (int i = 0; i < n; i++)
        nString += bin[i] ^ 1;

    unsigned int ceros = 0, unos = 0, multiplo = ((bin.length() / n) * n);
    for (unsigned int i = 0; i < multiplo; i++)
    {
        if (nString[i] == '1')
            unos += 1;
        else
            ceros += 1;

        if ((i + 1) % n == 0 && i != 0 && (i + n) < bin.length())
        {
            for (int t = 1; t <= n; t++)
            {
                if (unos == ceros || (ceros > unos && t % 2 == 0) || (ceros < unos && t % 3 == 0))
                    nString += bin[t + i] ^ 1;
                else
                    nString += bin[t + i];
            }
            unos = 0;
            ceros = 0;
        }
    }
    n = bin.length() - multiplo;
    for (int t = 0; t < n; t++)
    {
        if (unos == ceros || (ceros > unos && (t + 1) % 2 == 0) || (ceros < unos && (t + 1) % 3 == 0))
            nString += bin[t + multiplo] ^ 1;
        else
            nString += bin[t + multiplo];
    }
    return nString;
}

string desencriptarMetodo2(string bin, int n)
{
    string nString = "";
    unsigned int multiplo = ((bin.length() / n) * n);
    for (unsigned int t = 0; t < multiplo; t += n)
    {
        for (int r = 1; r < n ; r++)
            nString += bin[t + r];
        nString += bin[t];
    }

    n = bin.length() - multiplo;
    if (n != 0)
    {
        for (int r = 0; r < n - 1; r++)
            nString += bin[multiplo + r];
        nString += bin[multiplo + n - 1];
    }
    return nString;
}

string crearArchivoDesencriptado(string bin, bool mode, string narch)
{
    ofstream file;
    int decimal = 0, potencia = 7;
    string nString = "";
    for(unsigned int i=0;i<bin.length();i++){

        if(bin[i]=='1'){
            decimal += pow(2, potencia);
        }

        potencia--;
        if(potencia + 1 ==0){
            nString += char(decimal);
            decimal = 0;
            potencia = 7;
        }
    }
    if(mode == true){
        file.open(narch);
        file << nString;
        file.close();
        return "0";
    }
    return nString;
}
