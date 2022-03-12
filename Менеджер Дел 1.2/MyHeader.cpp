#include"MyHeader.h"

template<> float my_header_namespace::RandNumber(float min, float max)
{
	static std::mt19937 randgenerator(time(NULL));
	std::uniform_real_distribution<float> randnumber(min, max);
	return randnumber(randgenerator);
}

template<> double my_header_namespace::RandNumber(double min, double max)
{
	static std::mt19937 randgenerator(time(NULL));
	std::uniform_real_distribution<double> randnumber(min, max);
	return randnumber(randgenerator);
}

template<> long double my_header_namespace::RandNumber(long double min, long double max)
{
	static std::mt19937 randgenerator(time(NULL));
	std::uniform_real_distribution<long double> randnumber(min, max);
	return randnumber(randgenerator);
}

void my_header_namespace::MyGraphics(int Set_ConsoleCP, int Set_ConsoleOutputCP)
{
	SetConsoleCP(Set_ConsoleCP); //Example - 1251
	SetConsoleOutputCP(Set_ConsoleOutputCP); //Exmaple - 1251
}

void my_header_namespace::MyGraphics(int Set_ConsoleCP, int Set_ConsoleOutputCP, int textR, int textG, int textB, int backgroundR,
	int backgroundG, int backgroundB)
{
	SetConsoleCP(Set_ConsoleCP); //Example - 1251
	SetConsoleOutputCP(Set_ConsoleOutputCP); //Exmaple - 1251
	CONSOLE_SCREEN_BUFFER_INFOEX colorification;
	colorification.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfoEx(hConsole, &colorification);
	colorification.ColorTable[1] = RGB(textR, textG, textB); //Text color
	colorification.ColorTable[0] = RGB(backgroundR, backgroundG, backgroundB); //Background color
	SetConsoleScreenBufferInfoEx(hConsole, &colorification);
	SetConsoleTextAttribute(hConsole, 1);
}