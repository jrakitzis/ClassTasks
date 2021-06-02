#pragma once
#include <string>

class Car
{
	// member variables
	int m_year;
	int m_miles;
	std::string m_brand;

public:
	// constructors
	Car();
	Car(int year, int miles, std::string brand);

		//destructor
	~Car();


	//member functions
	void Display();
	void Drive(int miles);

	//public member variables
	bool m_repaired;

};