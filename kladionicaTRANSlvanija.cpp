#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cctype>
#include<fstream>
#include<vector>
#include<random>
#include<windows.h>
#include<ctime>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <fstream>
using namespace std;

void pauza() {
    cout << endl << "Pritisnite enter za nastavak...";
    string dummy;
    cin.ignore();
    getline(cin, dummy);
}

int main()
{
    int izbor;
    double* ulog = new double[1000];
    string* Imeprezime1 = new string[1000];
    int brojOvisnika = 0;
    string Imeprezime;
    long long int OIB;
    string grad;
    string odgovor;
    while (1) {
        system("cls");
        cout << "Dobrodosli u kladionicu TRANSilvanija\n" << endl;
        cout << "1. Registracija" << endl;
        cout << "2. Stanje racuna" << endl;
        cout << "3. Loto" << endl;
        cout << "4. Utrke cetveronoznih trckala" << endl;
        cout << "5. Slot masine" << endl;
        cout << "6. Izlaz iz programa" << endl;
        cout << "Vas odabir je: ";
        cin >> izbor;
        cout << endl;
        if (izbor == 1)
        {
            cout << "Dobrodosli u kladionicu TRANSilvanija: " << endl << "Unesite vase ime i prezime: " << endl;
            cin.ignore();
            getline(cin, Imeprezime);
            cout << "unesite ime grada u kojem zivite: " << endl;
            getline(cin, grad);
            cout << "Unesite vas OIB: " << endl;
            cin >> OIB;
            brojOvisnika++;
            ofstream datoteka("podatci.txt");
            if (datoteka.is_open())
            {
                datoteka << "ImePrezime: " << Imeprezime << endl;
                datoteka << "Grad: " << grad << endl;
                datoteka << "OIB: " << OIB << endl;
                datoteka.close();
            }
        }

        if (izbor == 2)
        {
            for (int i = 0; i < brojOvisnika; i++)
            {
                cout << "Provjera vaseg racuna:" << endl;
                cout << "\t\t" << Imeprezime << endl;
                cout << "\t\t" << grad << endl;
                cout << "\t\t" << OIB << endl;
                cout << "\t\t" << "Je li ovo vas racun koji ste registrirali? (da / ne)" << endl;
                cout << "\t\t" << endl;
                cin >> odgovor;
                if (odgovor == "da" || odgovor == "Da" || odgovor == "DA")
                    cout << "\t\t" << "Odlicno, odaberite igru." << endl;
                else if (odgovor == "ne" || odgovor == "Ne" || odgovor == "NE")
                    cout << "\t\t" << "Pokusajte se ponovno registrirati." << endl;
            }
        }
        if (izbor == 3)
        {
            int ulog1;
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dis(1, 35);
            cout << "Unesite novac koji zelite uloziti u loto: " << endl;
            cin >> ulog1;
            cout << "Unesite 7 brojeva koji su u rasponu brojeva 1 - 35" << endl;

            if (ulog1 <= 0) {
                cout << "Pogresan unos, ulog mora biti veci od 0." << endl;
                return 0;
            }

            int* polje = new int[7];
            int* brojevi = new int[7];
            for (int i = 0; i < 7; i++) {
                cout << "Unesite " << i + 1 << ". broj: ";
                cin >> polje[i];
                // Provjera je li broj vec unesen
                for (int j = 0; j < i; j++) {
                    if (polje[i] == polje[j]) {
                        cout << "Broj " << polje[i] << " je vec unesen. Molimo unesite drugi broj." << endl;
                        i--; // Ponovno trazimo unos istog broja
                        break;
                    }
                }
                // Provjera je li broj u zadanom rasponu
                if (polje[i] < 1 || polje[i] > 35) {
                    cout << "Pogresan unos, brojevi moraju biti u rasponu od 1 do 35." << endl;
                    i--; // Ponovno trazimo unos istog broja
                    continue;
                }
            }
            cout << "Vasi brojevi su: ";
            for (int i = 0; i < 7; i++) {
                cout << polje[i] << " ";
            }
            cout << endl;
            cout << "Dobitni brojevi su: ";
            for (int i = 0; i < 7; i++) {
                brojevi[i] = dis(gen);
                cout << brojevi[i] << " ";
            }
            cout << endl;
            int brojac = 0;
            for (int i = 0; i < 7; i++) {
                if (polje[i] == brojevi[i]) {
                    brojac++;
                }
            }
            if (brojac == 0) {
                cout << "Nazalost, niste osvojili nista." << endl;
            }
            else if (brojac == 7) {
                cout << "Cestitamo! Osvojili ste glavni dobitak!" << endl;
            }
            else {
                cout << "Cestitamo! Osvojili ste " << brojac << " pogodaka." << endl;
            }

            delete[] polje;
            delete[] brojevi;
        }
        string str;
        cin.ignore();
        getline(cin, str);
        if (izbor == 4)
        {
            //slot masine
        }
        if (izbor == 5)
        {
            fstream file;
            file.open("Povijest.txt", ios::app);
            char c;
            string g;
            int z, t;
            char polje[3][8] = { {'A','_', '_', '_', '_', '_', '_', 'g'},
                                 {'B','_', '_', '_', '_', '_','_','f'},
                                 {'C','_', '_', '_', '_','_','_', 'k'} };
            cout << "Dobrodosli u utrke konja, unesite vase ime: ";
            cin >> g;
            system("cls");
            cout << "Dobrodosli " << g << "\n";
            cout << "Odaberite konja na kojega se kladite : \n"
                << "                                                   A)\n"
                << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t                                                    B)\n"
                << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t                                                    C)\n\n"
                << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    ";
            cin >> c;
            while (c != 'A' && c != 'B' && c != 'C')
            {
                cout << "Unesite valjanog konja: ";
                cin >> c;
            }
            cout << "\n";
            cout << "Unesite vas ulog : ";
            cin >> z;
            int x1 = 0, y1 = 0, x2 = 1, y2 = 0, x3 = 2, y3 = 0;
            while ((polje[0][7] == 'g') && (polje[1][7] == 'f') && (polje[2][7] == 'k'))
            {
                int nasumicno;
                Sleep(700);
                srand(time(NULL));
                nasumicno = rand() % 10;

                if (nasumicno > 4)
                {
                    polje[x1][y1] = '_';
                    polje[x1][y1 + 1] = 'A';
                    y1++;
                }

                system("cls");
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 8; j++)
                        cout << polje[i][j];
                    cout << "\n";
                }

                Sleep(700);
                srand(time(NULL));
                nasumicno = rand() % 10;

                if (nasumicno > 4)
                {
                    polje[x2][y2] = '_';
                    polje[x2][y2 + 1] = 'B';
                    y2++;
                }

                system("cls");
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 8; j++)
                        cout << polje[i][j];
                    cout << "\n";
                }

                Sleep(700);
                srand(time(NULL));
                nasumicno = rand() % 10;

                if (nasumicno > 4)
                {
                    polje[x3][y3] = '_';
                    polje[x3][y3 + 1] = 'C';
                    y3++;
                }

                system("cls");
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 8; j++)
                        cout << polje[i][j];
                    cout << "\n";
                }
            }
            cout << "\n";
            if (polje[0][7] == 'A' && c == 'A')
            {
                t = z * 3;
                cout << "Cestitamo! Vas konj je pobijedio.\n";
                cout << "Vas dobitak je: " << t << "\n";
                file << g << " je uložio " << z << " i osvojio " << t << " s konjem A.\n";
            }
            else if (polje[0][7] == 'A' && c != 'A')
            {
                cout << "Izgubili ste, vise srece drugi put\n";
                file << g << " je uložio " << z << " i izgubio s konjem A.\n";
            }
            else if (polje[1][7] == 'B' && c == 'B')
            {
                t = z * 2;
                cout << "Cestitamo! Vas konj je pobijedio.\n";
                cout << "Vas dobitak je: " << t << "\n";
                file << g << " je uložio " << z << " i osvojio " << t << " s konjem B.\n";
            }
            else if (polje[1][7] == 'B' && c != 'B')
            {
                cout << "Izgubili ste, vise srece drugi put\n";
                file << g << " je uložio " << z << " i izgubio s konjem B.\n";
            }
            else if (polje[2][7] == 'C' && c == 'C')
            {
                t = z * 2;
                cout << "Cestitamo! Vas konj je pobijedio.\n";
                cout << "Vas dobitak je: " << t << "\n";
                file << g << " je uložio " << z << " i osvojio " << t << " s konjem C.\n";
            }
            else if (polje[2][7] == 'C' && c != 'C')
            {
                cout << "Izgubili ste, vise srece drugi put\n";
                file << g << " je uložio " << z << " i izgubio s konjem C.\n";
            }
            file.close();
        }
    
        if (izbor == 6)
        {
            cout << "Hvala vam, dodite nam opet! :3";
            break;
        }
          
            pauza();
        }

        return 0;
    }
  