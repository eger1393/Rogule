#pragma once

#include "stdafx.h"

class Mob : public Unit
{
public:
	Mob(int hit_point, // ��������
		int viewing_range, // ������ ������
		int damage, // ����
		int armor, // �����
		char icon, // ������ c�������
		short x, short y, // ���������� ��������
		std::string description // �������� �������
		);// �����������
	Mob();
	void social_agro(Map level); // ���������� ����(��������� ���� _is_attack ���� ����� � ������� ���������)
	int find_way(Map level, short x, short y); //level - �������, �,� ���������� ����� ���������� 1 ���� ��� ������� �����

	void set_is_attack(bool value); // ������������� �������� ����� �����
	bool get_is_attack(); // ����������� �������� ����� �����
	void set_is_retreat(bool value); // ������������� �������� ����� �����������
	bool get_is_retreat(); // ���������� �������� ����� �����������


private:
	std::string _description; // �������� �������
	bool _is_attack, //���� �����
		_is_retreat; //���� �����������
};