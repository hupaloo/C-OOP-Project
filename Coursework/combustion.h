// Гупало М. С.
// Визначає клас «двигун внутрішнього згоряння». Клас-нащадок класу «engine»  
#ifndef COMBUSTION_H
#define COMBUSTION_H
#include "engine.h"
using namespace std;

class combustion : public engine
{
private:
	string fuel;       
	int duty_cycle;     
	int cylinders;      
public:
	combustion();
	combustion(string _type, double _weight, int _cost, int _power, TData _struct_fields, string _fuel, int _duty_cycle, int _cylinders);
	~combustion();

	string getFuel(void) const;
	int getDuty_cycle(void) const;
	int getCylinders(void) const;
	
	void setFuel(string _fuel);
	void setDuty_cycle(int _duty_cycle);
	void setCylinders(int _cylinders);	

	void cout_object_info(ostream &);

	friend istream & operator >> (istream &, combustion &);
	friend ifstream &operator >> (ifstream &, combustion &);
	friend ostream & operator << (ostream &, combustion &);
	friend ofstream &operator << (ofstream &, combustion &);
};
#endif