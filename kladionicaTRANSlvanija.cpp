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
struct Karta {
    string vrijednost;
    string znak;
};

void podijeliKartu(vector<Karta>& špil, vector<Karta>& ruka) {
    ruka.push_back(špil.back());
    špil.pop_back();
}

void pomiješajŠpil(vector<Karta>& špil) {
    random_device rd;
    mt19937 gen(rd());
    shuffle(špil.begin(), špil.end(), gen);
}

int izračunajVrijednostRuke(const vector<Karta>& ruka) {
    int vrijednost = 0;
    int brojAsova = 0;

    for (const Karta& karta : ruka) {
        if (karta.vrijednost == "A") {
            vrijednost += 11;
            brojAsova++;
        }
        else {
            vrijednost += stoi(karta.vrijednost);
        }
    }

    while (vrijednost > 21 && brojAsova > 0) {
        vrijednost -= 10;
        brojAsova--;
    }

    return vrijednost;
}

void spremanjeRukeUDatoteku(const vector<Karta>& ruka, const string& imeDatoteke) {
    ofstream datoteka(imeDatoteke, ios::binary);
    if (datoteka.is_open()) {
        int brojKarata = ruka.size();
        datoteka.write(reinterpret_cast<const char*>(&brojKarata), sizeof(int));
        for (const Karta& karta : ruka) {
            int vrijednostSize = karta.vrijednost.size();
            datoteka.write(reinterpret_cast<const char*>(&vrijednostSize), sizeof(int));
            datoteka.write(karta.vrijednost.c_str(), vrijednostSize);
            int znakSize = karta.znak.size();
            datoteka.write(reinterpret_cast<const char*>(&znakSize), sizeof(int));
            datoteka.write(karta.znak.c_str(), znakSize);
        }
        datoteka.close();
    }
}

vector<Karta> ucitavanjeRukeIzDatoteke(const string& imeDatoteke) {
    vector<Karta> ruka;
    ifstream datoteka(imeDatoteke, ios::binary);
    if (datoteka.is_open()) {
        int brojKarata;
        datoteka.read(reinterpret_cast<char*>(&brojKarata), sizeof(int));
        for (int i = 0; i < brojKarata; i++) {
            int vrijednostSize;
            datoteka.read(reinterpret_cast<char*>(&vrijednostSize), sizeof(int));
            string vrijednost(vrijednostSize, '\0');
            datoteka.read(&vrijednost[0], vrijednostSize);
            int znakSize;
            datoteka.read(reinterpret_cast<char*>(&znakSize), sizeof(int));
            string znak(znakSize, '\0');
            datoteka.read(&znak[0], znakSize);
            Karta karta = { vrijednost, znak };
            ruka.push_back(karta);
        }
        datoteka.close();
    }
    return ruka;
}

void prikaziRuku(const vector<Karta>& ruka, bool prikažiSveKarte = true) {
    for (const Karta& karta : ruka) {
        cout << karta.vrijednost << " " << karta.znak << endl;
    }
    if (!prikažiSveKarte) {
        cout << "Ukupna vrijednost: " << izračunajVrijednostRuke(ruka) << endl;
    }
}

void blackjack() {
    vector<Karta> špil = {
        { "2", "♥" }, { "3", "♥" }, { "4", "♥" }, { "5", "♥" }, { "6", "♥" }, { "7", "♥" }, { "8", "♥" }, { "9", "♥" }, { "10", "♥" }, { "J", "♥" }, { "Q", "♥" }, { "K", "♥" }, { "A", "♥" },
        { "2", "♦" }, { "3", "♦" }, { "4", "♦" }, { "5", "♦" }, { "6", "♦" }, { "7", "♦" }, { "8", "♦" }, { "9", "♦" }, { "10", "♦" }, { "J", "♦" }, { "Q", "♦" }, { "K", "♦" }, { "A", "♦" },
        { "2", "♠" }, { "3", "♠" }, { "4", "♠" }, { "5", "♠" }, { "6", "♠" }, { "7", "♠" }, { "8", "♠" }, { "9", "♠" }, { "10", "♠" }, { "J", "♠" }, { "Q", "♠" }, { "K", "♠" }, { "A", "♠" },
        { "2", "♣" }, { "3", "♣" }, { "4", "♣" }, { "5", "♣" }, { "6", "♣" }, { "7", "♣" }, { "8", "♣" }, { "9", "♣" }, { "10", "♣" }, { "J", "♣" }, { "Q", "♣" }, { "K", "♣" }, { "A", "♣" }
    };

    pomiješajŠpil(špil);

    vector<Karta> rukaIgraca;
    vector<Karta> rukaDilera;

    podijeliKartu(špil, rukaIgraca);
    podijeliKartu(špil, rukaDilera);
    podijeliKartu(špil, rukaIgraca);
    podijeliKartu(špil, rukaDilera);

    while (true) {
        system("cls");
        cout << "Ruka igrača:" << endl;
        prikaziRuku(rukaIgraca);
        cout << endl;
        cout << "Ruka dilera:" << endl;
        prikaziRuku(rukaDilera, false);
        cout << endl;

        cout << "Da li želite uzeti još jednu kartu? (da/ne): ";
        string odgovor;
        cin >> odgovor;

        if (odgovor == "da") {
            podijeliKartu(špil, rukaIgraca);
            if (izračunajVrijednostRuke(rukaIgraca) > 21) {
                cout << "Prešli ste 21. Gubite!" << endl;
                pauza();
                return;
            }
        }
        else {
            break;
        }
    }

    while (izračunajVrijednostRuke(rukaDilera) < 17) {
        podijeliKartu(špil, rukaDilera);
        if (izračunajVrijednostRuke(rukaDilera) > 21) {
            cout << "Diler je prešao 21. Pobjeđujete!" << endl;
            pauza();
            return;
        }
    }

    cout << "Ruka igrača:" << endl;
    prikaziRuku(rukaIgraca);
    cout << endl;
    cout << "Ruka dilera:" << endl;
    prikaziRuku(rukaDilera);
    cout << endl;

    int vrijednostIgraca = izračunajVrijednostRuke(rukaIgraca);
    int vrijednostDilera = izračunajVrijednostRuke(rukaDilera);

    if (vrijednostIgraca > vrijednostDilera) {
        cout << "Pobjeđujete!" << endl;
    }
    else if (vrijednostIgraca < vrijednostDilera) {
        cout << "Gubite!" << endl;
    }
    else {
        cout << "Neriješeno!" << endl;
    }

    pauza();
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
        cout << "6. Blackjack" << endl;
        cout << "7. Izlaz iz programa" << endl;
        cout << "8. " << endl;
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
            cout << "Dobrodošli u igru Blackjack!" << endl;
            cout << "Želite li početi novu igru ili učitati prethodno spremljenu igru?" << endl;
            cout << "1. Nova igra" << endl;
            cout << "2. Učitaj spremljenu igru" << endl;
            cout << "Odabir: ";
            int odabirIgre;
            cin >> odabirIgre;

            if (odabirIgre == 1) {
                blackjack();
            }
            else if (odabirIgre == 2) 
            {
                cout << "Unesite ime datoteke za učitavanje: ";
                string imeDatoteke;
                cin >> imeDatoteke;
                vector<Karta> rukaIgraca = ucitavanjeRukeIzDatoteke(imeDatoteke);
                if (rukaIgraca.empty()) {
                    cout << "Neuspješno učitavanje igre iz datoteke." << endl;
                }
                else {
                    blackjack();
                }
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