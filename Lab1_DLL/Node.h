#ifndef NODE_H
#define NODE_H
#include "Link.h"
class Node : public Link<Node>
{
public:
	float data;
	Node(float v = 0) :data(v) {}
	bool Match(float v) { return data == v; }
	virtual std::ostream& Print(std::ostream& cout) const {
		return cout << data;
	}
	
};

#endif