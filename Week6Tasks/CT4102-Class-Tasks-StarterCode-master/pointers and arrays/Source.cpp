#include <iostream>


using namespace std;

int main() {
	
	int scores[]{ 100,95,89 };

	cout << "Value of Scores: " << scores << endl;

	int* scorePtr = nullptr;
	scorePtr = scores;

	cout << "\nArray subscript notation----------------" << endl;
	cout << scores[0] << endl;
	cout << scores[1] << endl;
	cout << scores[2] << endl;

	cout << "\nPointer subscript notation----------------" << endl;
	cout << scorePtr[0] << endl;
	cout << scorePtr[1] << endl;
	cout << scorePtr[2] << endl;

	cout << "\nPointer offset notation------------------" << endl;
	cout << *scorePtr << endl;
	cout << *(scorePtr+1) << endl;
	cout << *(scorePtr+2) << endl;

	cout << "\nArray offset notation------------------" << endl;
	cout << *scores << endl;
	cout << *(scores + 1) << endl;
	cout << *(scores + 2) << endl;

	cout << endl;
	return 0;
}