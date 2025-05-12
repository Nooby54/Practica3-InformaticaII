#include <bitset>
#include <iostream>
#include <fstream>

using namespace std;

#include "encriptado.h"

string abrirArchivo(string narch)
{
    ifstream file;
    file.open(narch);
    if (!file.is_open())
    {
        cout << "Falla." << endl;
        return "1";
    }
    string bin = "";
    while (file.good())
    {
        string bit = bitset<8>(int(file.get())).to_string();
        if (file.good())
            bin += bit;
    }
    file.close();
    for (unsigned int i = 0; i < bin.length(); i++)
    {
        bin[i] = bin[i] - '0';
    }
    return bin;
}

string metodo1(string bin, int n)
{
    string nString = "";
    for (int i = 0; i < n; i++)
    {
        nString += bin[i] ^ 1;
    }

    unsigned int ceros = 0, unos = 0;
    for (unsigned int i = 0; i < ((bin.size() / n) * n); i++)
    {
        if (bin[i] == 1)
            unos += 1;
        else
            ceros += 1;

        if ((i + 1) % n == 0 && i != 0 && (i + n) < bin.size())
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
    unsigned int desplazamiento = ((bin.size() / n) * n);
    n = bin.size() - (bin.size() / n) * n;
    for (int t = 1; t <= n; t++)
    {
        if (unos == ceros || (ceros > unos && t % 2 == 0) || (ceros < unos && t % 3 == 0))
            nString += bin[t + desplazamiento] ^ 1;
        else
            nString += bin[t + desplazamiento];
    }
    return nString;
}

void imprimir(string bin)
{
    for (unsigned int i = 0; i < bin.length(); i++)
    {
        cout << char(bin[i] + 48);
    }
    cout << endl;
}

string metodo2(string bin, int n)
{
    int mask = 0b1;
    for (int i = 0; i < n - 1; i++)
    {
        mask = mask * 10;
    }

    for (unsigned int t = 0; t < bin.length(); t += n)
    {
        unsigned char bit = (bin[t] & mask) >> (n - 1);
        bin[t] = (bin[t] << 1) | bit;
    }
    return bin;
}
