
#include "stdafx.h"

class Mob;

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

	// �������� ������
	int key_press(Map &level, View&, RenderWindow&); 
	// ���������� ������� ���������
	void viewing_range(Map level, bool flag_view); 
	//�������������� � ��������� �������� ( �����-������ � �.�)
	void active(char Symbol, Map &level, short,short, RenderWindow &window, View &view); 
	//��������� ������ �����
	void set_hit_point(int);
	//������� ������ ������
	int get_viewing_range();
	//������� �����
	int get_armor();

private:
    
};