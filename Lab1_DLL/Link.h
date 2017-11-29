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
	Link() {}
	virtual ~Link() = default;

	//Fix
	bool Invariant()
	{
		return (next->prev == this && prev->next == this);

	}



	//Fix
	T* Next()
	{
		return dynamic_cast <T*> (next);

	}

	T* Prev()
	{

		return dynamic_cast <T*> (prev);
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
		T* temp = this->Next();
		if (next == prev)
		{

			next = this;
			prev = this;
			return dynamic_cast <T*> (temp);
		}

		//Peka om pekarna
		this->next = next->Next();

		if (next == nullptr)
		{
			return dynamic_cast <T*> (temp);
		}
		next->prev = this;

		return dynamic_cast <T*> (temp);


	}


	template<class Argument>
	T* FindNext(const Argument& searchFor)
	{

		if (dynamic_cast <T*> (next) == nullptr)
		{

			return nullptr;
		}

		if (dynamic_cast <T*> (this->next)->Match(searchFor))
		{
			return dynamic_cast <T*>(next);
		}

		else
		{
			this->next->FindNext(searchFor);
		}



	}

	virtual std::ostream& Print(std::ostream& cout) { return cout; }


};

