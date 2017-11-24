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


	bool isEmpty()
	{
		if (prev == this && next == this)
		{
			return true;
		}
		return false;
	}

	T * First()
	{
		return this->Next();
	}

	T * Last()
	{
		return this->Prev();
	}

	T * PopFront()
	{
		this->DeleteAfter();
		return  0;
	}

	T * PushFront(T * item)
	{	
		if (isEmpty())
		{
			prev = item;
			next = item;	
			return item;
		}
		else
		{
			prev->prev = item;
			item->next = next;
			next = item;
			item->prev = nullptr;
			 
			 
			return item;
		}

		return item;
	}

	T * PushBack(T * item)
	{
		if (isEmpty())
		{
			prev = item;
			next = item;
			return item;
		}
		else
		{
			prev->next = item;
			item->prev = prev;
			prev = item;
			item->next = nullptr;
			return item;
		}

		return item;
	}

	bool Invariant()
	{
		return (next->prev == this && prev->next == this || next->prev == nullptr && prev->next == nullptr);
		
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



