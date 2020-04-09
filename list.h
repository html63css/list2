#pragma once
#include "element.h"

struct List
{
	void add(Element*);
	void addN(Element*);
	void remove(Element*);
	void removeN(Element*);
	void closure();
	void disjunction(Element*);
	void write();
	void read();
	List();
	Element* head;
	Element* end;
	bool isRing;
	int count;
};