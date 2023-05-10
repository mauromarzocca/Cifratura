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

void cif()
{
    const int CARATTERI = 1000; // costante per la lunghezza massima della stringa
    char t_originale[CARATTERI + 1];
    char t_cifrato[CARATTERI + 1];
    int chiave;
    int lung_string;
    int buffer;

    cout << "\tInserisci il testo da cifrare: ";
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
                t_cifrato[t] = ' '; // salva lo spazio nella cifratura
            }
            else if (t_originale[t] > 95)
            {
                buffer = ((t_originale[t] + chiave) % 96) % 26;
                if (buffer == 0)
                {
                    buffer = 26;
                }
                t_cifrato[t] = 96 + buffer;
            }
            else
            {
                buffer = ((t_originale[t] + chiave) % 64) % 26;
                if (buffer == 0)
                {
                    buffer = 26;
                }
                t_cifrato[t] = 64 + buffer;
            }
        }
        t_cifrato[lung_string] = '\0';
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



void decodifica_cesare()
{
    const string alfabeto = "abcdefghijklmnopqrstuvwxyzxz";
    const string cifrato = "defghijklmnopqrstuvwxyzabc";
    
    string frase("");
    string risultato("");
    getline(cin, frase);

    cout << " Inserire la parola da decodificare : ";
    cin >> frase;

    for (int i = 0; i < frase.length(); i++)
    {
        bool trovato = false;
        int j = 0;
        for (j = 0; j < cifrato.length(); j++)
        if (tolower(frase[i]) == tolower(cifrato[j]))
        {
           risultato = risultato + alfabeto[j];
           trovato = true;
        }
        if (trovato == false)
        {
            risultato = risultato + frase[i];
        }
    }
    cout << "\nLa parola decodificata con Cesare e' : " << risultato << endl << endl;
}


void mod()
{
    cout << "\t - Versione 1.0" << endl;
    cout << "\t    Release iniziale. " << endl;
    cout << "\t - Versione 1.0.1" << endl;
    cout << "\t    Risoluzione di alcuni Bug. " << endl;
    cout << "\t - Versione 1.1" << endl;
    cout << "\t      Codice Migliorato" << endl;
    cout << "\t - Versione 1.2" << endl;
    cout << "\t      Release Stabile" << endl;
    cout << "\t - Versione 1.2.1" << endl;
    cout << "\t      Bug Fix" << endl;
    cout << "\t - Versione 1.3" << endl;
    cout << "\t      Nuova Release" << endl;
    cout << "\t - Versione 1.4" << endl;
    cout << "\t      Bug Fix e Nuova Build" << endl;
    cout << "\t - Versione 1.5" << endl;
    cout << "\t      Implementazione Della Decofica del Cifrario di Cesare" << endl;
    cout << "\t - Versione 1.5.1" << endl;
    cout << "\t      Bug Fix" << endl;
    cout << "\t - Versione 1.5.2" << endl;
    cout << "\t      Bug Fix" << endl;
    cout << "\t - Versione 1.6" << endl;
    cout << "\t      Nuova Build" << endl;
    cout << "\t - Versione 1.7" << endl;
    cout << "\t      Miglioramenti al cifrario di Cesare" << endl;
    cout << "\t - Versione 1.8" << endl;
    cout << "\t      Miglioramenti di ROT13" << endl;
    cout << "\t - Versione 1.8.1" << endl;
    cout << "\t      Bug Fix" << endl;
    cout << "\t - Versione 1.9" << endl;
    cout << "\t      Miglioramenti alla Cifratura Monoalfabetica" << endl;
}

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
        cout << "\tVersione 1.9" << endl;
        cout << endl;
        cout << "\t1)  Cesare" << endl;
        cout << "\t2)  ROT13" << endl;
        cout << "\t3)  Cifratura MonoAlfabetica"
             << endl;
        cout << "\t4)  Decodifica del Cifrario di Cesare" << endl;
        cout << "\t9)  Modifiche versioni Precedenti" << endl;
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
            decodifica_cesare();
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
