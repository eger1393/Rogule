// rogule.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"



int main()
{
	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(800, 800), "Rogule!"); //����
	RectangleShape rectangle(Vector2f(16, 16)); //�� ����� �������� ����
	Map level_1(50, 70); // ��� �������
	Room *head; //�� ������ ������ ������
	head = level_1.initialize_Level(); // �� ��� �������
	Hero hero(10,10,10,10,16,16); // �����

	//level_1.print_map(); // �� � ������� �����

	while (window.isOpen()) // ���� ������� ����

	{

		sf::Event event; //�������

		while (window.pollEvent(event)) //�� ��� ��� ��������

		{

			if (event.type == sf::Event::Closed) // ���� ���� �������

				window.close();
			if ((Keyboard::isKeyPressed(Keyboard::Left))&&((level_1.get_cell(hero.rect.left, hero.rect.top - 1).is_permeable()))) // ���� ������ ������� ����� � �.�
			{
				hero.herosprite.move(-16, 0);
			}
			if ((Keyboard::isKeyPressed(Keyboard::Right)) && ((level_1.get_cell(hero.rect.left, hero.rect.top + 1).is_permeable())))
			{
				hero.herosprite.move(16, 0);
			}
			if ((Keyboard::isKeyPressed(Keyboard::Up)) && ((level_1.get_cell(hero.rect.left - 1, hero.rect.top).is_permeable())))
			{
				hero.herosprite.move(0, -16);
			}
			if ((Keyboard::isKeyPressed(Keyboard::Down)) && ((level_1.get_cell(hero.rect.left + 1, hero.rect.top ).is_permeable())))
			{
				hero.herosprite.move(0, 16);
			}

		}

		window.clear(Color::White); //����� ���

		for (int i = 0; i<50; i++) //������ �� ����� ��� � ������ �������� �� ��������� rectangle ������ ������
			for (int j = 0; j<70; j++)
			{
				if (level_1._game_field_level[i][j].get_value() == '#') rectangle.setFillColor(Color::White); //����

				if (level_1._game_field_level[i][j].get_value() == ' ')  rectangle.setFillColor(Color::Black);

				rectangle.setPosition(j * 16, i * 16);  //�������
				window.draw(rectangle); // ���������
			}

		window.draw(hero.herosprite); //��������� �����

		window.display(); //�����

		
	}
	
	system("pause");
	return 0;
}

