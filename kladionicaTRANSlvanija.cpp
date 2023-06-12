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
#include <chrono>
#include <thread>
using namespace std;

void pauza() {
    cout << endl << "Pritisnite enter za nastavak...";
    string dummy;
    cin.ignore();
    getline(cin, dummy);
}
struct GameData {
    int balance;
    int jackpot;
};

int getStartingBalance() {
    int startingBalance;
    cout << "Enter your starting balance: ";
    cin >> startingBalance;
    return startingBalance;
}

void displayRules() {
    cout << "----- SLOT MACHINE RULES -----\n";
    cout << "Match three symbols to win.\n";
    cout << "The jackpot grows with each spin.\n";
    cout << "If you win the jackpot, you have the option to gamble your winnings.\n";
    cout << "If you choose to gamble, you have a 50% chance of doubling your winnings, but you can also lose them.\n";
    cout << "Good luck!\n";
    cout << "------------------------------\n";
}

void displayIntro() {
    cout << "Welcome to the Slot Machine Game!\n";
    cout << "------------------------------\n";
    cout << "In this game, you will spin the reels and try to match three symbols to win.\n";
    cout << "The jackpot grows with each spin, and if you win it, you have the option to gamble your winnings.\n";
    cout << "Choose your bet amount, and let's get started!\n";
    cout << "------------------------------\n";
}

void displayDifficultyOptions() {
    cout << "Choose a difficulty level:\n";
    cout << "1. Easy (2x reward, higher chance of winning)\n";
    cout << "2. Medium (5x reward)\n";
    cout << "3. Hard (10x reward, lower chance of winning)\n";
}

int getDifficulty() {
    int difficulty;
    displayDifficultyOptions();
    cout << "Enter your choice (1-3): ";
    cin >> difficulty;
    return difficulty;
}

int getBetAmount(int balance) {
    int betAmount;
    cout << "Enter your bet amount (current balance: $" << balance << "): ";
    cin >> betAmount;
    return betAmount;
}

int getRandomNumber() {
    return rand() % 5 + 1; // Generates a random number between 1 and 5
}

void displaySymbols(int delay) {
    for (int i = 0; i < 3; i++) {
        int symbol = getRandomNumber();
        switch (symbol) {
        case 1:
            cout << "Cherry\t";
            break;
        case 2:
            cout << "Orange\t";
            break;
        case 3:
            cout << "Grape\t";
            break;
        case 4:
            cout << "Bell\t";
            break;
        case 5:
            cout << "Star\t";
            break;
        }
    }

    // Pause for a longer delay to enhance display
    this_thread::sleep_for(chrono::milliseconds(delay));
}

