#pragma once

#include "stdafx.h"


class Unit
{
public:
	Texture texture;
	Sprite sprite;
	//Unit(); // �� ������ ���������������

	// �����������
	Unit(int hit_point, // ��������
		int viewing_range, // ������ ������
		int damage, // ����
		int armor, // �����
		char icon, // ������ c�������
	short x, short y // ���������� ��������
	); // �����������
	
	//void viewing_range(Map level, char c); // ���������� ������� ���������

	// ���� ��������� �-�� ������ ���������� ����
	int attak(Unit &unit2);
	// ����������� ����
	void set_unit(Map level, short x, short y); 
	// ������� ���-�� ����� �����
	int get_hit_point();
	// ������� ���������� �
	int get_x();
	// ������� ���������� �
	int get_y();
	//������� ����
	int get_damage();

	void push_log(string);

	Text text;

protected:
	int _hit_point, // ��������
		_viewing_range, // ������ ������
		_damage, // ����
		_armor; // �����
	char _icon; // ������ c�������
	short _x, _y; // ���������� ��������
};