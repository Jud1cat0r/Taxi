#include <iostream>
#include <Windows.h>
#include "Taxi.h"
#include "Car.h"
#include <conio.h>

int Driver::counterDriver = 1;
int Car::counterTaxi = 1;
float Car::cashCompany = 0;



int main()
{
	Taxi taxi;
	Car car1("Y123TR", "Lada");
	Car car2("I543PO", "Niva");
	Car car3("L754UO", "Audi");
	Driver dr1("Petr", "+7934523453");
	Driver dr2("John", "+7935464356");
	taxi.addCar(car1);
	taxi.addCar(car2);
	taxi.addCar(car3);
	taxi.addDriver(dr1);
	taxi.addDriver(dr2);
	taxi.menu();


}
