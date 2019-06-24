// Гупало М. С.
// Реалізація методів класу-меню singleton
#include "singleton.h"
using namespace std;

singleton*singleton::_instance = 0;

// ------------------------------------------------------------------
singleton*singleton::instance()
{
	if (_instance == 0)
	{
		_instance = new singleton;
	}
	return _instance;
}

// ------------------------------------------------------------------
void singleton::menu()
{
	int i;
	for(;;)
	{
		system("cls");
		cin.sync();
		cout << " ------------- MENU --------------" << endl;
		cout << " 1 - Create combustion`s object." << endl;
		cout << " 2 - Create turbojet`s object." << endl;
		cout << " 3 - Show info about objects." << endl;
		cout << " 4 - Remove info about objects." << endl;
		cout << " 5 - Save to the file." << endl;
		cout << " 6 - Read from the file." << endl;
		cout << " 7 - Sort objects." << endl;
		cout << " 8 - Do request." << endl;
		cout << " 9 - Leave the programm." << endl<<endl;
		cout << "> ";
		string check;
		getline(cin, check);
		try
		{
			i = stoi(check);
		}
		catch (...)
		{
			cout << "Your choice isn`t correct... Please, try again." << endl;
			system("pause");
			continue;
		}
		switch (i)
		{
		case 1:
		{
			CreateCombustionObj(&list);
			break;
		}
		case 2:
		{
			CreateTurbojetObj(&list);
			break;
		}
		case 3:
		{
			ShowOnScreen();
			break;
		}
		case 4:
		{
			ClearList();
			break;
		}
		case 5:
		{
			SaveInFile();
			break;
		}
		case 6:
		{
			ReadFromFile();
			break;
		}
		case 7:
		{
			SortList();
			break;
		}
		case 8:
		{
			DoRequest();
			break;
		}
		default:
		{
			if (i > 9 || i < 1)
			{
				cout << "Your choice isn`t correct... Please, try again. " << endl << endl;
			}
			break;
		}
		}
		if (i == 9)
		{
			cout << "The program was successfully closed!" << endl;
			break;
		}
		system("pause");
	} 
}

// ------------------------------------------------------------------
void singleton::CreateCombustionObj(LinkList *Data)
{
	combustion *data = new combustion();
	cin >> *data;
	Data->pushfront(data);
	cout << "Combustion object was successfully created. " << endl;
}

// ------------------------------------------------------------------
void singleton::CreateTurbojetObj(LinkList *Data)
{
	turbojet *data = new turbojet();
	cin >> *data;
	Data->pushfront(data);
	cout << "Turbojet object was successfully created. " << endl;
}

// ------------------------------------------------------------------
void singleton::ShowOnScreen()
{
	system("cls");
	if (list.is_empty())
		cout << "List is empty!" << endl;
	else
	list.showList_front();
}

// ------------------------------------------------------------------
void  singleton::ClearList()
{
	if (list.is_empty())
		cout << "List is empty!" << endl;
	else
	{
		list.clear();
		cout << "List was successfully cleared!" << endl;
	}
}

// ------------------------------------------------------------------
void  singleton::SaveInFile()
{
	if (list.is_empty())
		cout << "List is empty!" << endl;
	else
		list.file_save();
}

// ------------------------------------------------------------------
void  singleton::ReadFromFile()
{
	
		list.clear();
		list.file_load();
}

// ------------------------------------------------------------------
void  singleton::SortList()
{
	if (list.is_empty())
		cout << "List is empty!" << endl;
	else
		list.sortlist();
}

// ------------------------------------------------------------------
void  singleton::DoRequest()
{
	if (list.is_empty())
		cout << "List is empty!" << endl;
	else
	{
		list.sortlist();
		list.find_data();
	}
}