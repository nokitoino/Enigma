#include "Enigma.h"
#include <iostream>
Enigma::Enigma() {
	
}
int Enigma::encrypt(int character) {
	rotateSet();
	return set[2].getDecryption(set[1].getDecryption(set[0].getDecryption(ukw.getEncryption(set[0].getEncryption(set[1].getEncryption(set[2].getEncryption(character))))))); // Rotor encryption

}
int* Enigma::getConfiguration() {
	return start_configuration;
}
void Enigma::addRotor(Rotor r) { //Erst schnellsten Rotor hinzufügen
	set.push_back(r);
}
void Enigma::addUKW(Rotor r) {
	ukw = r;
}
void Enigma::setConfiguration(int s, int m, int f) {
	
}
void Enigma::rotateSet() {
	if (set.size() != 3) { 
		std::cout << "We need 3 Rotors" << std::endl;
		return; 
	}
	int &s = start_configuration[0]; //slowest
	int &m = start_configuration[1]; //middle
	int &f = start_configuration[2]; //fastest

	f++;
	set[2].incrementRotor(1); //Inkrementiert auch die Walze um 1
	if (f % 26 == 0) {
		f = 0;
	}
	if (f == set[1].getTurnOver()) {
		m++;
		set[1].incrementRotor(1);
		if (m % 26 == 0) {
			m = 0;
		}
		if (m == set[0].getTurnOver()) {
			s++;
			set[0].incrementRotor(1);
			if (s % 26 == 0) {
				s = 0;
			}
			/*Use this line for more rotors or even a moving reflector*/
		}
	}

}