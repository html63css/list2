#include "list.h"
#include <iostream>
List::List()
{
	head = nullptr;
	end = nullptr;
	isRing = false;
	count = 0;
}
void List::add(Element* base)
{
	int num;
	std::cin >> num;
	Element* elem = new Element();
	elem->date = num;
	elem->next = nullptr;
	elem->early = nullptr;
	if (isRing == 0)
	{
		if (base == nullptr && head != nullptr && end != nullptr)
		{
			head->early = elem;
			elem->next = head;
			head = elem;
			++count;
			return;
		}
		if (base == end && head != nullptr && end != nullptr)
		{
			end->next = elem;
			elem->early = end;
			end = elem;
			++count;
			return;
		}
		if (base != nullptr && base != end && head != nullptr && end != nullptr)
		{
			elem->next = base->next;
			elem->early = base;
			base->next = elem;
			elem->next->early = elem;
			++count;
			return;
		}
		if (head == nullptr && end == nullptr)
		{
			head = elem;
			end = elem;
			++count;
			return;
		}
	}
	else
	{
		elem->next = base->next;
		elem->early = base;
		base->next = elem;
		elem->next->early = elem;
		++count;
		return;
	}
}

void List::remove(Element* base)
{
	if (isRing == 0)
	{
		if (base == head && base != end)
		{
			head = base->next;
			head->early = nullptr;
			delete base;
			--count;
			return;
		}
		else if (base != head && base == end)
		{
			end = base->early;
			end->next = nullptr;
			delete base;
			--count;
			return;
		}
		else if (base != head && base != end)
		{
			base->early->next = base->next;
			base->next->early = base->early;
			delete base;
			--count;
			return;
		}
		else if (base == head && base == end)
		{
			head = nullptr;
			end = nullptr;
			delete base;
			count = 0;
			return;
		}
	}
	else
	{
		base->early->next = base->next;
		base->next->early = base->early;
		delete base;
		--count;
		return;
	}
}