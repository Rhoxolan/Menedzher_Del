#include "program_filesystem_functional.h"

//Возвращает путь к папке для хранения данных приложения
std::wstring program_filesystem_functional::PathToTheFolder()
{
	PWSTR path = NULL;
	HRESULT pathres = SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &path); //Определение пути к папке "Документы"
	std::wstring pathtothefolder(path);
	return pathtothefolder += L"/Программные файлы приложения Менеджер Дел";
}

//Шифрование строкового значения
std::string program_filesystem_functional::Encryption(std::string _string)
{
	for (size_t i = 0; i < _string.length(); i++)
	{
		_string[i] += i;
	}
	return _string;
}

//Дешифрование строкового значения
std::string program_filesystem_functional::Decryption(std::string _string)
{
	for (size_t i = 0; i < _string.length(); i++)
	{
		_string[i] -= i;
	}
	return _string;
}

//Сохранение данных "дела"
void program_filesystem_functional::Saver(Deed& deal)
{
	std::ofstream ofstr;
	std::wstring filename{};
	filename = pfc::PathToTheFolder() + L"/deed" + std::to_wstring(deal.GetDealNumber()) + L".mddeed";
	ofstr.open(filename);
	if (!ofstr.is_open())
	{
		std::cout << "\n\aОшибка записи программных файлов! Данные могут не сохраниться! "
			<< "Нажмите любую клавишу, чтобы продолжить\n";
		std::system("pause");
	}
	else
	{
		ofstr << pfc::Encryption(deal.GetTitle()) << std::endl
			<< pfc::Encryption(std::to_string(deal.GetPriority())) << std::endl
			<< pfc::Encryption(deal.GetWriteUp()) << std::endl
			<< pfc::Encryption(std::to_string(deal.GetDealNumber())) << std::endl;
		if (!deal.GetDate().empty() && !deal.GetTime().empty())
		{
			ofstr << pfc::Encryption(std::to_string(deal.GetDate()[0])) << std::endl
				<< pfc::Encryption(std::to_string(deal.GetDate()[1])) << std::endl
				<< pfc::Encryption(std::to_string(deal.GetDate()[2])) << std::endl
				<< pfc::Encryption(std::to_string(deal.GetTime()[0])) << std::endl
				<< pfc::Encryption(std::to_string(deal.GetTime()[1])) << std::endl;
		}
	}
	ofstr.close();
}

//Загрузка данных с программной папки
void program_filesystem_functional::Loader(std::vector<Deed>& deal)
{
	std::string title{}, writeup{}, priority{}, dealnumber{};
	std::vector<std::string> date;
	std::vector<std::string> time;
	std::ifstream ifstr;
	std::wstring::size_type n;
	std::wstring::size_type n2;
	std::wstring path;
	for (const auto& i : fs::directory_iterator(pfc::PathToTheFolder()))
	{
		path = i.path();
		n = path.find(L"deed"); // Проверка на соответствие названия файла
		n2 = path.find(L".mddeed"); // и формата
		if (n != std::wstring::npos && n2 != std::wstring::npos)
		{
			title.clear();
			writeup.clear();
			priority.clear();
			dealnumber.clear();
			date.clear();
			time.clear();
			ifstr.open(i);
			if (ifstr.is_open())
			{
				std::getline(ifstr, title);
				std::getline(ifstr, priority);
				std::getline(ifstr, writeup);
				std::getline(ifstr, dealnumber);
				std::getline(ifstr, date.emplace_back());
				std::getline(ifstr, date.emplace_back());
				std::getline(ifstr, date.emplace_back());
				std::getline(ifstr, time.emplace_back());
				std::getline(ifstr, time.emplace_back());
			}
			ifstr.close();
			if (!date[2].empty() && !time[1].empty())
			{
				deal.emplace_back(pfc::Decryption(title),
					pfc::Decryption(writeup),
					std::stoi(pfc::Decryption(priority)),
					static_cast<std::size_t>(std::stoi(pfc::Decryption(dealnumber))),
					std::vector{ std::stoi(pfc::Decryption(date[0])), std::stoi(pfc::Decryption(date[1])),
					std::stoi(pfc::Decryption(date[2])) },
					std::vector{ std::stoi(pfc::Decryption(time[0])), std::stoi(pfc::Decryption(time[1])) });
			}
			else
			{
				deal.emplace_back(pfc::Decryption(title),
					pfc::Decryption(writeup),
					std::stoi(pfc::Decryption(priority)),
					static_cast<std::size_t>(std::stoi(pfc::Decryption(dealnumber))));
			}
		}
		std::sort(deal.begin(), deal.end(), [](auto& left, auto& right) {
			return left.GetDealNumber() < right.GetDealNumber(); });
	}
}

//Удаление указанного "дела" с программных файлов
bool program_filesystem_functional::FileRemover(Deed& deal)
{
	std::wstring path{ pfc::PathToTheFolder() + L"/deed" + std::to_wstring(deal.GetDealNumber()) + L".mddeed" };
	if (fs::remove(path))
	{
		return true;
	}
	else
	{
		return false;
	}
}