///////////////////////////////////////////////////////////
//  cTropaMagos.h
//  Implementation of the Class cTropaMagos
//  Created on:      01-Jun.-2018 2:57:08 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#if !defined(EA_24685A5A_0EAB_429f_8E3B_0704AF7A41A3__INCLUDED_)
#define EA_24685A5A_0EAB_429f_8E3B_0704AF7A41A3__INCLUDED_

#include "cTropa.h"

class cTropaMagos:public cTropa
{

public:

	///Const. y Dest.
	cTropaMagos(int tam,cPais*pais);
	virtual ~cTropaMagos();

	///Metodos
	bool Atacar(cTropa* atacado);
	void Contraatacar(cTropa* atacante);
	float Incremento(string tipo);
	void AtaqueMagico(cPais* pais, int ataque);
};
#endif // !defined(EA_24685A5A_0EAB_429f_8E3B_0704AF7A41A3__INCLUDED_)
