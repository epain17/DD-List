// Lab1_DLL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Link.h"
#include "DLList.h"
#include "Node.h"
#include <assert.h>




int main()
{
	DLList<Node> myList;
	assert(myList.Invariant());
	Node * nodeA3 = myList.PushFront(new Node(3));
	assert(myList.Invariant());
	myList.PushFront(new Node(2));
	myList.PushFront(new Node(1));
	assert(myList.Invariant());
	myList.PushBack(new Node(1));
	myList.PushBack(new Node(2));
	myList.PushBack(new Node(3));
	assert(myList.Invariant());
	//assert(myList.Last()->Next() == nullptr);
	std::cout << myList;    //should be 1 2 3 1 2 3

	Node * tempA3 = myList.FindNext(3);
	assert(tempA3 == nodeA3);
	Node * nodeB1 = nodeA3->FindNext(1);
	Node * tempB1 = tempA3->DeleteAfter();   //ta bort andra 1:an
	assert(myList.Invariant());
	assert(tempB1->data == 1);

	Node * nodeA2 = myList.FindFirst(2);
	Node * nodeB2 = nodeA2->FindNext(2);
	Node * temp = nodeB2->FindNext(2);
	assert(!temp);

	nodeA2->DeleteAfter();
	std::cout << myList;    //1 2 2 3

	myList.First()->Next()->InsertAfter(tempA3)->InsertAfter(tempB1);
	assert(myList.Last()->Prev()->data == 2);
	assert(myList.Invariant());
	std::cout << myList;    //should be 1 2 3 1 2 3
	{Node* t = myList.PopFront(); assert(t->data == 1); delete t; }
	{Node* t = myList.PopFront(); assert(t->data == 2); delete t; }
	{Node* t = myList.PopFront(); assert(t->data == 3); delete t; }
	{Node* t = myList.PopFront(); assert(t->data == 1); delete t; }
	{Node* t = myList.PopFront(); assert(t->data == 2); delete t; }
	{Node* t = myList.PopFront(); assert(t->data == 3); delete t; }
	assert(myList.PopFront() == nullptr);
	assert(myList.PopFront() == nullptr);
	std::cout << myList << "end";
	assert(myList.Invariant());
	std::cin.get();
    return 0;
}

