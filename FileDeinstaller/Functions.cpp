#include "Functions.h"

std::wstring PathToTheFolder()
{
	PWSTR path = NULL;
	HRESULT pathres = SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &path); // Определение пути к папке "Документы"
	std::wstring pathtothefolder(path);
	return pathtothefolder += L"/Программные файлы приложения Менеджер Дел";
}

void Remover()
{
	namespace fs = std::filesystem;

	std::wstring::size_type n, n2;
	std::wstring path;
	for (const auto& i : fs::directory_iterator(PathToTheFolder()))
	{
		path = i.path();
		n = path.find(L"deed");  // Проверка на соответствие названия файла
		n2 = path.find(L".mddeed"); // и формата
		if (n != std::wstring::npos && n2 != std::wstring::npos)
		{
			fs::remove(path);
		}
	}
}

bool Answer()
{
	std::string answer{};
	if (!(std::getline(std::cin, answer)) || !((answer[0] == 'Y' && answer.size() == 1) ||
		(answer[0] == 'y' && answer.size() == 1) || (answer[0] == 'N' && answer.size() == 1) ||
		(answer[0] == 'n' && answer.size() == 1)))
	{
		do
		{
			std::cout << TRIendl << "Вы ввели неверное значение! Пожалуйста, повторите ввод:\n";
			std::cin.clear();
			answer.clear();
			std::getline(std::cin, answer);
		} while (!((answer[0] == 'Y' && answer.size() == 1) || (answer[0] == 'y' && answer.size() == 1) ||
			(answer[0] == 'N' && answer.size() == 1) || (answer[0] == 'n' && answer.size() == 1)));
	}
	if (answer[0] == 'Y' || answer[0] == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ToDo()
{
	using namespace my_header_namespace;

	MyGraphics(1251, 1251);
	std::cout << "\aУдалить все программные файлы и сохранённую историю пользователей? Отменить это решение будет "
		<< "невозможно.\n\nY - Удалить\nN - Не удалять\n\n";
	if (Answer())
	{
		Remover();
	}
}