// Hupalo M. S.
// Realization of class-container methods LinkList

#include "ListLink.h"

using namespace std;

// ------------------------------------------------------------------
LinkList::LinkList() : current(NULL), size(0) { }        

// ------------------------------------------------------------------
LinkList::~LinkList()          
{
	if (current)
	{
		while (current != NULL)
			pop();
	}
}

// ------------------------------------------------------------------
void LinkList::pushfront(engine *data)        
{
	if (current == NULL)
	{
		current = new Link;
		current->data = data;
		current->prev = current;
		current->next = current;
		size = 1;
	}
	else
	{
		Link *tmp = new Link;
		tmp->data = data;
		tmp->next = current;
		tmp->prev = current->prev;
		current->prev = tmp;
		tmp->prev->next = tmp;
		++size;
	}
}

// ------------------------------------------------------------------
void LinkList::pop()
{
	if (size > 1)
	{
		Link *tmp = current;
		current = tmp->next;
		tmp->prev->next = current;
		current->prev = tmp->prev;
		delete tmp;
		--size;
	}
	else
	{
		delete current;
		current = NULL;
		size = 0;
	}
}

// ------------------------------------------------------------------
void LinkList::showList_front() const         
{
	if (current)
	{
		Link* temp = current;
		engine *show;
		do
		{
			show = temp->data;
			cout << *show;
			temp = temp->next;
		} while (temp != current);
	}
}

// ------------------------------------------------------------------
void LinkList::clear()           // clear list
{
	if (current)
	{
		while (current != NULL)
		{
			pop();
		}
	}
}

// ------------------------------------------------------------------
void LinkList::file_save()
{
	ofstream file;
	file.open("text.txt");
	if (!file.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}
	if (current)
	{
		Link* temp = current;
		do
		{
			if (typeid(*(temp->data)) == typeid(combustion))
			{
				file  << 1 << endl;
				file << (*((combustion*)(temp->data))) ;
			}
			if (typeid(*(temp->data)) == typeid(turbojet))
			{
				file << 2 << endl;
				file << (*((turbojet*)(temp->data))) ;
			}
			temp = temp->next;
		} while (temp != current);
		file  << endl;
		file.close();
		cout << "Data was successfully managed to the file!" << endl;
	}
}

// ------------------------------------------------------------------
void LinkList::file_load()
{
	ifstream file("text.txt");
	if (!file.is_open())
	{
		cout << "Error opening file!" << endl;
		return;
	}
	else
	{
		clear();
		combustion *comb;
		turbojet *turb;
		int flag(0);
		while (file >> flag)
		{
			file.get();
			if (flag == 1)
			{
				comb = new combustion;
				file >> *comb;
				pushfront(comb);
			}
			else if (flag == 2)
			{
				turb = new turbojet;
				file >> *turb;
				pushfront(turb);
			}
			else
			{
				cout << "Unknown id! Rewrite the file, please and try again!" << endl;
				break;
			}
			flag = 0;
		} // end of while (file >> flag)
		file.close();
		cout << "Data was successfully loaded from the file! " << endl;
	}
}

// ------------------------------------------------------------------
void LinkList::sortlist()
{
	if (size == 1)
	{
		cout << "Impossible to sort list. It has only one object!" << endl;
		return;
	}
	if (current)
	{
		engine *tempdata;
		Link *temp1 = current;
		int siz = size;
		for (int i = 0; i < siz - 1; i++)
		{
			Link* temp2 = temp1->prev;
			for (int x = i; x < siz - 1; x++)
			{
				if (temp1->data->getPower() > temp2->data->getPower())
				{
					tempdata = temp2->data;
					temp2->data = temp1->data;
					temp1->data = tempdata;
				}
				temp2 = temp2->prev;
			} // end of for (int x = i; x < siz - 1; x++)
			temp1 = temp1->prev;
		} // end of for (int i = 0; i < siz - 1; i++)
		current = temp1;
		cout << "The list was successfully sorted! " << endl;
	}
}

// ------------------------------------------------------------------
void LinkList::find_data()
{
	Link *temp = current;
	if (current)
	{
		cout << "All the types of added engines: ";
		do
		{
			cout << temp->data->getType() << "    ";
			temp = temp->prev;
		} while (temp != current);
		cout << endl;
		int i(0), summ_power(0);
		string check;
		while (true)
		{
			
			cout << "Do you want to choose any engine type?" << endl;
			cout << "<1>.Yes" << endl << "<2>.No" << endl;
			cout << "> ";
			cin >> check;
			try
			{
				i = stoi(check);
			}
			catch (...)
			{
				cout << "Incorrect input!" << endl;
				continue;
			}
			if (i == 1)
			{
				int error_catcher(0);
				string type_check;
				cout << "Input the type of an engine: ";
				cin >> type_check;
				do
				{
					if (type_check == temp->data->getType())
					{
						summ_power += temp->data->getPower();
						cout << "Type was successfully founded. It`s power was added to the sum!" << endl;
						error_catcher = 1;
					}
					temp = temp->prev;
				} while (temp != current);
				if (error_catcher == 0)
				{
					cout << "There is no such a type of the engine! Please, try again!" << endl;
				}
			}
			else if (i == 2)
			{
				if (summ_power != 0)
				{
					cout << "A sum of powers of the added engines: " << summ_power << endl;
				}
				else
				{
					cout << "You didn`t choose any engine type! If it something wrong, do request again please!" << endl;
				}
				break;
			}
			else
				cout << "You put a wrong value! Please, make a choice!" << endl;
		} // end of while(true)
	}
}

// ------------------------------------------------------------------
bool LinkList::is_empty()
{
	return ((size == 0) ? true : false);
}
