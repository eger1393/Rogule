#pragma once
#include "stdafx.h"


class Hero : public Unit
{
public:
    //Hero();
    Hero(int hit_point, // ��������
		int viewing_range, // ������ ������
		int damage, // ����
		int armor, // �����
		short x, short y // ���������� ��������
	); 
	void key_press(Map level); // �������� ������
	void viewing_range(Map level, char c); // ���������� ������� ���������
private:
    
};