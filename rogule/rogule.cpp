// rogule.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include "view.h"

void setting_text(Text *text,Hero *hero, int flag, View &view, int value = 0, string str = "Error")
{
	std::ostringstream playerData;
	int temp;
	switch (flag)
	{

		case 1:
		{
			temp = hero->get_hit_point();
			playerData << temp;
		text->setString("XP:" + playerData.str()); //������ ������ ������ � �������� �������������� ���� ������ ������� .str() 
			break;
		}
		case 2:
		{
		playerData << hero->get_damage();
		text->setString("Damage:" + playerData.str()); //������ ������ ������ � �������� �������������� ���� ������ ������� .str() 
			break;
		}
		case 3:
		{
		playerData << hero->get_viewing_range();
		text->setString("View:" + playerData.str()); //������ ������ ������ � �������� �������������� ���� ������ ������� .str() 
			break;
		}
	default:
		playerData << value;
		text->setString(str + playerData.str()); //������ ������ ������ � �������� �������������� ���� ������ ������� .str() 
			break;
	}
	text->setPosition(view.getCenter().x - 950, (view.getCenter().y - 540) + 25*flag);//������ ������� ������
}
int main()
{
	srand((unsigned int)time(0));

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Rogule!"); //sf::Style::Fullscreen); //����

	view.reset(sf::FloatRect(0, 0, 1920, 1080)); //������ 

	Map level_1(50, 50); // ��� �������

	Room *head; //�� ������ ������ ������

	head = level_1.initialize_Level(); // �� ��� �������

	Hero hero(100, 10, 1, 1, 1, 1); // �����

	vector <Mob*> arr_mob;
	arr_mob.push_back(new Mob(5, 5, 15, 2, 'A', 5, 5, "test mob"));
	arr_mob.push_back(new Mob(5, 5, 15, 2, 'B', 11, 11, "test mob"));

	Font font;//����� 
	font.loadFromFile("HelveticaNeue-Bold.ttf");//�������� ������ ������ ���� ������
	Text text("", font, 20);

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
		
		//����� ������
		for (int i = 1; i < 4; i++)
		{
			setting_text(&text, &hero, i, view);
			window.draw(text);
		}
		
		window.draw(hero.sprite); //��������� �����

		work_to_mobs(arr_mob, window, level_1);

		window.display(); //�����

		
	}
	return 0;
}


