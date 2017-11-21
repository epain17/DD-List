#pragma once

#include "Link.h"
#include <iostream>

template <class T>
class DLList :public Link<T>
{
	Link<T> * RefLink;
public:
	DLList();
	~DLList() = default;

	T * First()
	{
		return RefLink->next
	}

	T * Last()
	{
		return RefLink->prev;
	}

	T * PushFront(T * item)
	{
		if (RefLink == nullptr)
		{
			Link<T> * newLink;
			
			RefLink->InsertAfter(item);
			RefLink->prev = item;
			newLink->next = RefLink;
			newLink->prev = RefLink;
		}
		else
		{
			/*Link<T> *currentlyFirst = RefLink->next;
			Link<T> *newLink = item;
			currentlyFirst->prev = newLink;
			newLink->next = currentlyFirst;
			RefLink->next = newLink;
			newLink->prev = RefLink;*/
			
			RefLink->next->prev = item;
			item->next = RefLink->next;
			item->next = RefLink->next;
			item->prev = RefLink;
			
		}
	}

	T * PopFront()
	{
		if (RefLink->next == nullptr)
		{
			return 0;
		}

		else
		{

		}
	}
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



