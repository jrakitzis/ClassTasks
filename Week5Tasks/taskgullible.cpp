#include <iostream>  
using namespace std;


int main()
{

    int UserNumber = 0;
    int TotalGuesses = 1;
    while (TotalGuesses < 11)
    {
        cout << "Enter any number other than 5: \n";
        cin >> UserNumber;

        if (UserNumber == 5)
        {
            cout << "Hey! You weren't supposed to enter 5!\n";
            break;
        }

        else if (TotalGuesses == 10)
        {
            cout << "Wow, you're more patient then I am, you win.\n";
            break;
        }
        TotalGuesses++;
    }

}