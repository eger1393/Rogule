#pragma once

#include "stdafx.h"


class Unit
{
public:
	Texture texture;
	Sprite sprite;
	//Unit(); // Не должен исспользоваться

	// Конструктор
	Unit(int hit_point, // Здоровье
		int viewing_range, // Радиус обзора
		int damage, // Урон
		int armor, // Броня
		char icon, // Иконка cущества
	short x, short y, // Координаты существа
		std::string description // Описание монстра
	); // Конструктор
	
	//void viewing_range(Map level, char c); // Вычесление области видимости

	// Юнит вызвавший ф-ию атакую переданный юнит
	void attak(Unit &unit2); 
	// Передвинуть юнит
	void set_unit(Map level, short x, short y); 
	// Вернуть кол-во жизне юнита
	int get_hit_point();
	// Вернуть координату х
	int get_x();
	// Вернуть координату У
	int get_y();
protected:
	std::string _description; // Описание монстра
	int _hit_point, // Здоровье
		_viewing_range, // Радиус обзора
		_damage, // Урон
		_armor; // Броня
	char _icon; // Иконка cущества
	short _x, _y; // Координаты существа
};