#include<iostream>
#include<time.h>
#include<algorithm>
#include<string>
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
    string * Imeprezime = new string[1000];
    double ulog;
    while (1) {
        system("clear"); 
        cout << "Dobrodosli u kladionicu TRANSilvanija\n";
        cout << "1. Registracija" << endl;
        cout << "2. Stanje racuna" << endl;
        cout << "3. Utrke �etverono�nih tr�kala "<< endl;
        cout << "4. Nogometne utakmice" << endl;
        cout << "5. brisanje ra�una" << endl;
        cout << "6. ispi�i sortirano po prezimenu i imenu" << endl;
        cout << "7. izlaz iz programa" << endl;
        cout << "8. " << endl;
        cout << "vas odabir je: ";
        cin >> izbor;
        if (izbor == 1) 
        {
            cout << "Unesite vase ime i prezime " << endl;
            cin.ignore();
            getline(cin, *Imeprezime);
            cout << "unesite koli�inu novca kojeg �elite unesti: ";
            cin >> ulog;
        }
     if (izbor == 2) {
            cout << "Va�e stanje ra�una je:" << endl;

     }
     if (izbor == 3) {
         cout << "Odabrali ste utrke �etverono�nih tr�kala" << endl;
         cout << "PRAVILA: �etverono�na tr�kala tr�e s desna na lijevo." <<endl <<"Pobjednik je �etverono�no tr�kalo koje prvo do�e do zavr�ne linije." << endl "Ako va�e �etverono�no tr�kalo pobijedi dobitak je 1,5x va�eg uloga.";
         cout << "Odaberite jedno �etverono�no Tr�kalo:";

     }
     if (izbor == 4) {
         cout << "Odabrali ste Nogometne Utakmice:" << endl;
         cout << "PRAVILA:"<<endl<<endl "Na po�etku izlaze dva nogometna kluba koje �e odigrati utakmicu." <<endl << "Odabrani klub je pobijedio - dupli dobitak uloga." << endl "U suprotnom (gubitak ili izjedna�eno) gubite svotu uloga.";
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