bool playAgain() {
    char choice;
    cout << "------------------------------\n";
    cout << "Play again? (Y/N): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}

void displayJackpot(int jackpot) {
    cout << "Current Jackpot: $" << jackpot << endl;
}

bool isLuckySpin() {
    return (getRandomNumber() == 1); // 1 in 5 chance of a lucky spin
}

void displayAddFundsOption() {
    cout << "------------------------------\n";
    cout << "Your balance is 0. What would you like to do?\n";
    cout << "1. Add more funds\n";
    cout << "2. Quit the game\n";
    cout << "Enter your choice (1-2): ";
}

void saveGameData(const GameData& gameData) {
    ofstream outputFile("game_data.bin", ios::binary);
    if (outputFile.is_open()) {
        outputFile.write(reinterpret_cast<const char*>(&gameData), sizeof(GameData));
        outputFile.close();
    }
}

GameData loadGameData() {
    GameData gameData;
    ifstream inputFile("game_data.bin", ios::binary);
    if (inputFile.is_open()) {
        inputFile.read(reinterpret_cast<char*>(&gameData), sizeof(GameData));
        inputFile.close();
    }
    return gameData;
}

void deleteGameDataFile() {
    remove("game_data.bin");
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
        cout << "4. Slot masine" << endl;
        cout << "5. Utrke cetveronoznih trckala" << endl;
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
                cout << "Cestitamo! Pogodili ste " << brojac << " brojeva." << endl;
            }

            delete[] polje;
            delete[] brojevi;
        }
        string str;
        cin.ignore();
        getline(cin, str);
        if (izbor == 4)
        {
            srand(time(0)); // Initialize random seed

            displayIntro();

            char viewRulesChoice;
            cout << "Would you like to view the rules? (Y/N): ";
            cin >> viewRulesChoice;

            if (viewRulesChoice == 'Y' || viewRulesChoice == 'y') {
                displayRules();
            }

            char quitGameChoice;
            cout << "Do you want to quit the game? (Y/N): ";
            cin >> quitGameChoice;

            if (quitGameChoice == 'Y' || quitGameChoice == 'y') {
                cout << "Thank you for playing!\n";
                return 0;
            }

            GameData gameData;
            bool isNewGame = true;

            // Load game data if it exists
            if (ifstream("game_data.bin")) {
                gameData = loadGameData();
                isNewGame = false;
            }
            else {
                gameData.balance = getStartingBalance();
                gameData.jackpot = 100;
            }

            int betAmount;
            bool continuePlaying = true;

            while (continuePlaying) {
                int difficulty = getDifficulty();
                double winProbability;
                int rewardMultiplier;

                switch (difficulty) {
                case 1: // Easy difficulty
                    winProbability = 0.8;
                    rewardMultiplier = 2;
                    break;
                case 2: // Medium difficulty
                    winProbability = 0.5;
                    rewardMultiplier = 5;
                    break;
                case 3: // Hard difficulty
                    winProbability = 0.3;
                    rewardMultiplier = 10;
                    break;
                default:
                    cout << "Invalid difficulty selected. Defaulting to Easy difficulty.\n";
                    winProbability = 0.8;
                    rewardMultiplier = 2; // Default to easy difficulty
                    break;
                }

                betAmount = getBetAmount(gameData.balance);

                if (betAmount > gameData.balance) {
                    cout << "Insufficient balance. Please enter a valid bet amount.\n";
                    continue;
                }

                cout << "------------------------------\n";
                cout << "Spinning the reels...\n";

                // Display spinning animation with pauses between each spin
                for (int i = 0; i < 3; i++) {
                    cout << "------------------------------\n";
                    displaySymbols(1500);
                }

                cout << "------------------------------\n";
                cout << "Final spin:\n";
                displaySymbols(0);

                int symbol1 = getRandomNumber();
                int symbol2 = getRandomNumber();
                int symbol3 = getRandomNumber();

                switch (symbol1) {
                case 1:
                    cout << "Cherry\t";
                    break;
                case 2:
                    cout << "Orange\t";
                    break;
                case 3:
                    cout << "Grape\t";
                    break;
                case 4:
                    cout << "Bell\t";
                    break;
                case 5:
                    cout << "Star\t";
                    break;
                }

                switch (symbol2) {
                case 1:
                    cout << "Cherry\t";
                    break;
                case 2:
                    cout << "Orange\t";
                    break;
                case 3:
                    cout << "Grape\t";
                    break;
                case 4:
                    cout << "Bell\t";
                    break;
                case 5:
                    cout << "Star\t";
                    break;
                }

                switch (symbol3) {
                case 1:
                    cout << "Cherry\t";
                    break;
                case 2:
                    cout << "Orange\t";
                    break;
                case 3:
                    cout << "Grape\t";
                    break;
                case 4:
                    cout << "Bell\t";
                    break;
                case 5:
                    cout << "Star\t";
                    break;
                }

                if (symbol1 == symbol2 && symbol2 == symbol3) {
                    int winnings = betAmount * rewardMultiplier;
                    gameData.balance += winnings;
                    gameData.jackpot += betAmount;

                    cout << "\nCongratulations! You won $" << winnings << "!\n";
                    displayJackpot(gameData.jackpot);

                    if (isLuckySpin()) {
                        char gambleChoice;
                        cout << "You have the option to gamble your winnings. Would you like to gamble? (Y/N): ";
                        cin >> gambleChoice;

                        if (gambleChoice == 'Y' || gambleChoice == 'y') {
                            int gambleResult = getRandomNumber();
                            if (gambleResult <= 2) {
                                cout << "Congratulations! You doubled your winnings!\n";
                                gameData.balance += winnings;
                            }
                            else {
                                cout << "Oops! You lost your winnings!\n";
                                gameData.balance -= winnings;
                            }
                        }
                    }
                }
                else {
                    cout << "\nSorry, you didn't win this time.\n";
                    gameData.balance -= betAmount;
                }

                displayJackpot(gameData.jackpot);
                cout << "Current Balance: $" << gameData.balance << endl;

                if (gameData.balance <= 0) {
                    cout << "You have run out of balance.\n";
                    break;
                }

                saveGameData(gameData);

                if (isNewGame) {
                    deleteGameDataFile();
                    isNewGame = false;
                }

                continuePlaying = playAgain();
            }

            cout << "Thank you for playing!\n";

            return 0;
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
                this_thread::sleep_for(chrono::milliseconds(700));
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

                this_thread::sleep_for(chrono::milliseconds(700));
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

                this_thread::sleep_for(chrono::milliseconds(700));
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
        else
            pauza();   
        }

        return 0;
    }
  