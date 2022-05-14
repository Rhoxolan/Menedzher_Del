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
	//���� ��������� �������� � �������� ����������
	short input;
	while (!(cin >> input) || input < min || input > max)
	{
		if (!cin)
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "�� ����� ������������ ��������. ����������, ��������� ����: ";
	}
	return input;
}

void show(deed* deal, short number)
{
	//����� "����" �� �����
	if (deal[number].title[0] != '\0')
	{
		cout << "��������: " << deal[number].title << endl;
	}
	else
	{
		cout << "��������: (�����)" << endl;
	}
	if (deal[number].priority > 3)
	{
		cout << "��������� �� ���������" << endl;
	}
	else if (deal[number].priority > 2)
	{
		cout << "���������: ������" << endl;
	}
	else if (deal[number].priority > 1)
	{
		cout << "���������: �������" << endl;
	}
	else if (deal[number].priority > 0)
	{
		cout << "���������: ����� �������" << endl;
	}
	else if (deal[number].priority == 0)
	{
		cout << "��������� �� ���������" << endl;
	}
	if (deal[number].writeup[0] != '\0')
	{
		cout << "��������: " << deal[number].writeup << endl;
	}
	else
	{
		cout << "��������: (�����)" << endl;
	}
	if (deal[number].date[2] != 0)
	{
		cout << "���� ����������: " << deal[number].date[0] << '.' << deal[number].date[1] << '.' << deal[number].date[2] << endl;
		cout << "����� ����������: " << deal[number].time[1] << ':' << deal[number].time[0] << endl;
	}
}

