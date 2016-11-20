// rogule.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"



int main()
{
	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(800, 800), "Rogule!"); //окно
	RectangleShape rectangle(Vector2f(16, 16)); //эт кусок игрового поля
	Map level_1(50, 70); // сам уровень
	Room *head; //эт голова дерева комнат
	head = level_1.initialize_Level(); // ну тут понятно
	Hero hero(10,10,10,10,16,16); // герой

	//level_1.print_map(); // эт в консоли карта

	while (window.isOpen()) // пока открыто окно

	{

		sf::Event event; //событие

		while (window.pollEvent(event)) //хз как это работает

		{

			if (event.type == sf::Event::Closed) // если окно закрыто

				window.close();
			if ((Keyboard::isKeyPressed(Keyboard::Left))&&((level_1.get_cell(hero.rect.left, hero.rect.top - 1).is_permeable()))) // если нажата стрелка влево и т.д
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

		window.clear(Color::White); //белый фон

		for (int i = 0; i<50; i++) //проход по всему лвл и замена символов на текстурки rectangle разных цветов
			for (int j = 0; j<70; j++)
			{
				if (level_1._game_field_level[i][j].get_value() == '#') rectangle.setFillColor(Color::White); //цвет

				if (level_1._game_field_level[i][j].get_value() == ' ')  rectangle.setFillColor(Color::Black);

				rectangle.setPosition(j * 16, i * 16);  //позиция
				window.draw(rectangle); // отрисовка
			}

		window.draw(hero.herosprite); //отрисовка героя

		window.display(); //вывод

		
	}
	
	system("pause");
	return 0;
}

