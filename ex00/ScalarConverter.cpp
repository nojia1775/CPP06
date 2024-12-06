#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	return;
}

ScalarConverter::~ScalarConverter(void)
{
	return;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

void	ScalarConverter::convert(const std::string str) const
{
	int num;

	try
	{
		num = static_cast<int>(str);
	}
	
}