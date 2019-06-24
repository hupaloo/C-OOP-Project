// Hupalo M. S.
// Determines the class of "turbojet engine". Class-descendant of the class "engine"  
#ifndef TURBOJET_H
#define TURBOJET_H
#include "engine.h"

using namespace std;

class turbojet : public engine
{
private:
	int gas_temperature;				
	int rotation_freq;					
	string shaft_available;				

public:
	turbojet();										
	turbojet(string _type, double _weight,			
		int _cost, int _power, TData _struct_fields, 
		int _gas_temperature, int _rotation_freq, 
		string _shaft_available);
	~turbojet();									

	int getGas_temperature(void) const;				
	int getRotation_freq(void) const;				
	string getShaft_available(void) const;			

	void setGas_temperature(int _gas_temperature);	
	void setRotation_freq(int _rotation_freq);		
	void setShaft_available(int _shaft_available);	

	void cout_object_info(ostream &);				

	friend istream & operator >> (istream &, turbojet &);	
	friend ifstream &operator >> (ifstream &, turbojet &);	
	friend ostream & operator << (ostream &, turbojet &);	
	friend ofstream &operator << (ofstream &, turbojet &);	
};
#endif
