// Гупало М. С.
// Реалізація методів класу turbojet

#include "turbojet.h"
//#include <fstream>
//#include <istream>
using namespace std;
// ------------------------------------------------------------------
turbojet::turbojet() : engine(), gas_temperature(0), rotation_freq(0), 
	shaft_available("NaN") { }

// ------------------------------------------------------------------
turbojet::turbojet(string _type, double _weight, int _cost, int _power, 
	TData _struct_fields, int _gas_temperature, int _rotation_freq, 
	string _shaft_available) : engine(_type, _weight, _cost, _power, 
	_struct_fields), gas_temperature(_gas_temperature), 
	rotation_freq(_rotation_freq), shaft_available(_shaft_available){}

// ------------------------------------------------------------------
turbojet::~turbojet(){}

// ------------------------------------------------------------------
int turbojet::getGas_temperature(void) const 
	{ return gas_temperature; }

// ------------------------------------------------------------------
string turbojet::getShaft_available(void) const 
	{ return shaft_available; }

// ------------------------------------------------------------------
int turbojet::getRotation_freq(void) const 
	{ return rotation_freq; }

// ------------------------------------------------------------------
void turbojet::setGas_temperature(int _gas_temperature) 
	{gas_temperature = _gas_temperature;}

// ------------------------------------------------------------------
void turbojet::setRotation_freq(int _rotation_freq) 
	{ rotation_freq = _rotation_freq; }

// ------------------------------------------------------------------
void turbojet::setShaft_available(int _shaft_available) 
	{ shaft_available = _shaft_available; }

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
void turbojet::cout_object_info(ostream &obj)
{
	cout << "ENGINE NAME:\t";	obj << "Turbojet" << endl;
	engine::cout_object_info(obj);
	cout << "GAS TEMPR:\t";		obj << getGas_temperature() << endl;
	cout << "ROTAT FREQ:\t";	obj << getRotation_freq() << endl;
	cout << "SHAFT AVAIL:\t";	obj << getShaft_available() << endl;
	cout << endl;
}

// ------------------------------------------------------------------
istream & operator >> (istream &flow, turbojet &obj)
{
	flow >> dynamic_cast<engine&>(obj);
	input_and_check(flow, &obj.gas_temperature, "Input the gas temperature: ");
	input_and_check(flow, &obj.rotation_freq, "Input the rotation frequency: ");
	cout << "Input the shaft availability: ";
	flow >> obj.shaft_available;
	return flow;
}

// ------------------------------------------------------------------
ofstream &operator << (ofstream &write_in_file, turbojet &obj)
{
	write_in_file << dynamic_cast<engine&>(obj) <<
		obj.getGas_temperature() << "\n" <<
		obj.getRotation_freq() << "\n" <<
		obj.getShaft_available() << "\n";
	return write_in_file;
}

// ------------------------------------------------------------------
ifstream &operator >> (ifstream &read_from_file, turbojet &obj)
{
	read_from_file >> (engine&)obj >> obj.gas_temperature >> obj.rotation_freq >> obj.shaft_available;
	return read_from_file;
}

// ------------------------------------------------------------------
ostream& operator << (ostream&out, turbojet &obj)
{
	obj.cout_object_info(out);
	return out;
}