// rogule.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"

int main()
{
	srand(time(((time_t)0)));

	Map Level_1(30, 70);
	Level_1.initialize_Level();
	Level_1.print_map();
	system("pause");
	system("cls");
	return 0;
}

