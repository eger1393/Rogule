
#include "stdafx.h"
int Map::error = 0;
int Map::count_win = 0;
bool check = false;

// ����� �� ����� ������
bool Cell::get_view()
{
	return this->_view;
}

// ��������� ��������� ��������� ������
void Cell::set_view(bool bl)
{
	_view = bl;
}

// ��������� �������� ������
void Cell::set_prospected(bool value)
{
	this->_prospected = value;
}

// ���������� �� ������
bool Cell::get_prospected()
{
	return this->_prospected;
}

Cell::Cell()
{
	_value = ' ';
	_prospected = false;
	_view = false;
}

Cell::Cell(char symbol, bool prospected, bool view)
{
	_value = symbol;
	_prospected = prospected;
	_view = view;
}

// ��������� ������� ������
void Cell::set_value(char symbol)
{
	_value = symbol;
}

// ��������� ������� ������
char Cell::get_value()
{
	return _value;
}

//������ ���������?
bool Cell::is_limpid() // ������������
{
	if (this->_value == '#')
	{
		return false;
	}
	else
	{
		return true;
	}
}

// ������ ���������?
bool Cell::is_permeable() // ������������
{
	if (this->_value == '#' || (this->_value >= 'A' && this->_value <= 'Z'))
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

Map::~Map()
{
	for (int i = 0; i < this->_n; i++) {
		delete[] _game_field_level[i];

	}
	delete[] _game_field_level;
	this->arr_mob.clear();
	this->flag = true;
	this->flag_0 = true;
	Map::error = 0;
}
//void Cell::set_x_y(short x, short y) //������ ���������� �, �
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

//����������� �����
Map::Map(short n, short m)
{
	this->flag = true;
	this->flag_0 = true;
	Map::error = 0;
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
			_game_field_level[i][j].set_view(false);
		}
	}
	
	map.loadFromFile("images/map.png");

}

// �������������� ������ � �������
void Map::reprint_cell(short x, short y)
{
	COORD position = { x, y }; //������� x � y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
	cout << this->_game_field_level[y][x].get_value();
}


void Map::initialize_win_level()
{
	for (int i = 0; i < this->_n-1; i++)
	{
		for (int j = 0; j < this->_m-1; j++)
		{
			_game_field_level[i][j].set_value('$');
		}
	}
}


//�������� �������� �������
int Map::initialize_Level()
{
	Room *Head;
	Head = new Room(1, 1, this);
	check = false;
	if (flag)
	{
		Create_room(Head);
	}
	else
	{
		return 0;
	}
}

