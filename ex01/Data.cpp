#include "Data.hpp"

Data::Data(void) : _name("default"), _data(0)
{
	std::cout << "Data default constructor called\n";
}

Data::~Data(void)
{
	std::cout << "Data destructor called\n";
}

Data::Data(const std::string& name, const int& data) : _name(name), _data(data)
{
	std::cout << "Data constructor called\n";
}

Data::Data(const Data& other) : _name(other._name), _data(other._data)
{
	std::cout << "Data copy constructor called\n";
}

Data&	Data::operator=(const Data& other)
{
	(void)other;
	return *this;
}

int	Data::getData(void) const
{
	return _data;
}

std::string	Data::getName(void) const
{
	return _name;
}