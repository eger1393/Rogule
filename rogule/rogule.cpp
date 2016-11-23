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
	text->setPosition(view.getCenter().x + GetSystemMetrics(SM_CXSCREEN) / 2 - 250, 
		(view.getCenter().y - GetSystemMetrics(SM_CYSCREEN) / 2 + 100) + 25*flag);//������ ������� ������
}

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
	//arr_mob.push_back(new Mob(5, 5, 15, 2, 'A', 5, 5, "test mob", level_1));
	//arr_mob.push_back(new Mob(5, 5, 15, 2, 'B', 11, 11, "test mob", level_1));

	Font font;//����� 
	font.loadFromFile("HelveticaNeue-Bold.ttf");//�������� ������ ������ ���� ������
	Text text("", font, 20);

	Clock clock;

	Text text1("", font, 50);//������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);//��� ������ ����� (�� ������)
	text1.setFillColor(Color::Red);//��������� ����� � �������. ���� ������ ��� ������, �� �� ��������� �� �����
	text1.setString("You died!");//������ ������ ������

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

		level_1.work_to_mobs(window);

		window.display(); //�����

		
	}
	return 0;
}


