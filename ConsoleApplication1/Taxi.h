#pragma once
#include<iostream>
#include <conio.h>
using namespace std;
#include "Car.h"
#include "Driver.h"



class Taxi
{
	Car* car = nullptr;
	Driver* driver = nullptr;
	int sizeTaxi = 0;
	int sizeDriver = 0;
public:
	~Taxi();
	void addCar();
	void addCar(Car& carAdd);
	void addDriver();
	void addDriver(Driver& addDriver);
	void delDriver();
	void delCar();
	void driverToCar(int id1, int id2);
	void untieDriver(int id);
	void untieCar(int id);
	void showCar();
	void showFreeOrderCar();
	void showFreeCar();
	void showAllDriver();
	void showFreeDriver();
	void showAllOrderCar(Car&car);
	void showAllOrderCar();
	void menu();
};

