#pragma once

sf::View view;//�������� 

void set_position(View &view, int _x, int _y)
{
	int tepmX = _x, tempY = _y;
	if ((tepmX > ((GetSystemMetrics(SM_CXSCREEN) - 100)))||((tempY > ((GetSystemMetrics(SM_CYSCREEN) - 100)))))
	{
		view.setCenter(_x, _y);
	}
	else
	{
		view.setCenter((GetSystemMetrics(SM_CXSCREEN) - 100), (GetSystemMetrics(SM_CYSCREEN) - 100));
	}
}

void viewmap(float time) { //������� ��� ����������� ������ �� �����. ��������� ����� sfml


	if (Keyboard::isKeyPressed(Keyboard::D)) {
		view.move((float)0.5*time, 0);//�������� ����� ������ 
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) {
		view.move(0, (float)0.5*time);//�������� ����� ����
	}

	if (Keyboard::isKeyPressed(Keyboard::A)) {
		view.move((float)-0.5*time, 0);//�������� ����� ����� 
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		view.move(0, (float)-0.5*time);//�������� ����� ������
	}

}

void changeview() {


	if (Keyboard::isKeyPressed(Keyboard::U)) {
		view.zoom(1.0100f); //������������, ����������
							//view.zoom(1.0006f); //���� ����� ����������� ��������������
	}

	//if (Keyboard::isKeyPressed(Keyboard::R)) {
	//	//view.setRotation(90);//����� �� ������ ������� ������
	//	view.rotate(1);//���������� ������������ ������ (������������� �������� - � �������� �������)
	//}


	if (Keyboard::isKeyPressed(Keyboard::I)) {
		view.setSize(640, 480);//������������� ������ ������ (��� ��������)
	}

	if (Keyboard::isKeyPressed(Keyboard::P)) {
		
	}


	if (Keyboard::isKeyPressed(Keyboard::Q)) {
		view.setViewport(sf::FloatRect(0, 0, 0.5f, 1));//����� ������� �������� ���������� ����� ��� ���� �� �����. ����� ������ ������� ��� ���� ������ View � ����������� � ���� ���������� ������ 2.
	}

}