
#include "stdafx.h"

using namespace std;

class Mob;

class Cell
{
public:
    Cell();

	Cell(char symbol, bool prospected, bool view);

    ~Cell();
	//проверка на прозрачность
    bool is_limpid(); 
	// Проерка на проходимость 
    bool is_permeable();
	//  Можно исспользовать
	bool can_used(); 
	// Проверка, стоит ли на клетке моб
	bool is_mob();
	// Возвращает символ клетки
	char get_value();
	// Устанавливает символ клетки
	void set_value(char symbol);
	// Видит ли герой клетку
	bool get_view();
	// Устанавливает видимость клетки героем
	void set_view(bool bl);
	// Устанавливает разведку клетки
	void set_prospected(bool value);
	// озвращает разведку клетки
	bool get_prospected();
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
	virtual ~Map();
    //void test_Map(short n, short m); // Создание квадратной комнаты для теста
	//Антон
	Room* initialize_Level();
	//Антон
	int Create_room(Room *r);
	//Антон
	int Create_corridor(Room *r);
	// Перерисовывает клетку в консоли
	void reprint_cell(short x, short y); 
	// Возвращает ссылку на клетку по координатам х,у
    Cell& get_cell(short x, short y); 
	//задает клетку
    void set_cell(Cell cell, short x, short y); //задает ячейку
	//задает символ клетки
    void set_cell(char c, short x, short y); //задает ячейку
	//рисует карту
    void print_level(RenderWindow&);
	// Отрисовка мобов на карте
	void work_to_mobs(RenderWindow &window);
	//void print_circular();

	friend Room;
	//мобы
	vector <Mob*> arr_mob;
	//сам уровень
	Cell **_game_field_level;

	//массив вещей
	bool flag = true, flag_0 = true;
	static int error;
private:
	//текстурка карты
	Texture map;
	
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