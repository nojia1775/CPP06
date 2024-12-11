#include "Serializer.hpp"

int	main(void)
{
	Data data("data", 10);
	Data *ptr = NULL;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Data apres serialize : " << raw << "\n";
	ptr = Serializer::deserialize(raw);
	std::cout << "Data apres desrialize :\nName : " << ptr->getName() << "\nData : " << ptr->getData() << "\n";
	return 0;
}