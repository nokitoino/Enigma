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
	int getEncryption(int plain); //Interne Verschl¸sselung
	int getDecryption(int encrypted); //Nach Refkletion benˆtigen wir Entschl¸sselung (Abbildung invertiert)
	int getTurnOver(); //Walzen¸bertrag zum linken Nachbarn, wenn dieser Buchstabe erreicht wird
	void setTurnOver(int character_number); //Setze Walzen¸bertragskerbe
	~Rotor() {}
private:
	int rotor[26] = {0};
	int turnOver = 0;//‹bertragskerbe, Walzen¸bertrag zum linken Nachbarn, wenn dieser Buchstabe zur n‰chsten fortdreht
	// Walze 1: Q->R Walze 2: E->F Walze 3: V->W Walze 4: J -> K Walze 5: Z->A
	//Wir notieren R,F,W,K,A. Auﬂerdem gilt A = 0, B = 1, ... 
};
#endif