//������� �������
int Map::Create_room(Room *room)
{
	int temp_left_angle_y = 0, temp_left_angle_x = 0;

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
		
			//������� �� ���� �������
		if ((room->_left_angle_y > 35) && (room->_left_angle_x > 35) && (check==false))
		{
			this->exit_y = room->_left_angle_y;
			this->exit_x = room->_left_angle_x;
			check = true;
		}
		
	}

	//��������� ��������
	{
		int	temp = 1 + rand() % 4;
		
		_game_field_level[room->_left_angle_y + temp][room->_left_angle_x + temp].set_value('$');
	}
	
	//��������� ���������
	{
		int temp;
		do
		{
			temp = 1 + rand() % 3;
		} while (((room->_left_angle_y + temp + 2) > room->_nStr) && ((room->_left_angle_x + temp + 2) > room->_nStlb));
		
		int value = rand() % 10;
		switch (value)
		{
				//����� � ���
		case 1:
		{
			_game_field_level[room->_left_angle_y + temp][room->_left_angle_x + temp].set_value('!');
			_game_field_level[room->_left_angle_y + temp][room->_left_angle_x + temp + 1].set_value('!');
			_game_field_level[room->_left_angle_y + temp][room->_left_angle_x + temp + 2].set_value('!');
			break;
		}
			//����� � �������
		case 2:
		{
			_game_field_level[room->_left_angle_y + temp][room->_left_angle_x + temp].set_value('!');
			_game_field_level[room->_left_angle_y + temp+1][room->_left_angle_x + temp].set_value('!');
			_game_field_level[room->_left_angle_y + temp+2][room->_left_angle_x + temp].set_value('!');
			break;
		}
			//����� � ���������
		case 3:
		{
			_game_field_level[room->_left_angle_y + temp][room->_left_angle_x + temp].set_value('!');
			_game_field_level[room->_left_angle_y + temp+1][room->_left_angle_x + temp + 1].set_value('!');
			_game_field_level[room->_left_angle_y + temp+2][room->_left_angle_x + temp + 2].set_value('!');
			break;
		}
			//����� � �������
		case 4:
		{
			_game_field_level[room->_left_angle_y + temp][room->_left_angle_x + temp].set_value('`');
			_game_field_level[room->_left_angle_y + temp][room->_left_angle_x + temp + 1].set_value('`');
			_game_field_level[room->_left_angle_y + temp][room->_left_angle_x + temp + 2].set_value('`');
			break;
		}
			//����� � �������
		case 5:
		{
			_game_field_level[room->_left_angle_y + temp][room->_left_angle_x + temp].set_value('`');
			_game_field_level[room->_left_angle_y + temp+1][room->_left_angle_x + temp + 1].set_value('`');
			_game_field_level[room->_left_angle_y + temp+2][room->_left_angle_x + temp + 2].set_value('`');
			break;
		}
			//����� � �������
		case 6:
		{
			_game_field_level[room->_left_angle_y + temp][room->_left_angle_x + temp].set_value('`');
			_game_field_level[room->_left_angle_y + temp+1][room->_left_angle_x + temp].set_value('`');
			_game_field_level[room->_left_angle_y + temp+2][room->_left_angle_x + temp].set_value('`');
			break;
		}
			//���� � ���
		case 7:
		{
			_game_field_level[room->_left_angle_y + temp][room->_left_angle_x + temp].set_value('%');
			_game_field_level[room->_left_angle_y + temp][room->_left_angle_x + temp + 1].set_value('%');
			_game_field_level[room->_left_angle_y + temp][room->_left_angle_x + temp + 2].set_value('%');
			break;
		}
			//���� � ���������
		case 8:
		{
			_game_field_level[room->_left_angle_y + temp][room->_left_angle_x + temp].set_value('%');
			_game_field_level[room->_left_angle_y + temp+1][room->_left_angle_x + temp + 1].set_value('%');
			_game_field_level[room->_left_angle_y + temp+2][room->_left_angle_x + temp + 2].set_value('%');
		}
			//���� � �������
		case 9:
		{
			_game_field_level[room->_left_angle_y + temp][room->_left_angle_x + temp].set_value('%');
			_game_field_level[room->_left_angle_y + temp+1][room->_left_angle_x + temp].set_value('%');
			_game_field_level[room->_left_angle_y + temp+2][room->_left_angle_x + temp].set_value('%');
			break;
		}
		default:
			break;
		}
		
	}
	
	//��������� �����
	while (rand() % 10 < 5)
	{
		int temp_x = room->_left_angle_x + rand() % 5, // � ���������� ����
			temp_y = room->_left_angle_y + rand() % 5, // � ���������� ����
			temp = rand() % 5; // ��� ����
		switch (temp)
		{
		case 0: // �������� ���
			arr_mob.push_back(new Mob(5 + rand() % 5, 5, rand() % 5 + 5, rand() % 5, 'A',
				temp_x, temp_y, "Imp ", this));
			break;
		case 1: // �����
			arr_mob.push_back(new Mob(10 + rand() % 5, 5, rand() % 5 + 7, rand() % 5 + 2, 'B',
				temp_x, temp_y, "Snake ", this));
			break;

		case 2: // ������
			arr_mob.push_back(new Mob(15 + rand() % 5, 5, rand() % 5 + 10, rand() % 5 + 5, 'C',
				temp_x, temp_y, "Skeleton ", this));
			break;

		case 3: // ��������� ���
			arr_mob.push_back(new Mob(20 + rand() % 5, 5, rand() % 5 + 13, rand() % 5 + 7, 'D',
				temp_x, temp_y, "Evil cat ", this));
			break;
		case 4: // ������
			arr_mob.push_back(new Mob(30 + rand() % 5, 5, rand() % 5 + 15, rand() % 5  + 10, 'E',
				temp_x, temp_y, "The Dragon ", this));
			break;
		default:
			break;
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

//�����
int Map::Create_corridor(Room *room)
{
	bool flag_2, flag_3;
	Room *Buff_1 = NULL, *Buff_2 = NULL;

	if ((error == 10) || (flag_0 == false) || (flag == false))
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

		if ((lenght_corridor_y_down > this->_n - 10) || (_game_field_level[lenght_corridor_y_down + 9][j].get_value() != '#') || (_game_field_level[lenght_corridor_y_down + 9][j + 1].get_value() != '#') || (_game_field_level[lenght_corridor_y_down + 9][j - 1].get_value() != '#'))
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

		const int lenght_corridor_x_right = room->_nStlb + 2 + rand() % 5;
		int i;

		do
		{
			i = room->_left_angle_y + 1 + rand() % 5;
		} while ((i >= this->_n - 1) || (i > room->_nStr));

		if (((lenght_corridor_x_right) > this->_m - 10) || (_game_field_level[i][lenght_corridor_x_right + 9].get_value() != '#') || (_game_field_level[i + 1][lenght_corridor_x_right + 9].get_value() != '#') || (_game_field_level[i - 1][lenght_corridor_x_right + 9].get_value() != '#'))
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
			room->next_2 = Buff_2;




		}

		if ((flag_2 == false) && (flag_3 == false))
		{
			error++;
			Create_corridor(room);
		}
		else if ((flag_2 == true) && (flag_3 == false))
		{
			Create_room(Buff_1);
		}
		else if ((flag_3 == true) && (flag_2 == false))
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

// ���������� ������ �� ����������� �, �
Cell& Map::get_cell(short x, short y)
{
	if (x >= this->_m || y >= this->_n)
		_game_field_level[0][0]; // �������
	return this->_game_field_level[y][x];
}

// ������������� �������� ������ �� ����������� �, �
void Map::set_cell(Cell cell, short x, short y)
{
	if (x >= this->_m || y >= this->_n)
		exit(2);
	this->_game_field_level[y][x] = cell;
}

// ������������� �������� ������ �� ����������� �, �
void Map::set_cell(char c, short x, short y)
{
	if (x >= this->_m || y >= this->_n)
		exit(3);
	this->_game_field_level[y][x].set_value(c);
}

// ������ ������� � ����
void Map::print_level(RenderWindow &window)
{
	RectangleShape rectangle(Vector2f(32, 32));
	rectangle.setTexture(&map);

	_game_field_level[this->exit_y][this->exit_x].set_value('0');

	for (int i = 0; i < this->_n; i++) //������ �� ����� ��� � ������ �������� �� ��������� rectangle ������ ������
		for (int j = 0; j < this->_m; j++)
		{
			if (this->_game_field_level[i][j].get_prospected()) //���� ������ ����������
			{
				if (this->_game_field_level[i][j].get_view()) // ���� ������ ������ ����� �����
				{
					rectangle.setFillColor(sf::Color(255, 255, 255, 255)); // ������ ������
				}
				else
				{
					rectangle.setFillColor(sf::Color(255, 255, 255, 63)); // ����� �������� �������
				}
				switch (this->_game_field_level[i][j].get_value())
				{
				case '#': // �����
					rectangle.setTextureRect(IntRect(32, 0, 32, 32));
					break;

				case ' ': // ���
					rectangle.setTextureRect(IntRect(0, 0, 32, 32));;
					break;

				case '$': // ������
					rectangle.setTextureRect(IntRect(64, 0, 32, 32));;
					break;

				case '!': // ���������
					rectangle.setTextureRect(IntRect(160, 0, 32, 32));;
					break;

				case '`': // ���������
					rectangle.setTextureRect(IntRect(128, 0, 32, 32));;
					break;

				case '%': // ���������
					rectangle.setTextureRect(IntRect(192, 0, 32, 32));;
					break;

				case '0': // �����
					rectangle.setTextureRect(IntRect(224, 0, 32, 32));;
					break;

				default:
					break;
				}
			}
			else
			{
				rectangle.setTextureRect(IntRect(96, 0, 32, 32));;; // ������������� �������
			}
			rectangle.setPosition((float)j * 32, (float)i * 32);  //�������
			window.draw(rectangle); // ���������
		}
}


//void Map::print_circular()
//{
//	const int m = 15, n = 15;
//	int radius = 6;
//	for (int i = 0; i < radius / 2 + 1; i++)
//	{
//		this->_game_field_level[n + radius][m + i].set_value('#');
//		this->_game_field_level[n + radius][m - i].set_value('#');
//	}
//
//	int j = radius / 2, i = radius;
//	while (j != radius)
//	{
//		i--;
//		j++;
//		this->_game_field_level[n + i][m + j].set_value('#');
//	}
//	///////////////////
//	for (int i = 0; i < radius / 2 + 1; i++)
//	{
//		this->_game_field_level[n - i][m + radius].set_value('#');
//		this->_game_field_level[n + i][m + radius].set_value('#');
//	}
//
//	 j = radius, i = - radius / 2;
//	while (i != - radius)
//	{
//		i--;
//		j--;
//		this->_game_field_level[n + i][m + j].set_value('#');
//	}
//}

// ����� �� �� ������ ���
bool Cell::is_mob()
{
	if (this->_value >= 'A' && this->_value <= 'Z')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Map::work_to_mobs(RenderWindow &window)
{
	for (int i = 0; i < this->arr_mob.size(); i++)
	{
		if (this->arr_mob[i]->get_hit_point() < 0) // ���� ��� ����
		{
			this->get_cell(this->arr_mob[i]->get_x(), this->arr_mob[i]->get_y()).set_value(' '); //������ ������ ���� ���
			this->arr_mob.erase(this->arr_mob.begin() + i); // ������ ���� �� ������� �����
		}
		else // ���� ��� ���
		{
			if (this->get_cell(this->arr_mob[i]->get_x(), this->arr_mob[i]->get_y()).get_view()) // ���� ����� ����� ����
			{
				this->arr_mob[i]->set_unit(this, this->arr_mob[i]->get_x(), this->arr_mob[i]->get_y()); // �������
				window.draw(this->arr_mob[i]->sprite); //��������� ����
			}
		}
	}
}

