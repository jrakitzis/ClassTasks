#include <iostream>
using namespace std;


int main()
{
	int number = -1;
	int result = 0;

	do
	{
		cout << " Please enter a whole number: " << endl;
		cin >> number;
	} while (number < 1 || number > 9);

	for (int i = 1; i <= number; i++)
	{
		cout << i << endl;
		result += i;
	}

	cout << result << endl;
}

