#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
	private:
		uint size;
		T *array;

	public:
		Array() : size(0) {
			 this->array = new T[0](); 
		};

		Array(uint size) : size(size) {
			this->array = new T[size]();
		};

		Array &operator =(const Array &rhs) {
			if (this != rhs) {
				for (int i = 0; i < (int)this->size; i++) {
					rhs.array[i] = this->array[i];
				}
				rhs.size = this->size;
			}
			return (*this);
		}

		Array(const Array &toCopy) {
			for (int i = 0; i < (int)toCopy.size; i++) {
				this->array[i] = toCopy.array[i];
			}
			this->size = toCopy.size;
		}

		int getSize() { //nome da riportare a size(), conflitto con la variabile, modificare la variabile
			return (this->size);
		}

		T &operator[](int index) {
			if ((int)this->size <= index)
				throw (std::out_of_range("Index out of bounds"));
			return (this->array[index]);
		}

		const T &operator[](int index) const {
			if ((int)this->size <= index)
				throw (std::out_of_range("Index out of bounds"));
			return (this->array[index]);
		}

};

#endif