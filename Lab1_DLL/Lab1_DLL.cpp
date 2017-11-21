// Lab1_DLL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Link.h"
#include "DLList.h"
#include "Node.h"




int main()
{
	DLList<Node> *list = new DLList<Node>;
	Node *first = new Node(2);
	list->PushFront(first);
	
    return 0;
}

