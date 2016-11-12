
#include "stdafx.h"

using namespace std;

class Cell
{
public:
    Cell();
	Cell(char symbol, bool go_to, bool use);
    //Cell(char c, short x, short y); //�- ��� ������, �, � - ���������� ������  
    ~Cell();
    bool is_limpid(); //�������� �� ������������
    bool is_permeable(); // ������� �� ������������ 
    bool can_used(); //  ����� �������������
	char get_value();
	void set_value(char symbol);
    void set_x_y(short x, short y); //������ ���������� �, �
private:
    //char _type; //��� ������
    //short _x, _y; //���������� ������
	char _value;
	bool _move;
	bool _active;
};

class Room;

class Map
{
public:
    Map(short n, short m);
    void test_Map(short n, short m); // �������� ���������� ������� ��� �����
	void initialize_Level();
	void Create_room(Room *r);
	void Create_anroom(Room *r,const int, const int);
	void Create_corridor(Room *r);
	//void output();
    //friend void Hero::range_of_visibility(Map level); //��������� ������� ������ �����
    Cell& get_cell(short x, short y); //���������� ������ �� ������ ������������� �� ����������� �, �
    void set_cell(Cell cell, short x, short y); //������ ������
    void set_cell(char c, short x, short y); //������ ������
    void print_map(); //������ �����
	void print_circular();
private:
    //Cell **_cells; //������ �����
    short _n, _m; //������� �����
    //              //std::string name;
	Cell **_game_field_level;
};

class Room
{
private:
	int _left_angle_x = 0, _left_angle_y = 0, _nStr = 0, _nStlb = 0;
	int ID_room = 0;
	static int error;
	Cell **_room;
	Room *next;
public:
	friend Map;
	Room();
	Room(int, int);
	int get_x();
	int get_y();
	~Room();
};