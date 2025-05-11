#include <bitset>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include "encriptado.h"


string abrirArchivo(string narch){
    ifstream file;
    file.open(narch);
    if (!file.is_open()) {
        cout << "Falla." << endl;
        return "1";
    }
    string bin = "";
    while(file.good()){
        string bit = bitset<8>(int(file.get())).to_string();
        if(file.good())
            bin += bit;
    }
    file.close();
    return bin;
}

string metodo1(string bin, int n){
    string nString = "";
    for(int i = 0; i < n; i++){
        nString+= bin[i] ^ 1;
    }
    cout << nString << endl;
    return nString;
}

string metodo2(string bin, int n){
    int mask = 0b1;
    for (int i = 0; i<n-1;i++){
        mask = mask*10;
    }
    cout << endl << mask << endl;

    for (unsigned int t = 0; t < bin.length(); t+=8)
    {
        unsigned char bit = (bin[t] & 0b10000000) >> 7;
        bin[t] = (bin[t] << 1) | bit;
    }
    cout << endl << bin << endl;
    return bin;
}
