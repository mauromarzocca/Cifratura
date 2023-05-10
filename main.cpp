//
//  main.cpp
//  Cifratura
//
//  Created by Mauro Marzocca on 09/05/23.
//

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <cstdlib>

#include "cesare.hpp"
#include "rot13.hpp"
#include "cif.hpp"
#include "dec_ces.hpp"
#include "dec_rot.hpp"
#include "dec_cif.hpp"
#include "changelog.hpp"

using namespace std;

int main()
{
    int scelta = -1;
    do
    {
        system("cls");
        cout << endl
             << "\t-------CIFRATURA------" << endl
             << endl;
        cout << "\tProgramma realizzato da Mauro Marzocca" << endl;
        cout << "\tVersione 2.2" << endl;
        cout << endl;
        cout << "\t1)  Cesare" << endl;
        cout << "\t2)  ROT13" << endl;
        cout << "\t3)  Cifratura MonoAlfabetica"
             << endl
             << endl;
        cout << "\t4)  Decodifica del Cifrario di Cesare" << endl;
        cout << "\t5)  Decodifica di ROT13" << endl;
        cout << "\t6)  Decodifica MonoAlfabetica" << endl;
        cout << endl
             << "\t9)  Modifiche versioni Precedenti" << endl;
        cout << "\t0)  Fine";
        cout << endl
             << endl
             << "\tOpzione: ";
        cin >> scelta;
        cout << endl;
        switch (scelta)
        {
        case 1:
            cin.ignore(); // pulisci il buffer di input
            cesare();
            cout << endl
                 << "\t";
            system("pause");
            scelta = -1;
            break;

        case 2:
            cin.ignore(); // pulisci il buffer di input
            rot13();
            cout << endl
                 << "\t";
            system("pause");
            scelta = -1;
            break;

        case 3:
            cin.ignore(); // pulisci il buffer di input
            cif();
            cout << endl
                 << "\t";
            system("pause");
            scelta = -1;
            break;

        case 4:
            cin.ignore(); // pulisci il buffer di input
            decodifica_cesare();
            cout << endl
                 << "\t";
            system("pause");
            scelta = -1;
            break;

        case 5:
            cin.ignore(); // pulisci il buffer di input
            decodificaRot13();
            cout << endl
                 << "\t";
            system("pause");
            scelta = -1;
            break;

        case 6:
            cin.ignore(); // pulisci il buffer di input
            decodifica();
            cout << endl
                 << "\t";
            system("pause");
            scelta = -1;
            break;

        case 9:
            mod();
            cout << endl
                 << "\t";
            system("pause");

            scelta = -1;
            break;

        case 0:
            cout << endl
                 << "\tGrazie di aver usato il mio Programma!" << endl
                 << endl;
            cout << "\t";
            system("pause");
            return 0;
            break;

        default:
            cout << "\tErrore Inserimento! Valore non valido!\n\t";
            system("pause");
            break;
        }
    } while ((scelta >= 0) || (scelta <= 4));
}
