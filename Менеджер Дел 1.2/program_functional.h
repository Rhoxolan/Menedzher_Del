#pragma once
#include "MyHeader.h"
#include "program_filesystem_functional.h"
#include "Deed.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <array>
#include <filesystem>

namespace program_functional
{
	namespace pf = program_functional;
	namespace pfc = program_filesystem_functional;
	namespace fs = std::filesystem;
	using namespace my_header_namespace;

	constexpr auto TRIendl = "\n\n\n";

	//Используется при переходе в главное меню
	void ExitToMenu();

	//Используется при переходе в предыдущий пункт меню
	void ExitToSubMenu();

	//Используется как проверка нажатия клавиши выхода
	bool ExitTo(std::string _string);

	//Используется как проверка нажатия клавиши выхода
	bool ExitTo(int number, int exit_number);

	//Возвращает текущее время; [0] - year, [1] - month, [2] - day, [3] - hour, [4] - min
	std::array<int, 5> GetLocalTime();

	//Первоначальная настройка
	void InitialSetup(std::vector<Deed>& deal);
}
