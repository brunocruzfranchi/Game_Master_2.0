///////////////////////////////////////////////////////////
//  cTropaArqueros.h
//  Implementation of the Class cTropaArqueros
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#if !defined(EA_F8D5B892_CDDD_49eb_8FA4_F17C4DA02B86__INCLUDED_)
#define EA_F8D5B892_CDDD_49eb_8FA4_F17C4DA02B86__INCLUDED_

#include "cTropa.h"


class cTropaArqueros:public cTropa
{

public:
	///Const. y Dest.
	cTropaArqueros(int tam, cPais* pais);
	virtual ~cTropaArqueros();

	///Metodos
	bool Atacar(cTropa* atacado);
	void Contraatacar(cTropa* atacante);
	float Incremento(string tipo);
	void Segundo_AT(cTropa* atacado);	
};
#endif // !defined(EA_F8D5B892_CDDD_49eb_8FA4_F17C4DA02B86__INCLUDED_)
