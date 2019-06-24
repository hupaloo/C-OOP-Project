// Гупало М. С.
// Головна функція програмного додатку
#include "singleton.h"
using namespace std;


void main()
{
	singleton * Menu = singleton::instance();
	Menu->menu();
	system("pause");
}

