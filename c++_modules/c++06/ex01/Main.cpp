#include "Serializer.hpp"
#include <iostream>

int main() {
	Serializer::Data masseo;

	std::cout << Serializer::serialize(&masseo) << std::endl;
	std::cout << Serializer::deserialize(masseo.serialized) << std::endl;
	std::cout << Serializer::serialize(masseo.deserialized) << std::endl;

}