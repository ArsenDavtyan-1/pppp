#include "vehicle.h"
Vehicle::Vehicle() : producer("Arm"), model("Sep"), price(1500), mass(2000), motors_power(200), kmh(180), date(2023)
{
}
Vehicle::Vehicle(std::string a1, std::string a2, double p, int m, int mp, int kmh, int d)
{
	producer = a1;
	model = a2;
	price = p;
	mass = m;
	motors_power = mp;
	this->kmh = kmh;
	date = d;
}
void Vehicle::reset(std::string a, std::string b, double pr, int m, int mpower, int max_kmh, int dat)
{
	producer = a;
	model = b;
	price = pr;
	mass = m;
	motors_power = mpower;
	kmh = max_kmh;
	date = dat;
}


std::ostream& operator<<(std::ostream& os, const Vehicle& a)
{
	os << "producer: " << a.producer << std::endl;
	os << "model: " << a.model << std::endl;
	os << "price: " << a.price << std::endl;
	os << "mass: " << a.mass << std::endl;
	os << "motors power: " << a.motors_power << std::endl;
	os << "max kmh: " << a.kmh << std::endl;
	os << "date: " << a.date << std::endl;
	return os;
}

std::istream& operator>>(std::istream& in, Vehicle& a)
{
	std::cout << "producer: " << std::endl;
	in >> a.producer;
	std::cout << "model: " << std::endl;
	in >> a.model;
	std::cout << "price: " << std::endl;
	in >> a.price;
	std::cout << "mass: " << std::endl;
	in >> a.mass;
	std::cout << "motors power: " << std::endl;
	in >> a.motors_power;
	std::cout << "max kmh: " << std::endl;
	in >> a.kmh;
	std::cout << "date: " << std::endl;
	in >> a.date;
	return in;
}

std::ostream& operator<<(std::ostream& os, const Car& a)
{
	os << Vehicle(a);
	os << "seating places: " << a.seating_places << std::endl;
	return os;
}

std::istream& operator>>(std::istream& input, Car& a)
{
	input >> static_cast<Vehicle&>(a);
	std::cout << "seating places" << std::endl;
	input >> a.seating_places;
	return input;
}




Car::Car() :Vehicle::Vehicle(), seating_places(4)
{}

Car::Car(std::string a1, std::string a2, double p, int m, int mp, int kmh, int d, int places)
	:Vehicle(a1, a2, p, m, mp, kmh, d), seating_places(places)
{}

Car::Car(const Vehicle& asa, int a) :Vehicle(asa), seating_places(a)
{}

void Car::reset(std::string a, std::string b, double pr, int m, int mpower, int max_kmh, int dat, int l)
{
	Vehicle::reset(a, b, pr, m, mpower, max_kmh, dat);
	seating_places = l;
}

Truck::Truck() : load_capacity(550)
{}

Truck::Truck(std::string a1, std::string a2, double p, int m, int mp, int kmh, int d, int load_c)
	:Vehicle(a1, a2, p, m, mp, kmh, d), load_capacity(load_c)
{}

Truck::Truck(const Vehicle& tp, int a) :Vehicle(tp), load_capacity(a)
{}

void Truck::reset(std::string a, std::string b, double pr, int m, int mpower, int max_kmh, int dat, int l)
{
	Vehicle::reset(a, b, pr, m, mpower, max_kmh, dat);
	load_capacity = l;
}

std::istream& operator>>(std::istream& input, Truck& a)
{
	input >> static_cast<Vehicle&>(a);
	std::cout << "load capacity" << std::endl;
	input >> a.load_capacity;
	return input;
}

std::ostream& operator<<(std::ostream& os, const Truck& a)
{
	os << Vehicle(a);
	os << "load capacity: " << a.load_capacity << std::endl;
	return os;
}

TractoTrailer::TractoTrailer() :Truck(), carriage_lenght(4)
{}

TractoTrailer::TractoTrailer(std::string a1, std::string a2, double p, int m, int mp, int kmh, int d, int load_c, int lenght)
	:Truck(a1, a2, p, m, mp, kmh, d, load_c), carriage_lenght(lenght)
{}

TractoTrailer::TractoTrailer(const Truck& tp, int lenght)
	:Truck(tp), carriage_lenght(lenght)
{}

void TractoTrailer::reset(std::string a, std::string b, double pr, int m, int mpower, int max_kmh, int dat, int l, int lenght)
{
	Truck::reset(a, b, pr, m, mpower, max_kmh, dat, l);
	carriage_lenght = lenght;
}

std::istream& operator>>(std::istream& in, TractoTrailer& a)
{
	in >> static_cast<Truck&> (a);
	std::cout << "carriage lenght " << std::endl;
	in >> a.carriage_lenght;
	return in;
}

std::ostream& operator<<(std::ostream& os, const TractoTrailer& a)
{
	os << Truck(a);
	os << "carriage lenght: " << a.carriage_lenght;
	return os;
}