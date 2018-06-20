///////////////////////////////////////////////////////////
//  cTropa.h
//  Implementation of the Class cTropa
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: julie
///////////////////////////////////////////////////////////

#if !defined(EA_8A40037E_4D59_4c58_A939_91FA7C445ABE__INCLUDED_)
#define EA_8A40037E_4D59_4c58_A939_91FA7C445ABE__INCLUDED_

#include "cUnidades.h"
#include "cListaT.h"
#include "cPais.h"
#include "cArqueros.h"
#include "cMagos.h"
#include "cCaballeros.h"

#include <string.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class cTropa :public cListaT<class cUnidades> {

public:
	///Atributos

	const string Tipo;
	const string Clave;
	static unsigned int Contador;
	int ATTotal;
	int HPTotal;
	cPais* Pais;

	///Const. y Dest.
	cTropa(string tipo, int tam, cPais* pais);
	virtual ~cTropa();

	///Metodos
	virtual bool Atacar(cTropa* atacado) = 0;
	virtual void Contraatacar(cTropa* atacante);
	virtual void RecibirDanio(int danio);
	virtual float Incremento(string tipo) = 0;
	void Distribuir(int tipo, int tam);
	void operator ++ (int hpu);
	bool operator >(cTropa*t);
	void operator <(cTropa*t);
	void operator !=(int i);
	void Morir(cUnidades * u);
	void setPais(cPais*p) { Pais = p; };

	///getters
	cPais* getPais() { return Pais; }
	string getNombrePais() { return Pais->getNombre(); }
	int getATtotal() { return ATTotal; }
	int getHPTotal() { return HPTotal; }
	void getHPTotal(int h) { HPTotal = h; }

	///Template
	string getclave() { return Clave; }
	string getTipo() { return Tipo; }
	void Imprimir() {
		cout << endl << "Clave: " << Clave << setw(8) <<
			" Tipo: " << Tipo << setw(8) <<
			"Ataque Total: " << ATTotal << setw(8) <<
			"Vida Total: " << HPTotal << setw(8) <<
			"N de Unidades en la tropa: " << CA << endl;
	}

protected:
	///Atributos
	//const int Max_Uni;
	//const int Min_Uni;

};
#endif // !defined(EA_8A40037E_4D59_4c58_A939_91FA7C445ABE__INCLUDED_)
