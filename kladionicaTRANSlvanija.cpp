#include<iostream>
#include<cstdlib>
#include<time.h>
#include<algorithm>
#include<string>
#include<cctype>
#include<fstream>
#include<vector>
#include<random>
#include<windows.h>
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
        cout << "4. Nogometne utakmice" << endl;
        cout << "5. Utrke cetveronoznih trckala" << endl;
        cout << "6. Poker" << endl;
        cout << "7. Izlaz iz programa" << endl;
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
            uniform_int_distribution<int> dis(1, 49);
            cout << "Unesite novac koji zelite uloziti u loto: " << endl;
            cin >> ulog1;
            if (ulog1 <= 0)
            {
                cout << "Pogresan unos, ulog mora biti veci od 0." << endl;
                return 0;
            }
            int* polje = new int[7];
            int* brojevi = new int[7];
            for (int i = 0; i < 7; i++)
            {
                cout << "Unesite " << i + 1 << ". broj: ";
                cin >> polje[i];
                if (polje[i] <= 0 || polje[i] > 49)
                {
                    cout << "Pogrešan unos, brojevi moraju biti u rasponu od 1 do 49." << endl;
                    return 0;
                }
            }
            cout << "Vasi brojevi su: ";
            for (int i = 0; i < 7; i++)
            {
                cout << polje[i] << " ";
            }
            cout << endl;
            cout << "Dobitni brojevi su: ";
            for (int i = 0; i < 7; i++)
            {
                brojevi[i] = dis(gen);
                cout << brojevi[i] << " ";
            }
            cout << endl;
            int brojac = 0;
            for (int i = 0; i < 7; i++)
            {
                if (polje[i] == brojevi[i])
                {
                    brojac++;
                }
            }
            if (brojac == 0)
            {
                cout << "Nazalost, niste osvojili nista." << endl;
            }
            else if (brojac == 7)
            {
                cout << "Cestitamo! Osvojili ste glavni dobitak!" << endl;
            }
            else
            {
                cout << "Cestitamo! Osvojili ste " << brojac << " pogodaka." << endl;
            }
            delete[] polje;
            delete[] brojevi;
        }
        system("cls");
        if (izbor == 4)
        {
            double balans = 0.0;
            cout << "Unesite iznos koji zelite uloziti na nogometnu utakmicu: " << endl;
            cin >> balans;
            if (balans <= 0)
            {
                cout << "Pogresan unos, iznos uloga mora biti veci od 0." << endl;
                return 0;
            }
            // Ovdje dodajte logiku za nogometne utakmice
        }
        if (izbor == 5)
        {
            double ulog2;
            cout << "Unesite iznos koji želite uložiti na utrke četveronožnih trkača: " << endl;
            cin >> ulog2;
            if (ulog2 <= 0)
            {
                cout << "Pogrešan unos, iznos uloga mora biti veći od 0." << endl;
                return 0;
            }
            // Ovdje dodajte logiku za utrke četveronožnih trkača
        }
        if (izbor == 6)
        {
            // Deklaracija i inicijalizacija špila karata
            string karte[52] = {
                "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A",
                "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A",
                "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A",
                "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"
            };

            // Miješanje špila karata
            random_device rd;
            mt19937 gen(rd());
            shuffle(karte, karte + 52, gen);

            // Podjela karata igračima
            const int brojIgraca = 4;
            const int brojKarataPoIgracu = 5;
            string ruka[brojIgraca][brojKarataPoIgracu];

            for (int i = 0; i < brojKarataPoIgracu; i++)
            {
                for (int j = 0; j < brojIgraca; j++)
                {
                    ruka[j][i] = karte[i * brojIgraca + j];
                }
            }

            // Ispis podijeljenih karata
            string imeIgraca[brojIgraca] = { "Igrac 1", "Igrac 2", "Igrac 3", "Igrac 4" };

            for (int i = 0; i < brojIgraca; i++)
            {
                cout << imeIgraca[i] << ": ";
                for (int j = 0; j < brojKarataPoIgracu; j++)
                {
                    cout << ruka[i][j] << " ";
                }
                cout << endl;
            }

            pauza(); // Pauza za prikaz podijeljenih karata
        }
            if (izbor == 7)
            {
                break;
            }
        }

        delete[] Imeprezime1;
        delete[] ulog;

        return 0;
    }
  