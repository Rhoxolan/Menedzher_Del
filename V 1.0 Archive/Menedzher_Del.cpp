#include<iostream>
#include<windows.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<tuple>
#include<fstream>
#include<cstdio>
using namespace std;
constexpr auto TRIendl = "\n\n\n";

struct deed
{
	char title[100];
	unsigned short priority;
	char writeup[1000];
	short date[3];
	short time[2];
	short dealnumber;
};

short NumberInput(short min, short max)
{
	//Ввод числового значения с заданным диапазоном
	short input;
	while (!(cin >> input) || input < min || input > max)
	{
		if (!cin)
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "Вы ввели недопустимое значение. Пожалуйста, повторите ввод: ";
	}
	return input;
}

void show(deed* deal, short number)
{
	//Вывод "дела" на экран
	if (deal[number].title[0] != '\0')
	{
		cout << "Название: " << deal[number].title << endl;
	}
	else
	{
		cout << "Название: (пусто)" << endl;
	}
	if (deal[number].priority > 3)
	{
		cout << "Приоритет не определен" << endl;
	}
	else if (deal[number].priority > 2)
	{
		cout << "Приоритет: низкий" << endl;
	}
	else if (deal[number].priority > 1)
	{
		cout << "Приоритет: высокий" << endl;
	}
	else if (deal[number].priority > 0)
	{
		cout << "Приоритет: очень высокий" << endl;
	}
	else if (deal[number].priority == 0)
	{
		cout << "Приоритет не определен" << endl;
	}
	if (deal[number].writeup[0] != '\0')
	{
		cout << "Описание: " << deal[number].writeup << endl;
	}
	else
	{
		cout << "Описание: (пусто)" << endl;
	}
	if (deal[number].date[2] != 0)
	{
		cout << "Дата выполнения: " << deal[number].date[0] << '.' << deal[number].date[1] << '.' << deal[number].date[2] << endl;
		cout << "Время выполнения: " << deal[number].time[1] << ':' << deal[number].time[0] << endl;
	}
}

void getin(deed* deal, short number, string* myfile_title, string* myfile_writeup, string* myfile_priority, string** myfile_date, string** myfile_time, string* myfile_dealnumber)
{
	//Ввод данных в "дело"
	ofstream deedout;
	cout << "Пожалуйста, введите название дела: ";
	cin.ignore();
	gets_s(deal[number].title);
	deedout.open(myfile_title[number]);
	if (!deedout.is_open())
	{
		cout << "Ошибка открытия программного файла! Данные могут не сохранится. Нажмите любую клавишу для продолжения.";
		system("pause");
	}
	else
	{
		deedout << deal[number].title;
		deedout.close();
	}
	cout << "Пожалуйста, введите описание: ";
	gets_s(deal[number].writeup);
	deedout.open(myfile_writeup[number]);
	if (!deedout.is_open())
	{
		cout << "Ошибка открытия программного файла! Данные могут не сохранится. Нажмите любую клавишу для продолжения.";
		system("pause");
	}
	else
	{
		deedout << deal[number].writeup;
		deedout.close();
	}
	cout << "Пожалуйста, введите приоритет выполнения (1 - очень высокий, 2 - высокий, 3 - низкий): ";
	deal[number].priority = NumberInput(0, 4);
	deedout.open(myfile_priority[number]);
	if (!deedout.is_open())
	{
		cout << "Ошибка открытия программного файла! Данные могут не сохранится. Нажмите любую клавишу для продолжения.";
		system("pause");
	}
	else
	{
		deedout << deal[number].priority;
		deedout.close();
	}
	cout << "Ввести дату и время? 1 - Да, 0 - Нет: ";
	short datechoice;
	datechoice = NumberInput(0, 1);
	if (datechoice == 1)
	{
		cout << "Пожалуйста, введите год выполнения дела (пример - 2021): ";
		deal[number].date[2] = NumberInput(1, 3000);
		deedout.open(myfile_date[number][2]);
		if (!deedout.is_open())
		{
			cout << "Ошибка открытия программного файла! Данные могут не сохраниться. Нажмите любую клавишу для продолжения.";
			system("pause");
		}
		else
		{
			deedout << deal[number].date[2];
			deedout.close();
		}
		cout << "Пожалуйста, введите месяц выполнения дела цифрами (пример - 04): ";
		deal[number].date[1] = NumberInput(1, 12);
		deedout.open(myfile_date[number][1]);
		if (!deedout.is_open())
		{
			cout << "Ошибка открытия программного файла! Данные могут не сохраниться. Нажмите любую клавишу для продолжения.";
			system("pause");
		}
		else
		{
			deedout << deal[number].date[1];
			deedout.close();
		}
		cout << "Пожалуйста, введите день выполнения дела (пример - 26): ";
		deal[number].date[0] = NumberInput(1, 31);
		deedout.open(myfile_date[number][0]);
		if (!deedout.is_open())
		{
			cout << "Ошибка открытия программного файла! Данные могут не сохраниться. Нажмите любую клавишу для продолжения.";
			system("pause");
		}
		else
		{
			deedout << deal[number].date[0];
			deedout.close();
		}
		cout << "Пожалуйста, введите время выполнения дела (час, пример - 10): ";
		deal[number].time[1] = NumberInput(0, 23);
		deedout.open(myfile_time[number][1]);
		if (!deedout.is_open())
		{
			cout << "Ошибка открытия программного файла! Данные могут не сохраниться. Нажмите любую клавишу для продолжения.";
			system("pause");
		}
		else
		{
			deedout << deal[number].time[1];
			deedout.close();
		}
		cout << "Пожалуйста, введите время выполнения дела (минута, пример - 10): ";
		deal[number].time[0] = NumberInput(0, 59);
		deedout.open(myfile_time[number][0]);
		if (!deedout.is_open())
		{
			cout << "Ошибка открытия программного файла! Данные могут не сохраниться. Нажмите любую клавишу для продолжения.";
			system("pause");
		}
		else
		{
			deedout << deal[number].time[0];
			deedout.close();
		}
	}
	else
	{
		deal[number].date[2] = 0;
		deedout.open(myfile_date[number][2]);
		deedout << deal[number].date[2];
		deedout.close();
		deal[number].date[1] = 0;
		deedout.open(myfile_date[number][1]);
		deedout << deal[number].date[1];
		deedout.close();
		deal[number].date[0] = 0;
		deedout.open(myfile_date[number][0]);
		deedout << deal[number].date[0];
		deedout.close();
		deal[number].time[1] = 0;
		deedout.open(myfile_time[number][1]);
		deedout << deal[number].time[1];
		deedout.close();
		deal[number].time[0] = 0;
		deedout.open(myfile_time[number][0]);
		deedout << deal[number].time[0];
		deedout.close();
	}
}

