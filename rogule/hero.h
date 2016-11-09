#pragma once
#include "stdafx.h"

class Hero
{
public:
    Hero();
    Hero(short x, short y); 
	void key_press(Map level); // �������� ������
    void range_of_visibility(Map level, char c); // ���������� ������� ���������
    void set_hero(Map level, short x, short y); // ����������� �����
private:
    const short _range_of_visibility = 4; // ������ ���������
    const char _icon = '@'; //������ �����
    short _x, _y; // ���������� �����
};