#ifndef __KEY_H_
#define __KEY_H_

#include <vector>

class Key : std::vector<bool> {
public:
	Key();
	~Key();

	void fromIntArray(int *incomingArray);
	std::vector<int> toIntArray() const;

	void toggleAt(int index);
	bool getValAt(int index);
};
#endif