void ExitToMenu()
{
	//Используется при переходе в главное меню
	cout << TRIendl << "Нажмите любую клавишу для выхода в главное меню" << TRIendl;
	system("pause");
	system("cls");
}

void ExitToSubMenu()
{
	//Используется при переходе в предыдущий пункт меню
	cout << TRIendl << "Нажмите любую клавишу для выхода в предыдущий пункт меню" << TRIendl;
	system("pause");
	system("cls");
}

void AddNewDeed(bool* numid, short number, deed* deal, string* myfile_title, string* myfile_writeup, string* myfile_priority, string** myfile_date, string** myfile_time, string* myfile_dealnumber)
{
	//Добавление новых дел
	ofstream deedout;
	bool overf = true;
	for (short c = 0; c <= 99; c++)
		if (numid[c] != true)
		{
			overf = false;
			break;
		}
	if (overf == true)
	{
		cout << "Память переполнена! Пожалуйста, удалите дело - пункт 2 в меню.";
		ExitToMenu();
	}
	else
	{
		short x = 0;
		do
		{
			if (numid[x] == false)
			{
				number = x;
				cout << "Дело №" << x + 1 << ":\n";
				getin(deal, number, myfile_title, myfile_writeup, myfile_priority, myfile_date, myfile_time, myfile_dealnumber);
				deal[x].dealnumber = x;
				deedout.open(myfile_dealnumber[x]);
				if (!deedout.is_open())
				{
					cout << "Ошибка открытия программного файла! Данные могут не сохранится. Нажмите любую клавишу для продолжения.";
					system("pause");
				}
				else
				{
					deedout << deal[x].dealnumber;
					deedout.close();
				}
				numid[x] = true;
				x = 0;
				ExitToMenu();
			}
			else
			{
				x++;
			}
		} while (x != 0);
	}
}

