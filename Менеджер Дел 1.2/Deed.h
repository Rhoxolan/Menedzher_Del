#pragma once
#include "MyHeader.h"
#include <string>
#include <vector>
#include <cstddef>

class Deed
{
	std::string title;
	std::string writeup;
	int priority;
	std::size_t dealnumber;
	std::vector<int> date;
	std::vector<int> time;
public:
	Deed(std::string _title, std::string _writeup, int _priority, std::size_t _dealnumber, std::vector<int> _date,
		std::vector<int> _time) : title{ _title }, writeup{ _writeup }, priority{ _priority }, dealnumber{ _dealnumber },
		date{ _date }, time{ _time } {}

	Deed() : Deed{ std::string(), std::string(), 0, 0, std::vector<int>(), std::vector<int>() } {}

	Deed(std::string _title) : Deed{ _title, std::string(), 0, 0, std::vector<int>(), std::vector<int>() } {}

	Deed(std::string _title, std::string _writeup) : Deed{ _title, _writeup, 0, 0, std::vector<int>(),
		std::vector<int>() } {}

	Deed(std::string _title, std::string _writeup, int _priority) : Deed{ _title, _writeup, _priority, 0, std::vector<int>(),
		std::vector<int>() } {}

	Deed(std::string _title, std::string _writeup, int _priority, std::size_t _dealnumber) : Deed{ _title, _writeup, _priority,
		_dealnumber, std::vector<int>(), std::vector<int>() } {}

	Deed(std::string _title, std::string _writeup, int _priority, std::size_t _dealnumber, std::vector<int> _date)
		: Deed{ _title, _writeup, _priority, _dealnumber, _date, std::vector<int>() } {}

	void Set(std::string _title);

	void Set(std::string _title, std::string _writeup);

	void Set(std::string _title, std::string _writeup, int _priority);

	void Set(std::string _title, std::string _writeup, int _priority, std::size_t _dealnumber);

	void Set(std::string _title, std::string _writeup, int _priority, std::size_t _dealnumber, std::vector<int> _date);

	void Set(std::string _title, std::string _writeup, int _priority, std::size_t _dealnumber, std::vector<int> _date,
		std::vector<int> _time);

	void SetTitle(std::string _title);

	void SetPriority(int _priority);

	void SetWriteUp(std::string _writeup);

	void SetDate(std::vector<int> _date);

	void SetTime(std::vector<int> _time);

	std::string GetTitle();

	int GetPriority();

	std::string GetWriteUp();

	std::vector<int> GetDate();

	std::vector<int> GetTime();

	std::size_t GetDealNumber();

};
