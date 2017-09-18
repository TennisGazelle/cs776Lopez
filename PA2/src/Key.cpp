#ifndef __KEY_CPP_
#define __KEY_CPP_

#include "Key.h"

Key::Key() {
	for (int i = 0; i < MAX_KEY_SIZE; i++) {
		push_back(0);
	}
}

Key::Key(int size) {
	for (int i = 0; i < size; i++) {
		push_back(0);
	}
}

Key::~Key() {
}

void Key::print() const {
	for (unsigned int i = 0; i < this->size(); i++) {
		std::cout << at(i);
	}
	std::cout << std::endl;
}

std::vector<int> Key::toIntArray() const {
	std::vector<int> intArray(MAX_KEY_SIZE);
	for (unsigned int i = 0; i < this->size(); i++) {
		intArray[i] = this->at(i);
	}
	return intArray; // stub
}

void Key::toggleAt(int index) {
	this->at(index) = !this->at(index);
}

bool Key::getValAt(int index) {
	return this->at(index);
}
#endif
