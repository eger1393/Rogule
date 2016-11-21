// rogule.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include "view.h"
int main()
{
	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(800,600), "Rogule!"); //sf::Style::Fullscreen); //����

	view.reset(sf::FloatRect(0, 0, 800, 600)); //������ 

	Map level_1(50, 50); // ��� �������

	Room *head; //�� ������ ������ ������

	head = level_1.initialize_Level(); // �� ��� �������
	
	Hero hero(10,10,10,10,1,1); // �����

	Clock clock;

	/*level_1.print_level(window);*/

	while (window.isOpen()) // ���� ������� ����

	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		sf::Event event; //�������

		while (window.pollEvent(event)) //�� ��� ��� ��������

		{

			if (event.type == sf::Event::Closed ||
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) // ���� ���� �������
			{
				window.close(); 
			}

			hero.key_press(level_1, view);
		}

		viewmap(time);//������� ���������� �����, �������� �� ����� sfml

		changeview(hero);//������������� � ������� ����

		window.setView(view);//"��������" ������ � ���� sfml

		window.clear(Color::Black); //����� ���
	
		level_1.print_level(window); // ��������� �����

		window.draw(hero.sprite); //��������� �����

		window.display(); //�����

		
	}
	return 0;
}

