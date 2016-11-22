
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
	void key_press(Map &level, View&,vector <Mob*> &arr_mob, RenderWindow&); 
	// Вычесление области видимости
	void viewing_range(Map level, bool flag_view, vector <Mob*> &arr_mob);
	//Антон
	void active(char Symbol, Map &level, short,short, RenderWindow &window, View &view); 
	//Антон  если эта ф-ия тебе не нужна то удали ее
	void move(int x, int y);
	//установка жизней героя
	void set_hit_point(int);

private:
    
};