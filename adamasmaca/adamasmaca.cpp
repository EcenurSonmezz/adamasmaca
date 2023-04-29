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

    cout << "ADAM ASMACA OYUNUNA HOÞGELDÝNÝZ!" << endl;

    while ((wrong < MAX_WRONG) && (soFar != WORD))
    {
        cout << "\n\n" << soFar << endl;
        cout << "\nYanlýþ tahminleriniz: " << used << endl;
        cout << "\n" << MAX_WRONG - wrong << " hakkýnýz kaldý. Bir harf tahmin edin: ";
        char guess;
        cin >> guess;
        guess = toupper(guess);

        while (used.find(guess) != string::npos)
        {
            cout << "\nBu harfi zaten tahmin ettiniz. Lütfen baþka bir harf girin: ";
            cin >> guess;
            guess = toupper(guess);
        }

        used += guess;

        if (WORD.find(guess) != string::npos)
        {
            cout << "\nTebrikler! '" << guess << "' harfi doðru tahmin ettiniz." << endl;
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
            cout << "\nMaalesef, '" << guess << "' harfi yanlýþ tahmin ettiniz." << endl;
            ++wrong;
        }
    }

    if (wrong == MAX_WRONG)
    {
        cout << "\n\nMaalesef, kaybettiniz. Doðru kelime '" << WORD << "' idi." << endl;
    }
    else
    {
        cout << "\n\nTebrikler, kazandýnýz! Doðru kelime '" << WORD << "' idi." << endl;
    }

    return 0;
}
