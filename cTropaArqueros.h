///////////////////////////////////////////////////////////
//  cTropaArqueros.h
//  Implementation of the Class cTropaArqueros
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#if !defined(EA_F8D5B892_CDDD_49eb_8FA4_F17C4DA02B86__INCLUDED_)
#define EA_F8D5B892_CDDD_49eb_8FA4_F17C4DA02B86__INCLUDED_

#include "cTropa.h"

class cTropaArqueros : public cTropa
{

public:
	cTropaArqueros();
	virtual ~cTropaArqueros();

	void Atacar(cTropa* atacante);
	void Contraatacar(cTropa* t);

};
#endif // !defined(EA_F8D5B892_CDDD_49eb_8FA4_F17C4DA02B86__INCLUDED_)
