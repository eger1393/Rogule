#include "stdafx.h"

Unit::Unit(int hit_point, // ��������
	int viewing_range, // ������ ������
	int damage, // ����
	int armor, // �����
	char icon, // ������ c�������
	short x, short y // ���������� ��������
	) // �����������
{

	this->_hit_point = hit_point;
	this->_viewing_range = viewing_range;
	this->_damage = damage;
	this->_armor = armor;
	this->_icon = icon;
	this->_x = x;
	this->_y = y;
	text = new Message("", Color::Red, 0, 20);
}

int Unit::get_hit_point()
{
	return this->_hit_point;
}

//void Unit::viewing_range(Map level, char c) // ���������� ������� ���������
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


int Unit::get_x()
{
	return _x;
}

int Unit::get_y()
{
	return _y;
}

int Unit::get_damage()
{
	return this->_damage;
}

void Unit::push_log(string str, int value)
{
	if (str == "")
	{
		this->text->setString("");
	}

	std::ostringstream playerData;
	playerData << value;

	if (value != 0)
	{
		this->text->setString(this->text->getString() + "\n" + str + " Damage : " + playerData.str());
	}
	else
	{
		this->text->setString(this->text->getString() + "\n" + str);
	}
}

// ���� ��������� �-�� ������ ���������� ����
int Unit::attak(Unit &unit2)
{
	if (this->_damage <= unit2._armor) //���� ����� ������ ������
	{
		unit2._hit_point -= 1;

		if (unit2._icon == '@')
		{
			unit2.push_log("You little hit!");
		}
		else
		{
			this->push_log("You set hit!", 1);
		}
			
	}
	else
	{
		unit2._hit_point -= this->_damage - unit2._armor;
		if (unit2._icon == '@')
		{
			unit2.push_log("You hit", this->_damage - unit2._armor);
		}
		else
		{
			this->push_log("You set hit!", this->get_damage());
		}
			

		if (unit2._hit_point <= 0) // ������ �����
		{
			return 3;
			// ���������� ������
		}
	}
}

	void Unit::set_unit(Map *level, short x, short y) // ����������� ����
	{
		level->get_cell(this->_x, this->_y).set_value(' ');
		level->reprint_cell(this->_x, this->_y);
		this->sprite.move((float)(x - this->_x) * 32, (float)(y - this->_y) * 32);
		this->_x = x;
		this->_y = y;
		level->get_cell(x, y).set_value(this->_icon);
		level->reprint_cell(this->_x, this->_y);
	}
