#pragma once

#include "Link.h"
#include <iostream>

template <class T>
class DLList :public Link<T>
{

public:
	DLList();
	~DLList() = default;
	T * First();
	T * Last();
	T * PushFront(T * item);
	T * PopFront();
	T * PushBack(T * item);

	template<class Argument>
	T * FindFirst(const Argument& searchFor)
	{
		return FindNext(searchFor);
	}

	friend std::ostream& operator <<(std::ostream& cout, DLList& dLList)
	{
		return dLList.Print(cout);
	}
	void Check();
private:
	std::ostream& Print(std::ostream& cout) 
	{
		return cout;
	}

};



