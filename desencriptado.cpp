#include "desencriptado.h"

#include <bitset>
#include <iostream>
#include <fstream>

using namespace std;

string desencriptarMetodo2(string bin, int n)
{
    string nString = "";
    unsigned int multiplo = ((bin.length() / n) * n);
    for (unsigned int t = 0; t < multiplo; t += n)
    {
        for (int r = 0; r < n - 1; r++)
            nString += bin[t + r];
        nString += bin[t + n - 1];
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
