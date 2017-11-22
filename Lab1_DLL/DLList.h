#pragma once

#include "Link.h"
#include <iostream>

template <class T>
class DLList :public Link<T>
{
	
public:
	DLList() 
	{
		prev = this;
		next = this;
		
	}
	~DLList() = default;

	T * First()
	{
		return this->Next();
	}

	T * Last()
	{
		return this->Prev();
	}

	T * PushFront(T * item)
	{
		
		this->InsertBefore(item);
		return item;
	}

	T * PopFront()
	{
		this->DeleteAfter();
		return  0;
	}
	T * PushBack(T * item)
	{
		this->InsertAfter(item);
		return item;
	}

	bool Invariant()
	{
		return (next->prev == this && prev->next == this);
		
	}

	template<class Argument>
	T * FindFirst(const Argument& searchFor)
	{
		return FindNext(searchFor);
	}

	friend std::ostream& operator <<(std::ostream& cout, DLList& dLList)
	{
		return dLList.Print(cout);
	}
	void Check() {}
private:
	std::ostream& Print(std::ostream& cout)
	{
		return cout;
	}

};



