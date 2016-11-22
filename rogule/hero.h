
#include "stdafx.h"

class Mob;

class Hero : public Unit
{
public:

    //Hero();

    Hero(int hit_point, // Здоровье
		int viewing_range, // Радиус обзора
		int damage, // Урон
		int armor, // Броня
		short x, short y // Координаты существа
		); 

	// Перехват клавиш
	int key_press(Map &level, View&,vector <Mob*> &arr_mob, RenderWindow&); 
	// Вычесление области видимости
	void viewing_range(Map level, bool flag_view, char c); 
	//Взаимодействие с активными клетками ( огонь-сундук и т.д)
	void active(char Symbol, Map &level, short,short, RenderWindow &window, View &view); 
	//установка жизней героя
	void set_hit_point(int);
	//вернуть радиус обзора
	int get_viewing_range();
	//вернуть урон
	int get_damage();
	//вернуть броню
	int get_armor();

private:
    
};