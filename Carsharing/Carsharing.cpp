﻿#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	string path = "file.txt";
	ofstream fout;
	fout.open(path, ofstream::app);

	int selection;
	int a;
	int b;
	double c = 0.3;
	double d = 0.07;
rest: cout <<
"Выберите временной тариф" << endl <<
"1.Минутный" << endl <<
"2.3 часа" << endl <<
"3.6 часов" << endl <<
"4.9 часов" << endl <<
"5.12 часов" << endl <<
"6.24 часа" << endl <<
"7.Выход" << endl;

cin >> selection;

switch (selection)
{
case 1:
	cout << "Время аренды - минут" << endl;
	fout << "Время аренды - минут" << endl;
	cin >> a;
	fout << a << endl;
	cout << "Ожидание - минут" << endl;
	fout << "Ожидание - минут" << endl;
	cin >> b;
	fout << b << endl;
	cout << "К оплате=" << (a * c) + (b * d) << endl;
	fout << "К оплате=" << (a * c) + (b * d) << endl;
	break;

case 2:
	cout << "3 часа.Стоимость услуги-24руб\nВ услегу входит включённые 35км\nперепробег 0.29руб/км" << endl;
	fout << "3 часа.Стоимость услуги-24руб\nВ услегу входит включённые 35км\nперепробег 0.29руб/км" << endl;
	break;

case 3:
	cout << "6 часов.Стоимость услуги-34руб\nВ услегу входит включённые 55км\nперепробег 0.29руб/км" << endl;
	fout << "6 часов.Стоимость услуги-34руб\nВ услегу входит включённые 55км\nперепробег 0.29руб/км" << endl;
	break;

case 4:
	cout << "9 часов.Стоимость услуги-42руб\nВ услегу входит включённые 70км\nперепробег 0.29руб/км" << endl;
	fout << "9 часов.Стоимость услуги-42руб\nВ услегу входит включённые 70км\nперепробег 0.29руб/км" << endl;
	break;

case 5:
	cout << "12 часов.Стоимость услуги-49руб\nВ услегу входит включённые 80км\nперепробег 0.29руб/км" << endl;
	fout << "12 часов.Стоимость услуги-49руб\nВ услегу входит включённые 80км\nперепробег 0.29руб/км" << endl;
	break;

case 6:
	cout << "24 часа.Стоимость услуги-59руб\nВ услегу входит включённые 105км\nперепробег 0.29руб/км" << endl;
	fout << "24 часа.Стоимость услуги-59руб\nВ услегу входит включённые 105км\nперепробег 0.29руб/км" << endl;
	break;

case 7:
	return 0;

}
goto rest;
fout.close();
}