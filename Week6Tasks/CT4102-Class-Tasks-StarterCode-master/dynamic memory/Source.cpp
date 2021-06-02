#include <iostream>

using namespace std;

int main()
{

	int* intPtr{ nullptr };
	intPtr = new int;
	cout << intPtr << endl;
	delete intPtr;


	size_t size{ 0 };
	double* tempPtr{ nullptr };

	cout << "How many Temps?";
	cin >> size;

	tempPtr = new double[size];

	cout << tempPtr << endl;

	delete[] tempPtr;



	cout << endl;
	return 0;





}