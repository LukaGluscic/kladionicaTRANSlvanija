#include<iostream>
#include<time.h>
#include<algorithm>
#include<string>
#include<cctype>
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
    while (1) {
        cout << "Dobrodosli u kladionicu TRANSilvanija\n" << endl;
        cout << "1. Registracija" << endl;
        cout << "2. Stanje racuna" << endl;
        cout << "3. Uplata  " << endl;
        cout << "4. Nogometne utakmice" << endl;
        cout << "5. Utrke cetveronoznih trckala" << endl;
        cout << "6. " << endl;
        cout << "7. izlaz iz programa" << endl;
        cout << "8. " << endl;
        cout << "vas odabir je: ";
        cin >> izbor;
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
        if (izbor == 3) {
            
    }
}
     if (izbor == 4) {
         cout << "Odabrali ste Nogometne Utakmice:" << endl;
         cout << "PRAVILA:"<<endl<<endl "Na poèetku izlaze dva nogometna kluba koje æe odigrati utakmicu." <<endl << "Odabrani klub je pobijedio - dupli dobitak uloga." << endl "U suprotnom (gubitak ili izjednaèeno) gubite svotu uloga.";
         int odabir_nogometni_tim;
         int real, bayern, FC, arsenal, PSG, chelsea, bayern, city, united, juv, pool;
        
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

