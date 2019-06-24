// Гупало М. С.
// Визначення класу-контейнера за типом «двозв’язний кільцевий список»
#ifndef ListLink_H
#define ListLink_H
#include "combustion.h"
#include "turbojet.h"
using namespace std;

struct Link
{
	engine *data;
	Link* next;        
	Link* prev;        
};

class LinkList
{
private:
	Link* current;
	int size;
public:
	LinkList();        
	~LinkList();       
	void pushfront(engine *data);        
	void pop();						
	void showList_front() const;             
	void clear() ;            
	void file_save();
	void file_load();
	void sortlist();
	void find_data();
	bool is_empty();
};
#endif