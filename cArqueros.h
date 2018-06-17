///////////////////////////////////////////////////////////
//  cArqueros.h
//  Implementation of the Class cArqueros
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////

#if !defined(EA_15DC52D4_8D07_4cb9_BFA9_653F9D1BDF5D__INCLUDED_)
#define EA_15DC52D4_8D07_4cb9_BFA9_653F9D1BDF5D__INCLUDED_

#include "cUnidades.h"
#include <ctime>
class cArqueros : public cUnidades
{

public:	
	///Atributos
	int Prob_2AT;
	
	///Const. y Dest.
	cArqueros();
	virtual ~cArqueros();
	int get2AT() { return Prob_2AT; }
	///Metodos
	/*void Atacar(cTropa* atacado);
	void Contraatacar(cTropa* t);*/
	
};
#endif // !defined(EA_15DC52D4_8D07_4cb9_BFA9_653F9D1BDF5D__INCLUDED_)