void getin(deed* deal, short number, string* myfile_title, string* myfile_writeup, string* myfile_priority, string** myfile_date, string** myfile_time, string* myfile_dealnumber)
{
	//���� ������ � "����"
	ofstream deedout;
	cout << "����������, ������� �������� ����: ";
	cin.ignore();
	gets_s(deal[number].title);
	deedout.open(myfile_title[number]);
	if (!deedout.is_open())
	{
		cout << "������ �������� ������������ �����! ������ ����� �� ����������. ������� ����� ������� ��� �����������.";
		system("pause");
	}
	else
	{
		deedout << deal[number].title;
		deedout.close();
	}
	cout << "����������, ������� ��������: ";
	gets_s(deal[number].writeup);
	deedout.open(myfile_writeup[number]);
	if (!deedout.is_open())
	{
		cout << "������ �������� ������������ �����! ������ ����� �� ����������. ������� ����� ������� ��� �����������.";
		system("pause");
	}
	else
	{
		deedout << deal[number].writeup;
		deedout.close();
	}
	cout << "����������, ������� ��������� ���������� (1 - ����� �������, 2 - �������, 3 - ������): ";
	deal[number].priority = NumberInput(0, 4);
	deedout.open(myfile_priority[number]);
	if (!deedout.is_open())
	{
		cout << "������ �������� ������������ �����! ������ ����� �� ����������. ������� ����� ������� ��� �����������.";
		system("pause");
	}
	else
	{
		deedout << deal[number].priority;
		deedout.close();
	}
	cout << "������ ���� � �����? 1 - ��, 0 - ���: ";
	short datechoice;
	datechoice = NumberInput(0, 1);
	if (datechoice == 1)
	{
		cout << "����������, ������� ��� ���������� ���� (������ - 2021): ";
		deal[number].date[2] = NumberInput(1, 3000);
		deedout.open(myfile_date[number][2]);
		if (!deedout.is_open())
		{
			cout << "������ �������� ������������ �����! ������ ����� �� �����������. ������� ����� ������� ��� �����������.";
			system("pause");
		}
		else
		{
			deedout << deal[number].date[2];
			deedout.close();
		}
		cout << "����������, ������� ����� ���������� ���� ������� (������ - 04): ";
		deal[number].date[1] = NumberInput(1, 12);
		deedout.open(myfile_date[number][1]);
		if (!deedout.is_open())
		{
			cout << "������ �������� ������������ �����! ������ ����� �� �����������. ������� ����� ������� ��� �����������.";
			system("pause");
		}
		else
		{
			deedout << deal[number].date[1];
			deedout.close();
		}
		cout << "����������, ������� ���� ���������� ���� (������ - 26): ";
		deal[number].date[0] = NumberInput(1, 31);
		deedout.open(myfile_date[number][0]);
		if (!deedout.is_open())
		{
			cout << "������ �������� ������������ �����! ������ ����� �� �����������. ������� ����� ������� ��� �����������.";
			system("pause");
		}
		else
		{
			deedout << deal[number].date[0];
			deedout.close();
		}
		cout << "����������, ������� ����� ���������� ���� (���, ������ - 10): ";
		deal[number].time[1] = NumberInput(0, 23);
		deedout.open(myfile_time[number][1]);
		if (!deedout.is_open())
		{
			cout << "������ �������� ������������ �����! ������ ����� �� �����������. ������� ����� ������� ��� �����������.";
			system("pause");
		}
		else
		{
			deedout << deal[number].time[1];
			deedout.close();
		}
		cout << "����������, ������� ����� ���������� ���� (������, ������ - 10): ";
		deal[number].time[0] = NumberInput(0, 59);
		deedout.open(myfile_time[number][0]);
		if (!deedout.is_open())
		{
			cout << "������ �������� ������������ �����! ������ ����� �� �����������. ������� ����� ������� ��� �����������.";
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
	//������������ ��� �������� � ������� ����
	cout << TRIendl << "������� ����� ������� ��� ������ � ������� ����" << TRIendl;
	system("pause");
	system("cls");
}

void ExitToSubMenu()
{
	//������������ ��� �������� � ���������� ����� ����
	cout << TRIendl << "������� ����� ������� ��� ������ � ���������� ����� ����" << TRIendl;
	system("pause");
	system("cls");
}

void AddNewDeed(bool* numid, short number, deed* deal, string* myfile_title, string* myfile_writeup, string* myfile_priority, string** myfile_date, string** myfile_time, string* myfile_dealnumber)
{
	//���������� ����� ���
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
		cout << "������ �����������! ����������, ������� ���� - ����� 2 � ����.";
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
				cout << "���� �" << x + 1 << ":\n";
				getin(deal, number, myfile_title, myfile_writeup, myfile_priority, myfile_date, myfile_time, myfile_dealnumber);
				deal[x].dealnumber = x;
				deedout.open(myfile_dealnumber[x]);
				if (!deedout.is_open())
				{
					cout << "������ �������� ������������ �����! ������ ����� �� ����������. ������� ����� ������� ��� �����������.";
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
	//�������� ���
	short remdeal;
	do
	{
		cout << "����������, ��������:\n\n1 - ������� ��� ����;\n2 - ������� ���� ����;\n3 - ������� ��������� ���;\n0 - ����� � ������� ����.\n\n";
		remdeal = NumberInput(0, 3);
		system("cls");
		/*�������� ���������� ���*/if (remdeal > 2)
		{
			short* hidefewdeeds = new short[100];
			short hideid = -1;
			cout << "����������, ������� ������ ���, ������� ���������� ������� (��������� ������, ���� �� ������ ������ ���� - ����� 5 � ����).\n";
			cout << "������� �� ������ �����, ������� ����� ������� ����� Enter. 0 - ���������� ���� ��� ����� � ���������� ����� ����:\n\n";
			do
			{
				hideid++;
				hidefewdeeds[hideid] = NumberInput(0, 100);
				cout << "������� ��� ���� ����, ��� ������� 0: ";
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
					cout << "���� ������� �������!";
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
					cout << "���� �� �������!";
				}
				ExitToSubMenu();
			}
			delete[] hidefewdeeds;
		}
		/*�������� ������ ����*/else if (remdeal > 1)
		{
			cout << "����������, �������� ����� ����, ������� ���������� ������� (��������� ������, ���� �� ������ ����� ���� - ����� 5 � ����).\n";
			cout << "����� ���� (0 - ����� � ���������� ����� ����): ";
			short hidedeal;
			hidedeal = NumberInput(0, 101);
			system("cls");
			while (hidedeal != 0)
			{
				if (hidedeal > 100)
				{
					cout << "������ ���� ���!\n";
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
						cout << "���� ������� �������!";
						hidedeal = 0;
						ExitToSubMenu();
					}
					else
					{
						cout << "������ ���� ���!\n";
						hidedeal = 0;
						ExitToSubMenu();
					}
				}
			}
		}
		/*�������� ���� ���*/else if (remdeal > 0)
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
				cout << "������ �����!";
				ExitToSubMenu();
			}
			else
			{
				short choice;
				cout << "�� ����� ������ ��� �������?\n\n1 - ��\n0 - ���\n\n";
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
					cout << "������ ��������� �������!";
					ExitToSubMenu();
				}
			}
		}
	} while (remdeal != 0);
}

