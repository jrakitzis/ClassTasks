#include <iostream>
using namespace std;

int main()
{
	int grade;
	cout << "Enter a Grade 0-100:";
	cin >> grade;

	if (grade >= 80)
	{
		cout << " A+ " << endl;
	}
	else if (grade >= 70)
	{
		cout << " A " << endl;
	}
	else if (grade >= 60)
	{
		cout << " B " << endl;
	}
	else if (grade >= 50)
	{
		cout << " C " << endl;
	}
	else if (grade >= 40)
	{
		cout << " D " << endl;
	}
	else if (grade >= 1)
	{
		cout << " F " << endl;
	}
	else
	{
		cout << " U " << endl;
	}
}