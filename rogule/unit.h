#pragma once

#include "stdafx.h"


class Unit
{
public:
	Texture texture;
	Sprite sprite;
	//Unit(); // Не должен исспользоваться
	Unit(int hit_point, // Здоровье
		int viewing_range, // Радиус обзора
		int damage, // Урон
		int armor, // Броня
	short x, short y // Координаты существа
	); // Конструктор
	
	//void viewing_range(Map level, char c); // Вычесление области видимости
	void attak(Unit *unit2); // Атака текущего юнита вторым юнитом
	void set_unit(Map level, short x, short y); // Передвинуть юнит
	int get_x();
	int get_y();
protected:
	int _hit_point, // Здоровье
		_viewing_range, // Радиус обзора
		_damage, // Урон
		_armor; // Броня
	char _icon; // Иконка cущества
	short _x, _y; // Координаты существа
};