///////////////////////////////////////////////////////////
//  cArqueros.h
//  Implementation of the Class cArqueros
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////

#if !defined(EA_15DC52D4_8D07_4cb9_BFA9_653F9D1BDF5D__INCLUDED_)
#define EA_15DC52D4_8D07_4cb9_BFA9_653F9D1BDF5D__INCLUDED_

#include "cUnidades.h"

class cArqueros : public cUnidades
{

public:	
	///Atributos
	const int Prob_2AT; 
	
	///Const. y Dest.
	cArqueros(int prob, string tipo);
	virtual ~cArqueros();

	///Metodos
	void Atacar(cTropa* atacado);
	void Contraatacar(cTropa* t);
	
};
#endif // !defined(EA_15DC52D4_8D07_4cb9_BFA9_653F9D1BDF5D__INCLUDED_)
