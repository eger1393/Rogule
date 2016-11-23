#pragma once
#include "stdafx.h"


int Message::count = 1;

Message::Message(View &view, string str, Color color, int size, int value)
{

	this->setFillColor(color);

	this->setCharacterSize(size);

	font.loadFromFile("HelveticaNeue-Bold.ttf");//передаем нашему шрифту файл шрифта
	this->setFont(font);

	std::ostringstream playerData;
	playerData << value;
	if (value != 0)
	{
		this->setString(str + playerData.str()); //задаем строку тексту и вызываем сформированную выше строку методом .str()
	}
	else
	{
		this->setString(str);
	}
	
	this->setPosition(view.getCenter().x + GetSystemMetrics(SM_CXSCREEN) / 2 - 250,
		(view.getCenter().y - GetSystemMetrics(SM_CYSCREEN) / 2 + 100) + 25 * count);//задаем позицию текста
}

Message::Message(Hero *hero, int flag, View &view, Color color)
{
	count++;

	this->setFillColor(color);

	font.loadFromFile("HelveticaNeue-Bold.ttf");//передаем нашему шрифту файл шрифта
	this->setFont(font);

	std::ostringstream playerData;

	switch (flag)
	{

	case 1:
	{
		playerData << hero->get_hit_point();
		this->setString("XP:" + playerData.str()); //задаем строку тексту и вызываем сформированную выше строку методом .str() 
		break;
	}
	case 2:
	{
		playerData << hero->get_damage();
		this->setString("Damage:" + playerData.str()); //задаем строку тексту и вызываем сформированную выше строку методом .str() 
		break;
	}
	case 3:
	{
		playerData << hero->get_armor();
		this->setString("Armor" + playerData.str()); //задаем строку тексту и вызываем сформированную выше строку методом .str() 
		break;
	}
	case 4:
	{
		playerData << hero->get_viewing_range();
		this->setString("View:" + playerData.str()); //задаем строку тексту и вызываем сформированную выше строку методом .str() 
		break;
	}
	default:
		break;
	}

	this->setPosition(view.getCenter().x + GetSystemMetrics(SM_CXSCREEN) / 2 - 250,
		(view.getCenter().y - GetSystemMetrics(SM_CYSCREEN) / 2 + 100) + 35 * flag);//задаем позицию текста
}