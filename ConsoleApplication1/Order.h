#pragma once
#include<iostream>
using namespace std;
class Order
{
	string pointA;
	string pointB;
	float distance = 0;
	float cashDriver = 0;
	float cashCompany = 0;
public:
	Order();
	Order(string pontA, string pointB, float distance);
	Order(Order& order);
	Order& operator=(Order& order);
	void setPointA(string pointA);
	void setPointB(string pointB);
	void setDistance(float distance);
	void setCashDriver(float cashDriver);
	void setCashCompany(float cashCompany);
	string getPointB();
	float getDistance();
	float getCashCompany();
	void showOrder();
	void showOrderCompany();

};

