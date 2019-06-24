// Hupalo M. S.
// The main function of the application
#include "singleton.h"
using namespace std;


void main()
{
	singleton * Menu = singleton::instance();
	Menu->menu();
	system("pause");
}

