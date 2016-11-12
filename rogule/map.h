#pragma once

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
	friend Room;
private:
    //char _type; //“ип клетки
    //short _x, _y; // оординаты клетки
	char _value;
	bool _move;
	bool _active;
};

class Map
{
public:
    Map(short n, short m);
    void test_Map(short n, short m); // —оздание квадратной комнаты дл€ теста
	void initialize_Level();
	void Create_room(Room *_room);
	void Create_anroom(const int _y, const int _x);
	void Create_corridor(const int left_angle_y, const int left_angle_x, const int str_end, const int stlb_end);
	//void output();
    //friend void Hero::range_of_visibility(Map level); //вычисл€ет видимые клетки геро€
    Cell& get_cell(short x, short y); //возвращает ссылку на €чейку расположенную по координатам х, у
    void set_cell(Cell cell, short x, short y); //задает €чейку
    void set_cell(char c, short x, short y); //задает €чейку
    void print_map(); //рисует карту
	void print_circular();
private:
    //Cell **_cells; //массив €чеек
    short _n, _m; //размеры карты
    //              //std::string name;
	Cell **_game_field_level;
};

