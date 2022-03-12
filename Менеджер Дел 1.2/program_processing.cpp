#include"program_processing.h"

//Присвоение номера "дела"
std::size_t program_processing::CreateDealNumber(std::vector<Deed>& deal)
{
	for (size_t i = 0; i < deal.size(); i++)
	{
		if (deal[i].GetDealNumber() - 1 != i)
		{
			return i + 1;
		}
	}
	return deal.size() + 1;
}

//Вывод "Дела" на экран
void program_processing::show(Deed& deal)
{
	std::cout << "Дело № " << deal.GetDealNumber() << ":\n";
	if (deal.GetTitle().empty())
	{
		std::cout << "Название: (пусто)" << std::endl;
	}
	else
	{
		std::cout << "Название: " << deal.GetTitle() << std::endl;
	}
	if (deal.GetPriority() > 2)
	{
		std::cout << "Приоритет: низкий" << std::endl;
	}
	else if (deal.GetPriority() > 1)
	{
		std::cout << "Приоритет: высокий" << std::endl;
	}
	else if (deal.GetPriority() > 0)
	{
		std::cout << "Приоритет: очень высокий" << std::endl;
	}
	else if (deal.GetPriority() > -1)
	{
		std::cout << "Приоритет не определен" << std::endl;
	}
	if (deal.GetWriteUp().empty())
	{
		std::cout << "Описание: (пусто)" << std::endl;
	}
	else
	{
		std::cout << "Описание: " << deal.GetWriteUp() << std::endl;
	}
	if (!deal.GetDate().empty())
	{
		std::cout << "Дата выполнения: " << deal.GetDate()[2] << '.' << deal.GetDate()[1] << '.' << deal.GetDate()[0]
			<< std::endl;
	}
	if (!deal.GetTime().empty())
	{
		std::cout << "Время выполнения: " << deal.GetTime()[0] << ':' << deal.GetTime()[1] << std::endl;
	}
}

//Добавление новых дел
void program_processing::AddNewDeed(std::vector<Deed>& deal)
{
	std::cin.ignore();
	if (deal.size() == ppr::size)
	{
		std::cout << "Память переполнена! Пожалуйста, удалите дело - пункт 2 в меню.";
		pf::ExitToMenu();
		return;
	}
	std::string title{}, writeup{};
	int priority{ 0 };
	std::size_t _dealnumber = CreateDealNumber(deal);
	std::cout << "Дело № " << _dealnumber << ":\n"
		<< "Пожалуйста, введите название дела (0 - выход в главное меню): ";
	std::getline(std::cin, title);
	if (pf::ExitTo(title))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите описание (0 - выход в главное меню): ";
	std::getline(std::cin, writeup);
	if (pf::ExitTo(writeup))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите приоритет выполнения (1 - очень высокий, 2 - высокий, 3 - низкий)"
		<< "(4 - выход в главное меню): ";
	priority = NumberInput(0, 4);
	if (pf::ExitTo(priority, 4))
	{
		std::system("cls");
		return;
	}
	std::cout << "Ввести дату и время? 1 - Да, 0 - Нет: ";
	int datechoice = NumberInput(0, 1);
	if (datechoice == 1)
	{
		std::vector<int> _date{};
		std::vector<int> _time{};
		std::cout << "Пожалуйста, введите год выполнения дела (пример - " + std::to_string(pf::GetLocalTime()[0]) + ")"
			<< "(0 - выход в главное меню): ";
		_date.emplace_back(NumberInput(0, 3000));
		if (pf::ExitTo(_date.back(), 0))
		{
			std::system("cls");
			return;
		}
		std::cout << "Пожалуйста, введите месяц выполнения дела цифрами (пример - " + std::to_string(pf::GetLocalTime()[1]) + ")"
			<< "(0 - выход в главное меню): ";
		_date.emplace_back(NumberInput(0, 12));
		if (pf::ExitTo(_date.back(), 0))
		{
			std::system("cls");
			return;
		}
		std::cout << "Пожалуйста, введите день выполнения дела (пример - " + std::to_string(pf::GetLocalTime()[2]) + ")"
			<< "(0 - выход в главное меню): ";
		_date.emplace_back(NumberInput(0, 31));
		if (pf::ExitTo(_date.back(), 0))
		{
			std::system("cls");
			return;
		}
		std::cout << "Пожалуйста, введите время выполнения дела (час, пример - " + std::to_string(pf::GetLocalTime()[3]) + ")"
			<< "(24 - выход в главное меню): ";
		_time.emplace_back(NumberInput(0, 24));
		if (pf::ExitTo(_time.back(), 24))
		{
			std::system("cls");
			return;
		}
		std::cout << "Пожалуйста, введите время выполнения дела (минута, пример - " + std::to_string(pf::GetLocalTime()[4]) + ")"
			<< "(60 - выход в главное меню): ";
		_time.emplace_back(NumberInput(0, 60));
		if (pf::ExitTo(_time.back(), 60))
		{
			std::system("cls");
			return;
		}
		deal.emplace_back(title, writeup, priority, _dealnumber, _date, _time);
		pfc::Saver(deal.back());
		std::sort(deal.begin(), deal.end(), [](auto& left, auto& right) {
			return left.GetDealNumber() < right.GetDealNumber(); });
		std::system("cls");
		return;
	}
	deal.emplace_back(title, writeup, priority, _dealnumber);
	pfc::Saver(deal.back());
	std::sort(deal.begin(), deal.end(), [](auto& left, auto& right) {
		return left.GetDealNumber() < right.GetDealNumber(); });
	std::system("cls");
}

