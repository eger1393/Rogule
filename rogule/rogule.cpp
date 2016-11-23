// rogule.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "view.h"




int main()
{
	srand((unsigned int)time(0));

	sf::RenderWindow window(sf::VideoMode(GetSystemMetrics(SM_CXSCREEN) - 100, GetSystemMetrics(SM_CYSCREEN) - 100), "Rogule!"); //sf::Style::Fullscreen); //окно

	view.reset(sf::FloatRect(0, 0, GetSystemMetrics(SM_CXSCREEN) - 100, GetSystemMetrics(SM_CYSCREEN) - 100)); //камера 

	Map level_1(50, 50); // сам уровень

	Room *head; //эт голова дерева комнат

	head = level_1.initialize_Level(); // ну тут понятно

	Hero hero(1000, 10, 10, 10, 1, 1); // герой

	vector <Mob*> arr_mob;

	Font font;//шрифт 
	font.loadFromFile("HelveticaNeue-Bold.ttf");//передаем нашему шрифту файл шрифта
	Text text("", font, 20);

	Clock clock;

	/*level_1.print_level(window);*/
	hero.viewing_range(level_1, true);
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
			//if (hero.get_hit_point() > 0)
			//{
				hero.key_press(level_1, view, window);
				
			//}
			//else
			//{
			//	text1.setPosition(view.getCenter().x - 64, view.getCenter().y);//задаем позицию текста, центр камеры
			//	window.draw(text);
			//	//window.display();
			//}
		}

		viewmap(time);//функция скроллинга карты, передаем ей время sfml

		changeview();//прикалываемся с камерой вида

		window.setView(view);//"оживляем" камеру в окне sfml

		window.clear(Color::Black); //белый фон
	
		level_1.print_level(window); // Отрисовка карты
		
		//вывод текста
		for (int i = 1; i < 4; i++)
		{
			Message message_box(&hero, i, view,Color::White);
			window.draw(message_box);
		}
		
		window.draw(hero.sprite); //отрисовка героя

		level_1.work_to_mobs(window);

		window.display(); //вывод

		
	}
	return 0;
}


