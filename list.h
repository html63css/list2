#pragma once
#include "element.h"

struct List
{
	void add(Element*);
	void remove(Element*);
	void closure();
	void disjunction(Element*);
	List();
	Element* head;
	Element* end;
	bool isRing;
	int count;
};