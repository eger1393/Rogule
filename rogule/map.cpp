
#include "stdafx.h"

static int error;

Cell::Cell()
{
	_value = ' ';
	_move = true;
	_active = false;
}

Cell::Cell(char symbol, bool go_to, bool use)
{
	_value = symbol;
	_move = go_to;
	_active = use;
}

void Cell::set_value(char symbol)
{
	_value = symbol;
}

char Cell::get_value()
{
	return _value;
}

bool Cell::is_limpid()
{
    //if ((this->value <= 197 && this->value >= 191) || this->value == 217 || this->value == 218 || this->value == 179)
	if (this->_value == '#')
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
    if (this->_value == 35)
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
	Room *Head = new Room(1,1);
	Create_room(Head);
}

int Map::Create_room(Room *room)
{
	if ((room->ID_room > 9))
	{
		return 1;
	}
	for (int i = room->_left_angle_y; i < room->_nStr; i++)
	{
		if (i == this->_n - 1)
			break;
		for (int j = room->_left_angle_x; j < room->_nStlb; j++)
		{
			if (j == this->_m - 1)
				break;
			_game_field_level[i][j].set_value(' ');
		}
	}
	print_map();
	Create_corridor(room);
}

void Map::Create_anroom(Room *room, const int _y, const int _x)
{
	int str_end = 5 + rand() % 10,
		stlb_end = 5 + rand() % 10;
	int Y_left_angle = _y - str_end,
		X_left_angle = _x - stlb_end / 2;

	for (int i = Y_left_angle; i < Y_left_angle + str_end; i++)
	{
		if ((i > this->_n - 1) || (i < 1))
			break;
		for (int j = X_left_angle; j < X_left_angle + stlb_end; j++)
		{
			if ((j > this->_m - 1) || (j < 1))
				break;
			_game_field_level[i][j].set_value(' ');
		}
	}
	Room *Buff = new Room(Y_left_angle, X_left_angle);
	Buff->_nStr = Y_left_angle + str_end;
	Buff->_nStlb = X_left_angle + stlb_end;
	room->next = Buff;

	print_map();
	Create_corridor(Buff);
}

int Map::Create_corridor(Room *room)
{
	if (error == 15)
	{
		return false;
	}
	int type = 1 + rand() % 3;
	switch (type)
	{
	case 1: //corridor up
	{
		const int lenght_corridor_y_up = room->_left_angle_y - 5 - rand() % 3;
		int j;
		do
		{
			j = room->_left_angle_x + 1 + rand() % 4;
		} while (j >= this->_m - 1);

		if ((room->_left_angle_y - 8 < 1) || (_game_field_level[room->_left_angle_y - 5][j].get_value() != '#') || (_game_field_level[room->_left_angle_y - 5][j + 1].get_value() != '#') || (_game_field_level[room->_left_angle_y - 5][j - 1].get_value() != '#'))
		{
			error++;
			Create_corridor(room);
		}

		for (int i = room->_left_angle_y; i > lenght_corridor_y_up; i--)
		{
			if (i == 1)
			{
				break;
			}

			_game_field_level[i][j].set_value(' ');
		}

		Create_anroom(room,lenght_corridor_y_up + 1, j);
		break;
	}
	case 2: //corridor down
	{

		const int lenght_corridor_y_down = room->_nStr + 3 + rand() % 3;
		int j;
		do
		{
			j = room->_left_angle_x + 1 + rand() % 4;
		} while (j >= this->_m - 1);

		if ((room->_nStr + 5 > this->_n) || (_game_field_level[room->_nStr + 5][j].get_value() != '#') || (_game_field_level[room->_nStr + 5][j + 1].get_value() != '#') || (_game_field_level[room->_nStr + 5][j - 1].get_value() != '#'))
		{
			error++;
			Create_corridor(room);
		}

		for (int i = room->_nStr; i < lenght_corridor_y_down; i++)
		{
			if (i == this->_n - 1)
			{
				break;
			}
			_game_field_level[i][j].set_value(' ');
		}

		Room *Buff = new Room(lenght_corridor_y_down, room->_left_angle_x);
		room->next = Buff;
		Create_room(Buff);

		break;
	}
	case 3: //corridor right
	{

		const int lenght_corridor_y_right = room->_nStlb + 5 + rand() % 3;
		int i;
		do
		{
			i = room->_left_angle_y + 1 + rand() % 4;
		} while (i >= this->_n - 1);

		if ((room->_left_angle_x + 5 > this->_m) || (_game_field_level[i][room->_nStlb + 5].get_value() != '#') || (_game_field_level[i + 1][room->_nStlb + 5].get_value() != '#') || (_game_field_level[i - 1][room->_nStlb + 5].get_value() != '#'))
		{
			error++;
			Create_corridor(room);
		}

		for (int j = room->_nStlb; j < lenght_corridor_y_right; j++)
		{
			if (j == this->_m - 1)
			{
				break;
			}
			_game_field_level[i][j].set_value(' ');
		}

		Room *Buff = new Room(room->_left_angle_y, lenght_corridor_y_right);
		Create_room(Buff);
		break;
	}

	/*case 4: //corridor left
	{
		const int lenght_corridor_y_left = left_angle_x - 5 - rand() % 3;
		int i;
		do
		{
			i = left_angle_y + 1 + rand() % 4;
		} while (i >= this->_n - 1);


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
	}*/

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