void RedactingTheDeed(bool* numid, short number, deed* deal, string* myfile_title, string* myfile_writeup, string* myfile_priority, string** myfile_date, string** myfile_time, string* myfile_dealnumber)
{
	//�������������� ���
	ofstream deedout;
	cout << "����������, �������� ����� ����, ������� ���������� ��������������� (��������� ������, ���� �� ������ ����� ���� - ����� 5 � ����).";
	cout << "\n����� ����(0 - ����� � ������� ����) : ";
	short editthedeal;
	editthedeal = NumberInput(0, 101);
	system("cls");
	while (editthedeal != 0)
	{
		if (editthedeal > 100)
		{
			cout << "������ ���� ���!\n";
			editthedeal = 0;
			ExitToMenu();
		}
		else
		{
			if (numid[editthedeal - 1] == true)
			{
				number = editthedeal - 1;
				cout << "���� � " << editthedeal << ":\n";
				show(deal, number);
				cout << "\n����������, ��������, ��� ������ ���������������:\n1 - ��������;\n2 - ��������;\n3 - ���������;\n";
				cout << "4 - ���� � �����; \n5 - �� ����; \n0 - ����� �� ���������\n\n";
				short redact;
				redact = NumberInput(0, 5);
				system("cls");
				do
				{
					/*�������������� ����� ����*/if (redact > 4)
					{
						cout << "���� � " << editthedeal << ":\n";
						show(deal, number);
						cout << endl;
						cout << "����������, ������� ����� ������\n";
						getin(deal, number, myfile_title, myfile_writeup, myfile_priority, myfile_date, myfile_time, myfile_dealnumber);
						system("cls");
						cout << "���� ������� ���������������!";
						redact = 0;
						editthedeal = 0;
					}
					/*�������������� ���� � �������*/else if (redact > 3)
					{
						cout << "���� � " << editthedeal << ":\n";
						show(deal, number);
						cout << endl;
						cout << "\n����������, ������� ����� ��� ���������� ���� (������ - 2021): ";
						deal[number].date[2] = NumberInput(1, 3000);
						deedout.open(myfile_date[number][2]);
						if (!deedout.is_open())
						{
							cout << "������ �������� ������������ �����! ������ ����� �� ����������. ������� ����� ������� ��� �����������.";
							system("pause");
						}
						else
						{
							deedout << deal[number].date[2];
							deedout.close();
						}
						cout << "����������, ������� ����� ����� ���������� ���� ������� (������ - 04): ";
						deal[number].date[1] = NumberInput(1, 12);
						deedout.open(myfile_date[number][1]);
						if (!deedout.is_open())
						{
							cout << "������ �������� ������������ �����! ������ ����� �� ����������. ������� ����� ������� ��� �����������.";
							system("pause");
						}
						else
						{
							deedout << deal[number].date[1];
							deedout.close();
						}
						cout << "����������, ������� ����� ���� ���������� ���� (������ - 26): ";
						deal[number].date[0] = NumberInput(1, 31);
						deedout.open(myfile_date[number][0]);
						if (!deedout.is_open())
						{
							cout << "������ �������� ������������ �����! ������ ����� �� ����������. ������� ����� ������� ��� �����������.";
							system("pause");
						}
						else
						{
							deedout << deal[number].date[0];
							deedout.close();
						}
						cout << "����������, ������� ����� ����� ���������� ���� (���, ������ - 10): ";
						deal[number].time[1] = NumberInput(0, 23);
						deedout.open(myfile_time[number][1]);
						if (!deedout.is_open())
						{
							cout << "������ �������� ������������ �����! ������ ����� �� ����������. ������� ����� ������� ��� �����������.";
							system("pause");
						}
						else
						{
							deedout << deal[number].time[1];
							deedout.close();
						}
						cout << "����������, ������� ����� ����� ���������� ���� (������, ������ - 10): ";
						deal[number].time[0] = NumberInput(0, 59);
						deedout.open(myfile_time[number][0]);
						if (!deedout.is_open())
						{
							cout << "������ �������� ������������ �����! ������ ����� �� ����������. ������� ����� ������� ��� �����������.";
							system("pause");
						}
						else
						{
							deedout << deal[number].time[0];
							deedout.close();
						}
						system("cls");
						cout << "���� ������� ���������������!";
						redact = 0;
						editthedeal = 0;
					}
					/*�������������� ����������*/else if (redact > 2)
					{
						cout << "���� � " << editthedeal << ":\n";
						show(deal, number);
						cout << endl;
						cout << "\n����������, ������� ����� ��������� ���������� (1 - ����� �������, 2 - �������, 3 - ������): ";
						deal[number].priority = NumberInput(0, 4);
						deedout.open(myfile_priority[number]);
						if (!deedout.is_open())
						{
							cout << "������ �������� ������������ �����! ������ ����� �� ����������. ������� ����� ������� ��� �����������.";
							system("pause");
						}
						else
						{
							deedout << deal[number].priority;
							deedout.close();
						}
						system("cls");
						cout << "���� ������� ���������������!";
						redact = 0;
						editthedeal = 0;
					}
					/*�������������� ��������*/else if (redact > 1)
					{
						cout << "���� � " << editthedeal << ":\n";
						show(deal, number);
						cout << endl;
						cout << "\n����������, ������� ����� ��������: ";
						cin.ignore();
						gets_s(deal[number].writeup);
						deedout.open(myfile_writeup[number]);
						if (!deedout.is_open())
						{
							cout << "������ �������� ������������ �����! ������ ����� �� ����������. ������� ����� ������� ��� �����������.";
							system("pause");
						}
						else
						{
							deedout << deal[number].writeup;
							deedout.close();
						}
						system("cls");
						cout << "���� ������� ���������������!";
						redact = 0;
						editthedeal = 0;
					}
					/*�������������� ��������*/else if (redact > 0)
					{
						cout << "���� � " << editthedeal << ":\n";
						show(deal, number);
						cout << endl;
						cout << "\n����������, ������� ����� �������� ����: ";
						cin.ignore();
						gets_s(deal[number].title);
						deedout.open(myfile_title[number]);
						if (!deedout.is_open())
						{
							cout << "������ �������� ������������ �����! ������ ����� �� ����������. ������� ����� ������� ��� �����������.";
							system("pause");
						}
						else
						{
							deedout << deal[number].title;
							deedout.close();
						}
						system("cls");
						cout << "���� ������� ���������������!";
						redact = 0;
						editthedeal = 0;
					}
				} while (redact != 0);
				editthedeal = 0;
				ExitToMenu();
			}
			else
			{
				cout << "������ ���� ���!\n";
				editthedeal = 0;
				ExitToMenu();
			}
		}
	}
}

