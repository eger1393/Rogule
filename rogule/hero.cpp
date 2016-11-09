#include "stdafx.h"

Hero::Hero()
{
	this->_x = this->_y = 0;
}
Hero::Hero(short x, short y)
{
	this->_x = x;
	this->_y = y;
}

void Hero::set_hero(Map level, short x, short y)
{
	level.get_cell(this->_x, this->_y).set_type(' ');
	this->_x = x;
	this->_y = y;
	level.get_cell(x, y).set_type(this->_icon);
}

void Hero::range_of_visibility(Map level ,char c)
{
	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
	//level.get_cell(this->_x + 5, this->_y + 5).set_type('1');
	for (int i = 0; i <= this->_range_of_visibility; i++)
	{
		for (int j = 1; j <= this->_range_of_visibility - i; j++) // Правый нижний
		{
			if (!flag1 && j == 1 && !level.get_cell(this->_x + j, this->_y + i).is_limpid())
				flag1 = true;
			if (!flag1 && level.get_cell(this->_x + j, this->_y + i).is_limpid())
			{
				level.get_cell(this->_x + j, this->_y + i).set_type(c);
			}
			else
				break;
		}

		for (int j = 1; j <= this->_range_of_visibility - i; j++) // Левый нижний
		{
			if (!flag2 && j == 1 && !level.get_cell(this->_x - i, this->_y + j).is_limpid())
				flag2 = true;
			if (!flag2 && level.get_cell(this->_x - i, this->_y + j).is_limpid())
			{
				level.get_cell(this->_x - i, this->_y + j).set_type(c);
			}
			else
				break;
		}
		
		for (int j = 1; j <= this->_range_of_visibility - i; j++) //Левый верхний
		{
			if (!flag3 && j == 1 && !level.get_cell(this->_x - j, this->_y - i).is_limpid())
				flag3 = true;
			if (!flag3 && level.get_cell(this->_x - j, this->_y - i).is_limpid())
			{
				level.get_cell(this->_x - j, this->_y - i).set_type(c);
			}
			else
				break;
		}
		
		for (int j = 1; j <= this->_range_of_visibility - i; j++) // Правый верхний
		{
			if (!flag4 && j == 1 && !level.get_cell(this->_x + i, this->_y - j).is_limpid())
				flag4 = true;
			if (!flag4 && level.get_cell(this->_x + i, this->_y - j).is_limpid())
			{
				level.get_cell(this->_x + i, this->_y - j).set_type(c);
			}
			else
				break;
		}

	}
}

void Hero::key_press(Map level)
{
	char c; // Клавиша считаная с клавиатуры
	while (true)
	{
		c = _getch();
		/*if (c == -32)
			c = _getch();*/
		switch (c)
		{
		case 80:	// Стрелка вниз
			this->range_of_visibility(level, ' ');
			this->set_hero(level, this->_x, this->_y+1);
			this->range_of_visibility(level, '1');
			system("cls");		// Заменить этот блок на перересовку
			level.print_map();  // Отдельной клетки
			break;
		case 72:	//Стрелка вверх
			this->range_of_visibility(level, ' ');
			this->set_hero(level, this->_x, this->_y-1);
			this->range_of_visibility(level, '1');
			system("cls");		// Заменить этот блок на перересовку
			level.print_map();  // Отдельной клетки
			break;
		case 77:	// Стрелка влево
			this->range_of_visibility(level, ' ');
			this->set_hero(level, this->_x+1, this->_y);
			this->range_of_visibility(level, '1');
			system("cls");		// Заменить этот блок на перересовку
			level.print_map();  // Отдельной клетки
			break;
		case 75:	// Стрелка вправо
			this->range_of_visibility(level, ' ');
			this->set_hero(level, this->_x-1, this->_y);
			this->range_of_visibility(level, '1');
			system("cls");		// Заменить этот блок на перересовку
			level.print_map();  // Отдельной клетки
			break;
		/*default:
			break;*/
		}

	}


}