void DeedDelete(bool* numid, string* myfile_title, string* myfile_writeup, string* myfile_priority, string** myfile_date, string** myfile_time, string* myfile_dealnumber)
{
	//Удаление дел
	short remdeal;
	do
	{
		cout << "Пожалуйста, выберите:\n\n1 - Удалить все дела;\n2 - Удалить одно дело;\n3 - Удалить несколько дел;\n0 - Выход в главное меню.\n\n";
		remdeal = NumberInput(0, 3);
		system("cls");
		/*удаление нескольких дел*/if (remdeal > 2)
		{
			short* hidefewdeeds = new short[100];
			short hideid = -1;
			cout << "Пожалуйста, введите номера дел, которые необходимо удалить (проверьте список, если не знаете номера дела - пункт 5 в меню).\n";
			cout << "Вводите по одному числу, нажимая после каждого числа Enter. 0 - прекратить ввод или выйти в предыдущий пункт меню:\n\n";
			do
			{
				hideid++;
				hidefewdeeds[hideid] = NumberInput(0, 100);
				cout << "Введите еще одно дело, или нажмите 0: ";
			} while (hidefewdeeds[hideid] != 0);
			system("cls");
			if (hidefewdeeds[0] != 0)
			{
				bool showhide = false;
				for (short r = 0; r <= 99; r++)
				{
					if (numid[hidefewdeeds[r] - 1] == true)
					{
						showhide = true;
					}
				}
				if (showhide == true)
				{
					cout << "Дела успешно удалены!";
					for (short e = 0; e <= hideid - 1; e++)
					{
						numid[hidefewdeeds[e] - 1] = false;
						remove(myfile_title[hidefewdeeds[e] - 1].c_str());
						remove(myfile_writeup[hidefewdeeds[e] - 1].c_str());
						remove(myfile_priority[hidefewdeeds[e] - 1].c_str());
						remove(myfile_date[hidefewdeeds[e] - 1][2].c_str());
						remove(myfile_date[hidefewdeeds[e] - 1][1].c_str());
						remove(myfile_date[hidefewdeeds[e] - 1][0].c_str());
						remove(myfile_time[hidefewdeeds[e] - 1][1].c_str());
						remove(myfile_time[hidefewdeeds[e] - 1][0].c_str());
						remove(myfile_dealnumber[hidefewdeeds[e] - 1].c_str());
					}
				}
				else
				{
					cout << "Дела не найдены!";
				}
				ExitToSubMenu();
			}
			delete[] hidefewdeeds;
		}
		/*удаление одного дела*/else if (remdeal > 1)
		{
			cout << "Пожалуйста, выберите номер дела, которое необходимо удалить (проверьте список, если не знаете номер дела - пункт 5 в меню).\n";
			cout << "Номер дела (0 - выход в предыдущий пункт меню): ";
			short hidedeal;
			hidedeal = NumberInput(0, 101);
			system("cls");
			while (hidedeal != 0)
			{
				if (hidedeal > 100)
				{
					cout << "Такого дела нет!\n";
					hidedeal = 0;
					ExitToSubMenu();
				}
				else
				{
					if (numid[hidedeal - 1] == true)
					{
						numid[hidedeal - 1] = false;
						remove(myfile_title[hidedeal - 1].c_str());
						remove(myfile_writeup[hidedeal - 1].c_str());
						remove(myfile_priority[hidedeal - 1].c_str());
						remove(myfile_date[hidedeal - 1][2].c_str());
						remove(myfile_date[hidedeal - 1][1].c_str());
						remove(myfile_date[hidedeal - 1][0].c_str());
						remove(myfile_time[hidedeal - 1][1].c_str());
						remove(myfile_time[hidedeal - 1][0].c_str());
						remove(myfile_dealnumber[hidedeal - 1].c_str());
						cout << "Дело успешно удалено!";
						hidedeal = 0;
						ExitToSubMenu();
					}
					else
					{
						cout << "Такого дела нет!\n";
						hidedeal = 0;
						ExitToSubMenu();
					}
				}
			}
		}
		/*удаление всех дел*/else if (remdeal > 0)
		{
			bool lackof = false;
			for (short f = 0; f <= 99; f++)
				if (numid[f] != false)
				{
					lackof = true;
					break;
				}
			if (lackof == false)
			{
				cout << "Память пуста!";
				ExitToSubMenu();
			}
			else
			{
				short choice;
				cout << "Вы точно хотите это сделать?\n\n1 - Да\n0 - нет\n\n";
				choice = NumberInput(0, 1);
				system("cls");
				if (choice == 1)
				{
					for (short y = 0; y <= 99; y++)
					{
						numid[y] = false;
						remove(myfile_title[y].c_str());
						remove(myfile_writeup[y].c_str());
						remove(myfile_priority[y].c_str());
						remove(myfile_date[y][2].c_str());
						remove(myfile_date[y][1].c_str());
						remove(myfile_date[y][0].c_str());
						remove(myfile_time[y][1].c_str());
						remove(myfile_time[y][0].c_str());
						remove(myfile_dealnumber[y].c_str());
					}
					cout << "Память полностью очищена!";
					ExitToSubMenu();
				}
			}
		}
	} while (remdeal != 0);
}

