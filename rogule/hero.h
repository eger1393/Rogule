#pragma once
#include "stdafx.h"

class Hero
{
public:
    Hero();
    Hero(short x, short y); 
	void key_press(Map level); // Перехват клавиш
    void range_of_visibility(Map level, char c); // Вычесление области видемости
    void set_hero(Map level, short x, short y); // Передвинуть героя
private:
    const short _range_of_visibility = 4; // Радиус видимости
    const char _icon = '@'; //иконка героя
    short _x, _y; // Координаты героя
};