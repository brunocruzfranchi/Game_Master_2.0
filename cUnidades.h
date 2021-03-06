///////////////////////////////////////////////////////////
//  cUnidades.h
//  Implementation of the Class cUnidades
//  Created on:      01-Jun.-2018 2:57:08 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////
#pragma once
#if !defined(EA_F44D8CC2_4472_4b58_BA7F_3E087AF8782D__INCLUDED_)
#define EA_F44D8CC2_4472_4b58_BA7F_3E087AF8782D__INCLUDED_

#include "cListaT.h"
#include <string>

using namespace std;

class cUnidades
{

public:
	///Atributos
	const string Tipo;
	const string Clave;
	static unsigned int Contador;

	///Const. y Dest.
	cUnidades(string tipo);
	virtual ~cUnidades();

	///Metodos
	bool DisminuirHP(int v = 1);

	//getters
	int getAT();
	int getHP();
	string getTipo() const { return Tipo; }
	string getclave()const { return Clave; }

	//setters
	void setAT(int at);
	void setHP(int hp);
		

protected:
	///Atributos
	int AT;
	int HP;
	
};
#endif // !defined(EA_F44D8CC2_4472_4b58_BA7F_3E087AF8782D__INCLUDED_)