void RedactingTheDeed(bool* numid, short number, deed* deal, string* myfile_title, string* myfile_writeup, string* myfile_priority, string** myfile_date, string** myfile_time, string* myfile_dealnumber)
{
	//Редактирование дел
	ofstream deedout;
	cout << "Пожалуйста, выберите номер дела, которое необходимо отредактировать (проверьте список, если не знаете номер дела - пункт 5 в меню).";
	cout << "\nНомер дела(0 - выход в главное меню) : ";
	short editthedeal;
	editthedeal = NumberInput(0, 101);
	system("cls");
	while (editthedeal != 0)
	{
		if (editthedeal > 100)
		{
			cout << "Такого дела нет!\n";
			editthedeal = 0;
			ExitToMenu();
		}
		else
		{
			if (numid[editthedeal - 1] == true)
			{
				number = editthedeal - 1;
				cout << "Дело № " << editthedeal << ":\n";
				show(deal, number);
				cout << "\nПожалуйста, выберите, что хотите отредактировать:\n1 - Название;\n2 - Описание;\n3 - Приоритет;\n";
				cout << "4 - Дату и время; \n5 - Всё дело; \n0 - Выйти из редактора\n\n";
				short redact;
				redact = NumberInput(0, 5);
				system("cls");
				do
				{
					/*редактирование всего дела*/if (redact > 4)
					{
						cout << "Дело № " << editthedeal << ":\n";
						show(deal, number);
						cout << endl;
						cout << "Пожалуйста, введите новые данные\n";
						getin(deal, number, myfile_title, myfile_writeup, myfile_priority, myfile_date, myfile_time, myfile_dealnumber);
						system("cls");
						cout << "Дело успешно отредактировано!";
						redact = 0;
						editthedeal = 0;
					}
					/*редактирование даты и времени*/else if (redact > 3)
					{
						cout << "Дело № " << editthedeal << ":\n";
						show(deal, number);
						cout << endl;
						cout << "\nПожалуйста, введите новый год выполнения дела (пример - 2021): ";
						deal[number].date[2] = NumberInput(1, 3000);
						deedout.open(myfile_date[number][2]);
						if (!deedout.is_open())
						{
							cout << "Ошибка открытия программного файла! Данные могут не сохранится. Нажмите любую клавишу для продолжения.";
							system("pause");
						}
						else
						{
							deedout << deal[number].date[2];
							deedout.close();
						}
						cout << "Пожалуйста, введите новый месяц выполнения дела цифрами (пример - 04): ";
						deal[number].date[1] = NumberInput(1, 12);
						deedout.open(myfile_date[number][1]);
						if (!deedout.is_open())
						{
							cout << "Ошибка открытия программного файла! Данные могут не сохранится. Нажмите любую клавишу для продолжения.";
							system("pause");
						}
						else
						{
							deedout << deal[number].date[1];
							deedout.close();
						}
						cout << "Пожалуйста, введите новый день выполнения дела (пример - 26): ";
						deal[number].date[0] = NumberInput(1, 31);
						deedout.open(myfile_date[number][0]);
						if (!deedout.is_open())
						{
							cout << "Ошибка открытия программного файла! Данные могут не сохранится. Нажмите любую клавишу для продолжения.";
							system("pause");
						}
						else
						{
							deedout << deal[number].date[0];
							deedout.close();
						}
						cout << "Пожалуйста, введите новое время выполнения дела (час, пример - 10): ";
						deal[number].time[1] = NumberInput(0, 23);
						deedout.open(myfile_time[number][1]);
						if (!deedout.is_open())
						{
							cout << "Ошибка открытия программного файла! Данные могут не сохранится. Нажмите любую клавишу для продолжения.";
							system("pause");
						}
						else
						{
							deedout << deal[number].time[1];
							deedout.close();
						}
						cout << "Пожалуйста, введите новое время выполнения дела (минута, пример - 10): ";
						deal[number].time[0] = NumberInput(0, 59);
						deedout.open(myfile_time[number][0]);
						if (!deedout.is_open())
						{
							cout << "Ошибка открытия программного файла! Данные могут не сохранится. Нажмите любую клавишу для продолжения.";
							system("pause");
						}
						else
						{
							deedout << deal[number].time[0];
							deedout.close();
						}
						system("cls");
						cout << "Дело успешно отредактировано!";
						redact = 0;
						editthedeal = 0;
					}
					/*редактирование приоритета*/else if (redact > 2)
					{
						cout << "Дело № " << editthedeal << ":\n";
						show(deal, number);
						cout << endl;
						cout << "\nПожалуйста, введите новый приоритет выполнения (1 - очень высокий, 2 - высокий, 3 - низкий): ";
						deal[number].priority = NumberInput(0, 4);
						deedout.open(myfile_priority[number]);
						if (!deedout.is_open())
						{
							cout << "Ошибка открытия программного файла! Данные могут не сохранится. Нажмите любую клавишу для продолжения.";
							system("pause");
						}
						else
						{
							deedout << deal[number].priority;
							deedout.close();
						}
						system("cls");
						cout << "Дело успешно отредактировано!";
						redact = 0;
						editthedeal = 0;
					}
					/*редактирование описания*/else if (redact > 1)
					{
						cout << "Дело № " << editthedeal << ":\n";
						show(deal, number);
						cout << endl;
						cout << "\nПожалуйста, введите новое описание: ";
						cin.ignore();
						gets_s(deal[number].writeup);
						deedout.open(myfile_writeup[number]);
						if (!deedout.is_open())
						{
							cout << "Ошибка открытия программного файла! Данные могут не сохранится. Нажмите любую клавишу для продолжения.";
							system("pause");
						}
						else
						{
							deedout << deal[number].writeup;
							deedout.close();
						}
						system("cls");
						cout << "Дело успешно отредактировано!";
						redact = 0;
						editthedeal = 0;
					}
					/*редактирование названия*/else if (redact > 0)
					{
						cout << "Дело № " << editthedeal << ":\n";
						show(deal, number);
						cout << endl;
						cout << "\nПожалуйста, введите новое название дела: ";
						cin.ignore();
						gets_s(deal[number].title);
						deedout.open(myfile_title[number]);
						if (!deedout.is_open())
						{
							cout << "Ошибка открытия программного файла! Данные могут не сохранится. Нажмите любую клавишу для продолжения.";
							system("pause");
						}
						else
						{
							deedout << deal[number].title;
							deedout.close();
						}
						system("cls");
						cout << "Дело успешно отредактировано!";
						redact = 0;
						editthedeal = 0;
					}
				} while (redact != 0);
				editthedeal = 0;
				ExitToMenu();
			}
			else
			{
				cout << "Такого дела нет!\n";
				editthedeal = 0;
				ExitToMenu();
			}
		}
	}
}