void SortIng(bool* numid, short number, deed* deal)
{
	//���������� ���
	unsigned short sort_dl;
	do
	{
		cout << "����������, ��������:\n\n1 - ���������� �� ����������;\n2 - ���������� �� ����;\n0 - ����� � ���������� ����� ����.\n\n";
		sort_dl = NumberInput(0, 100);
		system("cls");
		if (sort_dl > 2)
		{
			cout << "������ ������ ���!" << endl;
			ExitToMenu();
		}
		/*���������� �� ����*/ else if (sort_dl > 1)
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
				cout << "��� ����-��� ���! �� ������ �� �������� � ������ 1 � ����.";
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
					cout << "��� ����-��� ���! �� ������ �� �������� � ������ 1 � ����.";
				}
				sort(sort_deal, sort_deal + sortid, [](auto& sort_deal1, auto& sort_deal2)
					{
						return tie(sort_deal1.date[2], sort_deal1.date[1], sort_deal1.date[0]) < tie(sort_deal2.date[2], sort_deal2.date[1], sort_deal2.date[0]);
					});
				for (short u = sortid - 1; u >= 0; u--)
				{
					cout << "����� ���� �� ����������� ����������: " << u + 1 << endl << "����� ����: " << sort_deal[u].dealnumber + 1 << endl;
					if (sort_deal[u].title[0] != '\0')
					{
						cout << "��������: " << sort_deal[u].title << endl;
					}
					else
					{
						cout << "��������: (�����)" << endl;
					}
					if (sort_deal[u].priority > 3)
					{
						cout << "��������� �� ���������" << endl;
					}
					else if (sort_deal[u].priority > 2)
					{
						cout << "���������: ������" << endl;
					}
					else if (sort_deal[u].priority > 1)
					{
						cout << "���������: �������" << endl;
					}
					else if (sort_deal[u].priority > 0)
					{
						cout << "���������: ����� �������" << endl;
					}
					else if (sort_deal[u].priority == 0)
					{
						cout << "��������� �� ���������" << endl;
					}
					if (sort_deal[u].writeup[0] != '\0')
					{
						cout << "��������: " << sort_deal[u].writeup << endl;
					}
					else
					{
						cout << "��������: (�����)" << endl;
					}
					cout << "���� ����������: " << sort_deal[u].date[0] << '.' << sort_deal[u].date[1] << '.' << sort_deal[u].date[2] << endl;
					cout << "����� ����������: " << sort_deal[u].time[1] << ':' << sort_deal[u].time[0] << TRIendl;
				}
				delete[] sort_deal;
				ExitToSubMenu();
			}
		}
		/*���������� �� ����������*/ else if (sort_dl > 0)
		{
			cout << "������ ���������:\n\n";
			short sort_pr = 0;
			bool bsort_pr = false;
			for (sort_pr = 99; sort_pr >= 0; sort_pr--)
			{
				if (numid[sort_pr] == true && deal[sort_pr].priority == 3)
				{
					number = sort_pr;
					cout << "���� �" << sort_pr + 1 << ':' << endl;
					show(deal, number);
					bsort_pr = true;
					cout << TRIendl;
				}
			}
			if (bsort_pr == false)
			{
				cout << "���� �� �������" << TRIendl;
			}
			cout << "������� ���������:\n\n";
			short sort_pr2 = 0;
			bool bsort_pr2 = false;
			for (sort_pr2 = 99; sort_pr2 >= 0; sort_pr2--)
			{
				if (numid[sort_pr2] == true && deal[sort_pr2].priority == 2)
				{
					number = sort_pr2;
					cout << "���� �" << sort_pr2 + 1 << ':' << endl;
					show(deal, number);
					bsort_pr2 = true;
					cout << TRIendl;
				}
			}
			if (bsort_pr2 == false)
			{
				cout << "���� �� �������" << TRIendl;
			}
			cout << "����� ������� ���������:\n\n";
			short sort_pr3 = 0;
			bool bsort_pr3 = false;
			for (sort_pr3 = 99; sort_pr3 >= 0; sort_pr3--)
			{
				if (numid[sort_pr3] == true && deal[sort_pr3].priority == 1)
				{
					number = sort_pr3;
					cout << "���� �" << sort_pr3 + 1 << ':' << endl;
					show(deal, number);
					bsort_pr3 = true;
					cout << TRIendl;
				}
			}
			if (bsort_pr3 == false)
			{
				cout << "���� �� �������" << TRIendl;
			}
			ExitToSubMenu();
		}
	} while (sort_dl != 0);
}