//Отображение списка дел
void program_processing::ListOfDeeds(std::vector<Deed>& deal)
{
	if (deal.empty())
	{
		std::cout << "Дела ещё не созданы! Можете добавить ваше первое дело в 1-м пункте меню!";
		pf::ExitToMenu();
	}
	else
	{
		for (auto& i : deal | std::views::reverse)
		{
			ppr::show(i);
			std::cout << pf::TRIendl;
		}
		pf::ExitToMenu();
	}
}

//Редактирование всего дела
void program_processing::RedactingTheWholeDeed(Deed& deal)
{
	std::cin.ignore();
	ppr::show(deal);
	std::cout << std::endl;
	std::string newtitle{}, newwriteup{};
	int newpriority{ 0 };
	std::cout << "Пожалуйста, введите название дела (0 - выход в предыдущий пункт меню): ";
	std::getline(std::cin, newtitle);
	if (pf::ExitTo(newtitle))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите описание (0 - выход в предыдущий пункт меню): ";
	std::getline(std::cin, newwriteup);
	if (pf::ExitTo(newwriteup))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите приоритет выполнения (1 - очень высокий, 2 - высокий, 3 - низкий)"
		<< "(4 - выход в предыдущий пункт меню): ";
	newpriority = NumberInput(0, 4);
	if (pf::ExitTo(newpriority, 4))
	{
		std::system("cls");
		return;
	}
	std::cout << "Ввести дату и время? 1 - Да, 0 - Нет: ";
	int datechoice = NumberInput(0, 1);
	if (datechoice == 1)
	{
		std::vector<int> newdate{};
		std::vector<int> newtime{};
		std::cout << "Пожалуйста, введите год выполнения дела (пример - " + std::to_string(pf::GetLocalTime()[0]) + ")"
			<< "(0 - выход в предыдущий пункт меню): ";
		newdate.emplace_back(NumberInput(0, 3000));
		if (pf::ExitTo(newdate.back(), 0))
		{
			std::system("cls");
			return;
		}
		std::cout << "Пожалуйста, введите месяц выполнения дела цифрами (пример - " + std::to_string(pf::GetLocalTime()[1]) + ")"
			<< "(0 - выход в предыдущий пункт меню): ";
		newdate.emplace_back(NumberInput(0, 12));
		if (pf::ExitTo(newdate.back(), 0))
		{
			std::system("cls");
			return;
		}
		std::cout << "Пожалуйста, введите день выполнения дела (пример - " + std::to_string(pf::GetLocalTime()[2]) + ")"
			<< "(0 - выход в предыдущий пункт меню): ";
		newdate.emplace_back(NumberInput(0, 31));
		if (pf::ExitTo(newdate.back(), 0))
		{
			std::system("cls");
			return;
		}
		std::cout << "Пожалуйста, введите время выполнения дела (час, пример - " + std::to_string(pf::GetLocalTime()[3]) + ")"
			<< "(24 - выход в предыдущий пункт меню): ";
		newtime.emplace_back(NumberInput(0, 24));
		if (pf::ExitTo(newtime.back(), 24))
		{
			std::system("cls");
			return;
		}
		std::cout << "Пожалуйста, введите время выполнения дела (минута, пример - " + std::to_string(pf::GetLocalTime()[4]) + ")"
			<< "(60 - выход в предыдущий пункт меню): ";
		newtime.emplace_back(NumberInput(0, 60));
		if (pf::ExitTo(newtime.back(), 60))
		{
			std::system("cls");
			return;
		}
		deal.Set(newtitle, newwriteup, newpriority, deal.GetDealNumber(), newdate, newtime);
		pfc::Saver(deal);
		std::system("cls");
		ppr::show(deal);
		std::cout << "\nДело успешно отредактировано!";
		pf::ExitToSubMenu();
		return;
	}
	deal.Set(newtitle, newwriteup, newpriority, deal.GetDealNumber());
	pfc::Saver(deal);
	std::system("cls");
	ppr::show(deal);
	std::cout << "\nДело успешно отредактировано!";
	pf::ExitToSubMenu();
}

