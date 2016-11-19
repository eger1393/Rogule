
#include "stdafx.h"


Hero::Hero(int hit_point, // ��������
	int viewing_range, // ������ ������
	int damage, // ����
	int armor, // �����
	short x, short y // ���������� ��������
) : Unit(hit_point, viewing_range, damage, armor, '@', x, y)
{
	herotexture.loadFromFile("images/hero.png"); //��������

	herosprite.setTexture(herotexture);//������� � ���� ������ Texture (��������)

	herosprite.setPosition(x, y);//������ ��������� ���������� ��������� �������
	
	rect = FloatRect(x, y, 16, 16);//���������� + ������-������ ����
}

void Hero::viewing_range(Map level, char c) // ���������� ������� ���������
{
	bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
	//level.get_cell(this->_x + 5, this->_y + 5).set_value('1');
	for (int i = 0; i <= this->_viewing_range; i++)
	{
		for (int j = 1; j <= this->_viewing_range - i; j++) // ������ ������
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

		for (int j = 1; j <= this->_viewing_range - i; j++) // ����� ������
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

		for (int j = 1; j <= this->_viewing_range - i; j++) //����� �������
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

		for (int j = 1; j <= this->_viewing_range - i; j++) // ������ �������
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
	char c; // ������� �������� � ����������
	while (true)
	{
		c = _getch();
		/*if (c == -32)
			c = _getch();*/
		switch (c)
		{
		case 80:	// ������� ����
			if (level.get_cell(this->_x, this->_y + 1).is_permeable()) // �������� �� ������������
			{
				this->viewing_range(level, ' ');
				this->set_unit(level, this->_x, this->_y + 1);
				this->viewing_range(level, '1');
				//system("cls");		// �������� ���� ���� �� �����������
				//level.print_map();  // ��������� ������

			}
			break;
		case 72:	//������� �����
			if (level.get_cell(this->_x, this->_y - 1).is_permeable()) // �������� �� ������������
			{
				this->viewing_range(level, ' ');
				this->set_unit(level, this->_x, this->_y - 1);
				this->viewing_range(level, '1');
				//system("cls");		// �������� ���� ���� �� �����������
				//level.print_map();  // ��������� ������
			}
			break;
		case 77:	// ������� �����
			if (level.get_cell(this->_x + 1, this->_y).is_permeable()) // �������� �� ������������
			{
				this->viewing_range(level, ' ');
				this->set_unit(level, this->_x + 1, this->_y);
				this->viewing_range(level, '1');
				//system("cls");		// �������� ���� ���� �� �����������
				//level.print_map();  // ��������� ������
			}
			break;
		case 75:	// ������� ������
			if (level.get_cell(this->_x - 1, this->_y).is_permeable()) // �������� �� ������������
			{
				this->viewing_range(level, ' ');
				this->set_unit(level, this->_x - 1, this->_y);
				this->viewing_range(level, '1');
				//system("cls");		// �������� ���� ���� �� �����������
				//level.print_map();  // ��������� ������
			}
			break;
		/*default:
			break;*/
		}
		a.find_way(level, this->_x, this->_y);

	}


}