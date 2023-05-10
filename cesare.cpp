//
//  cesare.cpp
//  Cifratura
//
//  Created by Mauro Marzocca on 10/05/23.
//

#include "cesare.hpp"
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <cstdlib>

using namespace std;

void cesare()
{
    const string alfabeto = "abcdefghijklmnopqrstuvwxyzxz";
    const string cifrato = "defghijklmnopqrstuvwxyzabc";

    string frase("");
    string risultato("");
    cout << "\tInserire la frase da criptare : ";
    getline(cin, frase);

    for (int i = 0; i < frase.length(); i++)
    {
        bool trovato = false;
        int j = 0;
        for (j = 0; j < alfabeto.length(); j++)
        {
            if (tolower(frase[i]) == tolower(alfabeto[j]))
            {
                risultato = risultato + cifrato[j];
                trovato = true;
                break; // interrompi il ciclo una volta che hai trovato il carattere corrispondente
            }
        }
        if (trovato == false)
        {
            risultato = risultato + frase[i];
        }
    }
    cout << "\tLa frase cifrata con Cesare e' : " << risultato << endl;
}
