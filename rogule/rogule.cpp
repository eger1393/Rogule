// rogule.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"



int main()
{
	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(800, 800), "Rogule!"); //окно
	RectangleShape rectangle(Vector2f(16, 16)); //эт кусок игрового поля
	Map level_1(20, 20); // сам уровень
	Room *head; //эт голова дерева комнат
	head = level_1.initialize_Level(); // ну тут понятно
	Hero hero(10,10,10,10,2,2); // герой
	Texture rect;
	//rect.loadFromFile("texture.jpg");

	while (window.isOpen()) // пока открыто окно
	{
	level_1.test_Map(window, 20, 20);
		//level_1.print_map(window);
		sf::Event event; //событие

		while (window.pollEvent(event)) //хз как это работает

		{
			

			if (event.type == sf::Event::Closed) // если окно закрыто

				window.close();
			if ((Keyboard::isKeyPressed(Keyboard::Left))&&((level_1.get_cell(hero._rect.left, hero._rect.top - 1).is_permeable()))) // если нажата стрелка влево и т.д
			{
				hero._unit_sprite.move(-32, 0);
			}
			if ((Keyboard::isKeyPressed(Keyboard::Right)) && ((level_1.get_cell(hero._rect.left, hero._rect.top + 1).is_permeable())))
			{
				hero._unit_sprite.move(32, 0);
			}
			if ((Keyboard::isKeyPressed(Keyboard::Up)) && ((level_1.get_cell(hero._rect.left - 1, hero._rect.top).is_permeable())))
			{
				hero._unit_sprite.move(0, -32);
			}
			if ((Keyboard::isKeyPressed(Keyboard::Down)) && ((level_1.get_cell(hero._rect.left + 1, hero._rect.top ).is_permeable())))
			{
				hero._unit_sprite.move(0, 32);
			}

		}

		//window.clear(Color::White); //белый фон

		//for (int i = 0; i<50; i++) //проход по всему лвл и замена символов на текстурки rectangle разных цветов
		//	for (int j = 0; j<70; j++)
		//	{
		//		if (level_1._game_field_level[i][j].get_value() == '#') rectangle.setTextureRect(IntRect(640, 768, 32, 32)) ; //цвет

		//		if (level_1._game_field_level[i][j].get_value() == ' ')  rectangle.setTextureRect(IntRect(192, 800, 32, 32));

		//		rectangle.setPosition(j * 16, i * 16);  //позиция
		//		window.draw(rectangle); // отрисовка
		//	}

		window.draw(hero._unit_sprite); //отрисовка героя

		window.display(); //вывод

		
	}
	
	system("pause");
	return 0;
}

