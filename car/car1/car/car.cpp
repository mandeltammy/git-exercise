#include <iostream>
#include <string.h>
using namespace std;

class Car
{
public:
	Car(char *make, char *model, int year, int engineVolume, char *color);
	friend ostream &operator<<(ostream & out, Car const& c);
	int older(Car);
	int stronger(Car);
	Car olderCar(Car);
	Car strongerCar(Car);
	void setYear(int);
	char* GetMake();
	char* GetModel();
	int GetYear();
	int GetEngine_volume();
	char* GetColor();

private:
	char make[10];
	char model[10];
	int year;
	int engine_volume;
	char color[10];
};

//constructor
Car::Car(char *g_make, char *g_model, int g_year, int g_engineVolume, char *g_color)
{
	strcpy(make, g_make);
	strcpy(model, g_model);
	setYear(g_year);
	engine_volume = g_engineVolume;
	strcpy(color, g_color);
}

//prints all the car details
ostream &operator<<(ostream & out,Car const& c)
{
	out << "make: " << c.make;
	out << "\nmodel: " << c.model;
	out << "\nyear: " << c.year;
	out << "\nengine volume: " << c.engine_volume;
	out << "\ncolor: " << c.color << endl;
	return out;	
}

//sets a year between 1900 to 2020
void Car::setYear(int y)
{
	while (y < 1900 || y > 2020)
	{
		cout << "enter valid year (1900-2020)\n";
		cin >> y;
	}		
	year = y;
}

//returns the maker
char* Car::GetMake() { return make; }

//returns the model
char* Car::GetModel() { return model; }

//returns the year
int Car::GetYear() { return year; }

//returns the engine volume
int Car::GetEngine_volume() { return engine_volume; }

//returns the color
char* Car::GetColor() { return color; }

//return 1 if lhs is older, else returns -1
int Car::older(Car c)
{
	if (c.GetYear() > year)
		return 1;
	return -1;
}

//return 1 if lhs has a stronger engine, else returns -1
int Car::stronger(Car c)
{
	if (c.GetEngine_volume() < engine_volume)
		return 1;
	return -1;
}

//return the older car
Car Car::olderCar(Car c)
{
	if ((*this).older(c) > 0)
		return *this;
	return c;
}

//return the car with the stronger engine
Car Car::strongerCar(Car c)
{
	if ((*this).stronger(c) > 0)
		return *this;
	return c;
}



int main()
{
	char make[10];
	char model[10];
	int year;
	int engine_volume;
	char color[10];
	cout << "enter the car details- make, model, year, engine volume, and color:\n";
	cin >> make >> model >> year >> engine_volume >> color;
	Car myCar = Car(make, model, year, engine_volume, color);
	cout << "you'r car:\n" << myCar;
	Car c1 = Car("audi", "x5", 2017, 1800, "white");
	Car c2 = Car("citroen", "c4", 2010, 1700, "silver");
	cout << "older car: " << c1.olderCar(c2) << endl;
	cout << "stronger car: " << c1.strongerCar(c2) << endl;
	return 0;
}