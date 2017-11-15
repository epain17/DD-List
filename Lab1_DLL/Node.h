#ifndef NODE_H
#define NODE_H
#include "Link.h"
class Node : public Link<Node>
{

	float val;
public:
	Node(float v) :val(v){};

	bool match(float rhs) { return val = rhs; };
	
	~Node();
};

#endif