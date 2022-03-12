#pragma once
#include "Deed.h"
#include <string>
#include <ShlObj.h>
#include <KnownFolders.h>
#include <fstream>
#include <cstdint>
#include <cstdlib>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <iostream>

namespace program_filesystem_functional
{
	namespace pfc = program_filesystem_functional;
	namespace fs = std::filesystem;
	using namespace my_header_namespace;

	//Возвращает путь к папке для хранения данных приложения
	std::wstring PathToTheFolder();

	//Шифрование строкового значения
	std::string Encryption(std::string _string);

	//Дешифрование строкового значения
	std::string Decryption(std::string _string);

	//Сохранение данных "дела"
	void Saver(Deed& deal);

	//Загрузка данных с программной папки
	void Loader(std::vector<Deed>& deal);

	//Удаление указанного "дела" с программных файлов
	bool FileRemover(Deed& deal);
}