//Редактирование даты и времени
void program_processing::RedactingTheTime(Deed& deal)
{
	std::vector<int> newdate{};
	std::vector<int> newtime{};
	ppr::show(deal);
	std::cout << std::endl;
	std::cout << "Пожалуйста, новый введите год выполнения дела (пример - " + std::to_string(pf::GetLocalTime()[0]) + "). "
		<< "Введите код '3001', чтобы удалить дату и время. '0' - выход в главное меню): ";
	newdate.emplace_back(NumberInput(0, 3001));
	if (pf::ExitTo(newdate.back(), 0))
	{
		std::system("cls");
		return;
	}
	if (newdate.back() == 3001)
	{
		deal.SetDate(std::vector<int>());
		deal.SetTime(std::vector<int>());
		pfc::Saver(deal);
		std::system("cls");
		ppr::show(deal);
		std::cout << "\nДело успешно отредактировано!";
		pf::ExitToSubMenu();
		return;
	}
	std::cout << "Пожалуйста, введите новый месяц выполнения дела цифрами (пример - " + std::to_string(pf::GetLocalTime()[1]) + ")"
		<< "(0 - выход в предыдущий пункт меню): ";
	newdate.emplace_back(NumberInput(0, 12));
	if (pf::ExitTo(newdate.back(), 0))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите новый день выполнения дела (пример - " + std::to_string(pf::GetLocalTime()[2]) + ")"
		<< "(0 - выход в предыдущий пункт меню): ";
	newdate.emplace_back(NumberInput(0, 31));
	if (pf::ExitTo(newdate.back(), 0))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите новое время выполнения дела (час, пример - " + std::to_string(pf::GetLocalTime()[3]) + ")"
		<< "(24 - выход в предыдущий пункт меню): ";
	newtime.emplace_back(NumberInput(0, 24));
	if (pf::ExitTo(newtime.back(), 24))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите новое время выполнения дела (минута, пример - " + std::to_string(pf::GetLocalTime()[4]) + ")"
		<< "(60 - выход в предыдущий пункт меню): ";
	newtime.emplace_back(NumberInput(0, 60));
	if (pf::ExitTo(newtime.back(), 60))
	{
		std::system("cls");
		return;
	}
	deal.SetDate(newdate);
	deal.SetTime(newtime);
	pfc::Saver(deal);
	std::system("cls");
	ppr::show(deal);
	std::cout << "\nДело успешно отредактировано!";
	pf::ExitToSubMenu();
}

//Редактирование приоритета
void program_processing::RedactingThePriority(Deed& deal)
{
	ppr::show(deal);
	std::cout << "\nПожалуйста, введите новый приоритет выполнения (1 - очень высокий, 2 - высокий, 3 - низкий)"
		<< "(4 - выход в предыдущий пункт меню): ";
	int newpriority = NumberInput(0, 4);
	if (pf::ExitTo(newpriority, 4))
	{
		std::system("cls");
		return;
	}
	deal.SetPriority(newpriority);
	pfc::Saver(deal);
	std::system("cls");
	ppr::show(deal);
	std::cout << "\nДело успешно отредактировано!";
	pf::ExitToSubMenu();
}

//Редактирование описания
void program_processing::RedactingTheWriteUp(Deed& deal)
{
	std::cin.ignore();
	std::string newwriteup{};
	ppr::show(deal);
	std::cout << "\nПожалуйста, введите новое описание дела (0 - выход в предыдущий пункт меню): ";
	std::getline(std::cin, newwriteup);
	if (pf::ExitTo(newwriteup))
	{
		std::system("cls");
		return;
	}
	deal.SetWriteUp(newwriteup);
	pfc::Saver(deal);
	std::system("cls");
	ppr::show(deal);
	std::cout << "\nДело успешно отредактировано!";
	pf::ExitToSubMenu();
}

