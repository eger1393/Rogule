#pragma once

#include "stdafx.h"

const char name_units[] = {
	'@','z','Z','x','X', 'A'
};

class Unit
{
public:
	//Unit(); // Не должен исспользоваться
	Unit(int hit_point, // Здоровье
		int viewing_range, // Радиус обзора
		int damage, // Урон
		int armor, // Броня
		char icon, // Иконка cущества
	short x, short y // Координаты существа
	); // Конструктор
	
	//void viewing_range(Map level, char c); // Вычесление области видимости
	void attak(Unit *unit2); // Атака текущего юнита вторым юнитом
	void set_unit(Map level, short x, short y); // Передвинуть юнит

protected:
	int _hit_point, // Здоровье
		_viewing_range, // Радиус обзора
		_damage, // Урон
		_armor; // Броня
	char _icon; // Иконка cущества
	short _x, _y; // Координаты существа
};