#pragma once

#include "stdafx.h"

#define STROKI 30
#define STOLBI 70

using namespace std;

class Cell
{
public:
    Cell();
    //Cell(char c); //с - тип клетки
	Cell(char symbol, bool go_to, bool use);
    //Cell(char c, short x, short y); //с- тип клетки, х, у - координаты клетки  
    ~Cell();
    bool is_limpid(); //проверка на прозрачность
    bool is_permeable(); // Проерка на проходимость 
    bool can_used(); //  Можно исспользовать
    //char get_type(); //возвращает тип клетки
	char get_value();
    //void set_type(char c); //задает тип клетки
	void set_value(char symbol);
    //short get_x(); //возвращает координату х
    //short get_y(); //возвращает координату у
    void set_x_y(short x, short y); //задает координаты х, у
private:
    //char _type; //Тип клетки
    //short _x, _y; //Координаты клетки
	char value;
	bool move;
	bool active;
};

class Map
{
public:
    Map(short n, short m);
    void test_Map(short n, short m); // Создание квадратной комнаты для теста
	void initialize_Level();
	void Create_room(const int left_angle_y, const int left_angle_x);
	void Create_anroom(const int _y, const int _x);
	void Create_corridor(const int left_angle_y, const int left_angle_x, const int str_end, const int stlb_end);
	//void output();
    //friend void Hero::range_of_visibility(Map level); //вычисляет видимые клетки героя
    Cell& get_cell(short x, short y); //возвращает ссылку на ячейку расположенную по координатам х, у
    void set_cell(Cell cell, short x, short y); //задает ячейку
    void set_cell(char c, short x, short y); //задает ячейку
    void print_map(); //рисует карту
	void print_circular();
private:
    //Cell **_cells; //массив ячеек
    short _n, _m; //размеры карты
    //              //std::string name;
	Cell **_game_field_level;
};

