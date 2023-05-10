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
    string t_cifrato;
    string t_originale = "";
    int chiave;

    cout << "\tInserisci il testo da decifrare: ";
    getline(cin, t_cifrato);

    cout << "\tInserisci la chiave: ";
    cin >> chiave;

    if (chiave >= 0)
    {
        for (int t = 0; t < t_cifrato.length(); t++)
        {
            if (t_cifrato[t] == ' ')
            {
                t_originale += ' ';
            }
            else if (t_cifrato[t] > 95)
            {
                int buffer = ((t_cifrato[t] - chiave - 96) % 26);
                if (buffer == 0)
                {
                    buffer = 26;
                }
                t_originale += buffer + 96;
            }
            else
            {
                int buffer = ((t_cifrato[t] - chiave - 64) % 26);
                if (buffer == 0)
                {
                    buffer = 26;
                }
                t_originale += buffer + 64;
            }
        }

        cout << "\tTesto decifrato: " << t_originale << endl;
    }
    else
    {
        do
        {
            system("CLS");
            cout << "\tErrore Inserimento! Valore non valido!\n";
            cout << "\tParola Inserita : " << t_cifrato << endl;
            cout << "\tInserisci la chiave: ";
            cin >> chiave;
        } while (chiave < 0);
    }
}
