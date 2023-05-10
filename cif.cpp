//
//  cif.cpp
//  Cifratura
//
//  Created by Mauro Marzocca on 10/05/23.
//

#include "cif.hpp"

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <cstdlib>

using namespace std;

void cif()
{
    string t_originale;
    string t_cifrato = "";
    int chiave;

    cout << "\tInserisci il testo da cifrare: ";
    getline(cin, t_originale);

    cout << "\tInserisci la chiave: ";
    cin >> chiave;

    if (chiave >= 0)
    {
        for (int t = 0; t < t_originale.length(); t++)
        {
            if (t_originale[t] == ' ')
            {
                t_cifrato += ' ';
            }
            else if (t_originale[t] > 95)
            {
                int buffer = ((t_originale[t] + chiave) % 96) % 26;
                if (buffer == 0)
                {
                    buffer = 26;
                }
                t_cifrato += 96 + buffer;
            }
            else
            {
                int buffer = ((t_originale[t] + chiave) % 64) % 26;
                if (buffer == 0)
                {
                    buffer = 26;
                }
                t_cifrato += 64 + buffer;
            }
        }

        cout << "\tTesto cifrato : " << t_cifrato << endl;
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
