// ������ �. �.
// ����������� ����, �� ������� ������� ''������'', ���� � ������ ��� ������ � ���
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
			double dimensions;									// �������� ������ �������
			double vibration_level;								// г���� ������� �������
			int details_number;									// �-��� ������� �������
			string overheating_tend;							// ��������� �������� �������
			TData(double dimensions, double vibration_level,	// ����������� � �����������
				int details_number, string overheating_tend);	
		};
		string type;						// ��� �������
		double weight;						// ���� �������
		int cost;							// ������� �������
		int power;							// ��������� �������
		TData struct_fields;				// ���� ��������� TData �������
	public:
		engine();											// ����������� �� �������������
		engine(string _type, double _weight,				// ����������� � �����������
			int _cost, int _power, TData _struct_fields);
		virtual ~engine();									// ³��������� ����������
		
		double getDimensions(void) const;					// ��������� �������� ���������� ������ �������
		double getVibrationLevel(void) const;				// ��������� �������� ���� ������� �������
		double getWeight(void) const;						// ��������� �������� ���� �������
		string getOverheatingTend(void) const;				// ��������� �������� ��������� �������� �������
		string getType(void) const;							// ��������� �������� ���� �������
		int getCost(void) const;							// ��������� �������� ������� �������
		int getDetailsNumber(void) const;					// ��������� �������� ������� ������� �������
		int getPower(void) const;							// ��������� �������� ��������� �������

		void setCost(int _cost);							// ������������ �������� ������� �������
		void setPower(int _power);							// ������������ �������� ��������� ������� 
		void setType(string _type);							// ������������ �������� ���� ������� 
		void setWeight(double _weight);						// ������������ �������� ���� ������� 
		void setDimensions(double _dimensions);				// ������������ �������� ���������� ������ ������� 
		void setVibrationLevel(double _vibration_level);	// ������������ �������� ���� ������� ������� 
		void setDetailsNumber(int _details_number);			// ������������ �������� ������� ������� ������� 
		void setOverheatingTend(string _overheating_tend);	// ������������ �������� ��������� �������� ������� 

		virtual void cout_object_info(ostream &);			// ³�������� ������� ������ ��������� ����� ��� �ᒺ�� �� �����

		friend istream & operator >> (istream &, engine &);		// �������������� ���������	������� � ������
		friend ostream & operator << (ostream &, engine &);		// �������������� ���������	��������� � ����
		friend ifstream &operator >> (ifstream &, engine  &);	// �������������� ��������� ���������	������� � ������
		friend ofstream &operator << (ofstream &, engine &);	// �������������� ��������� ���������	��������� � ����
};
#endif