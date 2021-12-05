//LEGITCLICKER
//Filip Rokita
//filiprokita.com

#include <iostream>
#include <Windows.h>

using namespace std;

char enable, disable;
int cps;

void menu()
{
	cout << "ENABLE: "; cin >> enable;
	cout << "DISABLE: "; cin >> disable;
	cout << "CPS: "; cin >> cps;
}

void autoclicker()
{
	bool autoclicker = false;
	while (true)
	{
		if (GetAsyncKeyState(enable))
		{
			autoclicker = true;
		}
		if (GetAsyncKeyState(disable))
		{
			autoclicker = false;
		}
		if (autoclicker == true)
		{
			INPUT i = { 0 };

			i.type = INPUT_MOUSE;
			i.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
			SendInput(1, &i, sizeof(i));
			ZeroMemory(&i, sizeof(i));

			i.type = INPUT_MOUSE;
			i.mi.dwFlags = MOUSEEVENTF_LEFTUP;
			SendInput(1, &i, sizeof(i));
			ZeroMemory(&i, sizeof(i));

			Sleep(1000 / cps);
		}
	}
}

int main()
{
	system("title LEGITCLICKER - filiprokita.com");
	menu();
	autoclicker();
	return 0;
}