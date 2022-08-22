#include "Driver.h"

Driver::Driver()
{
}

Driver::Driver(string name, string phone)
{
	this->name = name;
	this->phone = phone;
	this->idDriver = Driver::counterDriver++;
}

Driver::Driver(Driver& driver)
{
	this->name = driver.name;
	this->phone = driver.phone;
	this->idDriver = driver.idDriver;
	this->connect = driver.connect;
}

Driver& Driver::operator=(Driver& driver)
{
	this->name = driver.name;
	this->phone = driver.phone;
	this->idDriver = driver.idDriver;
	this->connect = driver.connect;
	return *this;
}

void Driver::showDriver()
{
	if (connect == 0)
	{
		cout << "Free ||\t";
	}
	else cout << "id car: " << this->connect << " || ";
	cout << "Id driver: " << this->idDriver << "||" << "Name: " << this->name << "||" << "Phone: " << this->phone << "||" << endl;
}

int Driver::getIdDriver()
{
	return idDriver;
}

void Driver::setIdDriver(int number)
{
	this->idDriver = number;
}

int Driver::getCounterDriver()
{
	return counterDriver++;
}

void Driver::setCounterDriver(int count)
{
	counterDriver = count;
}

string Driver::getName()
{
	return this->name;
}

string Driver::getPhone()
{
	return this->phone;
}

void Driver::setConnect(int idDriver)
{
	this->connect = idDriver;
}

int Driver::getConnect()
{
	return connect;
}



void Driver::setName(string name)
{
	this->name = name;
}

void Driver::setPhone(string phone)
{
	this->phone = phone;
}

void Driver::delCar()
{
	this->connect = 0;
}



