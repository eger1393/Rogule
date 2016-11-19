
#include "stdafx.h"

using namespace std;


class Cell
{
public:
    Cell();
	Cell(char symbol, bool go_to, bool use);
    //Cell(char c, short x, short y); //с- тип клетки, х, у - координаты клетки  
    ~Cell();
    bool is_limpid(); //проверка на прозрачность
    bool is_permeable(); // ѕроерка на проходимость 
    bool can_used(); //  ћожно исспользовать
	char get_value();
	void set_value(char symbol);
    void set_x_y(short x, short y); //задает координаты х, у
private:
    //char _type; //“ип клетки
    //short _x, _y; // оординаты клетки
	char _value;
	bool _move;
	bool _active;
};

class Room;

class Map
{
public:
    Map(short n, short m);
    void test_Map(short n, short m); // —оздание квадратной комнаты дл€ теста
	Room* initialize_Level();
	int Create_room(Room *r);
	int Create_corridor(Room *r);
	//void output();
   // friend void Hero::key_press(Map level); //вычисл€ет видимые клетки геро€
	void reprint_cell(short x, short y); // перересовка отдельной клетки
    Cell& get_cell(short x, short y); //возвращает ссылку на €чейку расположенную по координатам х, у
    void set_cell(Cell cell, short x, short y); //задает €чейку
    void set_cell(char c, short x, short y); //задает €чейку
    void print_map(); //рисует карту
	void print_circular();
	friend Room;
	Cell **_game_field_level;
private:
    //Cell **_cells; //массив €чеек
    short _n, _m; //размеры карты
    //              //std::string name;
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
	~Room();
};