void SearchIng(bool* numid, short number, deed* deal)
{
	//����� ���
	short search_dl;
	do
	{
		cout << "����������, ��������:\n\n1 - ����� ���� �� ��������;\n2 - ����� ���� �� ����������;\n";
		cout << "3 - ����� ���� �� ��������;\n4 - ����� ���� �� ����;\n5 - ����� ���� �� ������;\n6 - ����� ���� �� ���;\n";
		cout << "7 - ����� ���� �� ����; \n8 - ����� ���� �� ������; \n0 - ����� � ���������� ����� ����.\n\n";
		search_dl = NumberInput(0, 100);
		system("cls");
		if (search_dl > 8)
		{
			cout << "������ ������ ���!" << endl;
			ExitToMenu();
		}
		/*����� ��� �� ������*/ else if (search_dl > 7)
		{
			short search_y5, search_mon4, search_day3, search_hour2, search_min;
			short smi = 0;
			bool bsearch_min = false;
			cout << "����������, ������� ��� ���������� ���� (������ - 2021): ";
			search_y5 = NumberInput(1, 3000);
			cout << "����������, ������� ����� ���������� ���� ������� (������ - 04): ";
			search_mon4 = NumberInput(1, 12);
			cout << "����������, ������� ���� ���������� ���� (������ - 26): ";
			search_day3 = NumberInput(1, 31);
			cout << "����������, ������� ����� ���������� ���� (���, ������ - 10): ";
			search_hour2 = NumberInput(0, 23);
			cout << "����������, ������� ����� ���������� ���� (������, ������ - 10): ";
			search_min = NumberInput(0, 59);
			system("cls");
			for (smi = 99; smi >= 0; smi--)
			{
				if (numid[smi] == true && deal[smi].date[2] == search_y5 && deal[smi].date[1] == search_mon4 && deal[smi].date[0] == search_day3 && deal[smi].time[1] == search_hour2 && deal[smi].time[0] == search_min)
				{
					number = smi;
					cout << "���� �" << smi + 1 << ':' << endl;
					show(deal, number);
					bsearch_min = true;
					cout << TRIendl;
				}
			}
			if (bsearch_min == false)
			{
				cout << "���� �� �������";
			}
			ExitToSubMenu();
		}
		/*����� ��� �� ����*/ else if (search_dl > 6)
		{
			short search_y4, search_mon3, search_day2, search_hour;
			short sh = 0;
			bool bsearch_hour = false;
			cout << "����������, ������� ��� ���������� ���� (������ - 2021): ";
			search_y4 = NumberInput(1, 3000);
			cout << "����������, ������� ����� ���������� ���� ������� (������ - 04): ";
			search_mon3 = NumberInput(1, 12);
			cout << "����������, ������� ���� ���������� ���� (������ - 26): ";
			search_day2 = NumberInput(1, 31);
			cout << "����������, ������� ����� ���������� ���� (���, ������ - 10): ";
			search_hour = NumberInput(0, 23);
			system("cls");
			for (sh = 99; sh >= 0; sh--)
			{
				if (numid[sh] == true && deal[sh].date[2] == search_y4 && deal[sh].date[1] == search_mon3 && deal[sh].date[0] == search_day2 && deal[sh].time[1] == search_hour)
				{
					number = sh;
					cout << "���� �" << sh + 1 << ':' << endl;
					show(deal, number);
					bsearch_hour = true;
					cout << TRIendl;
				}
			}
			if (bsearch_hour == false)
			{
				cout << "���� �� �������";
			}
			ExitToSubMenu();
		}
		/*����� ��� �� ���*/ else if (search_dl > 5)
		{
			short search_y3, search_mon2, search_day;
			short sd = 0;
			bool bsearch_day = false;
			cout << "����������, ������� ��� ���������� ���� (������ - 2021): ";
			search_y3 = NumberInput(1, 3000);
			cout << "����������, ������� ����� ���������� ���� ������� (������ - 04): ";
			search_mon2 = NumberInput(1, 12);
			cout << "����������, ������� ���� ���������� ���� (������ - 26): ";
			search_day = NumberInput(1, 31);
			system("cls");
			for (sd = 99; sd >= 0; sd--)
			{
				if (numid[sd] == true && deal[sd].date[2] == search_y3 && deal[sd].date[1] == search_mon2 && deal[sd].date[0] == search_day)
				{
					number = sd;
					cout << "���� �" << sd + 1 << ':' << endl;
					show(deal, number);
					bsearch_day = true;
					cout << TRIendl;
				}
			}
			if (bsearch_day == false)
			{
				cout << "���� �� �������";
			}
			ExitToSubMenu();
		}
		/*����� ��� �� ������*/ else if (search_dl > 4)
		{
			short search_y2, search_mon;
			short sm = 0;
			bool bsearch_mon = false;
			cout << "����������, ������� ��� ���������� ���� (������ - 2021): ";
			search_y2 = NumberInput(1, 3000);
			cout << "����������, ������� ����� ���������� ���� ������� (������ - 04): ";
			search_mon = NumberInput(1, 12);
			system("cls");
			for (sm = 99; sm >= 0; sm--)
			{
				if (numid[sm] == true && deal[sm].date[2] == search_y2 && deal[sm].date[1] == search_mon)
				{
					number = sm;
					cout << "���� �" << sm + 1 << ':' << endl;
					show(deal, number);
					bsearch_mon = true;
					cout << TRIendl;
				}
			}
			if (bsearch_mon == false)
			{
				cout << "���� �� �������";
			}
			ExitToSubMenu();
		}
		/*����� ��� �� ����*/ else if (search_dl > 3)
		{
			short search_y;
			short sy = 0;
			bool bsearch_y = false;
			cout << "����������, ������� ��� ���������� ���� (������ - 2021): ";
			search_y = NumberInput(1, 3000);
			system("cls");
			for (sy = 99; sy >= 0; sy--)
			{
				if (numid[sy] == true && deal[sy].date[2] == search_y)
				{
					number = sy;
					cout << "���� �" << sy + 1 << ':' << endl;
					show(deal, number);
					bsearch_y = true;
					cout << TRIendl;
				}
			}
			if (bsearch_y == false)
			{
				cout << "���� �� �������";
			}
			ExitToSubMenu();
		}
		/*����� ��� �� ��������*/ else if (search_dl > 2)
		{
			char search_nr[100];
			bool bsearch_nr = false;
			char* text_nr;
			short nr = 0;
			cout << "����������, ������� ����� �� �������� ��� �������� �������: ";
			cin.ignore();
			gets_s(search_nr);
			system("cls");
			for (nr = 99; nr >= 0; nr--)
			{
				if (search_nr[0] != '\0' && numid[nr] == true && (text_nr = strstr(deal[nr].writeup, search_nr)) != NULL)
				{
					number = nr;
					cout << "���� �" << nr + 1 << ':' << endl;
					show(deal, number);
					bsearch_nr = true;
					cout << TRIendl;
				}
			}
			if (bsearch_nr == false)
			{
				cout << "���� �� �������";
			}
			ExitToSubMenu();
		}
		/*����� ��� �� ����������*/ else if (search_dl > 1)
		{
			short search_pr;
			short sp = 0;
			bool bsearch_pr = false;
			cout << "����������, ������� ��������� (1 - ����� �������, 2 - �������, 3 - ������): ";
			search_pr = NumberInput(1, 3);
			system("cls");
			for (sp = 99; sp >= 0; sp--)
			{
				if (numid[sp] == true && deal[sp].priority == search_pr && search_pr < 4 && search_pr > 0)
				{
					number = sp;
					cout << "���� �" << sp + 1 << ':' << endl;
					show(deal, number);
					bsearch_pr = true;
					cout << TRIendl;
				}
			}
			if (bsearch_pr == false)
			{
				cout << "���� �� �������";
			}
			ExitToSubMenu();
		}
		/*����� ��� �� ��������*/ else if (search_dl > 0)
		{
			char search_nm[100];
			bool bsearch_nm = false;
			char* text_nm;
			short nm = 0;
			cout << "����������, ������� ����� �� �������� ��� �������� �������: ";
			cin.ignore();
			gets_s(search_nm);
			system("cls");
			for (nm = 99; nm >= 0; nm--)
			{
				if (search_nm[0] != '\0' && numid[nm] == true && (text_nm = strstr(deal[nm].title, search_nm)) != NULL)
				{
					number = nm;
					cout << "���� �" << nm + 1 << ':' << endl;
					show(deal, number);
					bsearch_nm = true;
					cout << TRIendl;
				}
			}
			if (bsearch_nm == false)
			{
				cout << "���� �� �������";
			}
			ExitToSubMenu();
		}
	} while (search_dl != 0);
}