void SortIng(bool* numid, short number, deed* deal)
{
	//Сортировка дел
	unsigned short sort_dl;
	do
	{
		cout << "Пожалуйста, выберите:\n\n1 - Сортировка по приоритету;\n2 - Сортировка по дате;\n0 - Выход в предыдущий пункт меню.\n\n";
		sort_dl = NumberInput(0, 100);
		system("cls");
		if (sort_dl > 2)
		{
			cout << "Такого пункта нет!" << endl;
			ExitToMenu();
		}
		/*сортировка по дате*/ else if (sort_dl > 1)
		{
			bool incomp = false;
			for (short c = 0; c <= 99; c++)
				if (numid[c] != false)
				{
					incomp = true;
					break;
				}
			if (incomp == false)
			{
				cout << "Дел пока-что нет! Вы можете их добавить в пункте 1 в меню.";
				ExitToSubMenu();
			}
			else
			{
				short sortid = 0;
				for (short a = 0; a <= 99; a++)
				{
					if (numid[a] == true && deal[a].date[2] != 0)
					{
						sortid++;
					}
				}
				deed* sort_deal = new deed[sortid];
				short am_el = 0;
				for (short e = 0; e <= 99; e++)
				{
					if (numid[e] == true && deal[e].date[2] != 0)
					{
						sort_deal[am_el] = deal[e];
						am_el++;
					}
				}
				if (am_el == 0)
				{
					cout << "Дел пока-что нет! Вы можете их добавить в пункте 1 в меню.";
				}
				sort(sort_deal, sort_deal + sortid, [](auto& sort_deal1, auto& sort_deal2)
					{
						return tie(sort_deal1.date[2], sort_deal1.date[1], sort_deal1.date[0]) < tie(sort_deal2.date[2], sort_deal2.date[1], sort_deal2.date[0]);
					});
				for (short u = sortid - 1; u >= 0; u--)
				{
					cout << "Номер дела по очередности выполнения: " << u + 1 << endl << "Номер дела: " << sort_deal[u].dealnumber + 1 << endl;
					if (sort_deal[u].title[0] != '\0')
					{
						cout << "Название: " << sort_deal[u].title << endl;
					}
					else
					{
						cout << "Название: (пусто)" << endl;
					}
					if (sort_deal[u].priority > 3)
					{
						cout << "Приоритет не определен" << endl;
					}
					else if (sort_deal[u].priority > 2)
					{
						cout << "Приоритет: низкий" << endl;
					}
					else if (sort_deal[u].priority > 1)
					{
						cout << "Приоритет: высокий" << endl;
					}
					else if (sort_deal[u].priority > 0)
					{
						cout << "Приоритет: очень высокий" << endl;
					}
					else if (sort_deal[u].priority == 0)
					{
						cout << "Приоритет не определен" << endl;
					}
					if (sort_deal[u].writeup[0] != '\0')
					{
						cout << "Описание: " << sort_deal[u].writeup << endl;
					}
					else
					{
						cout << "Описание: (пусто)" << endl;
					}
					cout << "Дата выполнения: " << sort_deal[u].date[0] << '.' << sort_deal[u].date[1] << '.' << sort_deal[u].date[2] << endl;
					cout << "Время выполнения: " << sort_deal[u].time[1] << ':' << sort_deal[u].time[0] << TRIendl;
				}
				delete[] sort_deal;
				ExitToSubMenu();
			}
		}
		/*сортировка по приоритету*/ else if (sort_dl > 0)
		{
			cout << "Низкий приоритет:\n\n";
			short sort_pr = 0;
			bool bsort_pr = false;
			for (sort_pr = 99; sort_pr >= 0; sort_pr--)
			{
				if (numid[sort_pr] == true && deal[sort_pr].priority == 3)
				{
					number = sort_pr;
					cout << "Дело №" << sort_pr + 1 << ':' << endl;
					show(deal, number);
					bsort_pr = true;
					cout << TRIendl;
				}
			}
			if (bsort_pr == false)
			{
				cout << "Дела не найдены" << TRIendl;
			}
			cout << "Высокий приоритет:\n\n";
			short sort_pr2 = 0;
			bool bsort_pr2 = false;
			for (sort_pr2 = 99; sort_pr2 >= 0; sort_pr2--)
			{
				if (numid[sort_pr2] == true && deal[sort_pr2].priority == 2)
				{
					number = sort_pr2;
					cout << "Дело №" << sort_pr2 + 1 << ':' << endl;
					show(deal, number);
					bsort_pr2 = true;
					cout << TRIendl;
				}
			}
			if (bsort_pr2 == false)
			{
				cout << "Дела не найдены" << TRIendl;
			}
			cout << "Очень высокий приоритет:\n\n";
			short sort_pr3 = 0;
			bool bsort_pr3 = false;
			for (sort_pr3 = 99; sort_pr3 >= 0; sort_pr3--)
			{
				if (numid[sort_pr3] == true && deal[sort_pr3].priority == 1)
				{
					number = sort_pr3;
					cout << "Дело №" << sort_pr3 + 1 << ':' << endl;
					show(deal, number);
					bsort_pr3 = true;
					cout << TRIendl;
				}
			}
			if (bsort_pr3 == false)
			{
				cout << "Дела не найдены" << TRIendl;
			}
			ExitToSubMenu();
		}
	} while (sort_dl != 0);
}

