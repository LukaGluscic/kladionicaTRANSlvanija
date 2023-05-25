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
         cout << "PRAVILA:" << endl << "Na pocetku izlaze dva nogometna kluba koje ce odigrati utakmicu." << endl << "Odabrani klub je pobijedio - dupli dobitak uloga." << endl << "U suprotnom (gubitak ili izjednaceno) gubite svotu uloga." << endl;
         int Bir2;
         do {
             int bayern = 1, real = 2, FC = 3, PSG = 4, Chelsea = 5, Bayern = 6, City = 7, United = 8, Juv = 9, Pool = 10;
             time_t rand_broj1 = time(NULL);
             srand(rand_broj1);
             time_t rand_broj2 = time(NULL);
             srand(rand_broj2);
             time_t rand_broj3 = time(NULL);
             srand(rand_broj3);
             int random_broj1 = (rand() % 10) + 1;
             int random_broj2 = (rand() % 10) + 1;

             int klub1 = random_broj1, klub2 = random_broj2;
             if (klub1 == klub2) {
                 klub2 += 1;
             }
             if (klub1 == 1)
                 cout << endl << "Klub broj 1: Bayern" << endl;
             if (klub1 == 2)
                 cout << endl << "Klub broj 1: Real Madrid" << endl;
             if (klub1 == 3)
                 cout << endl << "Klub broj 1: FC Barcelona" << endl;
             if (klub1 == 4)
                 cout << endl << "Klub broj 1: PSG" << endl;
             if (klub1 == 5)
                 cout << endl << "Klub broj 1: Chelsea" << endl;
             if (klub1 == 6)
                 cout << endl << "Klub broj 1: Bayern" << endl;
             if (klub1 == 7)
                 cout << endl << "Klub broj 1: Manchester City" << endl;
             if (klub1 == 8)
                 cout << endl << "Klub broj 1: Manchester united" << endl;
             if (klub1 == 9)
                 cout << endl << "Klub broj 1: Juventus" << endl;
             if (klub1 == 10)
                 cout << endl << "Klub broj 1: Liverpool" << endl;


             if (klub2 == 1)
                 cout << endl << "Klub broj 2: Bayern" << endl << endl;
             if (klub2 == 2)
                 cout << endl << "Klub broj 2: Real Madrid" << endl << endl;
             if (klub2 == 3)
                 cout << endl << "Klub broj 2: FC Barcelona" << endl << endl;
             if (klub2 == 4)
                 cout << endl << "Klub broj 2: PSG" << endl << endl;
             if (klub2 == 5)
                 cout << endl << "Klub broj 2: Chelsea" << endl << endl;
             if (klub2 == 6)
                 cout << endl << "Klub broj 2: Bayern" << endl << endl;
             if (klub2 == 7)
                 cout << endl << "Klub broj 2: Manchester City" << endl << endl;
             if (klub2 == 8)
                 cout << endl << "Klub broj 2: Manchester united" << endl << endl;
             if (klub2 == 9)
                 cout << endl << "Klub broj 2: Juventus" << endl << endl;
             if (klub2 == 10)
                 cout << endl << "Klub broj 2: Liverpool" << endl << endl;

             int odabir_nogo, oklada;

             cout << "Odaberite klub: ";

         odabir:
             cin >> odabir_nogo;
             if (odabir_nogo <= 0 || odabir_nogo > 2) {
                 cout << "Pogresan odabir, pokusajte ponovni!" << endl << endl;
                 goto odabir;
             }
         ulog1:
             cout << endl << endl << "Ulog: ";
             cin >> oklada;
             if (oklada > balans) {
                 cout << "Nemate toliko novca, vas balans: " << balans;
                 goto ulog1;
             }

             cout << "Utakmica je u tijeku, pricekajte." << endl;


             int rez1 = (rand() % 7) + 0;
             int rez2 = (rand() % 7) + 0;

             cout << endl << "Rezultat je: " << endl << endl;

             cout << "[" << rez1 << "]" << " --- " << "[" << rez2 << "]";

             if (odabir_nogo == 1 && rez1 > rez2) {
                 cout << "Èestitamo, pobjedili ste!!" << endl;
                 balans = balans + oklada * 1.5;
                 cout << "Vaš balans: " << balans << endl;
             }
             else if (odabir_nogo == 2 && rez2 > 1) {
                 cout << "Èestitamo, pobjedili ste!!" << endl;
                 balans = balans + oklada * 1.5;
                 cout << "Vaš balans: " << balans << endl;
             }
             else if (odabir_nogo == 1 && rez1 < rez2) {
                 cout << "Izgubili ste.";
                 balans = balans - oklada;
                 cout << "Vaš balans: " << balans << endl;
             }
             else if (odabir_nogo == 2 && rez2 < rez1) {
                 cout << "Izgubili ste!" << endl;
                 balans = balans - oklada;
                 cout << "Vaš balans: " << balans << endl;
             }
             else if (odabir_nogo == 2 && rez2 == rez1) {
                 cout << "Izjednaèeno." << endl;
                 balans = balans - oklada;
                 cout << "Vaš balans: " << balans << endl;
             }
             else if (odabir_nogo == 1 && rez2 == rez1) {
                 cout << "Izjednaèeno." << endl;
                 balans = balans - oklada;
                 cout << "Vaš balans: " << balans << endl;
             }

             if (balans <= 0) {
                 cout << "Vas balans dosao je na 0." << endl << "Igra se zavrsava (isto ko vas jadan zivot)" << endl;
             }
             cout << endl << endl << "Za ponovno igranje pritisnite 1. Za prekid pritisnite 0" << endl;
         odb2:
             cin >> Bir2;
             if (Bir2 != 1 && Bir2 != 0)
             {
                 cout << "Pogresan odabir, birajte ponovno!" << endl;
                 goto odb2;
                 if (Bir2 == 0)
                     goto one;

             }
         } while (Bir2 == 1);
         goto one;


     }
        
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

