#include "program_functional.h"

//Используется при переходе в главное меню
void program_functional::ExitToMenu()
{
	std::cout << pf::TRIendl << "Нажмите любую клавишу для выхода в главное меню" << TRIendl;
	std::system("pause");
	std::system("cls");
}

//Используется при переходе в предыдущий пункт меню
void program_functional::ExitToSubMenu()
{
	std::cout << pf::TRIendl << "Нажмите любую клавишу для выхода в предыдущий пункт меню" << TRIendl;
	std::system("pause");
	std::system("cls");
}

//Используется как проверка нажатия клавиши выхода
bool program_functional::ExitTo(std::string _string)
{
	if (!_string.empty())
	{
		return _string[0] == '0' && _string.size() == 1;
	}
	return false;
}

//Используется как проверка нажатия клавиши выхода
bool program_functional::ExitTo(int number, int exit_number)
{
	return number == exit_number;
}

//Возвращает текущее время; [0] - year, [1] - month, [2] - day, [3] - hour, [4] - min
std::array<int, 5> program_functional::GetLocalTime()
{
	struct tm _tm;
	time_t now = time(0);
	localtime_s(&_tm, &now);
	return std::array<int, 5> {_tm.tm_year + 1900, _tm.tm_mon + 1, _tm.tm_mday, _tm.tm_hour, _tm.tm_min};
}

//Первоначальная настройка
void program_functional::InitialSetup(std::vector<Deed>& deal)
{
	MyGraphics(1251, 1251, 8, 0, 85, 182, 229, 255);
	if (!fs::exists(pfc::PathToTheFolder().c_str())) //Проверка наличия папки с программными файлами
	{
		fs::create_directory(pfc::PathToTheFolder().c_str()); //Создание папки с программными файлами
	}
	else
	{
		pfc::Loader(deal);
	}
}