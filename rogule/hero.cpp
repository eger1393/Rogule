
#include "stdafx.h"

Hero::Hero(int hit_point, // Здоровье
	int viewing_range, // Радиус обзора
	int damage, // Урон
	int armor, // Броня
	short x, short y // Координаты существа
	) : Unit(hit_point, viewing_range, damage, armor, y, x)
{
	texture.loadFromFile("images/hero.png"); //картинка

	sprite.setTexture(texture);//передаём в него объект Texture (текстуры)

	sprite.setPosition(y*32, x*32);//задаем начальные координаты появления спрайта
	
}

void Hero::set_hit_point(int hit)
{
	_hit_point += hit;
	/*if (_hit_point <= 0)
	{
		life = false;
	}
*/
}
int Hero::get_hit_point()
{
	return this->_hit_point;
}
void Hero::active(char Symbol, Map &level, short x, short y, View &view, RenderWindow &window)
{
	

	switch (Symbol)
	{
	case '$':
	{
		level.get_cell(x, y).set_value(' ');
		break;
	}
	case '!':
	{
		this->set_hit_point((this->get_hit_point())*-1);

		
		break;
	}
	default:
		break;
	}
}

void Hero::viewing_range(Map level,bool flag, char c) // Вычесление области видемости
{
	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
	//level.get_cell(this->_x + 5, this->_y + 5).set_value('1');
	for (int i = 0; i <= this->_viewing_range; i++)
	{
		for (int j = 1; j <= this->_viewing_range - i; j++) // Правый нижний
		{
			if (!flag1 && j == 1 && !level.get_cell(this->_x + j, this->_y + i).is_limpid())
			{
				flag1 = true;
				level.get_cell(this->_x + j, this->_y + i).set_view(flag);
				level.get_cell(this->_x + j, this->_y + i).set_prospected(true);
			}
			if (!flag1 && level.get_cell(this->_x + j, this->_y + i).is_limpid())
			{
				//level.get_cell(this->_x + j, this->_y + i).set_value(c);
				level.get_cell(this->_x + j, this->_y + i).set_view(flag);
				level.get_cell(this->_x + j, this->_y + i).set_prospected(true);
				level.reprint_cell(this->_x + j, this->_y + i);
			}
			else
				break;
		}

		for (int j = 1; j <= this->_viewing_range - i; j++) // Левый нижний
		{
			if (!flag2 && j == 1 && !level.get_cell(this->_x - i, this->_y + j).is_limpid())
			{
				flag2 = true;
				level.get_cell(this->_x - i, this->_y + j).set_view(flag);
				level.get_cell(this->_x - i, this->_y + j).set_prospected(true);
			}
			if (!flag2 && level.get_cell(this->_x - i, this->_y + j).is_limpid())
			{
				//level.get_cell(this->_x - i, this->_y + j).set_value(c);
				level.get_cell(this->_x - i, this->_y + j).set_view(flag);
				level.get_cell(this->_x - i, this->_y + j).set_prospected(true);
				level.reprint_cell(this->_x - i, this->_y + j);
			}
			else
				break;
		}

		for (int j = 1; j <= this->_viewing_range - i; j++) //Левый верхний
		{
			if (!flag3 && j == 1 && !level.get_cell(this->_x - j, this->_y - i).is_limpid())
			{
				flag3 = true;
				level.get_cell(this->_x - j, this->_y - i).set_view(flag);
				level.get_cell(this->_x - j, this->_y - i).set_prospected(true);
			}
			if (!flag3 && level.get_cell(this->_x - j, this->_y - i).is_limpid())
			{
				//level.get_cell(this->_x - j, this->_y - i).set_value(c);
				level.get_cell(this->_x - j, this->_y - i).set_view(flag);
				level.get_cell(this->_x - j, this->_y - i).set_prospected(true);
				level.reprint_cell(this->_x - j, this->_y - i);
			}
			else
				break;
		}

		for (int j = 1; j <= this->_viewing_range - i; j++) // Правый верхний
		{
			if (!flag4 && j == 1 && !level.get_cell(this->_x + i, this->_y - j).is_limpid())
			{
				flag4 = true;
				level.get_cell(this->_x + i, this->_y - j).set_view(flag);
				level.get_cell(this->_x + i, this->_y - j).set_prospected(true);
			}
			if (!flag4 && level.get_cell(this->_x + i, this->_y - j).is_limpid())
			{
				//level.get_cell(this->_x + i, this->_y - j).set_value(c);
				level.get_cell(this->_x + i, this->_y - j).set_view(flag);
				level.get_cell(this->_x + i, this->_y - j).set_prospected(true);
				level.reprint_cell(this->_x + i, this->_y - j);
			}
			else
				break;
		}

	}
}

