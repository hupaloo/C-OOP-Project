// Hupalo M. S.
// Definition of the user menu class

#include "ListLink.h"
class singleton
{
	LinkList list;
public:
	static singleton *instance();
	void menu();

	void CreateCombustionObj(LinkList *Data);
	void CreateTurbojetObj(LinkList *Data);
	void ShowOnScreen();
	void ClearList();
	void SaveInFile();
	void ReadFromFile();
	void SortList();
	void DoRequest();
protected:
	singleton() {};
private:
	static singleton *_instance;
};
