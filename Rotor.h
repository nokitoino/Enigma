#ifndef ROTOR_H
#define ROTOR_H
#include <string>
class Rotor {
public:
	Rotor();
	Rotor(const Rotor& r);
	void createRotor(int* seed); //bijektion vom Alphabet Eingang auf Alphabet Ausgang
	void incrementRotor(int k); //Dreht die Walze um k
	int* string_to_rotor(std::string s); //Wandelt String Abbildung f: Alphabet->Alphabet in Rotorsatz um
	int getEncryption(int plain); //Interne Verschlüsselung
	int getDecryption(int encrypted); //Nach Refkletion benötigen wir Entschlüsselung (Abbildung invertiert)
	int getTurnOver(); //Walzenübertrag zum linken Nachbarn, wenn dieser Buchstabe erreicht wird
	void setTurnOver(int character_number); //Setze Walzenübertragskerbe
	~Rotor() {}
private:
	int rotor[26] = {0};
	int turnOver = 0;//Übertragskerbe, Walzenübertrag zum linken Nachbarn, wenn dieser Buchstabe zur nächsten fortdreht
	// Walze 1: Q->R Walze 2: E->F Walze 3: V->W Walze 4: J -> K Walze 5: Z->A
	//Wir notieren R,F,W,K,A. Außerdem gilt A = 0, B = 1, ... 
};
#endif