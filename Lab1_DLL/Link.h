#pragma once
#include <iostream>

template <class T>
class DLList;

template <class T> class Link 
{
	Link* next; 
	Link* prev;
	friend class DLList<T>;

public:
	Link();
	virtual ~Link() = default;
	T* Next();
	T*Prev();

	T* InsertAfter(T * TToInsert);
	T* InsertBefore(T * TToInsert);
	T* DeleteAfter();

	template<class Argument> 
	T* FindNext(const Argument& searchFor);

	virtual std::ostream& Print(std::ostream& cout) { return cout; }


};



