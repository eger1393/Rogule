#pragma once

#include "stdafx.h"

class Mob : public Unit
{
public:
	Mob(int hit_point, // Здоровье
		int viewing_range, // Радиус обзора
		int damage, // Урон
		int armor, // Броня
		char icon, // Иконка cущества
		short x, short y, // Координаты существа
		std::string description // Описание монстра
		);// Конструктор
	Mob();
	void social_agro(Map level); // Социальное агро(добовляет флаг _is_attack всем мобам в радиусе видимисти)
	int find_way(Map level, Hero &hero); //level - уровень, х,у координаты героя возвращает 1 если мод атакует героя

	void set_is_attack(bool value); // Устанавливает значение флага атаки
	bool get_is_attack(); // Вовзвращает значение флага атаки
	void set_is_retreat(bool value); // Устанавливает значение флага отслупления
	bool get_is_retreat(); // Возвращает значение флага отступления
	friend void work_to_mobs(vector <Mob*>, RenderWindow &window, Map &level); //работа с мобами

private:
	std::string _description; // Описание монстра
	bool _is_attack, //флаг атаки
		_is_retreat; //флаг отступления
};