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

class cTropa : public cListaT<class T>
{

public:
	cTropa(int max, int min, string tipo);
	virtual ~cTropa();
	const string Tipo;
	//cPais* Pais;
	virtual void Atacar(cTropa* atacado) = 0;
	virtual void Contraatacar(cTropa* t) = 0;

protected:
	const int Max_Uni;
	const int Min_Uni;
	/*public:
	cTropa();
	virtual ~cTropa();
	const string Tipo;
	cPais* Pais:
	virtual void Atacar(cTropa* atacado) = 0;
	virtual void Contraatacar(cTropa* t) = 0;

protected:
	const int Max_Uni;
	const int Min_Uni;*/
};
#endif // !defined(EA_8A40037E_4D59_4c58_A939_91FA7C445ABE__INCLUDED_)
