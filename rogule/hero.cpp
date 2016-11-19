
#include "stdafx.h"


Hero::Hero(int hit_point, // Здоровье
	int viewing_range, // Радиус обзора
	int damage, // Урон
	int armor, // Броня
	short x, short y // Координаты существа
) : Unit(hit_point, viewing_range, damage, armor, '@', x, y)
{
	herotexture.loadFromFile("images/hero.png"); //картинка

	herosprite.setTexture(herotexture);//передаём в него объект Texture (текстуры)

	herosprite.setPosition(x, y);//задаем начальные координаты появления спрайта
	
	rect = FloatRect(x, y, 16, 16);//координаты + ширина-высота поля
}

void Hero::viewing_range(Map level, char c) // Вычесление области видемости
{
	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
	//level.get_cell(this->_x + 5, this->_y + 5).set_value('1');
	for (int i = 0; i <= this->_viewing_range; i++)
	{
		for (int j = 1; j <= this->_viewing_range - i; j++) // Правый нижний
		{
			if (!flag1 && j == 1 && !level.get_cell(this->_x + j, this->_y + i).is_limpid())
				flag1 = true;
			if (!flag1 && level.get_cell(this->_x + j, this->_y + i).is_limpid())
			{
				level.get_cell(this->_x + j, this->_y + i).set_value(c);
				level.reprint_cell(this->_x + j, this->_y + i);
			}
			else
				break;
		}

		for (int j = 1; j <= this->_viewing_range - i; j++) // Левый нижний
		{
			if (!flag2 && j == 1 && !level.get_cell(this->_x - i, this->_y + j).is_limpid())
				flag2 = true;
			if (!flag2 && level.get_cell(this->_x - i, this->_y + j).is_limpid())
			{
				level.get_cell(this->_x - i, this->_y + j).set_value(c);
				level.reprint_cell(this->_x - i, this->_y + j);
			}
			else
				break;
		}

		for (int j = 1; j <= this->_viewing_range - i; j++) //Левый верхний
		{
			if (!flag3 && j == 1 && !level.get_cell(this->_x - j, this->_y - i).is_limpid())
				flag3 = true;
			if (!flag3 && level.get_cell(this->_x - j, this->_y - i).is_limpid())
			{
				level.get_cell(this->_x - j, this->_y - i).set_value(c);
				level.reprint_cell(this->_x - j, this->_y - i);
			}
			else
				break;
		}

		for (int j = 1; j <= this->_viewing_range - i; j++) // Правый верхний
		{
			if (!flag4 && j == 1 && !level.get_cell(this->_x + i, this->_y - j).is_limpid())
				flag4 = true;
			if (!flag4 && level.get_cell(this->_x + i, this->_y - j).is_limpid())
			{
				level.get_cell(this->_x + i, this->_y - j).set_value(c);
				level.reprint_cell(this->_x + i, this->_y - j);
			}
			else
				break;
		}

	}
}

void Hero::key_press(Map level)
{
	Mob a(1, 1, 1, 1, 'A', 5, 5, "ww");
	a.set_unit(level, 5, 5);
	char c; // Клавиша считаная с клавиатуры
	while (true)
	{
		c = _getch();
		/*if (c == -32)
			c = _getch();*/
		switch (c)
		{
		case 80:	// Стрелка вниз
			if (level.get_cell(this->_x, this->_y + 1).is_permeable()) // Проверка на прохидимость
			{
				this->viewing_range(level, ' ');
				this->set_unit(level, this->_x, this->_y + 1);
				this->viewing_range(level, '1');
				//system("cls");		// Заменить этот блок на перересовку
				//level.print_map();  // Отдельной клетки

			}
			break;
		case 72:	//Стрелка вверх
			if (level.get_cell(this->_x, this->_y - 1).is_permeable()) // Проверка на прохидимость
			{
				this->viewing_range(level, ' ');
				this->set_unit(level, this->_x, this->_y - 1);
				this->viewing_range(level, '1');
				//system("cls");		// Заменить этот блок на перересовку
				//level.print_map();  // Отдельной клетки
			}
			break;
		case 77:	// Стрелка влево
			if (level.get_cell(this->_x + 1, this->_y).is_permeable()) // Проверка на прохидимость
			{
				this->viewing_range(level, ' ');
				this->set_unit(level, this->_x + 1, this->_y);
				this->viewing_range(level, '1');
				//system("cls");		// Заменить этот блок на перересовку
				//level.print_map();  // Отдельной клетки
			}
			break;
		case 75:	// Стрелка вправо
			if (level.get_cell(this->_x - 1, this->_y).is_permeable()) // Проверка на прохидимость
			{
				this->viewing_range(level, ' ');
				this->set_unit(level, this->_x - 1, this->_y);
				this->viewing_range(level, '1');
				//system("cls");		// Заменить этот блок на перересовку
				//level.print_map();  // Отдельной клетки
			}
			break;
		/*default:
			break;*/
		}
		a.find_way(level, this->_x, this->_y);

	}


}