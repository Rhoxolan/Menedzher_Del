#pragma once
#include "MyHeader.h"
#include "Deed.h"
#include "program_functional.h"
#include <string>
#include <iostream>
#include <array>
#include <vector>
#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <ranges>
#include <algorithm>
#include <tuple>

namespace program_processing
{
	namespace ppr = program_processing;
	namespace pf = program_functional;
	namespace pfc = program_filesystem_functional;
	using namespace my_header_namespace;

	constexpr auto size = 100;

	//Присвоение номера "дела"
	std::size_t CreateDealNumber(std::vector<Deed>& deal);

	//Вывод "Дела" на экран
	void show(Deed& deal);

	//Добавление новых дел
	void AddNewDeed(std::vector<Deed>& deal);

	//Отображение списка дел
	void ListOfDeeds(std::vector<Deed>& deal);

	//Редактирование всего дела
	void RedactingTheWholeDeed(Deed& deal);

	//Редактирование даты и времени
	void RedactingTheTime(Deed& deal);

	//Редактирование приоритета
	void RedactingThePriority(Deed& deal);

	//Редактирование описания
	void RedactingTheWriteUp(Deed& deal);

	//Редактирование названия
	void RedactingTheTitle(Deed& deal);

	//Процесс редактирования
	void RedactionProcess(Deed& deal);

	//Редактирование "дела"
	void RedactingTheDeed(std::vector<Deed>& deal);

	//Удаление одного "дела"
	void DeleteOneDeed(std::vector<Deed>& deal);

	//Удаление нескольких "дел"
	void RemoveSomeDeeds(std::vector<Deed>& deal);

	//Сортировка по дате
	void SortByDate(std::vector<Deed>& deal);

	//Сортировка по приоритету
	void SortByPriority(std::vector<Deed>& deal);

	//Сортировка дел
	void Sorting(std::vector<Deed>& deal);

	//Поиск по минуте
	void SearchByTheMinute(std::vector<Deed>& deal);

	//Поиск по часу
	void SearchByTheHour(std::vector<Deed>& deal);

	//Поиск по дню
	void SearchByTheDay(std::vector<Deed>& deal);

	//Поиск по месяцу
	void SearchByTheMonth(std::vector<Deed>& deal);

	//Поиск по году
	void SearchByTheYear(std::vector<Deed>& deal);

	//Поиск по описанию
	void SearchByTheWriteUp(std::vector<Deed>& deal);

	//Поиск по приоритету
	void SearchByThePriority(std::vector<Deed>& deal);

	//Поиск по названию
	void SearchByTheTitle(std::vector<Deed>& deal);

	//Поиск "дел"
	void Searching(std::vector<Deed>& deal);

	//Поиск и стртировка "дел"
	void SearchNSort(std::vector<Deed>& deal);

	//Удаление всех "дел"
	void AllDeedDelete(std::vector<Deed>& deal);

	//Удаление "дела"/"дел"
	void DeedDelete(std::vector<Deed>& deal);
}