void SearchNSort(bool* numid, short number, deed* deal)
{
	//����� � ���������� ���
	short scandeal;
	do
	{
		cout << "����������, ��������:\n\n1 - ����� ���;\n2 - ���������� ���;\n0 - ����� � ������� ����.\n\n";
		scandeal = NumberInput(0, 100);
		system("cls");
		if (scandeal > 2)
		{
			cout << "������ ������ ���!" << endl;
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
	//����������� ������ ���
	for (short i = 99; i >= 0; i--)
	{
		if (numid[i] == true)
		{
			number = i;
			cout << "���� � " << i + 1 << ":\n";
			show(deal, number);
			cout << TRIendl;
		}
		else
		{
			cout << "���� � " << i + 1 << ":\n" << "���� �� �������" << TRIendl;
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
	colorification.ColorTable[1] = RGB(8, 0, 85); //���� ������
	colorification.ColorTable[0] = RGB(182, 229, 255); //���� ����
	SetConsoleScreenBufferInfoEx(hConsole, &colorification);
	SetConsoleTextAttribute(hConsole, 1);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string* myfile_title = new string[100]; //string* myfile_.. - �������� ���� � �����, � ������� �������� "����"
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
	bool* numid = new bool[100]; //������������� ������� "����" � �������
	for (short z = 0; z <= 99; z++)
	{
		numid[z] = false;
	}
	for (short transmitter = 0; transmitter <= 99; transmitter++) //���������� "���" �� ����������� ������
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
		cout << "����������, ��������:\n\n1 - �������� ����� ����;\n2 - ������� ����;\n3 - ��������������� ����;\n";
		cout << "4 - ����� � ���������� ���;\n5 - ����������� ������ ���;\n0 - ����� �� ���������.\n\n";
		item = NumberInput(0, 100);
		system("cls");
		if (item > 5)
		{
			cout << "������ ������ ���!" << endl;
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