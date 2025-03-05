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

bool	ScalarConverter::isChar(const std::string str)
{
	if (str.size() != 1)
		return false;
	if (isdigit(str[0]))
		return false;
	return true;
}

bool	ScalarConverter::isInt(const std::string str)
{
	const char *tmp = str.c_str();
	while (*tmp == '0')
		tmp++;
	std::string newStr(tmp);
	if (newStr.size() < 1 || newStr.size() > 11)
		return false;
	for (std::string::const_iterator it = newStr.begin() ; it != newStr.end() ; ++it)
	{
		if (it != newStr.begin() && (*it == '-' || *it == '+'))
			return false;
		if (*it != '-' && *it != '+' && !isdigit(*it))
			return false;
	}
	return true;
}

bool	ScalarConverter::isDouble(const std::string str)
{
	int count_dot = 0;
	if (str == "+inf" || str == "-inf" || str == "nan")
		return true;
	if (str[str.size() - 1] == '.')
		return false;
	for (std::string::const_iterator it = str.begin() ; it != str.end() ; ++it)
	{
		if (it != str.begin() && (*it == '-' || *it == '+'))
			return false;
		if (*it == '.')
			count_dot++;
		if (*it != '-' && *it != '+' && *it != '.' && !isdigit(*it))
			return false;
	}
	if (count_dot != 1)
		return false;
	return true;
}

bool	ScalarConverter::isFloat(const std::string str)
{
	int count_dot = 0;
	int count_f = 0;
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	if (str[str.size() - 1] == '.')
		return false;
	for (std::string::const_iterator it = str.begin() ; it != str.end() ; ++it)
	{
		if (it != str.begin() && (*it == '-' || *it == '+'))
			return false;
		if (*it == '.')
			count_dot++;
		if (*it == 'f')
			count_f++;
		if (isdigit(*it) && count_f)
			return false;
		if (*it != '-' && *it != '+' && *it != '.' && *it != 'f' && !isdigit(*it))
			return false;
	}
	if (count_dot != 1 || count_f != 1)
		return false;
	return true;
}

void	ScalarConverter::convert(const std::string& str)
{
	double value;
	if (!isChar(str) && !isInt(str) && !isFloat(str) && !isDouble(str))
	{
		std::cout << "Not a number\n";
		return;
	}
	if (str.size() == 1 && (str[0] < '0' || str[0] > '9'))
		value = static_cast<double>(str[0]);
	else
		value = std::strtod(str.c_str(), NULL);
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

void	ScalarConverter::printChar(double &nbr)
{
	if (std::isnan(nbr) || std::isinf(nbr) || nbr < std::numeric_limits<char>::min() || nbr > std::numeric_limits<char>::max())
		std::cout << "char : impossible\n";
	else if (!std::isprint(static_cast<char>(nbr)))
		std::cout << "char : Non displayable\n";
	else
		std::cout << "char : '" << static_cast<char>(nbr) << "'\n";
}

void	ScalarConverter::printInt(double &nbr)
{
	if (std::isnan(nbr) || std::isinf(nbr) || nbr < std::numeric_limits<int>::min() || nbr > std::numeric_limits<int>::max())
		std::cout << "int : impossible\n";
	else
		std::cout << "int : " << static_cast<int>(nbr) << "\n";
}

void	ScalarConverter::printFloat(double &nbr)
{
	if (nbr == std::numeric_limits<float>::infinity())
		std::cout << "float : +inff\n";
	else if (nbr == -std::numeric_limits<float>::infinity())
		std::cout << "float : -inff\n";
	else if (std::isnan(nbr))
		std::cout << "float : nanf\n";
	else if (nbr == 0 || nbr / static_cast<int>(nbr) == 1)
		std::cout << "float : " << static_cast<float>(nbr) << ".0f\n";
	else
		std::cout << "float : " << static_cast<float>(nbr) << "f\n";
}

void	ScalarConverter::printDouble(double &nbr)
{
	if (nbr == std::numeric_limits<double>::infinity())
		std::cout << "double : +inf\n";
	else if (nbr == -std::numeric_limits<double>::infinity())
		std::cout << "double : -inf\n";
	else if (std::isnan(nbr))
		std::cout << "double : nan\n";
	else if (nbr == 0 || nbr / static_cast<int>(nbr) == 1)
		std::cout << "double : " << static_cast<float>(nbr) << ".0\n";
	else
		std::cout << "double : " << nbr << "\n";
}