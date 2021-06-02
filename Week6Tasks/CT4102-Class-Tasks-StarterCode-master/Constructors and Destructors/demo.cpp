#include <iostream>
#include "car.h"

void RepairCar(Car* carToRepair);

int main()
{
	Car myCar(2018, 300, "BMW");
	myCar.Display();
	myCar.Drive(200);
	myCar.Display();

	Car* secondCar = new Car(2018, 300, "BMW");
	secondCar->Display();
	secondCar->Drive(200);
	secondCar->Display();

	RepairCar(nullptr);

	if (myCar.m_repaired == true)
	{
		// do something
	}

}

void RepairCar(Car* carToRepair)
{
	if (!carToRepair) return; // Early out
	
	carToRepair->m_repaired = true;
}