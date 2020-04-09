#include "list.h"
#include <conio.h>
#include <iostream>
#define KEY_DOWN 80
#define KEY_UP 72
#define KEY_REMOVE 8
#define KEY_ADD 13
#define KEY_END 27
#define KEY_CLOSURE 9
#define KEY_DISJUNCTION 32
#pragma warning (default : 4996)
int main()
{
	setlocale(0, "");
	List list;
	Element* I;
	Element* positionElement = nullptr;
	Element* bufferDel = nullptr;
	char ch(0);
	int position(0);
	int buff(0);
	int size(0);
	std::cout << "Введите начальный размер списка\n";
	std::cin >> size;
	if (size <= 0) exit(0);
	for (int i = 0; i < size; ++i)
	{
		std::cout << "\nВведите число\n";
		list.add(nullptr);
	}
	do
	{
		system("cls");
		std::cout << "ДОБАВИТЬ ЭЛЕМЕНТ ПОСЛЕ УКАЗАТЕЛЯ - ENTER\n";
		std::cout << "УДАЛИТЬ ЭЛЕМЕНТ ЭЛЕМЕНТ, НА КОТОРОМ СТОИТ УКАЗАТЕЛЬ - BACKSPACE\n";
		std::cout << "ПРЕВРАТИТЬ СПИСОК В ЦЕПЬ - TAB\n";
		std::cout << "РАЗОРВАТЬ ЦЕПЬ - SPACE\n";
		std::cout << "ВЫЙТИ ИЗ ПРОГРАММЫ - ESC\n";
		if (ch >= 0)
		{
			I = list.head;
			if (position == 0) std::cout << "\t\t<--";
			std::cout << "\n";
			for (int i = 1; i <= list.count; ++i)
			{
				std::cout << "\t" << I->date;
				if (position == i) std::cout << "\t<--";
				std::cout << "\n";
				I = I->next;
			}
		}
		do
		{
			ch = getch();
		} while (ch != KEY_DOWN && ch != KEY_UP && ch != KEY_ADD && ch != KEY_REMOVE && ch != KEY_DISJUNCTION && ch != KEY_CLOSURE && ch != KEY_END);
		switch (ch)
		{
		case (KEY_DOWN):
			if (position == list.count)
			{
				position = 0;
				positionElement = nullptr;
			}
			else
			{
				++position;
				if (position == 1)
				{
					positionElement = list.head;
				}
				else
				{
					positionElement = positionElement->next;
				}
			}
			break;
		case (KEY_UP):
			if (position == 0)
			{
				position = list.count;
				positionElement = list.end;
			}
			else
			{
				--position;
				if (position == list.count)
				{
					positionElement = list.end;
				}
				else
				{
					positionElement = positionElement->early;
				}
			}
			break;
		case(KEY_ADD):
			system("cls");
			std::cout << "Введите число \n";
			list.add(positionElement);
			break;
		case(KEY_REMOVE):
			if (position != 0)
			{
				if (position == list.count)
				{
					position = 0;
					list.remove(positionElement);
					positionElement = nullptr;
				}
				else
				{
					bufferDel = positionElement->next;
					list.remove(positionElement);
					positionElement = bufferDel;
				}
			}
			break;
		case(KEY_CLOSURE):
			if (list.count >= 2 && list.isRing == 0)
			{
				list.closure();
			}
			break;
		case(KEY_DISJUNCTION):
			if (positionElement != nullptr)
			{
				list.disjunction(positionElement);
				position = 0;
				positionElement = nullptr;
			}
			break;
		}
	} while (ch != KEY_END);

}