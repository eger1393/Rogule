// rogule.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "view.h"
int main()
{
	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(800,600), "Rogule!"); //sf::Style::Fullscreen); //окно

	view.reset(sf::FloatRect(0, 0, 800, 600)); //камера 

	Map level_1(50, 50); // сам уровень

	Room *head; //эт голова дерева комнат

	head = level_1.initialize_Level(); // ну тут понятно
	
	Hero hero(10,10,10,10,1,1); // герой

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

			hero.key_press(level_1, view);
		}

		viewmap(time);//функция скроллинга карты, передаем ей время sfml

		changeview(hero);//прикалываемся с камерой вида

		window.setView(view);//"оживляем" камеру в окне sfml

		window.clear(Color::Black); //белый фон
	
		level_1.print_level(window); // Отрисовка карты

		window.draw(hero.sprite); //отрисовка героя

		window.display(); //вывод

		
	}
	return 0;
}

