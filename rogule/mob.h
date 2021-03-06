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
		std::string description, // �������� �������
		Map *level // ��� ������������ ��� (����� ��� ��� ����������)
		);// �����������
	Mob();
	//Mob(char icon, short x, short y, Map level);
	// ���������� ����(��������� ���� _is_attack ���� ����� � ������� ���������)
	void social_agro(Map level); 
	// ��� ���������� �����
	int find_way(Map *level, Hero &hero, View &viewer, RenderWindow &window); //level - �������, �,� ���������� ����� ���������� 1 ���� ��� ������� �����
	// ������������� �������� ����� �����
	void set_is_attack(bool value); 
	// ����������� �������� ����� �����
	bool get_is_attack(); 
	// ������������� �������� ����� �����������
	void set_is_retreat(bool value); 
	// ���������� �������� ����� �����������
	bool get_is_retreat();
	//������ � ������
	friend void work_to_mobs(vector <Mob*>&, RenderWindow &window, Map &level); 

private:
	std::string _description; // �������� �������
	bool _is_attack, //���� �����
		_is_retreat; //���� �����������
};