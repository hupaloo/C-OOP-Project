// Hupalo M. S.
// Realization of combustion class methods 

#include "combustion.h"
//#include <istream>
//#include <fstream>
using namespace std;

// ------------------------------------------------------------------
combustion::combustion() : engine(), fuel("NaN"), duty_cycle(0), cylinders(0) { }

// ------------------------------------------------------------------
combustion::combustion(string _type, double _weight, int _cost, int _power, TData _struct_fields, string _fuel, int _duty_cycle, int _cylinders)
	:engine(_type, _weight, _cost, _power, _struct_fields), fuel(_fuel), duty_cycle(_duty_cycle), cylinders(_cylinders){}

// ------------------------------------------------------------------
combustion::~combustion(){}

// ------------------------------------------------------------------
string combustion::getFuel(void) const { return fuel; }

// ------------------------------------------------------------------
int combustion::getDuty_cycle(void) const { return duty_cycle; }

// ------------------------------------------------------------------
int combustion::getCylinders(void) const { return cylinders; }

// ------------------------------------------------------------------
void combustion::setFuel(string _fuel) { fuel = _fuel; }

// ------------------------------------------------------------------
void combustion::setDuty_cycle(int _duty_cycle) { duty_cycle = _duty_cycle; }

// ------------------------------------------------------------------
void combustion::setCylinders(int _cylinders) { cylinders = _cylinders; }

// ------------------------------------------------------------------
void combustion::cout_object_info(ostream &obj)
{
	cout << "ENGINE NAME:\t";	obj << "Combustion" << endl;
	engine::cout_object_info(obj);
	cout << "FUEL TYPE:\t";		obj << getFuel() << endl;
	cout << "DUTY CYCLE:\t";	obj << getDuty_cycle() << endl;
	cout << "CYLIND NUMBER:\t"; obj << getCylinders() << endl;
	cout << endl;
}

// ------------------------------------------------------------------
template <class Type>
void input_and_check(istream &flow, Type *temp, const char *prompt)
{
	cout << prompt;
	flow >> *temp;
	while (flow.fail())
	{
		cout << "Invalid Input! Please input a numerical value." << endl;
		flow.clear();
		while (flow.get() != '\n');
		cout << "> ";
		flow >> *temp;
	}
}

// ------------------------------------------------------------------
istream & operator >> (istream &flow, combustion &obj)
{
	flow >> dynamic_cast<engine&>(obj);
	cout << "Input the type of fuel: ";
	flow >> obj.fuel;
	input_and_check(flow, &obj.duty_cycle, "Input the duty cycle: ");
	input_and_check(flow, &obj.cylinders, "Input the number of cylinders: ");
	return flow;
}

// ------------------------------------------------------------------
ofstream &operator << (ofstream &write_in_file, combustion &obj)
{
	write_in_file << dynamic_cast<engine&>(obj) <<
		obj.getFuel() << "\n" <<
		obj.getDuty_cycle() << "\n" <<
		obj.getCylinders() << "\n";
	return write_in_file;
}

// ------------------------------------------------------------------
ifstream &operator >> (ifstream &read_from_file, combustion  &obj)
{
	read_from_file >> (engine&)obj >> obj.fuel >> obj.duty_cycle >> obj.cylinders;
	return read_from_file;
}

// ------------------------------------------------------------------
ostream& operator << (ostream&out, combustion &obj)
{
	obj.cout_object_info(out); 
	return out;
}
