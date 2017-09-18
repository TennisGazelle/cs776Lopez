#ifndef __KEY_H_
#define __KEY_H_

#include <iostream>
#include <vector>

#define MAX_KEY_SIZE 150

class Key : public std::vector<bool> {
public:
	Key();
	Key(int size);
	~Key();

	std::vector<int> toIntArray() const;

	void print() const;

	void toggleAt(int index);
	bool getValAt(int index);
};
#endif
