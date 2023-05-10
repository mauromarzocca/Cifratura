//
//  dec_cif.cpp
//  Cifratura
//
//  Created by Mauro Marzocca on 10/05/23.
//

#include "dec_cif.hpp"

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <cstdlib>

using namespace std;

void decodifica()
{
    const int CARATTERI = 1000; // costante per la lunghezza massima della stringa
    char t_originale[CARATTERI + 1];
    char t_decifrato[CARATTERI + 1];
    int chiave;
    int lung_string;
    int buffer;

    cout << "\tInserisci il testo da decifrare: ";
    cin.ignore(); // ignore any previous input
    cin.getline(t_originale, CARATTERI);
    lung_string = strlen(t_originale);

    cout << "\tInserisci la chiave: ";
    cin >> chiave;

    if (chiave >= 0)
    {
        for (int t = 0; t < lung_string; t++)
        {
            if (t_originale[t] == ' ')
            {
                t_decifrato[t] = ' '; // salva lo spazio nella decifratura
            }
            else if (t_originale[t] > 95)
            {
                buffer = ((t_originale[t] - chiave + 192) % 96) % 26;
                if (buffer == 0)
                {
                    buffer = 26;
                }
                t_decifrato[t] = 96 + buffer;
            }
            else
            {
                buffer = ((t_originale[t] - chiave + 128) % 64) % 26;
                if (buffer == 0)
                {
                    buffer = 26;
                }
                t_decifrato[t] = 64 + buffer;
            }
        }
        t_decifrato[lung_string] = '\0';
        cout << "\tTesto decifrato : " << t_decifrato << endl;
    }
    else
    {
        do
        {
            system("CLS");
            cout << "\tErrore Inserimento! Valore non valido!\n";
            cout << "\tParola Inserita : " << t_originale << endl;
            cout << "\tInserisci la chiave: ";
            cin >> chiave;
        } while (chiave < 0);
    }
}
