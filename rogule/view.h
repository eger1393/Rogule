#pragma once
#include "stdafx.h" 

sf::View view;//объявили sfml объект "вид", который и является камерой
sf::View view_text;

void viewmap(float time) { //функция для перемещения камеры по карте. принимает время sfml


	if (Keyboard::isKeyPressed(Keyboard::D)) {
		view.move((float)0.5*time, 0);//скроллим карту вправо 
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {
		view.move(0, (float)0.5*time);//скроллим карту вниз
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		view.move((float)-0.5*time, 0);//скроллим карту влево 
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		view.move(0, (float)-0.5*time);//скроллим карту вправо
	}

}

void changeview() {


	if (Keyboard::isKeyPressed(Keyboard::U)) {
		view.zoom(1.0100f); //масштабируем, уменьшение
							//view.zoom(1.0006f); //тоже самое помедленнее соответственно
	}

	if (Keyboard::isKeyPressed(Keyboard::R)) {
		//view.setRotation(90);//сразу же задает поворот камере
		view.rotate(1);//постепенно поворачивает камеру (отрицательное значение - в обратную сторону)
	}


	if (Keyboard::isKeyPressed(Keyboard::I)) {
		view.setSize(640, 480);//устанавливает размер камеры (наш исходный)
	}

	if (Keyboard::isKeyPressed(Keyboard::P)) {
		
	}


	if (Keyboard::isKeyPressed(Keyboard::Q)) {
		view.setViewport(sf::FloatRect(0, 0, 0.5f, 1));//таким образом делается раздельный экран для игры на двоих. нужно только создать ещё один объект View и привязывать к нему координаты игрока 2.
	}

}