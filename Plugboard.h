#ifndef PLUGBOARD_H
#define PLUGBOARD_H
#include <utility>
#include <vector>
class Plugboard {
	public:
		void addPair(int x, int y);
		std::vector<std::pair<int,int>> pairs; //Keeps all "10" Wires of letter pairs which will be swapped
	
};
#endif