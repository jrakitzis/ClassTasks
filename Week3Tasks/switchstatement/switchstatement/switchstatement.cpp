#include <iostream>
using namespace std;

enum drink
{
    coke,
    pepsi,
    drpepper,
    water,
    icedtea
};

int main()
{
    int selectedDrink = -1;

    cout << "Select a beverage:";
    cin >> selectedDrink;

    switch (selectedDrink)
    {
        case coke:
        {
            cout << " You chose Coke " << endl;
            break;
        }
        case pepsi:
        {
            cout << " You chose Pepsi " << endl;
            break;
        }
        case drpepper:
        {
            cout << " You chose Dr Pepper " << endl;
            break;
        }
        case water:
        {
            cout << " You chose Water" << endl;
            break;
        }
        case icedtea:
        {
            cout << " You chose Iced Tea" << endl;
            break;
        }
        default:
        {
            break;
        }
    }
}