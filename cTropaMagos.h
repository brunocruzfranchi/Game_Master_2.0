///////////////////////////////////////////////////////////
//  cTropaMagos.h
//  Implementation of the Class cTropaMagos
//  Created on:      01-Jun.-2018 2:57:08 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#if !defined(EA_24685A5A_0EAB_429f_8E3B_0704AF7A41A3__INCLUDED_)
#define EA_24685A5A_0EAB_429f_8E3B_0704AF7A41A3__INCLUDED_

#include "cTropa.h"

class cTropaMagos : public cTropa
{

public:
	cTropaMagos();
	virtual ~cTropaMagos();

	void Atacar(cTropa* atacado);
	void Contraatacar(cTropa* t);

};
#endif // !defined(EA_24685A5A_0EAB_429f_8E3B_0704AF7A41A3__INCLUDED_)
