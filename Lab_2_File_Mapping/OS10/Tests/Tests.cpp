#include "Tests.h"

namespace test
{
	BOOL TC1(ht::HtHandle* ht, const void* key, const void* payload)
	{
		
		if(!ht) throw "-- open: error";
		ht::Element* insertElem = new ht::Element(key,std::strlen(reinterpret_cast<const char*>(key)) + 1, payload, std::strlen(reinterpret_cast<const char*>(payload)) + 1);
		ht::insert(ht, insertElem);
		ht::Element* getElem = ht::get(ht, new ht::Element(key, std::strlen(reinterpret_cast<const char*>(key)) + 1));

		ht::print(insertElem);
		ht::print(getElem);

		if (!std::strcmp(reinterpret_cast<const char*>(insertElem->key), reinterpret_cast<const char*>(getElem->key)) &&
			!std::strcmp(reinterpret_cast<const char*>(insertElem->payload), reinterpret_cast<const char*>(getElem->payload)))
			return TRUE;
		return FALSE;
	}

	BOOL TC2(ht::HtHandle* ht, const void* key, const void* payload)
	{
		ht::Element* getElemOld = ht::get(ht, new ht::Element(key, std::strlen(reinterpret_cast<const char*>(key)) + 1));
		const char* oldKey = new char[getElemOld->keyLength];
		const char* oldPayload = new char[getElemOld->payloadLength];
		strcpy_s(const_cast<char*>(oldKey), std::strlen(oldKey), reinterpret_cast<const char*>(getElemOld->key));
		strcpy_s(const_cast<char*>(oldPayload), std::strlen(oldPayload), reinterpret_cast<const char*>(getElemOld->payload));


		ht::update(ht, getElemOld, payload, std::strlen(reinterpret_cast<const char*>(payload)) + 1);
		ht::Element* getElemNew = ht::get(ht, new ht::Element(key, std::strlen(reinterpret_cast<const char*>(key)) + 1));
		ht::print(getElemNew);

		if (!std::strcmp(reinterpret_cast<const char*>(oldKey), reinterpret_cast<const char*>(getElemNew->key)) &&
			!std::strcmp(reinterpret_cast<const char*>(oldPayload), reinterpret_cast<const char*>(getElemNew->payload)))
			return FALSE;
		return TRUE;
	}

	BOOL TC3(ht::HtHandle* ht, const void* key)
	{
		ht::Element* getElemOld = ht::get(ht, new ht::Element(key, std::strlen(reinterpret_cast<const char*>(key)) + 1));
		ht::remove(ht, getElemOld);
		ht::Element* ElemOld = ht::get(ht, new ht::Element(key, std::strlen(reinterpret_cast<const char*>(key)) + 1));
		if(ElemOld == nullptr )
			return TRUE;
		return FALSE;
	}

	BOOL TC4(ht::HtHandle* ht, const void* key)
	{
		ht::Element* ElemOld = ht::get(ht, new ht::Element(key, std::strlen(reinterpret_cast<const char*>(key)) + 1));
		if (ElemOld == nullptr)
			return TRUE;
		return FALSE;
	}
}