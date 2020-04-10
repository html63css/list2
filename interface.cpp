#include "list.h"
#include <conio.h>
#include <iostream>
#define KEY_DOWN 80
#define KEY_UP 72
#define KEY_REMOVE 8
#define KEY_REMOVEN 'D' 
#define KEY_ADD 13
#define KEY_ADDN 'A'
#define KEY_END 27
#define KEY_CLOSURE 9
#define KEY_DISJUNCTION 32
#define KEY_WRITE 'W'
#define KEY_READ 'R'
#pragma warning (default : 4996)
int main()
{
	setlocale(0, "");
	FILE* file;
	List list;
	Element* I;
	Element* positionElement = nullptr;
	Element* bufferDel = nullptr;
	char namefile[100] = {'\0'};
	int a(0);
	int addn;
	char ch(0);
	int buff(0);
	int size(0);
	int position(0);
	do
	{
		std::cout << "Введите начальный размер списка\n";
		std::cin >> size;
		if (size < 0)
			printf("Размер не может быть отрицательным");
	} while (size < 0);
	if (size <= 0) exit(0);
	for (int i = 0; i < size; ++i)
	{
		list.add(nullptr);
	}
	do
	{
		system("cls");
		std::cout << "1) ДОБАВИТЬ ЭЛЕМЕНТ ПОСЛЕ УКАЗАТЕЛЯ - ENTER\n";
		std::cout << "2) УДАЛИТЬ ЭЛЕМЕНТ ЭЛЕМЕНТ, НА КОТОРОМ СТОИТ УКАЗАТЕЛЬ - BACKSPACE\n";
		std::cout << "3) ДОБАВИТЬ n ЭЛЕМЕНТОВ ПОСЛЕ СТРЕЛКИ - A (ВЕРХНИЙ РЕГИСТР, АНГЛ.)\n";
		std::cout << "4) УДАЛИТЬ ЭЛЕМЕНТЫ С ПОЗИЦИЙ ОТ a ДО b - D (ВЕРХНИЙ РЕГИСТР)\n";
		std::cout << "5) СОХРАНИТЬ СПИСОК В ФАЙЛ - W (ВЕРХНИЙ РЕГИСТР)\n";
		std::cout << "6) ОТОБРАЗИТЬ СОДЕРЖИМОЕ ФАЙЛА - R (ВЕРХНИЙ РЕГИСТР)\n";
		std::cout << "7) ПРЕВРАТИТЬ СПИСОК В КОЛЬЦО - TAB\n";
		std::cout << "8) РАЗОРВАТЬ КОЛЬЦА - SPACE\n";
		std::cout << "ВЫЙТИ ИЗ ПРОГРАММЫ - ESC\n";
		if (ch >= 0)
		{
			I = list.head;
			std::cout << "№|";
			if (position == 0) std::cout << "\t\t<--";
			std::cout << "\n";
			for (int i = 1; i <= list.count; ++i)
			{
				std::cout << i << "|" << "\t" << I->date;
				if (position == i) std::cout << "\t<--";
				std::cout << "\n";
				I = I->next;
			}
		}
		do
		{
			ch = getch();
		} while (ch != KEY_DOWN && ch != KEY_UP && ch != KEY_ADD && ch != KEY_REMOVE && ch != KEY_ADDN && ch != KEY_REMOVEN && ch != KEY_DISJUNCTION && ch != KEY_CLOSURE && ch != KEY_WRITE && ch != KEY_READ && ch != KEY_END);
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
		case(KEY_WRITE):
			system("cls");
			for (auto& a : namefile) a = '\0';
			printf("Введите название файла, в который будет записан спасок\n");
			std::cin >> namefile;
			if ((file = fopen(namefile, "w")) != NULL)
			{
				a = 0;
				for (Element* i = list.head ; a < list.count ; i = i->next, ++a)
				{
					fprintf(file, "%i\n", i->date);
				}
				fclose(file);
			}
			else
			{
				printf("Невозможно открыть файл");
				getch();
			}
			break;
		case(KEY_READ):
			system("cls");
			for (auto& a : namefile) a = '\0';
			printf("Введите название файла для чтения\n");
			std::cin >> namefile;
			if ((file = fopen(namefile, "r")) != NULL)
			{
				char buf[400] = {'\0'};
				fscanf(file, "%400[^~]", buf);
				printf("%s",buf);
				fclose(file);
				getch();
			}
			else
			{
				printf("Невозможно открыть файл");
				getch();
			}
			break;
		case(KEY_ADDN):
			system("cls");
			do
			{
				printf("Введите кол-во элементов\n");
				std::cin >> addn;
				if (addn <= 0)
				{
					printf("Повторите ввод. Введено некорректное значение");
					getch();
				}
			} while (addn <= 0);
			for (int i = 0; i < addn; ++i)
			{
				system("cls");
				list.add(positionElement);
			}
			break;
		case(KEY_REMOVEN):
			int a = 0;
			int b = 0;
			Element* DELETE = list.head;
			do
			{
				system("cls");
				printf("Введите с какой позиции начать удаление(включительно): ");
				std::cin >> a;
				if (a <= 0 || a >= list.count)
					{	
						printf("Повторите ввод. Введено некорректное значение");
						getch();
					}
			} while (a <= 0 || a >= list.count);
			do
			{
				system("cls");
				printf("Введите до какой позиции производить удаление(включительно, a<b): ");
				std::cin >> b;
				if (b <= a || b > list.count)
				{
					printf("Повторите ввод. Введено некорректное значение");
					getch();
				}
			} while (b <= a || b > list.count);
			for (int i = 1; i < a; ++i)
			{
				DELETE = DELETE->next;
			}
			for (int i = 0; i < (b - a) + 1; ++i)
			{
				Element* buf = DELETE->next;
				list.remove(DELETE);
				DELETE = buf;
			}
			break;
		}
	} while (ch != KEY_END);

}