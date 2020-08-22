#ifndef ENIGMA_H
#define ENIGMA_H

#include "Rotor.h"
#include "Plugboard.h"
/*
Brief code-relevant explanation on how the Enigma works by Akin Y.
The Enigma is made of 3 moving rotors and one static (not moving) Reflector and alphabetic input keyboard,
alphabetic output bulbs and the plugboard.

The rotors are connected.
If the first rotor does a full cycle (26 steps), the second rotor increments by one.
If the second rotor does a full cycle, the third rotor increments by one.
One rotor has an input alphabet and an output alphabet.
The internal wiring is usually randomly predefined, at the bottom of this page you can find tables for specific models 
https://en.wikipedia.org/wiki/Enigma_rotor_details.
So an input letter on rotor1 is translated to an output letter, which is input of the second rotor.
The reflector takes the last output increments by an specific offset and inverts the procedur.

The plugboard simply connects two pairs of letters which will be swapped before input travels trough first rotor.
After reflection it will be swapped again at the end.
*/
class Enigma {
public: 
	Enigma();
	int encrypt(int character);
	void rotateSet(); // Rotiert Enigma um 1
	void addRotor(Rotor r); //Rotor
	void addUKW(Rotor r); //Umkehrwalze
	void setConfiguration(int s, int m, int f); //Setzt innere Walzenverbindung
	int* getConfiguration(); //Zeiger auf 3-er Array mit der aktuellen Konfiguration
	~Enigma() {}
private:
	Plugboard p;
	std::vector<Rotor> set = {}; // Amount of rotors in the set
	Rotor ukw;
	int start_configuration[3] = { 0,0,0 }; // Amount of rotors in the set, left rotor slowest one
};
#endif