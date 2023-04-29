#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const int MAX_WRONG = 7;

    srand(static_cast<unsigned int>(time(0)));
    string WORDS[] = { "PROGRAM", "BILGISAYAR", "MATEMATIK", "DUNYA", "ISLETIM" };
    int n = (rand() % 5);
    string WORD = WORDS[n];
    int wrong = 0;
    string soFar(WORD.size(), '-');
    string used = "";

    cout << "ADAM ASMACA OYUNUNA HO�GELD�N�Z!" << endl;

    while ((wrong < MAX_WRONG) && (soFar != WORD))
    {
        cout << "\n\n" << soFar << endl;
        cout << "\nYanl�� tahminleriniz: " << used << endl;
        cout << "\n" << MAX_WRONG - wrong << " hakk�n�z kald�. Bir harf tahmin edin: ";
        char guess;
        cin >> guess;
        guess = toupper(guess);

        while (used.find(guess) != string::npos)
        {
            cout << "\nBu harfi zaten tahmin ettiniz. L�tfen ba�ka bir harf girin: ";
            cin >> guess;
            guess = toupper(guess);
        }

        used += guess;

        if (WORD.find(guess) != string::npos)
        {
            cout << "\nTebrikler! '" << guess << "' harfi do�ru tahmin ettiniz." << endl;
            for (unsigned int i = 0; i < WORD.length(); ++i)
            {
                if (WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            cout << "\nMaalesef, '" << guess << "' harfi yanl�� tahmin ettiniz." << endl;
            ++wrong;
        }
    }

    if (wrong == MAX_WRONG)
    {
        cout << "\n\nMaalesef, kaybettiniz. Do�ru kelime '" << WORD << "' idi." << endl;
    }
    else
    {
        cout << "\n\nTebrikler, kazand�n�z! Do�ru kelime '" << WORD << "' idi." << endl;
    }

    return 0;
}
