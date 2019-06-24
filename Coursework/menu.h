#include <string>


class menu
{
private:
	std::string input;
public:
	menu();
	~menu();

	void begin();
	void comb_obj();
	void turb_obj();
	void show();
	void output();
	void save();
	void load();
	void sort();
	void request();
	void exit();
};
