#pragma once
#include<iostream>
#include<windows.h>
#include<random>
#include<ctime>

namespace my_header_namespace
{
	//Функция для получения рандомного числового значения с заданным диапазоном; T min, T max
	template<typename T>
	T RandNumber(T min, T max)
	{
		static std::mt19937 randgenerator(time(NULL));
		std::uniform_int_distribution<T> randnumber(min, max);
		return randnumber(randgenerator);
	}

	//Функция для получения рандомного числового значения с заданным диапазоном; T min, T max
	template<> float RandNumber(float min, float max);

	//Функция для получения рандомного числового значения с заданным диапазоном; T min, T max
	template<> double RandNumber(double min, double max);

	//Функция для получения рандомного числового значения с заданным диапазоном; T min, T max
	template<> long double RandNumber(long double min, long double max);

	//Функция для ввода числового значения с заданным диапазоном; T min, T max
	template<typename T>
	T NumberInput(T min, T max)
	{
		T input;
		while (!(std::cin >> input) || input < min || input > max)
		{
			if (!std::cin)
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			std::cerr << "Error! Please re-enter: ";
		}
		return input;
	}

	//Функция для настройки кодировки ввода/вывода консоли
	//int Set_ConsoleCP, int Set_ConsoleOutputCP
	void MyGraphics(int Set_ConsoleCP, int Set_ConsoleOutputCP);

	//Функция для настройки кодировки ввода/вывода консоли и текста цвета текста/фона консоли по модели RGB
	/*int Set_ConsoleCP, int Set_ConsoleOutputCP, int textR, int textG, int textB, int backgroundR, int backgroundG,
	int backgroundB*/
	void MyGraphics(int Set_ConsoleCP, int Set_ConsoleOutputCP, int textR, int textG, int textB, int backgroundR,
		int backgroundG, int backgroundB);
}