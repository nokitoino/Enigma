#include <iostream>
#include "Enigma.h"

int main(int argc, char** argv) {
	std::string roemischEins = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
	std::string roemischZwei = "AJDKSIRUXBLHWTMCQGZNPYFVOE"; 
	std::string roemischDrei = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
	std::string reflektor_A = "EJMZALYXVBWFCRQUONTSPIKHGD";

	Enigma e;
	Rotor f,m,s, ukw;
	s.createRotor(s.string_to_rotor(roemischEins));
	m.createRotor(s.string_to_rotor(roemischZwei));
	f.createRotor(s.string_to_rotor(roemischDrei));
	ukw.createRotor(s.string_to_rotor(reflektor_A));

	s.setTurnOver(0);
	m.setTurnOver(0);
	f.setTurnOver(0);

	e.addRotor(s);
	e.addRotor(m);
	e.addRotor(f);
	e.addUKW(ukw);

	std::cout << "Enigma 1 mit statischem Reflektor A implementiert in C++" << std::endl;
	std::cout << "Abstrakt Programmiert. Es koennen maximal drei detaillierte Walzen und eine statische Umkehrwalze hinzugefügt werden." << std::endl;
	std::cout << "Mit wenig zusaetzlichem Code kann es auf Enigma-G mit X Walzen und drehbarer UKW veraendert werden." << std::endl;
	std::cout << "Programmiert von Akin Y.\n" << std::endl;
	std::string eingabe;
	while (true) {
		std::cin >> eingabe;
		for (int i = 0; i < eingabe.length(); i++) {
			std::cout << (char)(e.encrypt(eingabe[i]-97)+97);
		}
		std::cout << std::endl;
		std::cout << e.getConfiguration()[0] << " " << e.getConfiguration()[1] << " " << e.getConfiguration()[2] << std::endl;
	}
	return 0;
}