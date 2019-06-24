/*
#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "../Coursework/engine.h"
#include "../Coursework/singleton.h"
using namespace std;

BOOST_AUTO_TEST_CASE(engineTypeCheck)
{
  string expected_type = "NaN";
  engine obj;
  BOOST_REQUIRE_EQUAL(expected_type, obj.getType());
}

BOOST_AUTO_TEST_CASE(addCombCheck)
{
	LinkList list;
	combustion *data = new combustion("RTJ1.0", 333.33, 3333, 3333, 
		{ 33.3, 3.3, 333, "Overheated" }, "Diesel", 2, 4);
	list.pushfront(data);
	BOOST_CHECK(list.is_empty() == false);
}

BOOST_AUTO_TEST_CASE(addTurbCheck)
{
	LinkList list;
	turbojet *data = new turbojet("TF01", 1000.5, 1000000, 10000,
		{ 100.1, 1.5, 500, "Unoverheated" }, 200, 1500, "Available");
	list.pushfront(data);
	BOOST_CHECK(list.is_empty() == false);
}

BOOST_AUTO_TEST_SUITE(TestSuite1)

struct cout_redir {
	cout_redir(streambuf * new_buff)
		: old(cout.rdbuf(new_buff))
	{ }

	~cout_redir() {
		cout.rdbuf(old);
	}

private:
	streambuf * old;
};

BOOST_AUTO_TEST_CASE(testOutput)
{
	boost::test_tools::output_test_stream output;
	{
		cout_redir guard(output.rdbuf());
		LinkList list;
		if (list.is_empty())
			cout << "List is empty!" << endl;
		else
			cout << "List isn`t empty!" << endl;
	}

	BOOST_CHECK(output.is_equal("List is empty!\n"));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(delElem)
{
	LinkList list;
	turbojet *data = new turbojet("TF01", 1000.5, 1000000, 10000,
		{ 100.1, 1.5, 500, "Unoverheated" }, 200, 1500, "Available");
	list.pushfront(data);
	list.pop();
	BOOST_CHECK(list.is_empty() == true);
}

BOOST_AUTO_TEST_CASE(clearList)
{
	LinkList list;
	turbojet *data = new turbojet("TF01", 1000.5, 1000000, 10000,
		{ 100.1, 1.5, 500, "Unoverheated" }, 200, 1500, "Available");
	list.pushfront(data);
	turbojet *data1 = new turbojet("TF01", 1000.5, 1000000, 10000,
		{ 100.1, 1.5, 500, "Unoverheated" }, 200, 1500, "Available");
	list.pushfront(data1);
	list.clear();
	BOOST_CHECK(list.is_empty() == true);
}
*/