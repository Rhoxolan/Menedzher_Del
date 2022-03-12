#include "program_functional.h"
#include "MyHeader.h"
#include "Deed.h"
#include "program_processing.h"
#include <vector>
#include <cstdlib>
#include <iostream>

int main()
{
	namespace ppr = program_processing;
	namespace pf = program_functional;
	using namespace my_header_namespace;

	std::vector<Deed> deal;
	pf::InitialSetup(deal);
	int item{ 0 };
	do
	{
		std::cout << "Пожалуйста, выберите:\n\n1 - Добавить новое дело;\n2 - Удалить дело;\n3 - Отредактировать дело;\n"
			<< "4 - Поиск и сортировка дел;\n5 - Отображение списка дел;\n0 - Выход из программы.\n\n";
		item = NumberInput(0, 5);
		std::system("cls");
		if (item > 4)
		{
			ppr::ListOfDeeds(deal);
		}
		else if (item > 3)
		{
			ppr::SearchNSort(deal);
		}
		else if (item > 2)
		{
			ppr::RedactingTheDeed(deal);
		}
		else if (item > 1)
		{
			ppr::DeedDelete(deal);
		}
		else if (item > 0)
		{
			ppr::AddNewDeed(deal);
		}
	} while (item != 0);
	return 0;
}
