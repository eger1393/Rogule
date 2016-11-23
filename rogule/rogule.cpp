// rogule.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include "view.h"




int main()
{
	srand((unsigned int)time(0));

	sf::RenderWindow window(sf::VideoMode(GetSystemMetrics(SM_CXSCREEN) - 100, GetSystemMetrics(SM_CYSCREEN) - 100), "Rogule!"); //sf::Style::Fullscreen); //����

	view.reset(sf::FloatRect(0, 0, GetSystemMetrics(SM_CXSCREEN) - 100, GetSystemMetrics(SM_CYSCREEN) - 100)); //������ 

	Map level_1(50, 50); // ��� �������

	Room *head; //�� ������ ������ ������

	head = level_1.initialize_Level(); // �� ��� �������

	Hero hero(1000, 10, 10, 10, 1, 1); // �����

	vector <Mob*> arr_mob;

	Font font;//����� 
	font.loadFromFile("HelveticaNeue-Bold.ttf");//�������� ������ ������ ���� ������
	Text text("", font, 20);

	Clock clock;

	/*level_1.print_level(window);*/
	hero.viewing_range(level_1, true);
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
			//if (hero.get_hit_point() > 0)
			//{
				hero.key_press(level_1, view, window);
				
			//}
			//else
			//{
			//	text1.setPosition(view.getCenter().x - 64, view.getCenter().y);//������ ������� ������, ����� ������
			//	window.draw(text);
			//	//window.display();
			//}
		}

		viewmap(time);//������� ���������� �����, �������� �� ����� sfml

		changeview();//������������� � ������� ����

		window.setView(view);//"��������" ������ � ���� sfml

		window.clear(Color::Black); //����� ���
	
		level_1.print_level(window); // ��������� �����
		
		//����� ������
		for (int i = 1; i < 4; i++)
		{
			Message message_box(&hero, i, view,Color::White);
			window.draw(message_box);
		}
		
		window.draw(hero.sprite); //��������� �����

		level_1.work_to_mobs(window);

		window.display(); //�����

		
	}
	return 0;
}


