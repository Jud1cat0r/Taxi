#pragma once
#include<iostream>

using namespace std;
class Driver
{
	static int counterDriver;
	int idDriver = 0;
	int connect = 0;
	string name;
	string phone;
public:
	Driver();
	Driver(string name, string phone);
	Driver(Driver& driver);
	Driver& operator =(Driver& driver);
	void showDriver();
	int getIdDriver();
	void setIdDriver(int number);
	static int getCounterDriver();
	static void setCounterDriver(int count);
	string getName();
	string getPhone();
	void setConnect(int idDriver);
	int getConnect();
	void setName(string name);
	void setPhone(string phone);
	void delCar();
};
