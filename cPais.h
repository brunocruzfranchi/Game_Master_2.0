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
	cPais(string nombre);
	virtual ~cPais();
	const string Nombre;
	void Distribuir(cTropa* t);
	const string getNombre();

private:
	/**
	 * Este jugador es el que domina al pais
	 */
	int Jugador;

};
#endif // !defined(EA_AACE9F59_8DC5_4a64_8EC1_D3B95EB49799__INCLUDED_)
