#include<ShlObj.h>
#include<string>
#include<iostream>
#include"Header.h"
#include<cstdio>
int main()
{
	graphics();
	std::cout << "\aВы хотите удалить все программные файлы? Память приложения, включая ваши сохраненные Дела, будут безвозвратно удалены.\nY - да, N - нет\n";
	char antwoord[10000];
	gets_s(antwoord);
	if (!((antwoord[0] == 'Y' && antwoord[1] == '\0') || (antwoord[0] == 'y' && antwoord[1] == '\0') || (antwoord[0] == 'N' && antwoord[1] == '\0') || (antwoord[0] == 'n' && antwoord[1] == '\0')))
	{
		do {
			std::cout << TRIendl << "Вы ввели неверное значение! Пожалуйста, повторите ввод:\n";
			gets_s(antwoord);
		} while (!((antwoord[0] == 'Y' && antwoord[1] == '\0') || (antwoord[0] == 'y' && antwoord[1] == '\0') || (antwoord[0] == 'N' && antwoord[1] == '\0') || (antwoord[0] == 'n' && antwoord[1] == '\0')));
	}
	if (antwoord[0] == 'Y' || antwoord[0] == 'y')
	{
		PWSTR path = NULL;
		HRESULT pathres = SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &path); //Определение пути к папке "Документы"
		std::wstring pathtothefolder(path);
		pathtothefolder += L"/Программные файлы приложения Менеджер Дел";
		std::wstring* myfile_title = new std::wstring[100]; //string* myfile_.. - указание пути к файлу, в котором хранится "дело"
		std::wstring* myfile_priority = new std::wstring[100];
		std::wstring* myfile_writeup = new std::wstring[100];
		std::wstring** myfile_date = new std::wstring * [100];
		for (short initializer = 0; initializer <= 99; initializer++)
		{
			myfile_date[initializer] = new std::wstring[3];
		}
		std::wstring** myfile_time = new std::wstring * [100];
		for (short initializer = 0; initializer <= 99; initializer++)
		{
			myfile_time[initializer] = new std::wstring[2];
		}
		std::wstring* myfile_dealnumber = new std::wstring[100];
		for (short initializer = 0; initializer <= 99; initializer++)
		{
			myfile_title[initializer] = pathtothefolder + L"/title" + std::to_wstring(initializer + 1);
			myfile_priority[initializer] = pathtothefolder + L"/priority" + std::to_wstring(initializer + 1);
			myfile_writeup[initializer] = pathtothefolder + L"/writeup" + std::to_wstring(initializer + 1);
			myfile_date[initializer][0] = pathtothefolder + L"/date[0]" + std::to_wstring(initializer + 1);
			myfile_date[initializer][1] = pathtothefolder + L"/date[1]" + std::to_wstring(initializer + 1);
			myfile_date[initializer][2] = pathtothefolder + L"/date[2]" + std::to_wstring(initializer + 1);
			myfile_time[initializer][0] = pathtothefolder + L"/time[0]" + std::to_wstring(initializer + 1);
			myfile_time[initializer][1] = pathtothefolder + L"/time[1]" + std::to_wstring(initializer + 1);
			myfile_dealnumber[initializer] = pathtothefolder + L"/dealnumber" + std::to_wstring(initializer + 1);
		}
		for (short deinstaller = 0; deinstaller <= 99; deinstaller++) //Удаление файлов по указанному пути
		{
			_wremove(myfile_title[deinstaller].c_str());
			_wremove(myfile_writeup[deinstaller].c_str());
			_wremove(myfile_priority[deinstaller].c_str());
			_wremove(myfile_date[deinstaller][2].c_str());
			_wremove(myfile_date[deinstaller][1].c_str());
			_wremove(myfile_date[deinstaller][0].c_str());
			_wremove(myfile_time[deinstaller][1].c_str());
			_wremove(myfile_time[deinstaller][0].c_str());
			_wremove(myfile_dealnumber[deinstaller].c_str());
		}
		delete[] myfile_title, myfile_writeup, myfile_priority, myfile_dealnumber;
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
	}
	return 0;
}