#pragma once
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

	sprite.setPosition((float)y*32, (float)x*32);//задаем начальные координаты появления спрайта

	
}
void Hero::set_position(View &view, float _x, float _y)
{
	int tepmX = _x, tempY = _y;

		view.setCenter((GetSystemMetrics(SM_CXSCREEN) - 100) / 2, (GetSystemMetrics(SM_CYSCREEN) - 100) / 2);

	if (tepmX > (((GetSystemMetrics(SM_CXSCREEN) - 312))/2))
	{
		view.move(224, 0);
	}
	if (tempY > (((GetSystemMetrics(SM_CYSCREEN) - 312))/2))
	{
		view.move(0, 224);
	}
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
void Hero::active(char Symbol, Map *level, short x, short y, RenderWindow &window, View &view)
{


	switch (Symbol)
	{
	case '$':
	{
		level->get_cell(x, y).set_value(' ');
		push_log("Chest! \nYou have item_name");
		break;
	}
	case '!':
	{
		this->set_hit_point((this->get_hit_point())*-1);

		break;
	}
	case '`':
	{
		this->set_hit_point((this->get_hit_point())*-1);

		break;
	}
	case '%':
	{
		this->set_hit_point((this->get_hit_point())*-1);

		break;
	}
	case '0':
	{
		if (Map::count_win < 3)
		{
			delete level;
			level = new Map(50, 50);
			level->initialize_Level();
			this->set_unit(level, 2, 2);
			Map::count_win++;
		}
		else
		{
			Message message_box("     You winner! \n Congratulations! Hooray! ", Color::Red);
		}
		break;
	}
	default:
		break;
	}
}


int Hero::get_armor()
{
	return this->_armor;
}
int Hero::get_viewing_range()
{
	return this->_viewing_range;
}
void Hero::viewing_range(Map *level,bool flag) // Вычесление области видемости
{
	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
	//level->get_cell(this->_x + 5, this->_y + 5).set_value('1');
	for (int i = 0; i <= this->_viewing_range; i++)
	{
		for (int j = 1; j <= this->_viewing_range - i; j++) // Правый нижний
		{
			if (!flag1 && j == 1 && !level->get_cell(this->_x + j, this->_y + i).is_limpid())
			{
				flag1 = true;
				level->get_cell(this->_x + j, this->_y + i).set_view(flag); // сдесь видимость стены
				level->get_cell(this->_x + j, this->_y + i).set_prospected(true);
			}
			if (!flag1 && level->get_cell(this->_x + j, this->_y + i).is_limpid()) // это если не стена
			{
				//level->get_cell(this->_x + j, this->_y + i).set_value(c);
				level->get_cell(this->_x + j, this->_y + i).set_view(flag); // устанавливает флаг видимости
				level->get_cell(this->_x + j, this->_y + i).set_prospected(true); // делает клетку разведанной
				level->reprint_cell(this->_x + j, this->_y + i); // перерисовывает ее в консоли

				if (level->get_cell(this->_x + j, this->_y + i).is_mob()) // Если в клетке стоит моб
				{
					for (int k = 0; k < level->arr_mob.size(); k++) // Ищем моба который стоит в этой клетке
						if (level->arr_mob[k]->get_x() == (this->_x + j) && level->arr_mob[k]->get_y() == (this->_y + i))
							level->arr_mob[k]->set_is_attack(true); // Ставим флаг атаки = true
				}
			}
			else
				break;
		}

		for (int j = 1; j <= this->_viewing_range - i; j++) // Левый нижний
		{
			if (!flag2 && j == 1 && !level->get_cell(this->_x - i, this->_y + j).is_limpid())
			{
				flag2 = true;
				level->get_cell(this->_x - i, this->_y + j).set_view(flag);
				level->get_cell(this->_x - i, this->_y + j).set_prospected(true);
			}
			if (!flag2 && level->get_cell(this->_x - i, this->_y + j).is_limpid())
			{
				//level->get_cell(this->_x - i, this->_y + j).set_value(c);
				level->get_cell(this->_x - i, this->_y + j).set_view(flag);
				level->get_cell(this->_x - i, this->_y + j).set_prospected(true);
				level->reprint_cell(this->_x - i, this->_y + j);

				if (level->get_cell(this->_x - i, this->_y + j).is_mob()) // Если в клетке стоит моб
				{
					for (int k = 0; k < level->arr_mob.size(); k++) // Ищем моба который стоит в этой клетке
						if (level->arr_mob[k]->get_x() == (this->_x - i) && level->arr_mob[k]->get_y() == (this->_y + j))
							level->arr_mob[k]->set_is_attack(true); // Ставим флаг атаки = true
				}
			}
			else
				break;
		}

		for (int j = 1; j <= this->_viewing_range - i; j++) //Левый верхний
		{
			if (!flag3 && j == 1 && !level->get_cell(this->_x - j, this->_y - i).is_limpid())
			{
				flag3 = true;
				level->get_cell(this->_x - j, this->_y - i).set_view(flag);
				level->get_cell(this->_x - j, this->_y - i).set_prospected(true);
			}
			if (!flag3 && level->get_cell(this->_x - j, this->_y - i).is_limpid())
			{
				//level->get_cell(this->_x - j, this->_y - i).set_value(c);
				level->get_cell(this->_x - j, this->_y - i).set_view(flag);
				level->get_cell(this->_x - j, this->_y - i).set_prospected(true);
				level->reprint_cell(this->_x - j, this->_y - i);

				if (level->get_cell(this->_x - j, this->_y - i).is_mob()) // Если в клетке стоит моб
				{
					for (int k = 0; k < level->arr_mob.size(); k++) // Ищем моба который стоит в этой клетке
						if (level->arr_mob[k]->get_x() == (this->_x - j) && level->arr_mob[k]->get_y() == (this->_y - i))
							level->arr_mob[k]->set_is_attack(true); // Ставим флаг атаки = true
				}
			}
			else
				break;
		}

		for (int j = 1; j <= this->_viewing_range - i; j++) // Правый верхний
		{
			if (!flag4 && j == 1 && !level->get_cell(this->_x + i, this->_y - j).is_limpid())
			{
				flag4 = true;
				level->get_cell(this->_x + i, this->_y - j).set_view(flag);
				level->get_cell(this->_x + i, this->_y - j).set_prospected(true);
			}
			if (!flag4 && level->get_cell(this->_x + i, this->_y - j).is_limpid())
			{
				//level->get_cell(this->_x + i, this->_y - j).set_value(c);
				level->get_cell(this->_x + i, this->_y - j).set_view(flag);
				level->get_cell(this->_x + i, this->_y - j).set_prospected(true);
				level->reprint_cell(this->_x + i, this->_y - j);

				if (level->get_cell(this->_x + i, this->_y - j).is_mob()) // Если в клетке стоит моб
				{
					for (int k = 0; k < level->arr_mob.size(); k++) // Ищем моба который стоит в этой клетке
						if (level->arr_mob[k]->get_x() == (this->_x + i) && level->arr_mob[k]->get_y() == (this->_y - j))
							level->arr_mob[k]->set_is_attack(true); // Ставим флаг атаки = true
				}
			}
			else
				break;
		}

	}
}

int Hero::key_press(Map *level, View &viewer, RenderWindow &window)
{
	int temp = 0;

	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Right)
		|| Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Down)) {
		if (this->get_hit_point() > 0)
		{
			if (Keyboard::isKeyPressed(Keyboard::Left)) // если нажата стрелка влево и т.д
			{
				push_log("");
				if (level->get_cell(this->get_x() - 1, this->get_y()).is_mob())
				{
					for (int i = 0; i < level->arr_mob.size(); i++)
					{
						if (this->get_x() - 1 == level->arr_mob[i]->get_x() && this->get_y() == level->arr_mob[i]->get_y())
						{
							this->attak(*level->arr_mob[i]);
							/*Message box(viewer, "You damage : ", Color::Green,this->get_damage());
							window.draw(box);
							if (temp == 3)
							{
								Message box_1(viewer, "You killed the mob! ", Color::Color(191, 62, 255, 255));
								window.draw(box_1);
							}
							window.display();
							Sleep(300);*/
						}
					}
				}
				if (level->get_cell(this->get_x() - 1, this->get_y()).is_permeable())
				{
					this->viewing_range(level, false);

					active(level->get_cell(this->get_x() - 1, this->get_y()).get_value(), level, this->get_x() - 1, this->get_y(), window, viewer);
					this->set_unit(level, this->_x - 1, this->_y);

					this->set_position(viewer,(float)this->get_x() * 32, (float) this->get_y() * 32);

					this->viewing_range(level, true);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				push_log("");
				if (level->get_cell(this->get_x() + 1, this->get_y()).is_mob())
				{
					for (int i = 0; i < level->arr_mob.size(); i++)
					{
						if (this->get_x() + 1 == level->arr_mob[i]->get_x() && this->get_y() == level->arr_mob[i]->get_y())
						{
							this->attak(*level->arr_mob[i]);
						}

					}
				}

				if (level->get_cell(this->get_x() + 1, this->get_y()).is_permeable())
				{
					this->viewing_range(level, false);

					active(level->get_cell(this->get_x() + 1, this->get_y()).get_value(), level, this->get_x() + 1, this->get_y(), window, viewer);
					this->set_unit(level, this->_x + 1, this->_y);

					this->viewing_range(level, true);

					this->set_position(viewer, (float)this->get_x() * 32, (float) this->get_y() * 32);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				push_log("");
				if (level->get_cell(this->get_x(), this->get_y() - 1).is_mob())
				{
					for (int i = 0; i < level->arr_mob.size(); i++)
					{
						if (this->get_x() == level->arr_mob[i]->get_x() && this->get_y() - 1 == level->arr_mob[i]->get_y())
						{
							 this->attak(*level->arr_mob[i]);
						}
					}
				}
				if (level->get_cell(this->get_x(), this->get_y() - 1).is_permeable())
				{
					this->viewing_range(level, false);

					active(level->get_cell(this->get_x(), this->get_y() - 1).get_value(), level, this->get_x(), this->get_y() - 1, window, viewer);
					this->set_unit(level, this->_x, this->_y - 1);

					this->set_position(viewer, (float)this->get_x() * 32, (float) this->get_y() * 32);

					this->viewing_range(level, true);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				push_log("");
				if (level->get_cell(this->get_x(), this->get_y() + 1).is_mob())
				{
					for (int i = 0; i < level->arr_mob.size(); i++)
					{
						if (this->get_x() == level->arr_mob[i]->get_x() && this->get_y() + 1 == level->arr_mob[i]->get_y())
						{
							 this->attak(*level->arr_mob[i]);
						
							
						}
					}
				}
				if (level->get_cell(this->get_x(), this->get_y() + 1).is_permeable())
				{
					this->viewing_range(level, false);

					active(level->get_cell(this->get_x(), this->get_y() + 1).get_value(), level, this->get_x(), this->get_y() + 1, window, viewer);
					this->set_unit(level, this->_x, this->_y + 1);
			
					this->set_position(viewer, (float)this->get_x() * 32, (float) this->get_y() * 32);

					this->viewing_range(level, true);
				}
			}
			for (int i = 0; i < level->arr_mob.size(); i++)
				if (level->arr_mob[i]->get_is_attack()) // если установлен флаг атаки
					level->arr_mob[i]->find_way(level, *this, viewer, window); // моб бежит к герою
		}
		else // 
		{
			Message message_box("     You died! \n Try again? Press 'R' ", Color::Red);
			message_box.setPosition(viewer.getCenter().x - 64, viewer.getCenter().y);//задаем позицию текста, центр камеры
			window.draw(message_box);
			window.display();
			Sleep(500);
			return false;
		}
	}
}