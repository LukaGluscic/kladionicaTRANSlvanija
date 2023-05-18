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
    while (1) {
        system("clear"); 
        cout << "Dobrodosli u kladionicu TRANSilvanija\n";
        cout << "1. Registracija" << endl;
        cout << "2. Stanje racuna" << endl;
        cout << "3. Utrke èetveronožnih trèkala "<< endl;
        cout << "4. pretraga prema prezimenu i imenu" << endl;
        cout << "5. brisanje raèuna" << endl;
        cout << "6. ispiši sortirano po prezimenu i imenu" << endl;
        cout << "7. izlaz iz programa" << endl;
        cout << "8. " << endl;
        cout << "vas odabir je: ";
        cin >> izbor;
}