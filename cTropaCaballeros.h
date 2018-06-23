///////////////////////////////////////////////////////////
//  cTropaCaballeros.h
//  Implementation of the Class cTropaCaballeros
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#if !defined(EA_70643682_4B55_4b6c_9B22_45B5CE3C7B8C__INCLUDED_)
#define EA_70643682_4B55_4b6c_9B22_45B5CE3C7B8C__INCLUDED_

#include "cTropa.h"

class cTropaCaballeros : public cTropa
{

public:
	///Const. y Dest.
	cTropaCaballeros(int tam, cPais*pais);
	virtual ~cTropaCaballeros();

	///Metodos
	bool Atacar(cTropa* atacado);
	void Contraatacar(cTropa* atacante);
	float Incremento(string tipo);
};
#endif // !defined(EA_70643682_4B55_4b6c_9B22_45B5CE3C7B8C__INCLUDED_)
