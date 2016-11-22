
#include "stdafx.h"

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

	int key_press(Map &level, View&, RenderWindow&); // Перехват клавиш

	void viewing_range(Map level, bool flag_view, char c); // Вычесление области видимости

	void move(short x, short y);
	
	void active(char Symbol, Map &level, short,short, View &view, RenderWindow &window);
	//установка жизней героя
	void set_hit_point(int);
	//вернуть кол-во жизней 
	int get_hit_point();

private:
    
};