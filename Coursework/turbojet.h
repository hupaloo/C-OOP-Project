// Гупало М. С.
// Визначає клас «турбореактивний двигун». Клас-нащадок класу «engine»  
#ifndef TURBOJET_H
#define TURBOJET_H
#include "engine.h"

using namespace std;

class turbojet : public engine
{
private:
	int gas_temperature;				// Температура газу турбореактивного двигуна
	int rotation_freq;					// Частота обертання турбореактивного двигуна
	string shaft_available;				// Наявність валу турбореактивного двигуна

public:
	turbojet();										// Конструктор за замовчуванням
	turbojet(string _type, double _weight,			// Конструктор з параметрами
		int _cost, int _power, TData _struct_fields, 
		int _gas_temperature, int _rotation_freq, 
		string _shaft_available);
	~turbojet();									// Деструктор

	int getGas_temperature(void) const;				// Отримання значення температури газу двигуна
	int getRotation_freq(void) const;				// Отримання значення частоти обертання двигуна
	string getShaft_available(void) const;			// Отримання значення наявності валу у двигуна

	void setGas_temperature(int _gas_temperature);	// Встановлення значення температури газу двигуна
	void setRotation_freq(int _rotation_freq);		// Встановлення значення частоти обертання двигуна
	void setShaft_available(int _shaft_available);	// Встановлення значення наявність валу у двигуна

	void cout_object_info(ostream &);				// Виведення даних про об’єкт турбореактивний двигун на екран

	friend istream & operator >> (istream &, turbojet &);	// Перевантаження оператору	введеня з потоку
	friend ifstream &operator >> (ifstream &, turbojet &);	// Перевантаження файлового оператору	введеня з потоку
	friend ostream & operator << (ostream &, turbojet &);	// Перевантаження оператору	виведення в потік
	friend ofstream &operator << (ofstream &, turbojet &);	// Перевантаження файлового оператору	виведення в потік
};
#endif