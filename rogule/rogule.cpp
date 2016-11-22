// rogule.cpp: определяет точку входа для консольного приложения.
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
		text->setString("XP:" + playerData.str()); //задаем строку тексту и вызываем сформированную выше строку методом .str() 
			break;
		}
		case 2:
		{
		playerData << hero->get_damage();
		text->setString("Damage:" + playerData.str()); //задаем строку тексту и вызываем сформированную выше строку методом .str() 
			break;
		}
		case 3:
		{
		playerData << hero->get_viewing_range();
		text->setString("View:" + playerData.str()); //задаем строку тексту и вызываем сформированную выше строку методом .str() 
			break;
		}
	default:
		playerData << value;
		text->setString(str + playerData.str()); //задаем строку тексту и вызываем сформированную выше строку методом .str() 
			break;
	}
	text->setPosition(view.getCenter().x - 950, (view.getCenter().y - 540) + 25*flag);//задаем позицию текста
}
int main()
{
	srand((unsigned int)time(0));

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Rogule!"); //sf::Style::Fullscreen); //окно

	view.reset(sf::FloatRect(0, 0, 1920, 1080)); //камера 

	Map level_1(50, 50); // сам уровень

	Room *head; //эт голова дерева комнат

	head = level_1.initialize_Level(); // ну тут понятно

	Hero hero(100, 10, 1, 1, 1, 1); // герой

	vector <Mob*> arr_mob;
	arr_mob.push_back(new Mob(5, 5, 15, 2, 'A', 5, 5, "test mob"));
	arr_mob.push_back(new Mob(5, 5, 15, 2, 'B', 11, 11, "test mob"));

	Font font;//шрифт 
	font.loadFromFile("HelveticaNeue-Bold.ttf");//передаем нашему шрифту файл шрифта
	Text text("", font, 20);

	Clock clock;

	/*level_1.print_level(window);*/

	while (window.isOpen()) // пока открыто окно

	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		sf::Event event; //событие

		

		while (window.pollEvent(event)) //хз как это работает

		{

			if (event.type == sf::Event::Closed ||
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) // если окно закрыто
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

		viewmap(time);//функция скроллинга карты, передаем ей время sfml

		changeview(hero);//прикалываемся с камерой вида

		window.setView(view);//"оживляем" камеру в окне sfml

		window.clear(Color::Black); //белый фон
	
		level_1.print_level(window); // Отрисовка карты
		
		//вывод текста
		for (int i = 1; i < 4; i++)
		{
			setting_text(&text, &hero, i, view);
			window.draw(text);
		}
		
		window.draw(hero.sprite); //отрисовка героя

		work_to_mobs(arr_mob, window, level_1);

		window.display(); //вывод

		
	}
	return 0;
}


