#include "combustion.h"
#include "engine.h"
#include "menu.h"
#include "turbojet.h"
#include <string>
#include <iostream>

using namespace std;

menu::menu() 
{

}

void menu::comb_obj() {}
void menu::turb_obj(){}
void menu::show(){}
void menu::output(){}
void menu::save(){}
void menu::load(){}
void menu::sort(){}
void menu::request(){}
void menu::exit(){}

menu::~menu() {}

void menu::begin()
{
	int i;
	char s[10];

	do
	{
		system("cls");
		cout << "--------------- MENU ---------------" << endl;
		cout << "<1>.Create combustion`s object" << endl;
		cout << "<2>.Create turbojet`s object" << endl;
		cout << "<3>.Show info" << endl;
		cout << "<4>.Remove info" << endl;
		cout << "<5>.Save to the file" << endl;
		cout << "<6>.Load from the file" << endl;
		cout << "<7>.Sort objects" << endl;
		cout << "<8>.Do request" << endl;
		cout << "<9>.Leave the programm" << endl << endl;

		cin.getline(s, 10);
		i = atoi(s);
		switch (i)
		{
		case 1:
		{
			comb_obj();
			break;
		}
		case 2:
		{
			turb_obj();
			break;
		}
		case 3:
		{
			show();
			break;
		}
		case 4:
		{
			output();
			break;
		}
		case 5:
		{
			save();
			break;
		}
		case 6:
		{
			load();
			break;
		}
		case 7:
		{
			sort();
			break;
		}
		case 8:
		{
			request();
			break;
		}
		case 9:
		{
			exit();
			break;
		}
		default:
		{
			if (i > 9 || i < 1)
			{
				cout << "Your choice isn`t correct..." << endl;
				system("pause");
			}
			break;
		}
		}
	} while (i != 9);
}
