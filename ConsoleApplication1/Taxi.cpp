#include "Taxi.h"

Taxi::~Taxi()
{
	delete[] car;
	delete[] driver;
}


void Taxi::addCar()
{
	Car carAdd;
	carAdd.creatCar();
	this->addCar(carAdd);
}

void Taxi::addCar(Car& carAdd)
{
	carAdd.setIdCar(Car::getCounterTaxi());
	Car::setCounterTaxi(1);
	Car* buf = new Car[sizeTaxi + 1];
	for (int i = 0; i < sizeTaxi; i++)
	{
		buf[i] = car[i];
	}
	buf[sizeTaxi] = carAdd;
	delete[] car;
	car = buf;
	sizeTaxi++;
}
void Taxi::addDriver()
{
	Driver* buf = new Driver[sizeDriver + 1];
	Driver dr;
	string a, b;
	cout << endl << "input name: ";
	cin >> a;
	dr.setName(a);
	cout << endl;
	cout << endl << "input phone: ";
	cin >> b;
	dr.setPhone(b);
	dr.setIdDriver(Driver::getCounterDriver());
	for (int i = 0; i < sizeDriver; i++)
	{
		buf[i] = driver[i];
	}
	buf[sizeDriver] = dr;
	delete[] driver;
	driver = buf;
	sizeDriver++;
}

void Taxi::addDriver(Driver& addDriver)
{
	Driver* buf = new Driver[sizeDriver + 1];
	for (int i = 0; i < sizeDriver; i++)
	{
		buf[i] = driver[i];
	}
	buf[sizeDriver] = addDriver;
	delete[]driver;
	driver = buf;
	sizeDriver++;
}

void Taxi::delDriver()
{
	int idDriver = 0;
	cout << endl << "Input id driver: ";
	cin >> idDriver;
	Driver* buf = new Driver[sizeDriver - 1];
	for (int i = 0, k = 0; i < sizeDriver; i++)
	{
		if (driver[i].getIdDriver() != idDriver) buf[k++] = driver[i];
	}
	delete[]driver;
	driver = buf;
	sizeDriver--;
}

void Taxi::delCar()
{
	system("cls");
	for (int i = 0; i < sizeTaxi; i++)
	{
		car[i].info();
	}
	cout << endl << endl;
	cout << endl << "Input id car: ";
	int idCar = 0;
	cin >> idCar;
	bool flag = false;
	for (int i = 0, k = 0; i < sizeTaxi; i++)
	{
		if (car[i].findCar(idCar) == true)
		{
			flag = true;
			Car* buf = new Car[sizeTaxi - 1];
			for (int j = 0; j < i; j++)
			{
				buf[k++] = car[j];
			}
			for (int j = i + 1; j < sizeTaxi; j++)
			{
				buf[k++] = car[j];
			}
			delete[] car;
			car = buf;
			sizeTaxi--;
			cout << "Car delete";
		}
	}
	if(flag == false) cout << "No this car";
}

void Taxi::driverToCar(int id1, int id2)
{
	char c;
	bool flag1 = false;
	bool flag2 = false;
	for (int i = 0; i < sizeTaxi; i++)
	{
		if (car[i].getIdCar() == id1)
		{
			flag1 = true;
			for (int j = 0; j < sizeDriver; j++)
			{
				if (driver[j].getIdDriver() == id2)
				{
					flag2 = true;
					car[i].setConnect(id2);
					driver[j].setConnect(id1);
				}
			}
		}
	}
	if (flag1 == false) cout << "No this car" << endl << endl;
	if (flag2 == false) cout << "No this driver" << endl << endl;
	if (flag2 == true) cout << "Connect complete" << endl << endl;
	cout << "|| Esc-Return||";

	c = _getch();
	switch (c)
	{
	case 27:
		system("cls");
		this->menu();
		break;
	}
}

void Taxi::untieDriver(int id)
{
	for (int i = 0; i < sizeTaxi; i++)
	{
		if (car[i].getIdCar() == id)
		{
			if (car[i].getConnect() != 0)
			{
				for (int j = 0; j < sizeDriver; j++)
				{
					if (driver[j].getIdDriver() == car[i].getConnect())
					{
						driver[j].delCar();
						car[i].delDriverCar();
					}
				}
			}
			else cout << "Car not connect";
		}
		else cout << "Error id car";
	}
}

void Taxi::untieCar(int id)
{
	for (int i = 0; i < sizeDriver; i++)
	{
		if (driver[i].getIdDriver() == id)
		{
			if (driver[i].getConnect() != 0)
			{
				for (int j = 0; j < sizeTaxi; j++)
				{
					if (car[j].getIdCar() == driver[j].getConnect())
					{
						driver[j].delCar();
						car[i].delDriverCar();
					}
				}
			}
			else cout << "Driver not connect";
		}
		else cout << "Error id driver";
	}
}


void Taxi::showCar()//сделать меню
{
	int id = 0;
	while (true)
	{
		system("cls");
		for (int i = 0; i < sizeTaxi; i++)
		{
			car[i].info();
		}
		cout << endl << endl;
		cout << "1-Add car" << " || " << "2-Delete car" << " || " << "3-Untie the driver" << " || " << "Esc - Return" << " || " << endl;
		char c;
		c = _getch();
		switch (c)
		{
		case 49:
			this->addCar();
			break;
		case 50:
			this->delCar();
			break;
		case 51:
			cout << endl << "Input id car: ";
			cin >> id;
			this->untieDriver(id);
			break;
		case 27:
			system("cls");
			this->menu();
			break;
		}
	}
}

