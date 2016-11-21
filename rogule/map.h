
#include "stdafx.h"

using namespace std;


class Cell
{
public:
    Cell();

	Cell(char symbol, bool prospected, bool view);

    ~Cell();
    bool is_limpid(); //проверка на прозрачность

    bool is_permeable(); // Проерка на проходимость 

    bool can_used(); //  Можно исспользовать

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
    //void set_x_y(short x, short y); //задает координаты х, у
private:
    //short _x, _y; //Координаты клетки
	char _value;
	bool _prospected;
	bool _view;

};

class Room;

class Map
{
public:
    Map(short n, short m);

    //void test_Map(short n, short m); // Создание квадратной комнаты для теста

	Room* initialize_Level();

	int Create_room(Room *r);

	int Create_corridor(Room *r);
	
   //friend void Hero::key_press(Map level); //вычисляет видимые клетки героя

	void reprint_cell(short x, short y); // перересовка отдельной клетки

    Cell& get_cell(short x, short y); //возвращает ссылку на ячейку расположенную по координатам х, у

    void set_cell(Cell cell, short x, short y); //задает ячейку

    void set_cell(char c, short x, short y); //задает ячейку

    void print_level(RenderWindow&); //рисует карту

	//void print_circular();

	friend Room;

	Cell **_game_field_level;

private:

	Texture floor, wall, chest, empty, black;

    short _n, _m; //размеры карты
   
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