//Редактирование названия
void program_processing::RedactingTheTitle(Deed& deal)
{
	std::cin.ignore();
	std::string newtitle{};
	ppr::show(deal);
	std::cout << "\nПожалуйста, введите новое название дела (0 - выход в предыдущий пункт меню): ";
	std::getline(std::cin, newtitle);
	if (pf::ExitTo(newtitle))
	{
		std::system("cls");
		return;
	}
	deal.SetTitle(newtitle);
	pfc::Saver(deal);
	std::system("cls");
	ppr::show(deal);
	std::cout << "\nДело успешно отредактировано!";
	pf::ExitToSubMenu();
}

//Процесс редактирования
void program_processing::RedactionProcess(Deed& deal)
{
	int item{ 0 };
	do
	{
		ppr::show(deal);
		std::cout << "\nПожалуйста, выберите, что хотите отредактировать:\n1 - Название;\n2 - Описание;\n3 - Приоритет;\n"
			<< "4 - Дату и время; \n5 - Всё дело; \n0 - Выйти из редактора\n\n";
		item = NumberInput(0, 5);
		std::system("cls");
		if (item > 4) //Редактирование всего дела
		{
			ppr::RedactingTheWholeDeed(deal);
		}
		else if (item > 3) //Редактирование даты и времени
		{
			ppr::RedactingTheTime(deal);
		}
		else if (item > 2) //Редактирование приоритета
		{
			ppr::RedactingThePriority(deal);
		}
		else if (item > 1) //Редактирование описания
		{
			ppr::RedactingTheWriteUp(deal);
		}
		else if (item > 0) //Редактирование названия
		{
			ppr::RedactingTheTitle(deal);
		}
	} while (item != 0);
}

//Редактирование "дела"
void program_processing::RedactingTheDeed(std::vector<Deed>& deal)
{
	using std::intmax_t, std::size_t;
	intmax_t deededit{ 0 };
	bool checker{ false };
	while (true)
	{
		std::cout << "Пожалуйста, выберите номер дела, которое необходимо отредактировать (проверьте список, "
			<< "если не знаете номер дела - пункт 5 в меню).\nНомер дела (0 - выход в главное меню): ";
		deededit = NumberInput<intmax_t>(intmax_t(0), intmax_t(100));
		std::system("cls");
		if (deededit > 0)
		{
			for (auto& d : deal)
			{
				if (d.GetDealNumber() == static_cast<size_t>(deededit))
				{
					checker = true;
					ppr::RedactionProcess(d);
				}
			}
			if (!checker)
			{
				std::cout << "Такого дела нет!\n";
				pf::ExitToSubMenu();
			}
		}
		else if (deededit > -1)
		{
			return;
		}
	}
}

//Удаление одного "дела"
void program_processing::DeleteOneDeed(std::vector<Deed>& deal)
{
	std::cout << "Пожалуйста, выберите номер дела, которое необходимо удалить (проверьте список, если не"
		<< " знаете номер дела - пункт 5 в меню).\nНомер дела (0 - выход в предыдущий пункт меню): ";
	int remdeal = NumberInput(0, 100);
	std::system("cls");
	if (pf::ExitTo(remdeal, 0))
	{
		std::system("cls");
		return;
	}
	for (size_t i = 0; i < deal.size(); i++)
	{
		if (deal[i].GetDealNumber() == remdeal)
		{
			if (pfc::FileRemover(deal[i]))
			{
				std::cout << "Дело успешно удалено!";
				pf::ExitToSubMenu();
				deal.erase(deal.begin() + i);
				return;
			}
			else
			{
				std::cout << "\n\aОшибка удаления программных файлов! Данные могут удалиться не полностью!";
				pf::ExitToSubMenu();
				deal.erase(deal.begin() + i);
				return;
			}
		}
	}
	std::cout << "Дело не найдено!";
	pf::ExitToSubMenu();
}

