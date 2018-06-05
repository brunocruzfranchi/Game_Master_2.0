///////////////////////////////////////////////////////////
//  cUnidades.h
//  Implementation of the Class cUnidades
//  Created on:      01-Jun.-2018 2:57:08 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#if !defined(EA_F44D8CC2_4472_4b58_BA7F_3E087AF8782D__INCLUDED_)
#define EA_F44D8CC2_4472_4b58_BA7F_3E087AF8782D__INCLUDED_

#include <string>
using namespace std;

class cUnidades
{

public:
	///Const. y Dest.
	cUnidades(int at, int hp, string tipo);
	virtual ~cUnidades();

	///Metodos
		//getters
		int getAT();
		int getHP();
		string getTipo();
		//setters
		void setAT(int at);
		void setHP(int hp);

protected:
	///Atributos
	int AT;
	int HP;
	const string Tipo;

};
#endif // !defined(EA_F44D8CC2_4472_4b58_BA7F_3E087AF8782D__INCLUDED_)
