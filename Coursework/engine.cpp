// Гупало М. С.
// Реалізація методів класу engine

#include "engine.h"
//#include <ostream>
//#include <istream>

using namespace std;

// ------------------------------------------------------------------
engine::TData::TData(double _dimensions, double _vibration_level, int _details_number, 
	string _overheating_tend) : dimensions(_dimensions), vibration_level(_vibration_level), 
	details_number(_details_number), overheating_tend(_overheating_tend) { }

// ------------------------------------------------------------------
engine::engine() : type("NaN"), weight(0), cost(0), power(0), struct_fields(0, 0, 0, "NaN") {} 

// ------------------------------------------------------------------
engine::engine(string _type, double _weight, int _cost, int _power, TData _struct_fields) 
	: type(_type), weight(_weight), cost(_cost), power(_power), struct_fields(_struct_fields) { }

// ------------------------------------------------------------------
engine::~engine(){}

// ------------------------------------------------------------------
double engine::getDimensions(void) const { return struct_fields.dimensions; }

// ------------------------------------------------------------------
double engine::getVibrationLevel(void) const { return struct_fields.vibration_level; }

// ------------------------------------------------------------------
int engine::getDetailsNumber(void) const { return struct_fields.details_number; }

// ------------------------------------------------------------------
string engine::getOverheatingTend(void) const { return struct_fields.overheating_tend; }

// ------------------------------------------------------------------
int engine::getCost(void) const { return cost; }

// ------------------------------------------------------------------
string engine::getType(void) const { return type; }

// ------------------------------------------------------------------
int engine::getPower(void) const { return power; }

// ------------------------------------------------------------------
double engine::getWeight(void) const { return weight; }

// ------------------------------------------------------------------
void engine::setCost(int _cost) { cost = _cost; }

// ------------------------------------------------------------------
void engine::setPower(int _power) { power = _power; }

// ------------------------------------------------------------------
void engine::setType(string _type) { type = _type; }

// ------------------------------------------------------------------
void engine::setWeight(double _weight) { weight = _weight; }

// ------------------------------------------------------------------
void engine::setDimensions(double _dimensions) { struct_fields.dimensions = _dimensions; }

// ------------------------------------------------------------------
void engine::setVibrationLevel(double _vibration_level) { struct_fields.vibration_level = _vibration_level; }

// ------------------------------------------------------------------
void engine::setDetailsNumber(int _details_number) { struct_fields.details_number = _details_number; }

// ------------------------------------------------------------------
void engine::setOverheatingTend(string _overheating_tend) { struct_fields.overheating_tend = _overheating_tend; }

// ------------------------------------------------------------------
void engine::cout_object_info(ostream &obj) 
{
	cout << "COST:\t\t";		obj << getCost() << endl;
	cout << "TYPE:\t\t";		obj << getType() << endl;
	cout << "POWER:\t\t";		obj << getPower() << endl;
	cout << "WEIGHT:\t\t";		obj << getWeight() << endl;
	cout << "DIMENSION:\t";		obj << getDimensions() << endl;
	cout << "VIBR LEVEL:\t";	obj << getVibrationLevel() << endl;
	cout << "DET NUMBER:\t";	obj << getDetailsNumber() << endl;
	cout << "OVERHEATING:\t";	 obj << getOverheatingTend() << endl;
}

// ------------------------------------------------------------------
ostream& operator << (ostream&out, engine &obj)
{
	obj.cout_object_info(out); 
	return out;
}

// ------------------------------------------------------------------
ofstream &operator << (ofstream &write_in_file, engine &obj)
{
	write_in_file << obj.type << "\n" <<
		obj.getWeight() << "\n" <<
		obj.getCost() << "\n" <<
		obj.getPower() << "\n" <<
		obj.getDimensions() << "\n" <<
		obj.getVibrationLevel() << "\n" <<
		obj.getDetailsNumber() << "\n" <<
		obj.getOverheatingTend() << "\n";
	return write_in_file;
}

// ------------------------------------------------------------------
ifstream &operator >> (ifstream &read_from_file, engine  &obj)
{
	read_from_file >> obj.type
		>> obj.weight
		>> obj.cost
		>> obj.power
		>> obj.struct_fields.dimensions
		>> obj.struct_fields.vibration_level
		>> obj.struct_fields.details_number
		>> obj.struct_fields.overheating_tend;
	return read_from_file;
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
istream & operator >> (istream &flow, engine  &obj)
{

	cout << "Input the type: ";
	flow >> obj.type;
	input_and_check(flow, &obj.weight, "Input the weight: ");
	input_and_check(flow, &obj.cost, "Input the cost: ");
	input_and_check(flow, &obj.power, "Input the power: ");
	input_and_check(flow, &obj.struct_fields.dimensions, "Input the dimensions size: ");
	input_and_check(flow, &obj.struct_fields.vibration_level, "Input the vibration level: ");
	input_and_check(flow, &obj.struct_fields.details_number, "Input the details number: ");
	cout << "Input the overheating tendency: ";
	flow >> obj.struct_fields.overheating_tend;
	return flow;
}