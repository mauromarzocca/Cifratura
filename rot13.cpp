//
//  rot13.cpp
//  Cifratura
//
//  Created by Mauro Marzocca on 10/05/23.
//

#include "rot13.hpp"
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <cstdlib>

using namespace std;

void rot13()
{

    string frase("");
    string risultato("");
    cout << "\tInserire la parola da criptare : ";
    getline(cin, frase);

    for (int i = 0; i < frase.length(); i++)
    {
        int c = (int)frase[i];
        if (c >= 65 && c <= 77)
            c = c + 13;
        else if (c >= 78 && c <= 90)
            c = c - 13;
        else if (c >= 97 && c <= 109)
            c = c + 13;
        else if (c >= 110 && c <= 122)
            c = c - 13;
        risultato = risultato + (char)c;
    }
    cout << "\tLa frase criptata utilizzando ROT 13 e': " << risultato << endl;
}
