#include <iostream>
#include <vector>
#include <string>
using namespace std;


int *p;

int main()
{
	int num{ 10 };
	cout << " value of num is: " << num << endl;
	cout << " size of num is: " << sizeof num << endl;
	cout << " address of num is: " << &num << endl;




	
	cout << "\nValue of p is: " << p << endl;
	cout << "Address of p is: " << &p << endl;
	cout << "sizeof p is: " << sizeof p << endl;

	p = nullptr;
	cout << "\nValue of p is: " << p << endl;

	int* p1{ nullptr };
	double* p2{ nullptr };
	unsigned long long* p3{ nullptr };
	vector<string>* p4{ nullptr };
	string* p5{ nullptr };

	cout << "\n sizeof p1 is : " << sizeof p1 << endl;
	cout << " sizeof p2 is: " << sizeof p2 << endl;
	cout << " sizeof p3 is: " << sizeof p3 << endl;
	cout << " sizeof p4 is: " << sizeof p4 << endl;
	cout << " size of p5 is: " << sizeof p5 << endl;

	int score{ 10 };
	double high_temp{ 100.7 };

	int* score_ptr{ nullptr };

	score_ptr = &score;
	cout << "\nValue of score is: " << score << endl;
	cout << " Adress of score is: " << &score << endl;
	cout << " Value of score is: " << score_ptr << endl;


	return 0;


}