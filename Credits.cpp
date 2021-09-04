#include<iostream>
using namespace std;

int main()
{
rest:
	setlocale(LC_ALL, "Rus");
	double sum, proc, month, d, e, pay;

	cout << "Сумма" << endl;
	cin >> sum;
	cout << "Процентов" << endl; //Тут вбивать нужно 0.138 т.е это 13.8% 
	cin >> proc;
	cout << "Месяцев" << endl;
	cin >> month;

	while (month > 0)
	{
		month--;
		d = sum / month;
		e = sum * proc / 12;
		pay = d + e;
		sum = sum - pay;

		cout << "\n" << pay << " В месяц" << endl;
		cout << sum << endl;
	}
	goto rest;
}