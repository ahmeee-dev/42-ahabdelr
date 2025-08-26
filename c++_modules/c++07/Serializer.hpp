#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
#include <string>

class Serializer {
	private:
		Serializer() {};
	public:
		struct Data {
			uintptr_t serialized;
			Data* deserialized;
		};

		static uintptr_t serialize (Data *ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif