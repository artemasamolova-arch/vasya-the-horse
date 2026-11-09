#include <iostream>
#include <Windows.h>

bool visYear(int year)
{
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
	{
		return false;
	}
	if (year % 4 == 0)
	{
		return true;
	}
	return false;
}

int dateDifference(int d1, int m1, int y1, int d2, int m2, int y2)
{
	int days1 = d1;
	int days2 = d2;
	int monthDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	//дни первой даты
	for (int i = 1; i < y1; i++)
	{
		if (visYear(i))
		{
			days1 += 366;
		}
		else
		{
			days1 += 365;
		}
	}
	for (int i = 1; i < m1; i++)
	{
		days1 += monthDays[i - 1];
		if (i == 2 && visYear(y1))
		{
			days1++;
		}
	}
	//дни второй даты
	for (int i = 1; i < y2; i++)
	{
		if (visYear(i))
		{
			days2 += 366;
		}
		else
		{
			days2 += 365;
		}
	}
	for (int i = 1; i < m2; i++)
	{
		days2 += monthDays[i - 1];
		if (i == 2 && visYear(y2))
		{
			days2++;
		}
	}

	int result = days1 - days2;
	if (result < 0)
	{
		result = -result;
	}
	return result;
}




int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	int d1 = 0, m1 = 0, y1 = 0;
	int d2 = 0, m2 = 0, y2 = 0;
	std::cout << "Задание 1\nПервая дата\nДень: ";
	std::cin >> d1;
	std::cout << "Месяц: ";
	std::cin >> m1;
	std::cout << "Год: ";
	std::cin >> y1;
	std::cout << "Вторая дата\nДень:";
	std::cin >> d2;
	std::cout << "Месяц: ";
	std::cin >> m2;
	std::cout << "Год: ";
	std::cin >> y2;

	std::cout << "Разница в днях: " << dateDifference(d1, m1, y1, d2, m2, y2);




	return 0;
}