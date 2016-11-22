
#include "stdafx.h"

Hero::Hero(int hit_point, // Здоровье
	int viewing_range, // Радиус обзора
	int damage, // Урон
	int armor, // Броня
	short x, short y // Координаты существа
	) : Unit(hit_point, viewing_range, damage, armor, '@', y, x)
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
void Hero::active(char Symbol, Map &level, short x, short y, RenderWindow &window, View &view)
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

void Hero::viewing_range(Map level,bool flag, vector <Mob*> &arr_mob) // Вычесление области видемости
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
				level.get_cell(this->_x + j, this->_y + i).set_view(flag); // сдесь видимость стены
				level.get_cell(this->_x + j, this->_y + i).set_prospected(true);
			}
			if (!flag1 && level.get_cell(this->_x + j, this->_y + i).is_limpid()) // это если не стена
			{
				//level.get_cell(this->_x + j, this->_y + i).set_value(c);
				level.get_cell(this->_x + j, this->_y + i).set_view(flag); // устанавливает флаг видимости
				level.get_cell(this->_x + j, this->_y + i).set_prospected(true); // делает клетку разведанной
				level.reprint_cell(this->_x + j, this->_y + i); // перерисовывает ее в консоли

				if (level.get_cell(this->_x + j, this->_y + i).is_mob()) // Если в клетке стоит моб
				{
					for (int k = 0; k < arr_mob.size(); k++) // Ищем моба который стоит в этой клетке
						if (arr_mob[k]->get_x() == (this->_x + j) && arr_mob[k]->get_y() == (this->_y + i))
							arr_mob[k]->set_is_attack(true); // Ставим флаг атаки = true
				}
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

				if (level.get_cell(this->_x - i, this->_y + j).is_mob()) // Если в клетке стоит моб
				{
					for (int k = 0; k < arr_mob.size(); k++) // Ищем моба который стоит в этой клетке
						if (arr_mob[k]->get_x() == (this->_x - i) && arr_mob[k]->get_y() == (this->_y + j))
							arr_mob[k]->set_is_attack(true); // Ставим флаг атаки = true
				}
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

				if (level.get_cell(this->_x - j, this->_y - i).is_mob()) // Если в клетке стоит моб
				{
					for (int k = 0; k < arr_mob.size(); k++) // Ищем моба который стоит в этой клетке
						if (arr_mob[k]->get_x() == (this->_x - j) && arr_mob[k]->get_y() == (this->_y - i))
							arr_mob[k]->set_is_attack(true); // Ставим флаг атаки = true
				}
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

				if (level.get_cell(this->_x + i, this->_y - j).is_mob()) // Если в клетке стоит моб
				{
					for (int k = 0; k < arr_mob.size(); k++) // Ищем моба который стоит в этой клетке
						if (arr_mob[k]->get_x() == (this->_x + i) && arr_mob[k]->get_y() == (this->_y - j))
							arr_mob[k]->set_is_attack(true); // Ставим флаг атаки = true
				}
			}
			else
				break;
		}

	}
}

int Hero::key_press(Map &level, View &viewer, vector <Mob*> &arr_mob, RenderWindow &window)
{
	//Mob a(1, 1, 1, 1, 'A', 5, 5, "ww");
	//a.set_unit(level, 5, 5);
	
	if (this->get_hit_point() > 0)
	{
		if (Keyboard::isKeyPressed(Keyboard::Left)) // если нажата стрелка влево и т.д
		{
			if (level.get_cell(this->get_x() - 1, this->get_y()).is_permeable())
			{
				this->viewing_range(level, false, arr_mob);

				active(level.get_cell(this->get_x() - 1, this->get_y()).get_value(), level, this->get_x() - 1, this->get_y(), window, viewer);
				this->set_unit(level, this->_x - 1, this->_y);

				/*this->sprite.move(-32, 0);

				this->move(-1, 0);*/

				viewer.setCenter(this->get_x() * 32, this->get_y() * 32);

				this->viewing_range(level, true, arr_mob);
				//mob.find_way(level_1, hero.get_x(), hero.get_y());
			}
			if (level.get_cell(this->get_x() - 1, this->get_y()).is_mob())
			{
				for (int i = 0; i < arr_mob.size(); i++)
				{
					if (this->get_x() - 1 == arr_mob[i]->get_x() && this->get_y() == arr_mob[i]->get_y())
					{
						this->attak(*arr_mob[i]);
					}
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			if (level.get_cell(this->get_x() + 1, this->get_y()).is_permeable())
			{
				this->viewing_range(level, false, arr_mob);

				active(level.get_cell(this->get_x() + 1, this->get_y()).get_value(), level, this->get_x() + 1, this->get_y(), window, viewer);
				this->set_unit(level, this->_x + 1, this->_y);

				/*this->sprite.move(32, 0);

				this->move(1, 0);*/

				this->viewing_range(level, true, arr_mob);

				viewer.setCenter(this->get_x() * 32, this->get_y() * 32);
			}
			if (level.get_cell(this->get_x() + 1, this->get_y()).is_mob())
			{
				for (int i = 0; i < arr_mob.size(); i++)
				{
					if (this->get_x() + 1 == arr_mob[i]->get_x() && this->get_y() == arr_mob[i]->get_y())
					{
						this->attak(*arr_mob[i]);
					}
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (level.get_cell(this->get_x(), this->get_y() - 1).is_permeable())
			{
				this->viewing_range(level, false, arr_mob);

				active(level.get_cell(this->get_x(), this->get_y() - 1).get_value(), level, this->get_x(), this->get_y() - 1, window, viewer);
				this->set_unit(level, this->_x, this->_y - 1);

				/*this->sprite.move(0, -32);

				this->move(0, -1);*/

				viewer.setCenter(this->get_x() * 32, this->get_y() * 32);

				this->viewing_range(level, true, arr_mob);
			}
			if (level.get_cell(this->get_x(), this->get_y() - 1).is_mob())
			{
				for (int i = 0; i < arr_mob.size(); i++)
				{
					if (this->get_x() == arr_mob[i]->get_x() && this->get_y() - 1 == arr_mob[i]->get_y())
					{
						this->attak(*arr_mob[i]);
					}
				}
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (level.get_cell(this->get_x(), this->get_y() + 1).is_permeable())
			{
				this->viewing_range(level, false, arr_mob);

				active(level.get_cell(this->get_x(), this->get_y() + 1).get_value(), level, this->get_x(), this->get_y() + 1, window, viewer);
				this->set_unit(level, this->_x, this->_y + 1);
				//this->sprite.move(0, 32);

				//this->move(0, 1);

				viewer.setCenter(this->get_x() * 32, this->get_y() * 32);

				this->viewing_range(level, true, arr_mob);
			}
			if (level.get_cell(this->get_x(), this->get_y() + 1).is_mob())
			{
				for (int i = 0; i < arr_mob.size(); i++)
				{
					if (this->get_x() == arr_mob[i]->get_x() && this->get_y() + 1 == arr_mob[i]->get_y())
					{
						this->attak(*arr_mob[i]);
					}
				}
			}
		}
	}
	else
	{
		Font font;//шрифт 
		font.loadFromFile("HelveticaNeue-Bold.ttf");//передаем нашему шрифту файл шрифта
		Text text("", font, 50);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
		text.setFillColor(Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
		text.setString("You died!");//задает строку тексту
		text.setPosition(viewer.getCenter().x - 64, viewer.getCenter().y);//задаем позицию текста, центр камеры

		window.draw(text);
		window.display();
		Sleep(500);
		return false;
	}
}