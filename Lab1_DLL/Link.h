#pragma once
#include <iostream>

template <class T>
class DLList;

template <class T> class Link 
{
	Link* next = nullptr;
	Link* prev = nullptr
	friend class DLList<T>;

public:
	Link();
	virtual ~Link() = default;
	T* Next()
	{
		return next;
	}

	T*Prev()
	{
		return prev;
	}

	T* InsertAfter(T * TToInsert)
	{
		if (next == nullptr)
		{
			next = TToInsert;
		}
		else
		{
			Link<T> * temp = next;
			next = TToInsert;
			next->next = temp;

		}
		return TToInsert;
	}

	T* InsertBefore(T * TToInsert)
	{
		if (prev == nullptr)
		{
			prev = TToInsert;
		}
		else
		{
			Link<T> * temp = prev;
			prev = TToInsert;
			prev->prev = temp;

		}
		return TToInsert;
	}
	T* DeleteAfter()
	{
		if (next == nullptr)
		{
			std::cout << "nothing to delete";
			return NULL;
		}

		else
		{
			Link<T> * temp = next;

		}
	}
	

	template<class Argument> 
	T* FindNext(const Argument& searchFor);

	virtual std::ostream& Print(std::ostream& cout) { return cout; }


};



