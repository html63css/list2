#pragma once
#include "element.h"

struct List
{
	void add(Element*);
	void remove(Element*);
	void addN(Element*);
	void removeN(Element*);
	void write();
	void read();
	void closure();
	void disjunction(Element*);
	List();
	Element* head;
	Element* end;
	bool isRing;
	int count;
};