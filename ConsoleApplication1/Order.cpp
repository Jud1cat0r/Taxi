#include "Order.h"

Order::Order()
{
}

Order::Order(string pontA, string pointB, float distance)
{
	this->pointA = pointA;
	this->pointB = pointB;
	this->distance = distance;
	this->cashDriver = ((52 + distance * 30) / 100) * 85;
	this->cashDriver = ((52 + distance * 30) / 100) * 15;
}

Order::Order(Order& order)
{
	this->pointA = order.pointA;
	this->pointB = order.pointB;
	this->distance = order.distance;
	this->cashDriver = order.cashDriver;
	this->cashCompany = order.cashCompany;
}

Order& Order::operator=(Order& order)
{
	this->pointA = order.pointA;
	this->pointB = order.pointB;
	this->distance = order.distance;
	this->cashDriver = order.cashDriver;
	this->cashCompany = order.cashCompany;
	return *this;
}

void Order::setPointA(string pointA)
{
	this->pointA = pointA;
}

void Order::setPointB(string pointB)
{
	this->pointB = pointB;
}

void Order::setDistance(float distance)
{
	this->distance = distance;
}

void Order::setCashDriver(float cashDriver)
{
	this->cashDriver = cashDriver;
}

void Order::setCashCompany(float cashCompany)
{
	this->cashCompany = cashCompany;
}

string Order::getPointB()
{
	return pointB;
}

float Order::getDistance()
{
	return this->distance;
}

float Order::getCashCompany()
{
	return this->cashCompany;
}

void Order::showOrder()
{
	cout << "from: " << pointA << " || " << "to: " << pointB << " || " << "distance: " << distance << " || " << "cash Driver: " << cashDriver << " || " << "cash Company: " << cashCompany << " || " << endl;
}

void Order::showOrderCompany()
{
	cout << "from: " << pointA << " || " << "to: " << pointB << " || " << "distance: " << distance << " || " << "cash Company: " << cashCompany << "||" << endl;
}