//Удаление нескольких "дел"
void program_processing::RemoveSomeDeeds(std::vector<Deed>& deal)
{
	std::vector<int> remdeeds{}; //Массив номеров подлежащих удалению дел
	std::vector<int> deldeeds{}; //Массив номеров удаленных дел
	std::cout << "Пожалуйста, введите номера дел, которые необходимо удалить (проверьте список, если не знаете номера дела"
		<< " - пункт 5 в меню).\nВводите по одному числу, нажимая после каждого числа Enter. '0' - "
		<< "прекратить ввод, '101' - выход в предыдущий пункт меню:\n\n";
	do
	{
		remdeeds.emplace_back(NumberInput(0, 101));
		if (pf::ExitTo(remdeeds.back(), 101))
		{
			std::system("cls");
			return;
		}
		std::cout << "Введите еще одно дело, или нажмите 0: ";
	} while (remdeeds.back() != 0);
	std::system("cls");
	if (remdeeds.size() == 1 && remdeeds.back() == 0)
	{
		return;
	}
	remdeeds.erase(remdeeds.end() - 1);

	auto CheckNum = [&](int num)
	{
		for (auto& r : remdeeds)
		{
			if (r == num)
			{
				return true;
			}
		}
		return false;
	};

	bool checker{ false };
	for (auto it = deal.begin(); it != deal.end(); )
	{
		if (CheckNum(it->GetDealNumber()))
		{
			deldeeds.emplace_back(it->GetDealNumber());
			if (!pfc::FileRemover(*it))
			{
				checker = true;
			}
			it = deal.erase(it);
		}
		else
		{
			++it;
		}
	}
	if (deldeeds.empty())
	{
		std::cout << "Дела не найдены!";
		pf::ExitToSubMenu();
		return;
	}
	if (checker)
	{
		std::cout << "\n\aОшибка удаления программных файлов! Данные могут удалиться не полностью!";
		pf::ExitToSubMenu();
	}
	else
	{
		std::cout << "Успешно удалены следующие дела: ";
		for (auto& d : deldeeds)
		{
			std::cout << d << ' ';
		}
		pf::ExitToSubMenu();
	}
}

//Сортировка по дате
void program_processing::SortByDate(std::vector<Deed>& deal)
{
	if (deal.empty())
	{
		std::cout << "Дел пока-что нет! Вы можете их добавить в пункте 1 в меню.";
		pf::ExitToSubMenu();
		return;
	}
	std::vector<Deed> sort_deal; //Массив для хранения отсортированных дел
	for (auto& d : deal)
	{
		if (!d.GetDate().empty() && !d.GetTime().empty())
		{
			sort_deal.emplace_back(d);
		}
	}
	if (sort_deal.empty())
	{
		std::cout << "Дел c датой выполнения пока-что нет! Вы можете их добавить в пункте 1 в меню.";
		pf::ExitToSubMenu();
		return;
	}
	std::sort(sort_deal.begin(), sort_deal.end(), [](auto& left, auto& right)
		{
			return std::tie(left.GetDate()[0], left.GetDate()[1], left.GetDate()[2])
				< std::tie(right.GetDate()[0], right.GetDate()[1], right.GetDate()[2]);
		});
	for (auto& i : sort_deal | std::views::reverse)
	{
		ppr::show(i);
		std::cout << pf::TRIendl;
	}
	pf::ExitToMenu();
}

//Сортировка по приоритету
void program_processing::SortByPriority(std::vector<Deed>& deal)
{
	bool checker{ false };
	std::cout << "Низкий приоритет:\n\n";
	for (auto& d : deal | std::views::reverse)
	{
		if (d.GetPriority() == 3)
		{
			ppr::show(d);
			checker = true;
			std::cout << pf::TRIendl;
		}
	}
	if (!checker)
	{
		std::cout << "Дела не найдены" << pf::TRIendl;
	}
	checker = false;
	std::cout << "Высокий приоритет:\n\n";
	for (auto& d : deal | std::views::reverse)
	{
		if (d.GetPriority() == 2)
		{
			ppr::show(d);
			checker = true;
			std::cout << pf::TRIendl;
		}
	}
	if (!checker)
	{
		std::cout << "Дела не найдены" << pf::TRIendl;
	}
	checker = false;
	std::cout << "Очень высокий приоритет:\n\n";
	for (auto& d : deal | std::views::reverse)
	{
		if (d.GetPriority() == 1)
		{
			ppr::show(d);
			checker = true;
			std::cout << pf::TRIendl;
		}
	}
	if (!checker)
	{
		std::cout << "Дела не найдены" << pf::TRIendl;
	}
	checker = false;
	pf::ExitToMenu();
}

//Сортировка дел
void program_processing::Sorting(std::vector<Deed>& deal)
{
	int item{ 0 };
	do
	{
		std::cout << "Пожалуйста, выберите:\n\n1 - Сортировка по приоритету;\n2 - Сортировка по дате;"
			<< "\n0 - Выход в предыдущий пункт меню.\n\n";
		item = NumberInput(0, 3);
		std::system("cls");
		if (item > 1) //Сортировка по дате
		{
			ppr::SortByDate(deal);
		}
		else if (item > 0) //Сортировка по приоритету
		{
			ppr::SortByPriority(deal);
		}
	} while (item != 0);
}