void SearchIng(bool* numid, short number, deed* deal)
{
	//Поиск дел
	short search_dl;
	do
	{
		cout << "Пожалуйста, выберите:\n\n1 - Найти дела по названию;\n2 - Найти дела по приоритету;\n";
		cout << "3 - Найти дела по описанию;\n4 - Найти дела по году;\n5 - Найти дела по месяцу;\n6 - Найти дела по дню;\n";
		cout << "7 - Найти дела по часу; \n8 - Найти дела по минуте; \n0 - Выход в предыдущий пункт меню.\n\n";
		search_dl = NumberInput(0, 100);
		system("cls");
		if (search_dl > 8)
		{
			cout << "Такого пункта нет!" << endl;
			ExitToMenu();
		}
		/*поиск дел по минуте*/ else if (search_dl > 7)
		{
			short search_y5, search_mon4, search_day3, search_hour2, search_min;
			short smi = 0;
			bool bsearch_min = false;
			cout << "Пожалуйста, введите год выполнения дела (пример - 2021): ";
			search_y5 = NumberInput(1, 3000);
			cout << "Пожалуйста, введите месяц выполнения дела цифрами (пример - 04): ";
			search_mon4 = NumberInput(1, 12);
			cout << "Пожалуйста, введите день выполнения дела (пример - 26): ";
			search_day3 = NumberInput(1, 31);
			cout << "Пожалуйста, введите время выполнения дела (час, пример - 10): ";
			search_hour2 = NumberInput(0, 23);
			cout << "Пожалуйста, введите время выполнения дела (минута, пример - 10): ";
			search_min = NumberInput(0, 59);
			system("cls");
			for (smi = 99; smi >= 0; smi--)
			{
				if (numid[smi] == true && deal[smi].date[2] == search_y5 && deal[smi].date[1] == search_mon4 && deal[smi].date[0] == search_day3 && deal[smi].time[1] == search_hour2 && deal[smi].time[0] == search_min)
				{
					number = smi;
					cout << "Дело №" << smi + 1 << ':' << endl;
					show(deal, number);
					bsearch_min = true;
					cout << TRIendl;
				}
			}
			if (bsearch_min == false)
			{
				cout << "Дела не найдены";
			}
			ExitToSubMenu();
		}
		/*поиск дел по часу*/ else if (search_dl > 6)
		{
			short search_y4, search_mon3, search_day2, search_hour;
			short sh = 0;
			bool bsearch_hour = false;
			cout << "Пожалуйста, введите год выполнения дела (пример - 2021): ";
			search_y4 = NumberInput(1, 3000);
			cout << "Пожалуйста, введите месяц выполнения дела цифрами (пример - 04): ";
			search_mon3 = NumberInput(1, 12);
			cout << "Пожалуйста, введите день выполнения дела (пример - 26): ";
			search_day2 = NumberInput(1, 31);
			cout << "Пожалуйста, введите время выполнения дела (час, пример - 10): ";
			search_hour = NumberInput(0, 23);
			system("cls");
			for (sh = 99; sh >= 0; sh--)
			{
				if (numid[sh] == true && deal[sh].date[2] == search_y4 && deal[sh].date[1] == search_mon3 && deal[sh].date[0] == search_day2 && deal[sh].time[1] == search_hour)
				{
					number = sh;
					cout << "Дело №" << sh + 1 << ':' << endl;
					show(deal, number);
					bsearch_hour = true;
					cout << TRIendl;
				}
			}
			if (bsearch_hour == false)
			{
				cout << "Дела не найдены";
			}
			ExitToSubMenu();
		}
		/*поиск дел по дню*/ else if (search_dl > 5)
		{
			short search_y3, search_mon2, search_day;
			short sd = 0;
			bool bsearch_day = false;
			cout << "Пожалуйста, введите год выполнения дела (пример - 2021): ";
			search_y3 = NumberInput(1, 3000);
			cout << "Пожалуйста, введите месяц выполнения дела цифрами (пример - 04): ";
			search_mon2 = NumberInput(1, 12);
			cout << "Пожалуйста, введите день выполнения дела (пример - 26): ";
			search_day = NumberInput(1, 31);
			system("cls");
			for (sd = 99; sd >= 0; sd--)
			{
				if (numid[sd] == true && deal[sd].date[2] == search_y3 && deal[sd].date[1] == search_mon2 && deal[sd].date[0] == search_day)
				{
					number = sd;
					cout << "Дело №" << sd + 1 << ':' << endl;
					show(deal, number);
					bsearch_day = true;
					cout << TRIendl;
				}
			}
			if (bsearch_day == false)
			{
				cout << "Дела не найдены";
			}
			ExitToSubMenu();
		}
		/*поиск дел по месяцу*/ else if (search_dl > 4)
		{
			short search_y2, search_mon;
			short sm = 0;
			bool bsearch_mon = false;
			cout << "Пожалуйста, введите год выполнения дела (пример - 2021): ";
			search_y2 = NumberInput(1, 3000);
			cout << "Пожалуйста, введите месяц выполнения дела цифрами (пример - 04): ";
			search_mon = NumberInput(1, 12);
			system("cls");
			for (sm = 99; sm >= 0; sm--)
			{
				if (numid[sm] == true && deal[sm].date[2] == search_y2 && deal[sm].date[1] == search_mon)
				{
					number = sm;
					cout << "Дело №" << sm + 1 << ':' << endl;
					show(deal, number);
					bsearch_mon = true;
					cout << TRIendl;
				}
			}
			if (bsearch_mon == false)
			{
				cout << "Дела не найдены";
			}
			ExitToSubMenu();
		}
		/*поиск дел по году*/ else if (search_dl > 3)
		{
			short search_y;
			short sy = 0;
			bool bsearch_y = false;
			cout << "Пожалуйста, введите год выполнения дела (пример - 2021): ";
			search_y = NumberInput(1, 3000);
			system("cls");
			for (sy = 99; sy >= 0; sy--)
			{
				if (numid[sy] == true && deal[sy].date[2] == search_y)
				{
					number = sy;
					cout << "Дело №" << sy + 1 << ':' << endl;
					show(deal, number);
					bsearch_y = true;
					cout << TRIendl;
				}
			}
			if (bsearch_y == false)
			{
				cout << "Дела не найдены";
			}
			ExitToSubMenu();
		}
		/*поиск дел по описанию*/ else if (search_dl > 2)
		{
			char search_nr[100];
			bool bsearch_nr = false;
			char* text_nr;
			short nr = 0;
			cout << "Пожалуйста, введите слово из описания или описание целиком: ";
			cin.ignore();
			gets_s(search_nr);
			system("cls");
			for (nr = 99; nr >= 0; nr--)
			{
				if (search_nr[0] != '\0' && numid[nr] == true && (text_nr = strstr(deal[nr].writeup, search_nr)) != NULL)
				{
					number = nr;
					cout << "Дело №" << nr + 1 << ':' << endl;
					show(deal, number);
					bsearch_nr = true;
					cout << TRIendl;
				}
			}
			if (bsearch_nr == false)
			{
				cout << "Дела не найдены";
			}
			ExitToSubMenu();
		}
		/*поиск дел по приоритету*/ else if (search_dl > 1)
		{
			short search_pr;
			short sp = 0;
			bool bsearch_pr = false;
			cout << "Пожалуйста, введите приоритет (1 - очень высокий, 2 - высокий, 3 - низкий): ";
			search_pr = NumberInput(1, 3);
			system("cls");
			for (sp = 99; sp >= 0; sp--)
			{
				if (numid[sp] == true && deal[sp].priority == search_pr && search_pr < 4 && search_pr > 0)
				{
					number = sp;
					cout << "Дело №" << sp + 1 << ':' << endl;
					show(deal, number);
					bsearch_pr = true;
					cout << TRIendl;
				}
			}
			if (bsearch_pr == false)
			{
				cout << "Дела не найдены";
			}
			ExitToSubMenu();
		}
		/*поиск дел по названию*/ else if (search_dl > 0)
		{
			char search_nm[100];
			bool bsearch_nm = false;
			char* text_nm;
			short nm = 0;
			cout << "Пожалуйста, введите слово из названия или название целиком: ";
			cin.ignore();
			gets_s(search_nm);
			system("cls");
			for (nm = 99; nm >= 0; nm--)
			{
				if (search_nm[0] != '\0' && numid[nm] == true && (text_nm = strstr(deal[nm].title, search_nm)) != NULL)
				{
					number = nm;
					cout << "Дело №" << nm + 1 << ':' << endl;
					show(deal, number);
					bsearch_nm = true;
					cout << TRIendl;
				}
			}
			if (bsearch_nm == false)
			{
				cout << "Дела не найдены";
			}
			ExitToSubMenu();
		}
	} while (search_dl != 0);
}

