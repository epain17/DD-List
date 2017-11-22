#pragma once
#include <iostream>
#include <assert.h>

template <class T>
class DLList;

template <class T> class Link 
{
	Link* next = nullptr;
	Link* prev = nullptr;
	friend class DLList<T>;

public:
	Link(){}
	virtual ~Link() = default;
	//Fix
	bool Invariant()
	{
		return (next->prev == this && prev->next == this);

	}
	
	//Fix
	T* Next()
	{
		return static_cast <T*> (next);

	}
	//Fix
	T* Prev()
	{
		
		return static_cast <T*> (prev);
	}

	T* InsertAfter(T * TToInsert)
	{
		assert(Invariant());
		TToInsert->next = next;
		TToInsert->prev = this;
		if (next != nullptr)
		{
			next->prev = TToInsert;
		}

		next = TToInsert;
		assert(Invariant());
		return TToInsert;
	}

	T* InsertBefore(T * TToInsert)
	{
		assert(Invariant());
		TToInsert->prev = prev;
		TToInsert->next = this;
		if (prev != nullptr)
		{
			prev->next = TToInsert;
		}
		prev = TToInsert;
		assert(Invariant());
		return TToInsert;
	}
	//Fix
	T* DeleteAfter()
	{
		if (next == nullptr)
		{
			return nullptr;
		}
		T* temp = static_cast <T*>(this->next);
		this->next = temp->next;
		temp->next->prev = this;
		temp -> next = nullptr;
		temp->prev = nullptr;
		return temp;

		
	}
	

	template<class Argument> 
	T* FindNext(const Argument& searchFor)
	{
	/*	T * current = static_cast <T*> (current);
		current->Match(searchFor);*/
		return NULL;
	}

	virtual std::ostream& Print(std::ostream& cout) { return cout; }


};

