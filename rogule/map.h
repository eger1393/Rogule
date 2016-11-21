
#include "stdafx.h"

using namespace std;


class Cell
{
public:
    Cell();

	Cell(char symbol, bool prospected, bool view);

    ~Cell();
    bool is_limpid(); //�������� �� ������������

    bool is_permeable(); // ������� �� ������������ 

    bool can_used(); //  ����� �������������

	char get_value();

	void set_value(char symbol);

	bool get_view()
	{
		return _view;
	}
	void set_view(bool bl)
	{
		_view = bl;
	}
	void set_prospected(bool value)
	{
		this->_prospected = value;
	}
	bool get_prospected()
	{
		return this->_prospected;
	}
    //void set_x_y(short x, short y); //������ ���������� �, �
private:
    //short _x, _y; //���������� ������
	char _value;
	bool _prospected;
	bool _view;

};

class Room;

class Map
{
public:
    Map(short n, short m);

    //void test_Map(short n, short m); // �������� ���������� ������� ��� �����

	Room* initialize_Level();

	int Create_room(Room *r);

	int Create_corridor(Room *r);
	
   //friend void Hero::key_press(Map level); //��������� ������� ������ �����

	void reprint_cell(short x, short y); // ����������� ��������� ������

    Cell& get_cell(short x, short y); //���������� ������ �� ������ ������������� �� ����������� �, �

    void set_cell(Cell cell, short x, short y); //������ ������

    void set_cell(char c, short x, short y); //������ ������

    void print_level(RenderWindow&); //������ �����

	//void print_circular();

	friend Room;

	Cell **_game_field_level;

private:

	Texture floor, wall, chest, empty, black;

    short _n, _m; //������� �����
   
};

class Room
{
private:
	int _left_angle_x = 0, _left_angle_y = 0, _nStr = 0, _nStlb = 0;

	Cell **_room;

	int ID;

	Room *next_1;

	Room *next_2;

public:
	friend Map;

	Room();

	Room(int, int, Map*);

	int get_x();

	int get_y();

	void fill_room();
	~Room();
};