//Поиск по минуте
void program_processing::SearchByTheMinute(std::vector<Deed>& deal)
{
	std::cout << "Пожалуйста, введите год выполнения дела (пример - " + std::to_string(pf::GetLocalTime()[0]) + ")"
		<< "(0 - выход в предыдущий пункт меню): ";
	int search_year = NumberInput(0, 3000);
	if (pf::ExitTo(search_year, 0))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите месяц выполнения дела цифрами (пример - " + std::to_string(pf::GetLocalTime()[1]) + ")"
		<< "(0 - выход в предыдущий пункт меню): ";
	int search_month = NumberInput(0, 12);
	if (pf::ExitTo(search_month, 0))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите день выполнения дела (пример - " + std::to_string(pf::GetLocalTime()[2]) + ")"
		<< "(0 - выход в предыдущий пункт меню): ";
	int search_day = NumberInput(0, 31);
	if (pf::ExitTo(search_day, 0))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите время выполнения дела (час, пример - " + std::to_string(pf::GetLocalTime()[3]) + ")"
		<< "(24 - выход в главное меню): ";
	int search_hour = NumberInput(0, 24);
	if (pf::ExitTo(search_hour, 24))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите время выполнения дела (минута, пример - " + std::to_string(pf::GetLocalTime()[4]) + ")"
		<< "(60 - выход в главное меню): ";
	int search_min = NumberInput(0, 60);
	if (pf::ExitTo(search_min, 24))
	{
		std::system("cls");
		return;
	}
	std::system("cls");
	bool checker{ false };
	for (auto& d : deal | std::views::reverse)
	{
		if (d.GetDate()[0] == search_year &&
			d.GetDate()[1] == search_month &&
			d.GetDate()[2] == search_day &&
			d.GetTime()[0] == search_hour &&
			d.GetTime()[1] == search_min)
		{
			ppr::show(d);
			std::cout << pf::TRIendl;
			checker = true;
		}
	}
	if (!checker)
	{
		std::cout << "Дела не найдены";
	}
	pf::ExitToSubMenu();
	system("cls");
}

//Поиск по часу
void program_processing::SearchByTheHour(std::vector<Deed>& deal)
{
	std::cout << "Пожалуйста, введите год выполнения дела (пример - " + std::to_string(pf::GetLocalTime()[0]) + ")"
		<< "(0 - выход в предыдущий пункт меню): ";
	int search_year = NumberInput(0, 3000);
	if (pf::ExitTo(search_year, 0))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите месяц выполнения дела цифрами (пример - " + std::to_string(pf::GetLocalTime()[1]) + ")"
		<< "(0 - выход в предыдущий пункт меню): ";
	int search_month = NumberInput(0, 12);
	if (pf::ExitTo(search_month, 0))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите день выполнения дела (пример - " + std::to_string(pf::GetLocalTime()[2]) + ")"
		<< "(0 - выход в предыдущий пункт меню): ";
	int search_day = NumberInput(0, 31);
	if (pf::ExitTo(search_day, 0))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите время выполнения дела (час, пример - " + std::to_string(pf::GetLocalTime()[3]) + ")"
		<< "(24 - выход в главное меню): ";
	int search_hour = NumberInput(0, 24);
	if (pf::ExitTo(search_hour, 24))
	{
		std::system("cls");
		return;
	}
	std::system("cls");
	bool checker{ false };
	for (auto& d : deal | std::views::reverse)
	{
		if (d.GetDate()[0] == search_year &&
			d.GetDate()[1] == search_month &&
			d.GetDate()[2] == search_day &&
			d.GetTime()[0] == search_hour)
		{
			ppr::show(d);
			std::cout << pf::TRIendl;
			checker = true;
		}
	}
	if (!checker)
	{
		std::cout << "Дела не найдены";
	}
	pf::ExitToSubMenu();
	system("cls");
}

//Поиск по дню
void program_processing::SearchByTheDay(std::vector<Deed>& deal)
{
	std::cout << "Пожалуйста, введите год выполнения дела (пример - " + std::to_string(pf::GetLocalTime()[0]) + ")"
		<< "(0 - выход в предыдущий пункт меню): ";
	int search_year = NumberInput(0, 3000);
	if (pf::ExitTo(search_year, 0))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите месяц выполнения дела цифрами (пример - " + std::to_string(pf::GetLocalTime()[1]) + ")"
		<< "(0 - выход в предыдущий пункт меню): ";
	int search_month = NumberInput(0, 12);
	if (pf::ExitTo(search_month, 0))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите день выполнения дела (пример - " + std::to_string(pf::GetLocalTime()[2]) + ")"
		<< "(0 - выход в предыдущий пункт меню): ";
	int search_day = NumberInput(0, 31);
	if (pf::ExitTo(search_day, 0))
	{
		std::system("cls");
		return;
	}
	std::system("cls");
	bool checker{ false };
	for (auto& d : deal | std::views::reverse)
	{
		if (d.GetDate()[0] == search_year &&
			d.GetDate()[1] == search_month &&
			d.GetDate()[2] == search_day)
		{
			ppr::show(d);
			std::cout << pf::TRIendl;
			checker = true;
		}
	}
	if (!checker)
	{
		std::cout << "Дела не найдены";
	}
	pf::ExitToSubMenu();
	system("cls");
}

