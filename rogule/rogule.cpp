// rogule.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"



int main()
{
	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(800, 800), "Rogule!"); //����
	RectangleShape rectangle(Vector2f(16, 16)); //�� ����� �������� ����
	Map level_1(20, 20); // ��� �������
	Room *head; //�� ������ ������ ������
	head = level_1.initialize_Level(); // �� ��� �������
	Hero hero(10,10,10,10,2,2); // �����
	Texture rect;
	//rect.loadFromFile("texture.jpg");

	while (window.isOpen()) // ���� ������� ����
	{
	level_1.test_Map(window, 20, 20);
		//level_1.print_map(window);
		sf::Event event; //�������

		while (window.pollEvent(event)) //�� ��� ��� ��������

		{
			

			if (event.type == sf::Event::Closed) // ���� ���� �������

				window.close();
			if ((Keyboard::isKeyPressed(Keyboard::Left))&&((level_1.get_cell(hero._rect.left, hero._rect.top - 1).is_permeable()))) // ���� ������ ������� ����� � �.�
			{
				hero._unit_sprite.move(-32, 0);
			}
			if ((Keyboard::isKeyPressed(Keyboard::Right)) && ((level_1.get_cell(hero._rect.left, hero._rect.top + 1).is_permeable())))
			{
				hero._unit_sprite.move(32, 0);
			}
			if ((Keyboard::isKeyPressed(Keyboard::Up)) && ((level_1.get_cell(hero._rect.left - 1, hero._rect.top).is_permeable())))
			{
				hero._unit_sprite.move(0, -32);
			}
			if ((Keyboard::isKeyPressed(Keyboard::Down)) && ((level_1.get_cell(hero._rect.left + 1, hero._rect.top ).is_permeable())))
			{
				hero._unit_sprite.move(0, 32);
			}

		}

		//window.clear(Color::White); //����� ���

		//for (int i = 0; i<50; i++) //������ �� ����� ��� � ������ �������� �� ��������� rectangle ������ ������
		//	for (int j = 0; j<70; j++)
		//	{
		//		if (level_1._game_field_level[i][j].get_value() == '#') rectangle.setTextureRect(IntRect(640, 768, 32, 32)) ; //����

		//		if (level_1._game_field_level[i][j].get_value() == ' ')  rectangle.setTextureRect(IntRect(192, 800, 32, 32));

		//		rectangle.setPosition(j * 16, i * 16);  //�������
		//		window.draw(rectangle); // ���������
		//	}

		window.draw(hero._unit_sprite); //��������� �����

		window.display(); //�����

		
	}
	
	system("pause");
	return 0;
}

