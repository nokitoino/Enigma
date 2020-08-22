#include "Plugboard.h"

void Plugboard::addPair(int x, int y) {
	pairs.push_back(std::make_pair(x, y));
}