void Taxi::showFreeOrderCar()//сделать меню
{
	while (true)
	{
		system("cls");
		for (int i = 0; i < sizeTaxi; i++)
		{
			car[i].infoOrder();
		}
		cout << endl << endl;
		cout << "1-Add order" << " || " << "2-Check orders" << " || " << "Esc-Return" << " || ";
		char c;
		int id = 0;
		c = _getch();
		switch (c)
		{
		case 49:
			cout << endl << "Input id car: ";
			cin >> id;
			system("cls");
			for (int i = 0; i < sizeTaxi; i++)
			{
				if (car[i].getIdCar() == id)
				{
					car[i].addOrder();
				}
			}
			break;
		case 50:
			cout << endl << "Input id car: ";
			cin >> id;
			system("cls");
			for (int i = 0; i < sizeTaxi; i++)
			{
				if (car[i].getIdCar() == id)
				{
					this->showAllOrderCar(car[i]);
				}
			}
			break;
		case 27:
			system("cls");
			this->menu();
			break;
		}
	}
}

void Taxi::showFreeCar()//сделать меню
{
	while (true)
	{
		for (int i = 0; i < sizeTaxi; i++)
		{
			if (car[i].getConnect() == 0) car[i].info();
		}
		cout << endl << endl;
		cout << "1-Add driver to car" << " || " << "Esc-Return" << " || ";
		char c;
		int id1 = 0, id2 = 0;
		c = _getch();
		switch (c)
		{
		case 49:
			cout << endl << "Input id car: ";
			cin >> id1;
			system("cls");
			for (int i = 0; i < sizeDriver; i++)
			{
				if (driver[i].getConnect() == 0) driver[i].showDriver();
			}
			cout << endl << "Input id driver: ";
			cin >> id2;
			this->driverToCar(id1, id2);
			break;
		case 27:
			system("cls");
			this->menu();
			break;
		}
	}
}

void Taxi::showAllDriver()//сделать меню
{
	int id = 0;
	while (true)
	{
		system("cls");
		for (int i = 0; i < sizeDriver; i++)
		{
			driver[i].showDriver();
		}
		cout << endl << endl;
		cout << "1-Add driver" << " || " << "2-Delete driver" << " || " << "3-Untie the car" << " || " << "Esc - Return" << " || " << endl;
		char c;
		c = _getch();
		switch (c)
		{
		case 49:
			this->addDriver();
			break;
		case 50:
			this->delDriver();
			break;
		case 51:
			cout << endl << "Input id driver: ";
			cin >> id;
			this->untieCar(id);
			break;
		case 27:
			system("cls");
			this->menu();
			break;
		}
	}
}

void Taxi::showFreeDriver()//сделать меню
{
	for (int i = 0; i < sizeDriver; i++)
	{
		if(driver[i].getConnect() == 0) driver[i].showDriver();
	}
	cout << endl << endl;
	cout << "1-Add driver to car" << " || " << "Esc-Return" << " || ";
	char c;
	int id1 = 0, id2 = 0;
	c = _getch();
	switch (c)
	{
	case 49:
		cout << endl << "Input id driver: ";
		cin >> id2;
		system("cls");
		for (int i = 0; i < sizeTaxi; i++)
		{
			if (car[i].getConnect() == 0) car[i].info();
		}
		cout << endl << "Input id car: ";
		cin >> id1;
		this->driverToCar(id1, id2);
		break;
	case 27:
		system("cls");
		this->menu();
		break;
	}
}

void Taxi::showAllOrderCar(Car& car)
{
	car.showAllOrder();
	cout << endl << endl;
	cout << " || " << "Esc-Return" << " || ";
	char c;
	int id = 0;
	c = _getch();
	switch (c)
	{
		system("cls");
		this->menu();
		break;
	}
}

void Taxi::showAllOrderCar()
{
	for (int i = 0; i < sizeTaxi; i++)
	{
		car[i].showAllOrderCash();
	}
	cout << endl << endl << "All cash Company: " << Car::getCashCompany();
	char c;
	int id = 0;
	c = _getch();
	switch (c)
	{
		system("cls");
		this->menu();
		break;
	}
}

void Taxi::menu()
{
	cout << "\t\t" << char(201);
	for (int i = 0; i < 23; i++)
	{
		cout << char(205);
	}
	cout << char(187) << endl;

	cout << "\t\t" << char(186) << "1-show all car\t\t" << char(186) << endl
		<< "\t\t" << char(186) << "2-show all drivers\t" << char(186) << endl
		<< "\t\t" << char(186) << "3-show free car\t" << char(186) << endl
		<< "\t\t" << char(186) << "4-show free drivers\t" << char(186) << endl
		<< "\t\t" << char(186) << "5-show working cars\t" << char(186) << endl
		<< "\t\t" << char(186) << "6-show status order\t" << char(186) << endl;
	cout << "\t\t" << char(200);
	for (int i = 0; i < 23; i++)
	{
		cout << char(205);
	}
	cout << char(188) << endl;

	char c;

	c = _getch();
	switch (c)
	{
	case 49:
		system("cls");
		showCar();
		break;
	case 50:
		system("cls");
		showAllDriver();
		break;
	case 51:
		system("cls");
		showFreeCar();
		break;
	case 52:
		system("cls");
		showFreeDriver();
		break;
	case 53:
		system("cls");
		showFreeOrderCar();
		break;
	case 54:
		system("cls");
		showAllOrderCar();
		break;
	}
}



