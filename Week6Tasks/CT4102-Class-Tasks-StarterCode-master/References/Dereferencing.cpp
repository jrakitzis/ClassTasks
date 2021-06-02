#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int score{ 100 };
	int* score_ptr{ &score };
	
	cout << *score_ptr << endl;

	*score_ptr = 200;

	cout << *score_ptr << endl;
	cout << score << endl;

	cout << "\n----------------------" << endl;
	
	double HighTemp{ 100.7 };
	double LowTemp{ 37.4 };
	double* temp_ptr{ &HighTemp };

	cout << *temp_ptr << endl;
	temp_ptr = &LowTemp;
	cout << *temp_ptr << endl;


	cout << "\n----------------------" << endl;


	string name{ "Frank" };
	string* stringPtr{ &name };

	cout << *stringPtr << endl;
	name = "James";
	cout << *stringPtr << endl;

	cout << "\n----------------------" << endl;

	vector<string> stooges{ "Larry","Moe","Curly" };
	vector<string>* vectorPtr{ nullptr };

	cout << "First Stooge: " << (*vectorPtr).at(0) << endl;
	cout << "Stooges: ";
	for (auto stooge : *vectorPtr)
		cout << stooge << "";
	cout << endl;

	cout << endl;
	return 0;


}
