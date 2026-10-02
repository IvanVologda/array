#include <iostream>
#include<windows.h>

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	srand(time(NULL));

	const int size = 10;
	int numbers[size]{};

	for (int i = 0; i < size; i++)
	{
		numbers[i] = rand() % 21 - 10;

		std::cout << numbers[i] << " ";
	}

	int largerNumber = numbers[0], smallerNumber = numbers[0];

	for (int i = 0; i < size; i++)
	{
		if (numbers[i] > largerNumber)
			largerNumber = numbers[i];
		if (numbers[i] < smallerNumber)
			smallerNumber = numbers[i];
	}

	std::cout << "\nМеньшее число: " << smallerNumber << "\n";
	std::cout << "Большее число: " << largerNumber << "\n\n\n";

	system("pause");
	system("cls");

	int secondNumbers[size]{};
	int start = 0, end = 0, diaposon = 0, userNumber = 0, sum = 0;

	std::cout << "Введите начало диапазона: ";
	std::cin >> start;
	std::cout << "\nВведите конец диапазона: ";
	std::cin >> end;

	while (start >= end)
	{
		std::cout << "\nНачало диапазона не может быть равно или быть больше конца " 
			<< "диапазона. \nВведите начало диапазона: ";
		std::cin >> start;
		std::cout << "\nВведите конец диапазона: ";
		std::cin >> end;
	}

	diaposon = end - start;

	for  (int i = 0; i < size; i++)
	{
		secondNumbers[i] = rand() % (diaposon + 1) + start;
		std::cout << secondNumbers[i] << " ";
	}

	std::cout << "\n\nВведите число, чтобы посчитать сумму элементов меньше него: ";
	std::cin >> userNumber;

	for (int i = 0; i < size; i++)
	{
		if (secondNumbers[i] < userNumber)
		{
			sum += secondNumbers[i];
		}
	}

	std::cout << "\nСумма элементов меньше " << userNumber << " равна: " << sum << "\n";

	system("pause");
	system("cls");

	int monthInYear = 12, firstMonth = 0, lastMonth = 0;
	int financy[12]{};

	for (int i = 0; i < monthInYear; i++)
	{
		std::cout << "\nВведите доход за " << i + 1 << " месяц: ";
		std::cin >> financy[i];

		while (financy[i] < 0)
		{
			std::cout << "\nДоход не может быть отрицательным. \nВведите доход за " << i + 1 << " месяц: ";
			std::cin >> financy[i];
		}
	}	

	std::cout << "Введите диапозон поиска: ";
	std::cin >> firstMonth;

	while (firstMonth < 1 || firstMonth > 12)
	{
		std::cout << "Диапазон поиска не может быть меньше 1 и больше 12. \nВведите начало диапазона: ";
		std::cin >> firstMonth;
	}

	std::cout << "Введите конец диапазона: ";
	std::cin >> lastMonth;

	while (lastMonth > 12 || lastMonth < firstMonth)
	{
		std::cout << "Диапазон поиска не может быть больше 12 и меньше начала диапазона. \nВведите конец диапазона: ";
		std::cin >> lastMonth;
	}

	int minProfit = financy[firstMonth - 1], maxProfit = financy[firstMonth - 1];

	for (int i = firstMonth - 1; i < lastMonth; i++)
	{
		if (financy[i] > maxProfit)
		{
			maxProfit = financy[i];
		}

		if (financy[i] < minProfit)
		{
			minProfit = financy[i];
		}
	}

	for (int i = firstMonth - 1; i < lastMonth; i++)
	{
		if(financy[i] == maxProfit)
			std::cout << "\nМаксимальный доход в диапазоне между " << firstMonth << " и " 
			<< lastMonth << " месяцем будет в " << i + 1 << " месяце: " << maxProfit;
		
		if (financy[i] == minProfit)
			std::cout << "\nМинимальный доход в диапазоне между " << firstMonth << " и "
			<< lastMonth << " месяцем будет в " << i + 1 << " месяце: " << minProfit << "\n";
	}

	system("pause");
	system("cls");

	return 0;
}