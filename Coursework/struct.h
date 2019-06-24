using namespace std;

struct TData
{
	double dimensions;          // габаритные размеры
	double vibration_level;     // уровень вибрации 1,6 - 1000√÷
	int details_number;         // число деталей
	string overheating_tend;    // тенденци€ перегрева присутсвует\отсутствует

	double getDimensions(void)  { return dimensions; }
	double getVibrationLevel(void) { return vibration_level; }
	int getDetailsNumber(void) { return details_number; }
	string getOverheatingTend(void) { return overheating_tend; }
};

