
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

	void key_press(Map &level, View&); // �������� ������

	void viewing_range(Map level, bool flag_view, char c); // ���������� ������� ���������

	void move(short x, short y);
	
	void active(char Symbol, Map &level, short,short);


private:
    
};