#include<iostream>
#include<time.h>
#include<algorithm>
#include<string>
#include<cctype>
#include<fstream>
#include<vector>
#include<random>
#include<windows.h>
using namespace std;

void pause() {
	cout << endl << "Pritisnite enter za nastavak...";
	string dummy;
	cin.ignore();
	getline(cin, dummy);
}

int main()
{
    int izbor;
    string* Imeprezime = new string[1000];
    double* ulog = new double[1000];
    int ovisnik = 0;
    string odgovor;
    fstream datoteka;
    while (1) {
        cout << "Dobrodosli u kladionicu TRANSilvanija\n" << endl;
        cout << "1. Registracija" << endl;
        cout << "2. Stanje racuna" << endl;
        cout << "3. Loto  " << endl;
        cout << "4. Nogometne utakmice" << endl;
        cout << "5. Utrke cetveronoznih trckala" << endl;
        cout << "6. " << endl;
        cout << "7. izlaz iz programa" << endl;
        cout << "8. " << endl;
        cout << "vas odabir je: ";
        cin >> izbor;
        cout << endl;
        if (izbor == 1)
        {
            cout << "Unesite vase ime i prezime " << endl;
            cin.ignore();
            getline(cin, *Imeprezime);
            cout << "unesite kolicinu novca kojeg zelite unesti: " << endl;
            cin >> ulog[ovisnik];
            ovisnik++;
        }
        if (izbor == 2)
        {
            for (int i = 0; i < ovisnik; i++)
            {
                cout << "Provjera vaseg racuna:" << endl;
                cout << "\t\t" << Imeprezime[i] << endl;
                cout << "\t\t" << ulog[i] << endl;
                cout << "\t\t"<<"da li je ovo vas racun koji ste registrirali ? (da / ne)" << endl;
                cout << "\t\t" << endl;
                cin >> odgovor;
                if (odgovor == "da" || odgovor == "Da" || odgovor == "DA")
                    cout << "\t\t" << "Odlicno, odaberite igru. " << endl;
                else if (odgovor == "ne" || odgovor == "Ne" || odgovor == "NE")
                    cout << "\t\t" << "pokusajte se ponovo registrirati." << endl;
                cout << endl; 
            }


        }
        if (izbor == 3)
        {
            int ulog1;
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dis(1, 49);
            cout << "unesite novac koji zelite uloziti u lotu: " << endl;
            cin >> ulog1;
            if (ulog1 <= 0)
            {
                cout << "pogresan unos, ulog mora biti veci od 0." << endl;
                return 0;
            }
            vector<int> dobitak;
            while (dobitak.size() < 6)
            {
                int broj = dis(gen);
                //provjera je li broj vec generiran
                if (find(dobitak.begin(), dobitak.end(), broj) == dobitak.end())
                {
                    dobitak.push_back(broj);
                }
            }

            //generiranje korisnikovih brojeva
            vector<int> korisnikoviBrojevi;
            cout << "unesite 6 brojeva. BROJEVI MORAJU BITI U INTERVALU! (1-49)" << endl;
            for (int i = 0; i < 6; i++)
            {
                int broj;
                cin >> broj;

                //provjera je li broj vec unesen
                if (find(korisnikoviBrojevi.begin(), korisnikoviBrojevi.end(), broj) == korisnikoviBrojevi.end()) {
                    korisnikoviBrojevi.push_back(broj);
                }
                else
                {
                    cout << "Dvaputa je unesen isti broj. Pokusaj ponovo " << endl;
                    i--;
                }
                //provjera da li je unesen broj koji nije u zadanom intervalu
                if (broj <= 0 || broj > 49)
                    return 0;
                else
                {
                    cout << "unjeli ste broj koji nije u zadanom intervalu, pokusajte ponovo"<< endl;

                }
            }
            
            //ispis dobitnih brojeva
            cout << "Dobitni brojevi su: ";
            for (int broj : dobitak)
                cout << broj << " ";
            cout << endl;

            //provjera dobitnika
            int pogodak = 0;
            for (int broj : korisnikoviBrojevi)
            {
                if (find(dobitak.begin(), dobitak.end(), broj) != dobitak.end())
                    pogodak++;
            }
            //ispis rezultata
            cout << "broj pogodataka: " << pogodak << endl;
            if (pogodak == 6)
            {
                cout << "cestitamo, osvojili ste Jackpot!" << endl;
                cout << "Vas dobitak iznosi: " << ulog1 * 100000 << "eura" << endl;
            }
            else if (pogodak >= 3)
            {
                cout << "osvojili ste mali dobitak" << endl;
                cout << "vas dobitak iznosi: " << ulog1 * 100 << "eura" << endl;
            }
            else
                cout << "Nazalost,niste osvojili dobitak. Vise srece drugi put <3 " << endl;
            
            
        }
}
     if (izbor == 4) {
         cout << "Odabrali ste Nogometne Utakmice:" << endl;
         int odabir_nogometni_tim;
        
     }
     if (izbor == 5) {

        
     }
     if (izbor == 6) {

        
     }
     if (izbor == 7) {

        
     }
     if (izbor == 8) {

        
     }

}

