// Гупало М. С.
// Абстрактний клас, що визначає сутність ''двигун'', поля і методи для роботи з ним
#ifndef ENGINE_H
#define ENGINE_H
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class engine 
{
	protected:
		struct TData
		{
			double dimensions;									// Габаритні розміри двигуна
			double vibration_level;								// Рівень вібрації двигуна
			int details_number;									// К-сть деталей двигуна
			string overheating_tend;							// Тенденція перегріву двигуна
			TData(double dimensions, double vibration_level,	// Конструктор з параметрами
				int details_number, string overheating_tend);	
		};
		string type;						// Тип двигуна
		double weight;						// Вага двигуна
		int cost;							// Вартість двигуна
		int power;							// Потужність двигуна
		TData struct_fields;				// Поля структури TData двигуна
	public:
		engine();											// Конструктор за замовчуванням
		engine(string _type, double _weight,				// Конструктор з параметрами
			int _cost, int _power, TData _struct_fields);
		virtual ~engine();									// Віртуальний деструктор
		
		double getDimensions(void) const;					// Отримання значення габаритних розмірів двигуна
		double getVibrationLevel(void) const;				// Отримання значення рівня вібрації двигуна
		double getWeight(void) const;						// Отримання значення ваги двигуна
		string getOverheatingTend(void) const;				// Отримання значення тенденції перегріву двигуна
		string getType(void) const;							// Отримання значення типу двигуна
		int getCost(void) const;							// Отримання значення вартості двигуна
		int getDetailsNumber(void) const;					// Отримання значення кількості деталей двигуна
		int getPower(void) const;							// Отримання значення потужності двигуна

		void setCost(int _cost);							// Встановлення значення вартості двигуна
		void setPower(int _power);							// Встановлення значення потужності двигуна 
		void setType(string _type);							// Встановлення значення типу двигуна 
		void setWeight(double _weight);						// Встановлення значення ваги двигуна 
		void setDimensions(double _dimensions);				// Встановлення значення габаритних розмірів двигуна 
		void setVibrationLevel(double _vibration_level);	// Встановлення значення рівня вібрації двигуна 
		void setDetailsNumber(int _details_number);			// Встановлення значення кількості деталей двигуна 
		void setOverheatingTend(string _overheating_tend);	// Встановлення значення тенденції перегріву двигуна 

		virtual void cout_object_info(ostream &);			// Віртуальна функція виводу загальних даних про об’єкт на екран

		friend istream & operator >> (istream &, engine &);		// Перевантаження оператору	введеня з потоку
		friend ostream & operator << (ostream &, engine &);		// Перевантаження оператору	виведення в потік
		friend ifstream &operator >> (ifstream &, engine  &);	// Перевантаження файлового оператору	введеня з потоку
		friend ofstream &operator << (ofstream &, engine &);	// Перевантаження файлового оператору	виведення в потік
};
#endif