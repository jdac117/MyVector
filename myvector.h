#pragma once
#ifndef DELANGEL_MYVECTOR_H
#define DELANGEL_MYVECTOR_H

#include <cstddef>
#include <stdexcept>

template<typename T>
class MyVector {
	T* elem;
	std::size_t array_size; //how mabny elements are ACTUALLY stored (size())
	std::size_t space; // how many elements the array has room for (capacity, reserve())
public:
	MyVector() {
		elem = nullptr;
		array_size = 0;
		space = 0;	
	}

	~MyVector(){
		delete[] elem; // runs automatically when the vector goes out of scope
	}

	// precent copying (prevent undefined behavior or memory leak)
	MyVector(const MyVector&) = delete;
	MyVector& operator=(const MyVector&) = delete;

	// return the number of elements in container
	std::size_t size() const {
		return array_size;
	}

	// return the alocated capacity
	std::size_t capacity() const {
		return space;
	}

	void reserve(std::size_t new_capacity){
		if (new_capacity <= space){
			return; // already big enough! nothing to do
		}

		T* new_elem = new T[new_capacity];

		// copy new elements into bigger array
		try
		{
			for (std::size_t i = 0; i < array_size; i++){
				new_elem[i] = elem[i];
			}
		}
		catch(...) {
			delete[] new_elem;
			throw;
		}

		// relase old array (after copy succeeds) and switch to new bigger array
		delete[] elem;
		elem = new_elem;
		space = new_capacity;
	}

	void push_back(const T& value) {
		if (array_size == space){
			if (space == 0) {
				reserve(1); // start with room for 1 if first element
			}
			else {
				reserve(space * 2); // double - keep push back fast
			}
		}

		elem[array_size] = value;
		array_size++;
	}

	T& at(std::size_t index){
		if(index >= array_size){
			throw std::out_of_range("Index out of range!");
		}

		return elem[index];
	}
};

#endif
