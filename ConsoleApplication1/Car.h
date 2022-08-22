#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include<iostream>
using namespace std;
#include "Order.h"
#include <conio.h>


class Car
{
	static int counterTaxi;
	int idCar = 0;
	int connect = 0;
	string number;
	string model;
	bool status = false;
	Order* order = nullptr;
	int sizeOrder = 0;
	static float cashCompany;
public:
	Car();
	Car(string number,string model);
	~Car();
	Car(Car& car);
	Car& operator=(Car& car);
	bool getStatus();
	int getSizeOrder();
	void setConnect(int connect);
	int getConnect();
	void setIdCar(int idCar);
	int getIdCar();
	static int getCounterTaxi();
	static void setCounterTaxi(int count);
	static float getCashCompany();
	bool findCar(int id);
	void delDriverCar();
	void info();
	void infoOrder();
	Car creatCar();
	void addOrder();
	void showAllOrder();
	void showAllOrderCash();
};

