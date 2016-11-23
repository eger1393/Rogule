#pragma once
#include "stdafx.h"

class Message : public Text
{
private:
	static int count;
	Font font;
public:

	Message(View &view, string str, Color color,  int size = 30, int value = 0);
	
	Message(Hero *hero, int flag, View &view, Color);
	




};