
#include "stdafx.h"

static int error;
bool flag = true, flag_0 = true;
Room *Head;

Texture texture_all;

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
	_cell_texture.loadFromFile("texture.jpg"); //картинка
	_cell_sprite.setTexture(_cell_texture);//передаём в него объект Texture (текстуры)
	switch (symbol)
	{
	case '#':
		_cell_sprite.setTextureRect(IntRect(670, 768, 32, 32));
		break;

	case ' ':
		_cell_sprite.setTextureRect(IntRect(192, 800, 32, 32));
		break;
	default:
		break;
	}
	//_cell_sprite.setTextureRect(IntRect(384, 320, 32, 32));
	//_cell_sprite.setPosition(x, y);//задаем начальные координаты появления спрайта
}

void Cell::set_value(char symbol)
{
	_value = symbol;
	if (this->_cell_sprite.getTexture() == NULL)
	{
		//_cell_texture.loadFromFile("texture.jpg"); //картинка
		_cell_sprite.setTexture(_cell_texture);//передаём в него объект Texture (текстуры)
	}
	switch (symbol)
	{
	case '#':
		_cell_sprite.setTextureRect(IntRect(670, 768, 32, 32));
		break;

	case ' ':
		_cell_sprite.setTextureRect(IntRect(192, 800, 32, 32));
		break;
	default:
		break;
	}
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

bool Cell::is_unit()
{
	for (int i = 0; i < sizeof(name_units) / sizeof(name_units[0]); i++)
	{
		if (this->_value == name_units[i])
			return true;
	}
	return false;
}

bool Cell::is_permeable()
{
    //if ((this->value <= 197 && this->value >= 191) || this->value == 217 || this->value == 218 || this->value == 179)
    if (this->_value == ' ' || this->_value == '1')
    {
        return true;
    }
    else
    {
        return false;
    }
}

Cell::~Cell()
{
	
}

//void Cell::set_x_y(short x, short y) //задает координаты х, у
//{
//	this->_x = x;
//	this->_y = y;
//}
//
//short Cell::get_x()
//{
//	return this->_x;
//}
//
//short Cell::get_y()
//{
//	return this->_y;
//}


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

void Map::reprint_cell(short x, short y)
{
	COORD position = { x, y }; //позиция x и y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
	cout << this->_game_field_level[y][x].get_value();
}



Room* Map::initialize_Level()
{
	Head = new Room(1, 1, this);
	if (flag)
	{
		Create_room(Head);
	}
	else
	{
		return Head;
	}
}

int Map::Create_room(Room *room)
{
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
	if (flag)
	{
		Create_corridor(room);
	}
	else
	{
		return flag_0 = false;
	}
}

int Map::Create_corridor(Room *room)
{
	bool flag_2, flag_3;
	Room *Buff_1 = NULL , *Buff_2 = NULL;

	if ((error == 10) || (flag_0 == false)||(flag == false))
	{
		return flag = false;
	}
	 //corridor down
	{

		const int lenght_corridor_y_down = room->_nStr + 2 + rand() % 5;
		int j;
		do
		{
			j = room->_left_angle_x + rand() % 5;
		} while ((j >= this->_m - 1) || (j > room->_nStlb));

		if ((lenght_corridor_y_down> this->_n-10) || (_game_field_level[lenght_corridor_y_down + 9][j].get_value() != '#') || (_game_field_level[lenght_corridor_y_down + 9][j + 1].get_value() != '#') || (_game_field_level[lenght_corridor_y_down + 9][j - 1].get_value() != '#'))
		{
			flag_2 = false;
			//Create_corridor(room);
		}
		else {
				flag_2 = true;
				for (int i = room->_nStr; i < lenght_corridor_y_down; i++)
				{
					if (i == this->_n - 1)
					{
						break;
					}
						_game_field_level[i][j].set_value(' ');
				}
					Buff_1 = new Room(lenght_corridor_y_down, room->_left_angle_x, this);
					room->next_1 = Buff_1;
				
		}
	}
	//corridor right
	{

		const int lenght_corridor_x_right = room->_nStlb + 2 +  rand() % 5;
		int i;

		do
		{
			i = room->_left_angle_y + 1 + rand() % 5;
		} while ((i >= this->_n - 1) || (i > room->_nStr));

		if (((lenght_corridor_x_right) > this->_m-10) || (_game_field_level[i][lenght_corridor_x_right + 9].get_value() != '#') || (_game_field_level[i + 1][lenght_corridor_x_right + 9].get_value() != '#') || (_game_field_level[i - 1][lenght_corridor_x_right + 9].get_value() != '#'))
		{
			flag_3 = false;
			//Create_corridor(room);
		}
		else {
			flag_3 = true;
			for (int j = room->_nStlb; j < lenght_corridor_x_right; j++)
			{
				if (j == this->_m - 1)
				{
					break;
				}
				_game_field_level[i][j].set_value(' ');
			}

				Buff_2 = new Room(room->_left_angle_y, lenght_corridor_x_right, this);
				Head;
				room->next_2 = Buff_2;

			
			
			
		}

		if ((flag_2 == false)&&(flag_3 == false))
		{
			error++;
			Create_corridor(room);
		}
		else if ((flag_2 == true) && (flag_3 == false))
		{
			Create_room(Buff_1);
		}
		else if ((flag_3 == true)&&(flag_2 == false))
		{
			Create_room(Buff_2);
		}
		else if ((flag_3 == true) && (flag_2 == true))
		{
			Create_room(Buff_1);
			flag = true;
			error = 0;
			Create_room(Buff_2);

		}
		
	}
}

void Map::test_Map(sf::RenderWindow &window, short n, short m)
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

	for (int i = 0; i < this->_n; i++)
	{
		for (int j = 0; j < this->_m; j++)
		{
			// координаты клетки задаются костыльно, переделать!!!
			this->get_cell(i, j)._cell_sprite.setPosition(i * 32, j * 32);
			window.draw(this->get_cell(i, j)._cell_sprite);
			//std::cout << this->_game_field_level[i][j].get_value();
		}
		//std::cout << std::endl;
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

void Map::print_map(sf::RenderWindow &window)
{
	//system("cls");
    for (int i = 0; i < this->_n; i++)
    {
        for (int j = 0; j < this->_m; j++)
        {
			// координаты клетки задаются костыльно, переделать!!!
			this->get_cell(i, j)._cell_sprite.setPosition(i * 32, j * 32);
			window.draw(this->get_cell(i, j)._cell_sprite);
            //std::cout << this->_game_field_level[i][j].get_value();
        }
        //std::cout << std::endl;
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


