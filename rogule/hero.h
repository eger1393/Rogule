
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

	void key_press(Map &level, View&,vector <Mob*> &arr_mob); // Перехват клавиш

	void viewing_range(Map level, bool flag_view, char c); // Вычесление области видимости

	void active(char Symbol, Map &level, short,short, RenderWindow &window, View &view); // чтото с сундучками

	void move(int x, int y);
	//установка жизней героя
	void set_hit_point(int);
	//вернуть кол-во жизней 
	int get_hit_point();
private:
    
};