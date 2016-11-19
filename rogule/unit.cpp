#include "stdafx.h"

Unit::Unit(int hit_point, // Здоровье
	int viewing_range, // Радиус обзора
	int damage, // Урон
	int armor, // Броня
	char icon, // Иконка cущества
	short x, short y // Координаты существа
	) // Конструктор
{
	this->_hit_point = hit_point;
	this->_viewing_range = viewing_range;
	this->_damage = damage;
	this->_armor = armor;
	this->_icon = icon;
	this->_x = x;
	this->_y = y;
}

//void Unit::viewing_range(Map level, char c) // Вычесление области видемости
//{
//	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
//	//level.get_cell(this->_x + 5, this->_y + 5).set_value('1');
//	for (int i = 0; i <= this->_viewing_range; i++)
//	{
//		for (int j = 1; j <= this->_viewing_range - i; j++) // Правый нижний
//		{
//			if (!flag1 && j == 1 && !level.get_cell(this->_x + j, this->_y + i).is_limpid())
//				flag1 = true;
//			if (!flag1 && level.get_cell(this->_x + j, this->_y + i).is_limpid())
//			{
//				level.get_cell(this->_x + j, this->_y + i).set_value(c);
//			}
//			else
//				break;
//		}
//
//		for (int j = 1; j <= this->_viewing_range - i; j++) // Левый нижний
//		{
//			if (!flag2 && j == 1 && !level.get_cell(this->_x - i, this->_y + j).is_limpid())
//				flag2 = true;
//			if (!flag2 && level.get_cell(this->_x - i, this->_y + j).is_limpid())
//			{
//				level.get_cell(this->_x - i, this->_y + j).set_value(c);
//			}
//			else
//				break;
//		}
//
//		for (int j = 1; j <= this->_viewing_range - i; j++) //Левый верхний
//		{
//			if (!flag3 && j == 1 && !level.get_cell(this->_x - j, this->_y - i).is_limpid())
//				flag3 = true;
//			if (!flag3 && level.get_cell(this->_x - j, this->_y - i).is_limpid())
//			{
//				level.get_cell(this->_x - j, this->_y - i).set_value(c);
//			}
//			else
//				break;
//		}
//
//		for (int j = 1; j <= this->_viewing_range - i; j++) // Правый верхний
//		{
//			if (!flag4 && j == 1 && !level.get_cell(this->_x + i, this->_y - j).is_limpid())
//				flag4 = true;
//			if (!flag4 && level.get_cell(this->_x + i, this->_y - j).is_limpid())
//			{
//				level.get_cell(this->_x + i, this->_y - j).set_value(c);
//			}
//			else
//				break;
//		}
//
//	}
//}

void Unit::attak(Unit *unit2) // Текущий юнит атакует второго юнита
{
	if (unit2->_armor >= this->_damage) //если броня больше дамага
	{
		unit2->_hit_point -= 1;
	}
	else
	{
		unit2->_hit_point -= this->_damage - unit2->_armor;
		
	}
	if (unit2->_hit_point <= 0) // Смерть юнита
	{ 
		// Обработать смерть
	}
	return;
}

void Unit::set_unit(Map level, short x, short y) // Передвинуть юнит
{
	level.get_cell(this->_x, this->_y).set_value(' ');
	level.reprint_cell(this->_x, this->_y);
	this->_x = x;
	this->_y = y;
	level.get_cell(x, y).set_value(this->_icon);
	level.reprint_cell(this->_x, this->_y);
}
