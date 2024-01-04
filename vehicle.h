#ifndef VEHICLE_H_
#define VEHICLE_H_
#include <iostream>
#include <string>
class Vehicle
{
private:
	std::string producer;
	std::string model;
	double price;
	int mass;
	int motors_power;
	int kmh;
	int date;
public:
	double get_price() { return price; }
	Vehicle();
	Vehicle(std::string a1, std::string a2, double p, int m, int mp, int kmh, int d);
	virtual void reset(std::string a, std::string b, double pr, int m, int mpower, int max_kmh, int dat);
	friend std::ostream& operator<<(std::ostream&, const Vehicle&);
	friend std::istream& operator>>(std::istream&, Vehicle&);
	virtual ~Vehicle() {}
};


class Car : public Vehicle
{
private:
	int seating_places;
public:
	Car();
	Car(std::string a1, std::string a2, double p, int m, int mp, int kmh, int d, int places);
	Car(const Vehicle&, int a);
	virtual void reset(std::string a, std::string b, double pr, int m, int mpower, int max_kmh, int dat, int l);
	friend std::ostream& operator<<(std::ostream&, const Car&);
	friend std::istream& operator>>(std::istream&, Car&);
};

class Truck : public Vehicle
{
private:
	int load_capacity;
public:
	Truck();
	Truck(std::string a1, std::string a2, double p, int m, int mp, int kmh, int d, int load_c);
	Truck(const Vehicle&, int a);
	virtual void reset(std::string a, std::string b, double pr, int m, int mpower, int max_kmh, int dat, int l);
	friend std::istream& operator>>(std::istream&, Truck&);
	friend std::ostream& operator<<(std::ostream&, const Truck&);
};

class TractoTrailer : public Truck
{
private:
	int carriage_lenght;
public:
	TractoTrailer();
	TractoTrailer(std::string a1, std::string a2, double p, int m, int mp, int kmh, int d, int load_c, int lenght);
	TractoTrailer(const Truck&, int lenght);
	virtual void reset(std::string a, std::string b, double pr, int m, int mpower, int max_kmh, int dat, int l, int lenght);
	friend std::istream& operator>>(std::istream&, TractoTrailer&);
	friend std::ostream& operator<<(std::ostream&, const TractoTrailer&);

};
#endif 

