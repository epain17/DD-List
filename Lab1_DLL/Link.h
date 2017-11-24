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
		if (next == nullptr)
		{
			return nullptr;
		}
	
		//Peka om pekarna
		this->next = next->Next();
		this->next->prev = this;
		
		
		return dynamic_cast <T*> (this);


	}


	template<class Argument>
	T* FindNext(const Argument& searchFor)
	{

		if (dynamic_cast <T*> (next) == nullptr)
		{

			/*Node* current = dynamic_cast<Node*> (this->next);*/

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

