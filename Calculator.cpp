#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int a, b, selection;

rest: cout <<
"Введите матиматическую операцию" << endl <<
"1.Сложение" << endl <<
"2.Вычитание" << endl <<
"3.Умножение" << endl <<
"4.Деление" << endl <<
"5.Выход" << endl;

cin >> selection;

switch (selection)
{
case 1:
	cout << "Введите первое число: " << endl;
	cin >> a;
	cout << "Введите второе число: " << endl;
	cin >> b;
	cout << "Результат сложения " << a + b << endl;
	break;
case 2:
	cout << "Введите первое число: " << endl;
	cin >> a;
	cout << "Введите второе число: " << endl;
	cin >> b;
	cout << "Результат вычетания " << a - b << endl;
case 3:
	cout << "Введите первое число: " << endl;
	cin >> a;
	cout << "Введите второе число: " << endl;
	cin >> b;
	cout << "Результат умножения " << a * b << endl;
	break;
case 4:
	cout << "Введите первое число: " << endl;
	cin >> a;
	cout << "Введите второе число: " << endl;
	cin >> b;
	cout << "Результат деления " << (float)a / b << endl;
	break;
case 5:
	cout << "Спасибо что использовали мою программу=) : " << endl;
	system("pause");
	return 0;
default:
	cout << "Да ну!\nПопробуйте ещё раз! " << endl;
}
system("pause");
goto rest;
}