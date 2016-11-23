#pragma once
#include "stdafx.h" 

sf::View view;//объ€вили sfml объект "вид", который и €вл€етс€ камерой

void getplayercoordinateforview(float x, float y) { //функци€ дл€ считывани€ координат игрока

	view.setCenter(x, y); //следим за игроком, передава€ его координаты. 
}


void viewmap(float time) { //функци€ дл€ перемещени€ камеры по карте. принимает врем€ sfml


	if (Keyboard::isKeyPressed(Keyboard::D)) {
		view.move((float)0.5*time, 0);//скроллим карту вправо (см урок, когда мы двигали геро€ - всЄ тоже самое)
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {
		view.move(0, (float)0.5*time);//скроллим карту вниз (см урок, когда мы двигали геро€ - всЄ тоже самое)
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		view.move((float)-0.5*time, 0);//скроллим карту влево (см урок, когда мы двигали геро€ - всЄ тоже самое)
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		view.move(0, (float)-0.5*time);//скроллим карту вправо (см урок, когда мы двигали геро€ - всЄ тоже самое)
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
		view.setViewport(sf::FloatRect(0, 0, 0.5f, 1));//таким образом делаетс€ раздельный экран дл€ игры на двоих. нужно только создать ещЄ один объект View и прив€зывать к нему координаты игрока 2.
	}

}