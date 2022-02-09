#include<iostream> 
#include<string>
#include<Windows.h> 
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	int b = 216;

	cout <<
		"Я есмь Альфа и Омега, начало и конец;" << endl <<
		"жаждущему дам даром от источника воды живой." << endl <<
		"Откровение...?" << endl;
	cin >> b;
	system("cls");

	if (b == 216)
	{
		double c = 589521563547;
		cout << "Это ещё не всё!!!" << endl;
		cin >> c;
		system("cls");

		if (c == 589521563547)
		{
			cout << "О, создатаель! ПРИВЕТСТВУЮ ВАС!" << endl;
			Sleep(1000);

			int selection, a = 0;
		rest: cout <<
			"Выберите операцию" << endl <<
			"1.Запуск" << endl <<
			"2.Информация" << endl <<
			"3.Выйти" << endl;

		cin >> selection;

		switch (selection)
		{

		case 1:
			cout << "Инициализирую подключение к серверам..." << endl;
			Sleep(5000);
			system("cls");
			cout << "https://www.defense.gov" << endl;
			Sleep(10000);
			system("cls");
			cout << "Подключение ботнета" << endl;
			Sleep(3000);
			system("cls");
			cout << "Запуск алгоритма" << endl;
			Sleep(5000);
			system("cls");
			cout << "Обнаружена уязвимость!" << endl;
			Sleep(2000);

			while (101 > a)
			{
				cout << "Взломано на: " << a << "%" << endl;
				a++;
				Sleep(100);
				system("cls");
			}
			cout << "CONGRATULATION!" << endl;
			Sleep(1000);
			system("cls");
			cout << "Взлом ПЕНТАГОНА произошёл успешно!" << endl;
			Sleep(1000);
			system("cls");
			cout << "Идёт процесс выгрузки документации в облачное хранилище" << endl;
			Sleep(5000);
			system("cls");
			break;

		case 2:
			cout << "\t\t\t\t Данная программа несёт развлекательный характер." << endl;
			cout << "\t\t\t\t Разработал   Симан Александр Васильевич" << endl;

			system("pause");
			system("cls");
			break;

		case 3:
			system("cls");
			return 0;

		default:
			cout << "Ослепило? Нет такой функции! " << endl;
		}
		goto rest;
		system("pause");
		system("cls");
		}

		else if (c != 589521563547)
		{
			cout << "12-ти значный пароль подобрать собираетесь?...УДАЧИ!" << endl <<
				system("pause");
			return 0;
		}
	}

	else if (b != 216)
	{
		cout << "Всё ясно! Подсказка из Fallout3" << endl;
		system("pause");
		return 0;
	}
}