#include "Rotor.h"
#include <iostream> // REMOVE
Rotor::Rotor() {

}
void Rotor::incrementRotor(int k) {
	int stored = rotor[0];
	for (int i = 0; i <= 24; i++) {
		rotor[i] = rotor[i + 1];
	}
	rotor[25] = stored;
}
Rotor::Rotor(const Rotor& r) {
	for (int i = 0; i < 26; i++) {
		rotor[i] = r.rotor[i];
	}
	turnOver = r.turnOver;
}
void Rotor::createRotor(int* seed) {
	for (int i = 0; i < 26; i++) {
		rotor[i] = seed[i];
	}
}
int* Rotor::string_to_rotor(std::string s) {
	for (int i = 0; i < s.length(); i++) {
		rotor[i] = s[i] - 65; //Converts A -> 0, B->1, ... in ASCII
	}

	for (int j = 0; j < 26; j++) {
		std::cout << rotor[j] << " ";
	}
	std::cout << std::endl;


	return rotor;
}
int Rotor::getEncryption(int plain) {
	return rotor[plain];
}
int Rotor::getDecryption(int encrypted) {
	for (int i = 0; i < 26; i++) {
		if (rotor[i] == encrypted) {
			return i;
		}
	}
}
int Rotor::getTurnOver() {
	return turnOver;
}
void Rotor::setTurnOver(int character_number) {
	turnOver = character_number;
}