int Hero::key_press(Map &level, View &viewer, RenderWindow &window)
{
	//Mob a(1, 1, 1, 1, 'A', 5, 5, "ww");
	//a.set_unit(level, 5, 5);
	
	if (this->get_hit_point() > 0)
	{
		if ((Keyboard::isKeyPressed(Keyboard::Left)) && ((level.get_cell(this->get_x() - 1, this->get_y()).is_limpid()))) // если нажата стрелка влево и т.д
		{
			this->viewing_range(level, false, ' ');

			active(level.get_cell(this->get_x() - 1, this->get_y()).get_value(), level, this->get_x() - 1, this->get_y(), viewer, window);

			this->set_unit(level, this->_x - 1, this->_y);

			/*this->sprite.move(-32, 0);

			this->move(-1, 0);*/

			viewer.setCenter(this->get_x() * 32, this->get_y() * 32);

			this->viewing_range(level, true, '1');
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right)) && ((level.get_cell(this->get_x() + 1, this->get_y()).is_limpid())))
		{
			this->viewing_range(level, false, ' ');

			active(level.get_cell(this->get_x() + 1, this->get_y()).get_value(), level, this->get_x() + 1, this->get_y(), viewer, window);
			this->set_unit(level, this->_x + 1, this->_y);

			/*this->sprite.move(32, 0);

			this->move(1, 0);*/

			this->viewing_range(level, true, '1');

			viewer.setCenter(this->get_x() * 32, this->get_y() * 32);


		}
		if (((Keyboard::isKeyPressed(Keyboard::Up))) && ((level.get_cell(this->get_x(), this->get_y() - 1).is_limpid())))
		{
			this->viewing_range(level, false, ' ');

			active(level.get_cell(this->get_x(), this->get_y() - 1).get_value(), level, this->get_x(), this->get_y() - 1, viewer, window);
			this->set_unit(level, this->_x, this->_y - 1);

			/*this->sprite.move(0, -32);

			this->move(0, -1);*/

			viewer.setCenter(this->get_x() * 32, this->get_y() * 32);

			this->viewing_range(level, true, '1');
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down)) && (level.get_cell(this->get_x(), this->get_y() + 1).is_limpid()))
		{
			this->viewing_range(level, false, ' ');

			active(level.get_cell(this->get_x(), this->get_y() + 1).get_value(), level, this->get_x(), this->get_y() + 1, viewer, window);

			this->set_unit(level, this->_x, this->_y + 1);
			//this->sprite.move(0, 32);

			//this->move(0, 1);

			viewer.setCenter(this->get_x() * 32, this->get_y() * 32);

			this->viewing_range(level, true, '1');
		}
	}
	else
	{
		Font font;//шрифт 
		font.loadFromFile("HelveticaNeue-Bold.ttf");//передаем нашему шрифту файл шрифта
		Text text("", font, 50);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
		text.setFillColor(Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
		text.setString("You died!");//задает строку тексту
		text.setPosition(viewer.getCenter().x-64, viewer.getCenter().y);//задаем позицию текста, центр камеры

		window.draw(text);
		window.display();
		Sleep(1000);
		return false;
			
	}
}

void Hero::move(short x, short y)
{
	_x += x;
	_y += y;
}