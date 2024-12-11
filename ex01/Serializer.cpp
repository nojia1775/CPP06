#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer constructor called\n";
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer destructor called\n";
}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
	std::cout << "Serializer copy constructor called\n";
}

Serializer&	Serializer::operator=(const Serializer& other)
{
	(void)other;
	return *this;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}