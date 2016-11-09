#include "stdafx.h"

Cell::Cell()
{
	value = ' ';
	move = true;
	active = false;
}

Cell::Cell(char symbol, bool go_to, bool use)
{
	value = symbol;
	move = go_to;
	active = use;
}

void Cell::set_value(char symbol)
{
	value = symbol;
}

char Cell::get_value()
{
	return value;
}

bool Cell::is_limpid()
{
    //if ((this->value <= 197 && this->value >= 191) || this->value == 217 || this->value == 218 || this->value == 179)
	if (this->value == '#')
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Cell::is_permeable()
{
    //if ((this->value <= 197 && this->value >= 191) || this->value == 217 || this->value == 218 || this->value == 179)
    if (this->value == 35)
    {
        return false;
    }
    else
    {
        return true;
    }
}

Cell::~Cell()
{
	
}



Map::Map(short n, short m)
{
	this->_n = n;
	this->_m = m;
	_game_field_level = new Cell *[this->_n];
	for (int i = 0; i < this->_n; i++) {
		_game_field_level[i] = new Cell[this->_m];
	}

	for (int i = 0; i < this->_n; i++)
	{
		for (int j = 0; j < this->_m; j++)
		{
			_game_field_level[i][j].set_value('#');
		}
	}
}

void Map::initialize_Level()
{
	const int left_angle_y = 1, left_angle_x = 1;
	Create_room(left_angle_y, left_angle_x);
}

void Map::Create_room(const int left_angle_y, const int left_angle_x)
{
	int str_end = left_angle_y + 5 + rand() % 10,
		stlb_end = left_angle_x + 5 + rand() % 10;

	for (int i = left_angle_y; i < str_end; i++)
	{
		if (i == STROKI - 1)
			break;
		for (int j = left_angle_x; j < stlb_end; j++)
		{
			if (j == STOLBI - 1)
				break;
			_game_field_level[i][j].set_value(' ');
		}
	}
	output();
	Create_corridor(left_angle_y, left_angle_x, str_end, stlb_end);
}

void Map::Create_anroom(const int _y, const int _x)
{
	int str_end = 5 + rand() % 10,
		stlb_end = 5 + rand() % 10;
	int Y_left_angle = _y - str_end,
		X_left_angle = _x - stlb_end / 2;

	for (int i = Y_left_angle; i < Y_left_angle + str_end; i++)
	{
		if ((i > STROKI - 1) || (i < 1))
			break;
		for (int j = X_left_angle; j < X_left_angle + stlb_end; j++)
		{
			if ((j > STOLBI - 1) || (j < 1))
				break;
			_game_field_level[i][j].set_value(' ');
		}
	}
	output();
	Create_corridor(Y_left_angle, X_left_angle, Y_left_angle + str_end, X_left_angle + stlb_end);
}

void Map::Create_corridor(const int left_angle_y, const int left_angle_x, const int str_end, const int stlb_end)
{
	int type = 1 + rand() % 3;
	switch (type)
	{
	case 1: //corridor up
	{
		const int lenght_corridor_y_up = left_angle_y - 5 - rand() % 3;
		int j;
		do
		{
			j = left_angle_x + 1 + rand() % 4;
		} while (j >= STOLBI - 1);

		if ((left_angle_y - 8 < 1) || (_game_field_level[left_angle_y - 5][j].get_value() != '#') || (_game_field_level[left_angle_y - 5][j + 1].get_value() != '#') || (_game_field_level[left_angle_y - 5][j - 1].get_value() != '#'))
		{
			Create_corridor(left_angle_y, left_angle_x, str_end, stlb_end);
		}

		for (int i = left_angle_y; i > lenght_corridor_y_up; i--)
		{
			if (i == 1)
			{
				break;
			}

			_game_field_level[i][j].set_value(' ');
		}
		Create_anroom(lenght_corridor_y_up + 1, j);
		break;
	}
	case 2: //corridor down
	{

		const int lenght_corridor_y_down = str_end + 3 + rand() % 3;
		int j;
		do
		{
			j = left_angle_x + 1 + rand() % 4;
		} while (j >= STOLBI - 1);

		if ((str_end + 5 > STROKI) || (_game_field_level[str_end + 5][j].get_value() != '#') || (_game_field_level[str_end + 5][j + 1].get_value() != '#') || (_game_field_level[str_end + 5][j - 1].get_value() != '#'))
		{
			Create_corridor(left_angle_y, left_angle_x, str_end, stlb_end);
		}

		for (int i = str_end; i < lenght_corridor_y_down; i++)
		{
			if (i == STROKI - 1)
			{
				break;
			}
			_game_field_level[i][j].set_value(' ');
		}
		Create_room(lenght_corridor_y_down, left_angle_x);
		break;
	}
	case 3: //corridor right
	{

		const int lenght_corridor_y_right = stlb_end + 5 + rand() % 3;
		int i;
		do
		{
			i = left_angle_y + 1 + rand() % 4;
		} while (i >= STROKI - 1);

		if ((left_angle_x + 5 > STOLBI) || (_game_field_level[i][stlb_end + 5].get_value() != '#') || (_game_field_level[i + 1][stlb_end + 5].get_value() != '#') || (_game_field_level[i - 1][stlb_end + 5].get_value() != '#'))
		{
			Create_corridor(left_angle_y, left_angle_x, str_end, stlb_end);
		}


		for (int j = stlb_end; j < lenght_corridor_y_right; j++)
		{
			if (j == STOLBI - 1)
			{
				break;
			}
			_game_field_level[i][j].set_value(' ');
		}
		Create_room(left_angle_y, lenght_corridor_y_right);
		break;
	}
	case 4: //corridor left
	{

		const int lenght_corridor_y_left = left_angle_x - 5 - rand() % 3;
		int i;
		do
		{
			i = left_angle_y + 1 + rand() % 4;
		} while (i >= STROKI - 1);


		if ((_game_field_level[i][left_angle_x - 5].get_value() != '#') || (left_angle_x - 5 < 1) || (_game_field_level[i + 1][left_angle_x - 5].get_value() != '#') || (_game_field_level[i - 1][left_angle_x - 5].get_value() != '#'))
		{
			Create_corridor(left_angle_y, left_angle_x, str_end, stlb_end);
		}

		for (int j = left_angle_x; j > lenght_corridor_y_left; j--)
		{
			if (j == 1)
			{
				break;
			}

			_game_field_level[i][j].set_value(' ');
		}
		break;
	}
	default:
		break;
	}
}

void Map::test_Map(short n, short m)
{
    this->_n = n;
    this->_m = m;
    this->_game_field_level = new Cell*[this->_n];
    for (short i = 0; i < this->_n; i++)
    {
        this->_game_field_level[i] = new Cell[this->_m];
    }  
	 
    for (short i = 0; i < this->_n - 1; i++)
    {
        this->_game_field_level[0][i].set_value(35);
        this->_game_field_level[this->_n - 1][i].set_value(35);
        this->_game_field_level[i][0].set_value(35);
        this->_game_field_level[i][this->_n - 1].set_value(35);

        for (short j = 1; j < this->_m - 1; j++)
        {
            this->_game_field_level[i][j].set_value(' ');
        }
    }

    /*this->_game_field_level[0][0].set_value(218);
    this->_game_field_level[this->_n - 1][0].set_value(192);
    this->_game_field_level[0][this->_m - 1].set_value(191);
    this->_game_field_level[this->_n - 1][this->_m - 1].set_value(217);*/


}

Cell& Map::get_cell(short x, short y)
{
	if (x >= this->_m || y >= this->_n)
		_game_field_level[0][0]; // Костыль
    return this->_game_field_level[y][x];
}

void Map::set_cell(Cell cell, short x, short y)
{
    if (x >= this->_m || y >= this->_n)
        exit(2);
    this->_game_field_level[y][x] = cell;
}

void Map::set_cell(char c, short x, short y)
{
    if (x >= this->_m || y >= this->_n)
        exit(3);
    this->_game_field_level[y][x].set_value(c);
}

void Map::print_map()
{
	system("cls");
    for (int i = 0; i < this->_n; i++)
    {
        for (int j = 0; j < this->_m; j++)
        {
            std::cout << this->_game_field_level[i][j].get_value();
        }
        std::cout << std::endl;
    }
}

void Map::print_circular()
{
	const int m = 15, n = 15;
	int radius = 6;
	for (int i = 0; i < radius / 2 + 1; i++)
	{
		this->_game_field_level[n + radius][m + i].set_value('#');
		this->_game_field_level[n + radius][m - i].set_value('#');
	}

	int j = radius / 2, i = radius;
	while (j != radius)
	{
		i--;
		j++;
		this->_game_field_level[n + i][m + j].set_value('#');
	}
	///////////////////
	for (int i = 0; i < radius / 2 + 1; i++)
	{
		this->_game_field_level[n - i][m + radius].set_value('#');
		this->_game_field_level[n + i][m + radius].set_value('#');
	}

	 j = radius, i = - radius / 2;
	while (i != - radius)
	{
		i--;
		j--;
		this->_game_field_level[n + i][m + j].set_value('#');
	}
}


