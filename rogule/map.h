
#include "stdafx.h"

using namespace std;

class Mob;

class Cell
{
public:
    Cell();

	Cell(char symbol, bool prospected, bool view);

    ~Cell();
	//�������� �� ������������
    bool is_limpid(); 
	// ������� �� ������������ 
    bool is_permeable();
	//  ����� �������������
	bool can_used(); 
	// ��������, ����� �� �� ������ ���
	bool is_mob();
	// ���������� ������ ������
	char get_value();
	// ������������� ������ ������
	void set_value(char symbol);
	// ����� �� ����� ������
	bool get_view();
	// ������������� ��������� ������ ������
	void set_view(bool bl);
	// ������������� �������� ������
	void set_prospected(bool value);
	// ��������� �������� ������
	bool get_prospected();
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
	virtual ~Map();
    //void test_Map(short n, short m); // �������� ���������� ������� ��� �����
	//�������� ������������ �������
	int initialize_Level();
	//�������� �������
	void initialize_win_level();
	//������� �������
	int Create_room(Room *r);
	//������� ��������
	int Create_corridor(Room *r);
	// �������������� ������ � �������
	void reprint_cell(short x, short y); 
	// ���������� ������ �� ������ �� ����������� �,�
    Cell& get_cell(short x, short y); 
	//������ ������
    void set_cell(Cell cell, short x, short y); //������ ������
	//������ ������ ������
    void set_cell(char c, short x, short y); //������ ������
	//������ �����
    void print_level(RenderWindow&);
	// ��������� ����� �� �����
	void work_to_mobs(RenderWindow &window);
	//void print_circular();

	friend Room;
	//����
	vector <Mob*> arr_mob;
	//��� �������
	Cell **_game_field_level;

	int exit_x , exit_y;

	bool flag = true, flag_0 = true;
	static int error;
	static int count_win;
private:
	//��������� �����
	Texture map;
	
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