#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t raw = (uintptr_t)ptr;
	ptr->serialized = raw;
	ptr->deserialized = ptr;
		return (raw);
};

Serializer::Data* Serializer::deserialize(uintptr_t raw) {
	Data *ptr = (Data *)raw;
	ptr->serialized = raw;
	ptr->deserialized = ptr;
	return ptr;
}