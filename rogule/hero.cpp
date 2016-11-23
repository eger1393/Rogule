
#include "stdafx.h"

Hero::Hero(int hit_point, // ��������
	int viewing_range, // ������ ������
	int damage, // ����
	int armor, // �����
	short x, short y // ���������� ��������
	) : Unit(hit_point, viewing_range, damage, armor, '@', y, x, "Hero")
{
	texture.loadFromFile("images/hero.png"); //��������

	sprite.setTexture(texture);//������� � ���� ������ Texture (��������)

	sprite.setPosition((float)y*32, (float)x*32);//������ ��������� ���������� ��������� �������
	
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
int Hero::get_damage()
{
	return this->_damage;
}

int Hero::get_armor()
{
	return this->_armor;
}
int Hero::get_viewing_range()
{
	return this->_viewing_range;
}
void Hero::viewing_range(Map level,bool flag) // ���������� ������� ���������
{
	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
	//level.get_cell(this->_x + 5, this->_y + 5).set_value('1');
	for (int i = 0; i <= this->_viewing_range; i++)
	{
		for (int j = 1; j <= this->_viewing_range - i; j++) // ������ ������
		{
			if (!flag1 && j == 1 && !level.get_cell(this->_x + j, this->_y + i).is_limpid())
			{
				flag1 = true;
				level.get_cell(this->_x + j, this->_y + i).set_view(flag); // ����� ��������� �����
				level.get_cell(this->_x + j, this->_y + i).set_prospected(true);
			}
			if (!flag1 && level.get_cell(this->_x + j, this->_y + i).is_limpid()) // ��� ���� �� �����
			{
				//level.get_cell(this->_x + j, this->_y + i).set_value(c);
				level.get_cell(this->_x + j, this->_y + i).set_view(flag); // ������������� ���� ���������
				level.get_cell(this->_x + j, this->_y + i).set_prospected(true); // ������ ������ �����������
				level.reprint_cell(this->_x + j, this->_y + i); // �������������� �� � �������

				if (level.get_cell(this->_x + j, this->_y + i).is_mob()) // ���� � ������ ����� ���
				{
					for (int k = 0; k < level.arr_mob.size(); k++) // ���� ���� ������� ����� � ���� ������
						if (level.arr_mob[k]->get_x() == (this->_x + j) && level.arr_mob[k]->get_y() == (this->_y + i))
							level.arr_mob[k]->set_is_attack(true); // ������ ���� ����� = true
				}
			}
			else
				break;
		}

		for (int j = 1; j <= this->_viewing_range - i; j++) // ����� ������
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

				if (level.get_cell(this->_x - i, this->_y + j).is_mob()) // ���� � ������ ����� ���
				{
					for (int k = 0; k < level.arr_mob.size(); k++) // ���� ���� ������� ����� � ���� ������
						if (level.arr_mob[k]->get_x() == (this->_x - i) && level.arr_mob[k]->get_y() == (this->_y + j))
							level.arr_mob[k]->set_is_attack(true); // ������ ���� ����� = true
				}
			}
			else
				break;
		}

		for (int j = 1; j <= this->_viewing_range - i; j++) //����� �������
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

				if (level.get_cell(this->_x - j, this->_y - i).is_mob()) // ���� � ������ ����� ���
				{
					for (int k = 0; k < level.arr_mob.size(); k++) // ���� ���� ������� ����� � ���� ������
						if (level.arr_mob[k]->get_x() == (this->_x - j) && level.arr_mob[k]->get_y() == (this->_y - i))
							level.arr_mob[k]->set_is_attack(true); // ������ ���� ����� = true
				}
			}
			else
				break;
		}

		for (int j = 1; j <= this->_viewing_range - i; j++) // ������ �������
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

				if (level.get_cell(this->_x + i, this->_y - j).is_mob()) // ���� � ������ ����� ���
				{
					for (int k = 0; k < level.arr_mob.size(); k++) // ���� ���� ������� ����� � ���� ������
						if (level.arr_mob[k]->get_x() == (this->_x + i) && level.arr_mob[k]->get_y() == (this->_y - j))
							level.arr_mob[k]->set_is_attack(true); // ������ ���� ����� = true
				}
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
	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Right)
		|| Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Down)) {
		if (this->get_hit_point() > 0)
		{
			if (Keyboard::isKeyPressed(Keyboard::Left)) // ���� ������ ������� ����� � �.�
			{
				if (level.get_cell(this->get_x() - 1, this->get_y()).is_mob())
				{
					for (int i = 0; i < level.arr_mob.size(); i++)
					{
						if (this->get_x() - 1 == level.arr_mob[i]->get_x() && this->get_y() == level.arr_mob[i]->get_y())
						{
							this->attak(*level.arr_mob[i]);
						}
					}
				}
				if (level.get_cell(this->get_x() - 1, this->get_y()).is_permeable())
				{
					this->viewing_range(level, false);

					active(level.get_cell(this->get_x() - 1, this->get_y()).get_value(), level, this->get_x() - 1, this->get_y(), window, viewer);
					this->set_unit(level, this->_x - 1, this->_y);

					/*this->sprite.move(-32, 0);

					this->move(-1, 0);*/

					viewer.setCenter((float)this->get_x() * 32, (float) this->get_y() * 32);

					this->viewing_range(level, true);
					//mob.find_way(level_1, hero.get_x(), hero.get_y());
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				if (level.get_cell(this->get_x() + 1, this->get_y()).is_mob())
				{
					for (int i = 0; i < level.arr_mob.size(); i++)
					{
						if (this->get_x() + 1 == level.arr_mob[i]->get_x() && this->get_y() == level.arr_mob[i]->get_y())
						{
							this->attak(*level.arr_mob[i]);
						}
					}
				}
				if (level.get_cell(this->get_x() + 1, this->get_y()).is_permeable())
				{
					this->viewing_range(level, false);

					active(level.get_cell(this->get_x() + 1, this->get_y()).get_value(), level, this->get_x() + 1, this->get_y(), window, viewer);
					this->set_unit(level, this->_x + 1, this->_y);

					/*this->sprite.move(32, 0);

					this->move(1, 0);*/

					this->viewing_range(level, true);

					viewer.setCenter((float)this->get_x() * 32, (float) this->get_y() * 32);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				if (level.get_cell(this->get_x(), this->get_y() - 1).is_mob())
				{
					for (int i = 0; i < level.arr_mob.size(); i++)
					{
						if (this->get_x() == level.arr_mob[i]->get_x() && this->get_y() - 1 == level.arr_mob[i]->get_y())
						{
							this->attak(*level.arr_mob[i]);
						}
					}
				}
				if (level.get_cell(this->get_x(), this->get_y() - 1).is_permeable())
				{
					this->viewing_range(level, false);

					active(level.get_cell(this->get_x(), this->get_y() - 1).get_value(), level, this->get_x(), this->get_y() - 1, window, viewer);
					this->set_unit(level, this->_x, this->_y - 1);

					/*this->sprite.move(0, -32);

					this->move(0, -1);*/

					viewer.setCenter((float)this->get_x() * 32, (float) this->get_y() * 32);

					this->viewing_range(level, true);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				if (level.get_cell(this->get_x(), this->get_y() + 1).is_mob())
				{
					for (int i = 0; i < level.arr_mob.size(); i++)
					{
						if (this->get_x() == level.arr_mob[i]->get_x() && this->get_y() + 1 == level.arr_mob[i]->get_y())
						{
							this->attak(*level.arr_mob[i]);
						}
					}
				}
				if (level.get_cell(this->get_x(), this->get_y() + 1).is_permeable())
				{
					this->viewing_range(level, false);

					active(level.get_cell(this->get_x(), this->get_y() + 1).get_value(), level, this->get_x(), this->get_y() + 1, window, viewer);
					this->set_unit(level, this->_x, this->_y + 1);
					//this->sprite.move(0, 32);

					//this->move(0, 1);

					viewer.setCenter((float)this->get_x() * 32, (float) this->get_y() * 32);

					this->viewing_range(level, true);
				}
			}
			for (int i = 0; i < level.arr_mob.size(); i++)
				if (level.arr_mob[i]->get_is_attack()) // ���� ���������� ���� �����
					level.arr_mob[i]->find_way(level, *this); // ��� ����� � �����
		}
		else // 
		{
			Font font;//����� 
			font.loadFromFile("HelveticaNeue-Bold.ttf");//�������� ������ ������ ���� ������
			Text text("", font, 50);//������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);//��� ������ ����� (�� ������)
			text.setFillColor(Color::Red);//��������� ����� � �������. ���� ������ ��� ������, �� �� ��������� �� �����
			text.setString("You died!");//������ ������ ������
			text.setPosition(viewer.getCenter().x - 64, viewer.getCenter().y);//������ ������� ������, ����� ������

			window.draw(text);
			window.display();
			Sleep(500);
			return false;
		}
	}
}