#include"Deed.h"

void Deed::Set(std::string _title)
{
	title = _title;
	writeup = std::string();
	priority = 0;
	dealnumber = 0;
	date = std::vector<int>();
	time = std::vector<int>();
}

void Deed::Set(std::string _title, std::string _writeup)
{
	title = _title;
	writeup = _writeup;
	priority = 0;
	dealnumber = 0;
	date = std::vector<int>();
	time = std::vector<int>();
}

void Deed::Set(std::string _title, std::string _writeup, int _priority)
{
	title = _title;
	writeup = _writeup;
	priority = _priority;
	dealnumber = 0;
	date = std::vector<int>();
	time = std::vector<int>();
}

void Deed::Set(std::string _title, std::string _writeup, int _priority, std::size_t _dealnumber)
{
	title = _title;
	writeup = _writeup;
	priority = _priority;
	dealnumber = _dealnumber;
	date = std::vector<int>();
	time = std::vector<int>();
}

void Deed::Set(std::string _title, std::string _writeup, int _priority, std::size_t _dealnumber, std::vector<int> _date)
{
	title = _title;
	writeup = _writeup;
	priority = _priority;
	dealnumber = _dealnumber;
	date = _date;
	time = std::vector<int>();
}

void Deed::Set(std::string _title, std::string _writeup, int _priority, std::size_t _dealnumber, std::vector<int> _date,
	std::vector<int> _time)
{
	title = _title;
	writeup = _writeup;
	priority = _priority;
	dealnumber = _dealnumber;
	date = _date;
	time = _time;
}

void Deed::SetTitle(std::string _title)
{
	title = _title;
}

void Deed::SetPriority(int _priority)
{
	priority = _priority;
}

void Deed::SetWriteUp(std::string _writeup)
{
	writeup = _writeup;
}

void Deed::SetDate(std::vector<int> _date)
{
	date = _date;
}

void Deed::SetTime(std::vector<int> _time)
{
	time = _time;
}

std::string Deed::GetTitle()
{
	return title;
}

int Deed::GetPriority()
{
	return priority;
}

std::string Deed::GetWriteUp()
{
	return writeup;
}

std::vector<int> Deed::GetDate()
{
	return date;
}

std::vector<int> Deed::GetTime()
{
	return time;
}

std::size_t Deed::GetDealNumber()
{
	return dealnumber;
}