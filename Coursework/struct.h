using namespace std;

struct TData
{
	double dimensions;          // ���������� �������
	double vibration_level;     // ������� �������� 1,6 - 1000��
	int details_number;         // ����� �������
	string overheating_tend;    // ��������� ��������� �����������\�����������

	double getDimensions(void)  { return dimensions; }
	double getVibrationLevel(void) { return vibration_level; }
	int getDetailsNumber(void) { return details_number; }
	string getOverheatingTend(void) { return overheating_tend; }
};

