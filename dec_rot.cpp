//
//  dec_rot.cpp
//  Cifratura
//
//  Created by Mauro Marzocca on 10/05/23.
//

#include "dec_rot.hpp"

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <cstdlib>

using namespace std;

void decodificaRot13()
{
    string frase("");
    string risultato("");
    cout << "\tInserire la frase da decifrare: ";
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
    cout << "\tLa parola decodificata con ROT13 e' : " << risultato << endl
         << endl;
}