//Поиск по месяцу
void program_processing::SearchByTheMonth(std::vector<Deed>& deal)
{
	std::cout << "Пожалуйста, введите год выполнения дела (пример - " + std::to_string(pf::GetLocalTime()[0]) + ")"
		<< "(0 - выход в предыдущий пункт меню): ";
	int search_year = NumberInput(0, 3000);
	if (pf::ExitTo(search_year, 0))
	{
		std::system("cls");
		return;
	}
	std::cout << "Пожалуйста, введите месяц выполнения дела цифрами (пример - " + std::to_string(pf::GetLocalTime()[1]) + ")"
		<< "(0 - выход в предыдущий пункт меню): ";
	int search_month = NumberInput(0, 12);
	if (pf::ExitTo(search_month, 0))
	{
		std::system("cls");
		return;
	}
	std::system("cls");
	bool checker{ false };
	for (auto& d : deal | std::views::reverse)
	{
		if (d.GetDate()[0] == search_year &&
			d.GetDate()[1] == search_month)
		{
			ppr::show(d);
			std::cout << pf::TRIendl;
			checker = true;
		}
	}
	if (!checker)
	{
		std::cout << "Дела не найдены";
	}
	pf::ExitToSubMenu();
	system("cls");
}

//Поиск по году
void program_processing::SearchByTheYear(std::vector<Deed>& deal)
{
	std::cout << "Пожалуйста, введите год выполнения дела (пример - " + std::to_string(pf::GetLocalTime()[0]) + ")"
		<< "(0 - выход в предыдущий пункт меню): ";
	int search_year = NumberInput(0, 3000);
	if (pf::ExitTo(search_year, 0))
	{
		std::system("cls");
		return;
	}
	std::system("cls");
	bool checker{ false };
	for (auto& d : deal | std::views::reverse)
	{
		if (d.GetDate()[0] == search_year)
		{
			ppr::show(d);
			std::cout << pf::TRIendl;
			checker = true;
		}
	}
	if (!checker)
	{
		std::cout << "Дела не найдены";
	}
	pf::ExitToSubMenu();
	system("cls");
}

//Поиск по описанию
void program_processing::SearchByTheWriteUp(std::vector<Deed>& deal)
{
	std::cin.ignore();
	std::string writeup{};
	std::wstring::size_type n{};
	std::cout << "Пожалуйста, введите слово из описания или описание целиком (0 - выход в главное меню): ";
	std::getline(std::cin, writeup);
	if (pf::ExitTo(writeup))
	{
		std::system("cls");
		return;
	}
	std::system("cls");
	bool checker{ false };
	for (auto& d : deal | std::views::reverse)
	{
		n = d.GetWriteUp().find(writeup);
		if (n != std::string::npos)
		{
			ppr::show(d);
			checker = true;
			std::cout << pf::TRIendl;
		}
	}
	if (!checker)
	{
		std::cout << "Дела не найдены";
	}
	pf::ExitToSubMenu();
	system("cls");
}

//Поиск по приоритету
void program_processing::SearchByThePriority(std::vector<Deed>& deal)
{
	std::cout << "Пожалуйста, введите приоритет (1 - очень высокий, 2 - высокий, 3 - низкий)"
		<< "(0 - выход в предыдущий пункт меню): ";
	int search_pr = NumberInput(0, 3);
	if (pf::ExitTo(search_pr, 0))
	{
		std::system("cls");
		return;
	}
	std::system("cls");
	bool checker{ false };
	for (auto& d : deal | std::views::reverse)
	{
		if (d.GetPriority() == search_pr)
		{
			ppr::show(d);
			std::cout << pf::TRIendl;
			checker = true;
		}
	}
	if (!checker)
	{
		std::cout << "Дела не найдены";
	}
	pf::ExitToSubMenu();
	system("cls");
}

