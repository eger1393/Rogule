// rogule.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
  

int main()
{
	Map test(20, 20);
	test.test_Map(20, 20);

	Hero hero(10, 6, 10, 5, 10, 10);
	test.print_map();
	hero.key_press(test);
	system("pause");
    return 0;
}