void SearchNSort(bool* numid, short number, deed* deal)
{
	//Поиск и сортировка дел
	short scandeal;
	do
	{
		cout << "Пожалуйста, выберите:\n\n1 - Поиск дел;\n2 - Сортировка дел;\n0 - Выход в главное меню.\n\n";
		scandeal = NumberInput(0, 100);
		system("cls");
		if (scandeal > 2)
		{
			cout << "Такого пункта нет!" << endl;
			ExitToMenu();
		}
		else if (scandeal > 1)
		{
			SortIng(numid, number, deal);
		}
		else if (scandeal > 0)
		{
			SearchIng(numid, number, deal);
		}
	} while (scandeal != 0);
}

void ListOfDeeds(bool* numid, short number, deed* deal)
{
	//Отображение списка дел
	for (short i = 99; i >= 0; i--)
	{
		if (numid[i] == true)
		{
			number = i;
			cout << "Дело № " << i + 1 << ":\n";
			show(deal, number);
			cout << TRIendl;
		}
		else
		{
			cout << "Дело № " << i + 1 << ":\n" << "Дело не создано" << TRIendl;
		}
	}
	ExitToMenu();
}

int main()
{
	CONSOLE_SCREEN_BUFFER_INFOEX colorification;
	colorification.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfoEx(hConsole, &colorification);
	colorification.ColorTable[1] = RGB(8, 0, 85); //Цвет шрифта
	colorification.ColorTable[0] = RGB(182, 229, 255); //Цвет фона
	SetConsoleScreenBufferInfoEx(hConsole, &colorification);
	SetConsoleTextAttribute(hConsole, 1);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string* myfile_title = new string[100]; //string* myfile_.. - указание пути к файлу, в котором хранится "дело"
	string* myfile_priority = new string[100];
	string* myfile_writeup = new string[100];
	string** myfile_date = new string * [100];
	for (short initializer = 0; initializer <= 99; initializer++)
	{
		myfile_date[initializer] = new string[3];
	}
	string** myfile_time = new string * [100];
	for (short initializer = 0; initializer <= 99; initializer++)
	{
		myfile_time[initializer] = new string[2];
	}
	string* myfile_dealnumber = new string[100];
	for (short initializer = 0; initializer <= 99; initializer++)
	{
		myfile_title[initializer] = "title" + to_string(initializer + 1);
	}
	for (short initializer = 0; initializer <= 99; initializer++)
	{
		myfile_priority[initializer] = "priority" + to_string(initializer + 1);
	}
	for (short initializer = 0; initializer <= 99; initializer++)
	{
		myfile_writeup[initializer] = "writeup" + to_string(initializer + 1);
	}
	for (short initializer = 0; initializer <= 99; initializer++)
	{
		myfile_date[initializer][0] = "date[0]" + to_string(initializer + 1);
		myfile_date[initializer][1] = "date[1]" + to_string(initializer + 1);
		myfile_date[initializer][2] = "date[2]" + to_string(initializer + 1);
	}
	for (short initializer = 0; initializer <= 99; initializer++)
	{
		myfile_time[initializer][0] = "time[0]" + to_string(initializer + 1);
		myfile_time[initializer][1] = "time[1]" + to_string(initializer + 1);
	}
	for (short initializer = 0; initializer <= 99; initializer++)
	{
		myfile_dealnumber[initializer] = "dealnumber" + to_string(initializer + 1);
	}
	ifstream deedin;
	short number = 0;
	deed* deal = new deed[100];
	bool* numid = new bool[100]; //Идентификатор наличия "дела" в массиве
	for (short z = 0; z <= 99; z++)
	{
		numid[z] = false;
	}
	for (short transmitter = 0; transmitter <= 99; transmitter++) //Считывание "дел" из программных файлов
	{
		deedin.open(myfile_title[transmitter]);
		if (deedin.is_open())
		{
			while (!deedin.eof())
			{
				deedin.getline(deal[transmitter].title, 100);
			}
		}
		deedin.close();
		deedin.open(myfile_writeup[transmitter]);
		if (deedin.is_open())
		{
			while (!deedin.eof())
			{
				deedin.getline(deal[transmitter].writeup, 1000);
			}
		}
		deedin.close();
		deedin.open(myfile_priority[transmitter]);
		if (deedin.is_open())
		{
			while (!deedin.eof())
			{
				deedin >> deal[transmitter].priority;
			}
		}
		deedin.close();
		deedin.open(myfile_date[transmitter][2]);
		if (deedin.is_open())
		{
			while (!deedin.eof())
			{
				deedin >> deal[transmitter].date[2];
			}
		}
		deedin.close();
		deedin.open(myfile_date[transmitter][1]);
		if (deedin.is_open())
		{
			while (!deedin.eof())
			{
				deedin >> deal[transmitter].date[1];
			}
		}
		deedin.close();
		deedin.open(myfile_date[transmitter][0]);
		if (deedin.is_open())
		{
			while (!deedin.eof())
			{
				deedin >> deal[transmitter].date[0];
			}
		}
		deedin.close();
		deedin.open(myfile_time[transmitter][1]);
		if (deedin.is_open())
		{
			while (!deedin.eof())
			{
				deedin >> deal[transmitter].time[1];
			}
		}
		deedin.close();
		deedin.open(myfile_time[transmitter][0]);
		if (deedin.is_open())
		{
			while (!deedin.eof())
			{
				deedin >> deal[transmitter].time[0];
			}
		}
		deedin.close();
		deedin.open(myfile_dealnumber[transmitter]);
		if (deedin.is_open())
		{
			while (!deedin.eof())
			{
				deedin >> deal[transmitter].dealnumber;
				numid[transmitter] = true;
			}
		}
		deedin.close();
	}
	short item;
	do
	{
		cout << "Пожалуйста, выберите:\n\n1 - Добавить новое дело;\n2 - Удалить дело;\n3 - Отредактировать дело;\n";
		cout << "4 - Поиск и сортировка дел;\n5 - Отображение списка дел;\n0 - Выход из программы.\n\n";
		item = NumberInput(0, 100);
		system("cls");
		if (item > 5)
		{
			cout << "Такого пункта нет!" << endl;
			ExitToMenu();
		}
		else if (item > 4)
		{
			ListOfDeeds(numid, number, deal);
		}
		else if (item > 3)
		{
			SearchNSort(numid, number, deal);
		}
		else if (item > 2)
		{
			RedactingTheDeed(numid, number, deal, myfile_title, myfile_writeup, myfile_priority, myfile_date, myfile_time, myfile_dealnumber);
		}
		else if (item > 1)
		{
			DeedDelete(numid, myfile_title, myfile_writeup, myfile_priority, myfile_date, myfile_time, myfile_dealnumber);
		}
		else if (item > 0)
		{
			AddNewDeed(numid, number, deal, myfile_title, myfile_writeup, myfile_priority, myfile_date, myfile_time, myfile_dealnumber);
		}
	} while (item != 0);
	delete[] deal, numid, myfile_title, myfile_writeup, myfile_priority, myfile_dealnumber;
	for (short liberator = 0; liberator <= 3; liberator++)
	{
		delete[]myfile_date[liberator];
	}
	delete[]myfile_date;
	for (short liberator = 0; liberator <= 2; liberator++)
	{
		delete[]myfile_time[liberator];
	}
	delete[]myfile_time;
	return 0;
}