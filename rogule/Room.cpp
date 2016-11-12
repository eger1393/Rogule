
#include "stdafx.h"

Room::Room()
{

}
Room::Room(int left_angle_y, int left_angle_x)
	{
		ID_room++;
		_left_angle_y = left_angle_y;
			_left_angle_x = left_angle_x;

		_nStr = _left_angle_y + 5 + rand() % 10,
			_nStlb = _left_angle_x + 5 + rand() % 10;

		_room = new Cell *[_nStr];
		for (int i = 0; i < _nStr; i++)
		{
			_room[i] = new Cell[_nStlb];
		}
	}

int Room::get_x()
	{
		return _left_angle_x;
	}

int Room::get_y()
	{
		return _left_angle_y;
	}

Room::~Room()
{
}
