//
//  dec_ces.cpp
//  Cifratura
//
//  Created by Mauro Marzocca on 10/05/23.
//

#include "dec_ces.hpp"

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <cstdlib>

using namespace std;

void decodifica_cesare()
{
    const string alfabeto = "abcdefghijklmnopqrstuvwxyzxz";
    const string cifrato = "defghijklmnopqrstuvwxyzabc";

    string frase("");
    string risultato("");
    cout << "\tInserire la frase da decodificare : ";
    getline(cin, frase);

    for (int i = 0; i < frase.length(); i++)
    {
        bool trovato = false;
        int j = 0;
        for (j = 0; j < cifrato.length(); j++)
        {
            if (tolower(frase[i]) == tolower(cifrato[j]))
            {
                risultato = risultato + alfabeto[j];
                trovato = true;
                break; // interrompi il ciclo una volta che hai trovato il carattere corrispondente
            }
        }
        if (trovato == false)
        {
            risultato = risultato + frase[i];
        }
    }
    cout << "\tLa frase decodificata con Cesare e' : " << risultato << endl;
}
