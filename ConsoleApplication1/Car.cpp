#include "Car.h"

Car::Car()
{
	
}

Car::Car(string number, string model)
{
	this->number = number;
	this->model = model;
	this->idCar = Car::counterTaxi++;
}

Car::~Car()
{
	//delete[] order;
}

Car::Car(Car& car)
{
	this->idCar = car.idCar;
	this->connect = car.connect;
	this->number = car.number;
	this->model = car.model;
	this->status = car.status;
	this->sizeOrder = car.sizeOrder;
	for (int i = 0; i < car.sizeOrder; i++)
	{
		this->order[i] = car.order[i];
	}
}

Car& Car::operator=(Car& car)
{
	this->idCar = car.idCar;
	this->connect = car.connect;
	this->number = car.number;
	this->model = car.model;
	this->status = car.status;
	this->sizeOrder = car.sizeOrder;
	for (int i = 0; i < car.sizeOrder; i++)
	{
		this->order[i] = car.order[i];
	}
	return *this;
}

bool Car::getStatus()
{
	return this->status;
}

int Car::getSizeOrder()
{
	return sizeOrder;
}

void Car::setConnect(int connect)
{
	this->connect = connect;
}

int Car::getConnect()
{
	return connect;
}

void Car::setIdCar(int idCar)
{
	this->idCar = idCar;
}



int Car::getIdCar()
{
	return idCar;
}

int Car::getCounterTaxi()
{
	return Car::counterTaxi;
}

void Car::setCounterTaxi(int count)
{
	Car::counterTaxi += count;
}


bool Car::findCar(int id)
{
	if(this->idCar == id)return true;
	return false;
}

float Car::getCashCompany()
{
	return Car::cashCompany;
}

void Car::info()
{
	if (connect == 0)
	{
		cout << "Free ||\t";
	}
	else cout << "id driver: " << connect << " || ";
	cout << "id car: " << this->idCar << "||" << "Number: " << this->number << "||" << "Model: " << this->model << "||" << endl;
}


void Car::infoOrder()
{
	if (connect != 0)
	{
		if (status == false)
		{
			cout << "Free ||\t";
		}
		else cout << "Busy" << " || ";
		cout << "id car: " << this->idCar << "||" << "Number: " << this->number << "||" << "Model: " << this->model << "||";
		if (status == true) cout << order[sizeOrder - 1].getPointB() << endl;
		else cout << endl;
	}
}

void Car::delDriverCar()
{
	this->connect = 0;

}

Car Car::creatCar()
{
	cout << "Input number: ";
	cin >> this->number;
	cout << endl;
	cout << "Input model: ";
	cin >> this->model;
	cout << endl;
	return *this;
}

void Car::addOrder()
{
	time_t t1 = time(NULL);
	tm t = *localtime(&t1);
	Order* buf = new Order[sizeOrder + 1];
	Order ord;
	float a;
	string b, c;
	cout << "input pointA: ";
	cin >> b;
	ord.setPointA(b);
	cout << endl;
	cout<< "input pointB: ";
	cin >> c;
	ord.setPointB(c);
	cout << endl;
	cout << "input distance: ";
	cin >> a;
	ord.setDistance(a);

	if (t.tm_hour >= 7 && t.tm_min >= 30 && t.tm_hour < 10 || t.tm_hour >= 8 && t.tm_hour < 10 || t.tm_hour >= 17 && t.tm_hour < 20)
	{
		ord.setCashDriver(((52 + ord.getDistance() * 30) / 100) * 85);
		ord.setCashCompany(((52 + ord.getDistance() * 30) / 100) * 15);
	}
	else
	{
		ord.setCashDriver(((52 + ord.getDistance() * 25) / 100) * 85);
		ord.setCashCompany(((52 + ord.getDistance() * 25) / 100) * 15);
	}


	for (int i = 0; i < sizeOrder; i++)
	{
		buf[i] = order[i];
	}
	buf[sizeOrder] = ord;
	delete[] order;
	order = buf;
	sizeOrder++;
	this->status = true;
}

void Car::showAllOrder()
{
	for (int i = 0; i < sizeOrder; i++)
	{
		cout << idCar << " || ";
		order[i].showOrder();
		cout << endl;
	}
}

void Car::showAllOrderCash()
{

	for (int i = 0; i < sizeOrder; i++)
	{
		cout << idCar << " || ";
		order[i].showOrderCompany();
		cout << endl;
		Car::cashCompany += order[i].getCashCompany();
	}

}
