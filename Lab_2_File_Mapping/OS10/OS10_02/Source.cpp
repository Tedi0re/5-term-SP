#pragma comment(lib, "D:/OS10_HTAPI")
#include "../OS10_HTAPI/pch.h"

using namespace std;

int main()
{
	ht::HtHandle* ht = nullptr;
	try
	{
		/*	ht = ht::create(1000, 3, 10, 256, L"D:/HTspace.ht");
			if (ht)
				cout << "-- create: success" << endl;
			else
				throw "-- create: error";*/

		ht = ht::open(L"D:/HTspace.ht");
		if (ht)
			cout << "-- open: success" << endl;
		else
			throw "-- open: error";

		//----------------------------------------------------------

		if (ht::insert(ht, new ht::Element("key", 4, "payload", 8)))
			cout << "-- insert: success" << endl;
		else
			throw "-- insert: error";

		ht::Element* hte = ht::get(ht, new ht::Element("key", 4));
		if (hte)
			cout << "-- get: success" << endl;
		else
			throw "-- get: error";

		ht::print(hte);

		if (ht::update(ht, hte, "newPayload", 11))
			cout << "-- update: success" << endl;
		else
			throw "-- update: error";

		if (ht::snap(ht))
			cout << "-- snapSync: success" << endl;
		else
			throw "-- snap: error";

		hte = ht::get(ht, new ht::Element("key", 4));
		if (hte)
			cout << "-- get: success" << endl;
		else
			throw "-- get: error";

		ht::print(hte);

		SleepEx(3000, TRUE);

		if (ht::remove(ht, hte))
			cout << "-- remove: success" << endl;
		else
			throw "-- remove: error";

		hte = ht::get(ht, new ht::Element("key", 4));
		if (hte)
			cout << "-- get: success" << endl;
		else
			throw "-- get: error";
	}
	catch (const char* msg)
	{
		cout << msg << endl;

		if (ht != nullptr)
			cout << ht::getLastError(ht) << endl;
	}

	try
	{
		if (ht != nullptr)
			if (ht::close(ht))
				cout << "-- close: success" << endl;
			else
				throw "-- close: error";
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}