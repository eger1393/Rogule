
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

	void key_press(Map &level, View&,vector <Mob*> &arr_mob); // �������� ������

	void viewing_range(Map level, bool flag_view, char c); // ���������� ������� ���������

	void active(char Symbol, Map &level, short,short, RenderWindow &window, View &view); // ����� � ����������

	void move(int x, int y);
	//��������� ������ �����
	void set_hit_point(int);
	//������� ���-�� ������ 
	int get_hit_point();
private:
    
};