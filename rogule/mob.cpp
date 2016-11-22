#include "stdafx.h"

Mob::Mob(int hit_point, // ��������
	int viewing_range, // ������ ������
	int damage, // ����
	int armor, // �����
	char icon, // ������ c�������
	short x, short y, // ���������� ��������
	std::string description // �������� �������
	) : Unit(hit_point, viewing_range, damage, armor, icon, x,y)
{
	texture.loadFromFile("images/mob.png"); //��������

	sprite.setTexture(texture);//������� � ���� ������ Texture (��������)

	sprite.setPosition(y * 32, x * 32);//������ ��������� ���������� ��������� �������

	this->_description = description;
	this->_is_attack = false;
	this->_is_retreat = false;
}

//void Mob::social_agro(Map level) // ���������� ����(��������� ���� _is_attack ���� ����� � ������� ���������)
//{
//	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
//	//level.get_cell(this->_x + 5, this->_y + 5).set_value('1');
//	for (int i = 0; i <= this->_viewing_range; i++)
//	{
//		for (int j = 1; j <= this->_viewing_range - i; j++) // ������ ������
//		{
//			if (!flag1 && j == 1 && !level.get_cell(this->_x + j, this->_y + i).is_limpid())
//				flag1 = true;
//			if (!flag1 && level.get_cell(this->_x + j, this->_y + i).is_limpid())
//			{
//				level.get_cell(this->_x + j, this->_y + i).set_value(c);
//			}
//			else
//				break;
//		}
//
//		for (int j = 1; j <= this->_viewing_range - i; j++) // ����� ������
//		{
//			if (!flag2 && j == 1 && !level.get_cell(this->_x - i, this->_y + j).is_limpid())
//				flag2 = true;
//			if (!flag2 && level.get_cell(this->_x - i, this->_y + j).is_limpid())
//			{
//				level.get_cell(this->_x - i, this->_y + j).set_value(c);
//			}
//			else
//				break;
//		}
//
//		for (int j = 1; j <= this->_viewing_range - i; j++) //����� �������
//		{
//			if (!flag3 && j == 1 && !level.get_cell(this->_x - j, this->_y - i).is_limpid())
//				flag3 = true;
//			if (!flag3 && level.get_cell(this->_x - j, this->_y - i).is_limpid())
//			{
//				level.get_cell(this->_x - j, this->_y - i).set_value(c);
//			}
//			else
//				break;
//		}
//
//		for (int j = 1; j <= this->_viewing_range - i; j++) // ������ �������
//		{
//			if (!flag4 && j == 1 && !level.get_cell(this->_x + i, this->_y - j).is_limpid())
//				flag4 = true;
//			if (!flag4 && level.get_cell(this->_x + i, this->_y - j).is_limpid())
//			{
//				level.get_cell(this->_x + i, this->_y - j).set_value(c);
//			}
//			else
//				break;
//		}
//
//	}
//}


int Mob::find_way(Map level, Hero &hero) // �� ���� �������� � �����
{
	int temp_x = this->_x, temp_y = this->_y; //��������� ���������� ����� ��� ���������� ������ �-�� set_unit
	//�������� �� ��� �
	if (this->_x > hero.get_x() && level.get_cell(this->_x - 1, this->_y).is_permeable()) //���� ����� ������ ���� � ������ ������ ��������
		temp_x--; // �� ��� �������� ������
	if (this->_x < hero.get_x() && level.get_cell(this->_x + 1, this->_y).is_permeable())
		temp_x++;
	// �������� �� ��� �
	if (this->_y > hero.get_y() && level.get_cell(this->_x, this->_y - 1).is_permeable())
		temp_y--;
	if (this->_y < hero.get_y() && level.get_cell(this->_x, this->_y + 1).is_permeable())
		temp_y++;

	if (temp_x != hero.get_x() || temp_y != hero.get_y()) // ���� ��� �� ����� �� �����
	{
		this->set_unit(level, temp_x, temp_y); // �� ���������
		return 0;
	}
	else
	{
		this->attak(hero);
		return 1;
	}

}

void Mob::set_is_attack(bool value)
{
	this->_is_attack = value;
}

bool Mob::get_is_attack()
{
	return this->_is_attack;
}

void Mob::set_is_retreat(bool value)
{
	this->_is_retreat = value;
}

bool Mob::get_is_retreat()
{
	return this->_is_retreat;
}

void work_to_mobs(vector <Mob*> &arr_mob, RenderWindow &window, Map &level)
{
	for (int i = 0; i < arr_mob.size(); i++)
	{
		if (arr_mob[i]->get_hit_point() < 0) // ���� ��� ����
		{
			level.get_cell(arr_mob[i]->get_x(), arr_mob[i]->get_y()).set_value(' '); //������ ������ ���� ���
			arr_mob.erase(arr_mob.begin() + i); // ������ ���� �� ������� �����
		}
		else // ���� ��� ���
			window.draw(arr_mob[i]->sprite); //��������� ����
	}
}