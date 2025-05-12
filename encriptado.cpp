#include <bitset>
#include <fstream>

#include "encriptado.h"

using namespace std;

string abrirArchivoEncriptacion(string narch)
{
    ifstream file;
    file.open(narch);
    if (!file.is_open())
        return "1";
    string bin = "";
    while (file.good())
    {
        string bit = bitset<8>(int(file.get())).to_string();
        if (file.good())
            bin += bit;
    }
    file.close();
    return bin;
}

string encriptacionMetodo1(string bin, int n)
{
    string nString = "";
    for (int i = 0; i < n; i++)
        nString += bin[i] ^ 1;

    unsigned int ceros = 0, unos = 0, multiplo = ((bin.length() / n) * n);
    for (unsigned int i = 0; i < multiplo; i++)
    {
        if (bin[i] == '1')
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

string encriptacionMetodo2(string bin, int n)
{
    string nString = "";
    unsigned int multiplo = ((bin.length() / n) * n);
    for (unsigned int t = 0; t < multiplo; t += n)
    {
        nString += bin[t + n - 1];
        for (int r = 0; r < n - 1; r++)
            nString += bin[t + r];
    }

    n = bin.length() - multiplo;
    if (n != 0)
    {
        nString += bin[multiplo + n - 1];
        for (int r = 0; r < n - 1; r++)
            nString += bin[multiplo + r];
    }
    return nString;
}

void crearArchivoEncriptado(string bin,string narch)
{
    ofstream file;
    file.open(narch);
    file << bin;
    file.close();
}
