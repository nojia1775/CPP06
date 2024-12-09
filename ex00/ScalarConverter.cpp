#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) : _nbrc(NULL), _nbrd(NULL), _nbrf(NULL), _nbri(NULL)
{
	return;
}

ScalarConverter::~ScalarConverter(void)
{
	if (_nbrc)
		delete _nbrc;
	if (_nbrd)
		delete _nbrd;
	if (_nbrf)
		delete _nbrf;
	if (_nbri)
		delete _nbri;
	return;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) : _nbrc(other._nbrc), _nbrd(other._nbrd), _nbrf(other._nbrf), _nbri(other._nbri)
{
	(void)other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

bool	ScalarConverter::isChar(const std::string str) const
{
	if (str.size() != 1)
		return false;
	if (isdigit(str[0]))
		return false;
	return true;
}

bool	ScalarConverter::isInt(const std::string str) const
{
	if (str.size() < 1 || str.size() > 11)
		return false;
	for (int i = 0 ; i < str.size() ; i++)
		if (!isdigit(str[i]))
			return false;
	return true;
}

bool	ScalarConverter::isDouble(const std::string str) const
{
	if (str == "inf" || str == "nan")
	{
		return true;
	}
	
}