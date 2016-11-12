#pragma once
#include "stdafx.h"
class Room
{
private :
	int _left_angle_x = 0;
	int	_left_angle_y = 0;
	int _nStr = 0;
	int _nStlb = 0;
	int ID_room = 0;
	Cell **_room;
	Room *next, *prev;
public:
	friend Map;
	Room();
	Room(int,int);
	int get_x();
	int get_y();
	~Room();
};

