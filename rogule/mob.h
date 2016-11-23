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
		std::string description, // Описание монстра
		Map level // где сгенерирован моб (нужно для его размещения)
		);// Конструктор
	Mob();
	//Mob(char icon, short x, short y, Map level);
	// Социальное агро(добовляет флаг _is_attack всем мобам в радиусе видимисти)
	void social_agro(Map level); 
	// Моб преследует героя
	int find_way(Map level, Hero &hero); //level - уровень, х,у координаты героя возвращает 1 если мод атакует героя
	// Устанавливает значение флага атаки
	void set_is_attack(bool value); 
	// Вовзвращает значение флага атаки
	bool get_is_attack(); 
	// Устанавливает значение флага отслупления
	void set_is_retreat(bool value); 
	// Возвращает значение флага отступления
	bool get_is_retreat();
	//работа с мобами
	friend void work_to_mobs(vector <Mob*>&, RenderWindow &window, Map &level); 

private:
	std::string _description; // Описание монстра
	bool _is_attack, //флаг атаки
		_is_retreat; //флаг отступления
};