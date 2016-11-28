#pragma once
#include "stdafx.h"

class Message : public Text
{
private:
	Font font;
public:
	static int count;

	Message();

	Message(string str, Color color, int value = 0, int size = 30 );
	
	Message(Hero *hero, int flag, View &view, Color);
	
};