//Поиск по названию
void program_processing::SearchByTheTitle(std::vector<Deed>& deal)
{
	std::cin.ignore();
	std::string title{};
	std::wstring::size_type n{};
	std::cout << "Пожалуйста, введите слово из названия или название целиком (0 - выход в главное меню): ";
	std::getline(std::cin, title);
	if (pf::ExitTo(title))
	{
		std::system("cls");
		return;
	}
	std::system("cls");
	bool checker{ false };
	for (auto& d : deal | std::views::reverse)
	{
		n = d.GetTitle().find(title);
		if (n != std::string::npos)
		{
			ppr::show(d);
			checker = true;
			std::cout << pf::TRIendl;
		}
	}
	if (!checker)
	{
		std::cout << "Дела не найдены";
	}
	pf::ExitToSubMenu();
	system("cls");
}

//Поиск "дел"
void program_processing::Searching(std::vector<Deed>& deal)
{
	int item{ 0 };
	do
	{
		std::cout << "Пожалуйста, выберите:\n\n1 - Найти дела по названию;\n2 - Найти дела по приоритету;\n"
			<< "3 - Найти дела по описанию;\n4 - Найти дела по году;\n5 - Найти дела по месяцу;\n6 - Найти дела по дню;\n"
			<< "7 - Найти дела по часу; \n8 - Найти дела по минуте; \n0 - Выход в предыдущий пункт меню.\n\n";
		item = NumberInput(0, 8);
		std::system("cls");
		if (item > 7) //Поиск по минуте
		{
			ppr::SearchByTheMinute(deal);
		}
		else if (item > 6) //Поиск по часу
		{
			ppr::SearchByTheHour(deal);
		}
		else if (item > 5) //Поиск по дню
		{
			ppr::SearchByTheDay(deal);
		}
		else if (item > 4) //Поиск по месяцу
		{
			ppr::SearchByTheMonth(deal);
		}
		else if (item > 3) //Поиск по году
		{
			ppr::SearchByTheYear(deal);
		}
		else if (item > 2) //Поиск по описанию
		{
			ppr::SearchByTheWriteUp(deal);
		}
		else if (item > 1) //Поиск по приоритету
		{
			ppr::SearchByThePriority(deal);
		}
		else if (item > 0) //Поиск по названию
		{
			ppr::SearchByTheTitle(deal);
		}
	} while (item != 0);
}

//Поиск и стртировка "дел"
void program_processing::SearchNSort(std::vector<Deed>& deal)
{
	int item{ 0 };
	do
	{
		std::cout << "Пожалуйста, выберите:\n\n1 - Поиск дел;\n2 - Сортировка дел;\n0 - Выход в главное меню.\n\n";
		item = NumberInput(0, 2);
		std::system("cls");
		if (item > 1) //Сортировка
		{
			ppr::Sorting(deal);
		}
		else if (item > 0) //Поиск
		{
			ppr::Searching(deal);
		}
	} while (item != 0);
}

//Удаление всех "дел"
void program_processing::AllDeedDelete(std::vector<Deed>& deal)
{
	if (deal.empty())
	{
		std::cout << "Память пуста!";
		pf::ExitToSubMenu();
		return;
	}
	std::cout << "Вы точно хотите это сделать?\n\n1 - Да\n0 - нет\n\n";
	int choice = NumberInput(0, 1);
	std::system("cls");
	bool checker{ false };
	if (choice == 1)
	{
		for (auto& d : deal)
		{
			if (!pfc::FileRemover(d))
			{
				checker = true;
			}
		}
		if (checker)
		{
			deal.clear();
			std::cout << "\n\aОшибка удаления программных файлов! Данные могут удалиться не полностью!";
			pf::ExitToSubMenu();
			return;
		}
		deal.clear();
		std::cout << "Память полностью очищена!";
		pf::ExitToSubMenu();
		return;
	}
}

//Удаление "дела"/"дел"
void program_processing::DeedDelete(std::vector<Deed>& deal)
{
	int item{ 0 };
	do
	{
		std::cout << "Пожалуйста, выберите:\n\n1 - Удалить все дела;\n2 - Удалить одно дело;\n3 - Удалить несколько дел;"
			<< "\n0 - Выход в главное меню.\n\n";
		item = NumberInput(0, 3);
		std::system("cls");
		if (item > 2) //Удаление нескольких дел
		{
			ppr::RemoveSomeDeeds(deal);
		}
		else if (item > 1) //Удаление одного дела
		{
			ppr::DeleteOneDeed(deal);
		}
		else if (item > 0) //Удаление всех дел
		{
			ppr::AllDeedDelete(deal);
		}
	} while (item != 0);
}