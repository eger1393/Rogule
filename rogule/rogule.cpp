// rogule.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include "view.h"
int main()
{
	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(800, 600), "Rogule!"); //sf::Style::Fullscreen); //����

	view.reset(sf::FloatRect(0, 0, 800, 600)); //������ 

	Map level_1(50, 50); // ��� �������

	Room *head; //�� ������ ������ ������

	head = level_1.initialize_Level(); // �� ��� �������

	Hero hero(100, 10, 10, 10, 1, 1); // �����

	vector <Mob*> arr_mob;
	arr_mob.push_back(new Mob(2, 5, 2, 2, 'A', 5, 5, "test mob"));
	arr_mob.push_back(new Mob(2, 5, 2, 2, 'B', 6, 6, "test mob"));

	//Mob *arr_mob[2] = {new Mob(5, 5, 2, 2, 'A', 5, 5, "test mob"), new Mob(5, 5, 2, 2, 'B', 6, 6, "test mob") };
	//Mob mob(5, 5, 2, 2, 'A', 5, 5, "test mob");
	//Mob mob2(5, 5, 2, 2, 'B', 6, 6, "test mob");

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
			hero.key_press(level_1, view,arr_mob,window);
			if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Right)
				|| Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Down)) {
				for (int i = 0; i < arr_mob.size(); i++)
					arr_mob[i]->find_way(level_1, hero);
			}
		}

		viewmap(time);//������� ���������� �����, �������� �� ����� sfml

		changeview(hero);//������������� � ������� ����

		window.setView(view);//"��������" ������ � ���� sfml

		window.clear(Color::Black); //����� ���
	
		level_1.print_level(window); // ��������� �����

		window.draw(hero.sprite); //��������� �����

		work_to_mobs(arr_mob, window, level_1);

		window.display(); //�����

		
	}
	return 0;
}

