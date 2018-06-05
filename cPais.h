///////////////////////////////////////////////////////////
//  cPais.h
//  Implementation of the Class cPais
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#if !defined(EA_AACE9F59_8DC5_4a64_8EC1_D3B95EB49799__INCLUDED_)
#define EA_AACE9F59_8DC5_4a64_8EC1_D3B95EB49799__INCLUDED_

#include "cListaT.h"
#include "cTropa.h"
#include <string>
using namespace std;

class cPais : public cListaT<class T>
{

public:
	static cListaT<cPais> **Lista_Paises;
	const string Nombre;
	int Jugador;
	cPais(string nombre);
	virtual ~cPais();
	//void Distribuir(cTropa* t);
	const string getNombre();
	//cPais** getLimitrofes();
	int getJugador() { return Jugador; }
	void setJugador(int j) { Jugador = j; }

private:
	/**
	* Este jugador es el que domina al pais
	*/


};
#endif // !defined(EA_AACE9F59_8DC5_4a64_8EC1_D3B95EB49799__INCLUDED_)

