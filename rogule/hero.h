
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
	Texture herotexture;
	Sprite herosprite;
	FloatRect rect;
	void key_press(Map level); // Перехват клавиш
	void viewing_range(Map level, char c); // Вычесление области видимости
private:
    
};