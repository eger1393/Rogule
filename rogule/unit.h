#pragma once

#include "stdafx.h"

const char name_units[] = {
	'@','z','Z','x','X', 'A'
};

class Unit
{
public:
	//Unit(); // �� ������ ���������������
	Unit(int hit_point, // ��������
		int viewing_range, // ������ ������
		int damage, // ����
		int armor, // �����
		char icon, // ������ c�������
	short x, short y // ���������� ��������
	); // �����������
	
	//void viewing_range(Map level, char c); // ���������� ������� ���������
	void attak(Unit *unit2); // ����� �������� ����� ������ ������
	void set_unit(Map level, short x, short y); // ����������� ����

protected:
	int _hit_point, // ��������
		_viewing_range, // ������ ������
		_damage, // ����
		_armor; // �����
	char _icon; // ������ c�������
	short _x, _y; // ���������� ��������
};