
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

	int key_press(Map &level, View&, RenderWindow&); // �������� ������

	void viewing_range(Map level, bool flag_view, char c); // ���������� ������� ���������

	void move(short x, short y);
	
	void active(char Symbol, Map &level, short,short, View &view, RenderWindow &window);
	//��������� ������ �����
	void set_hit_point(int);
	//������� ���-�� ������ 
	int get_hit_point();

private:
    
};