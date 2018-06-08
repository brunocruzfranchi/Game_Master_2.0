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
#include <string.h>

class cTropa : public cListaT<cUnidades>
{
	public:
		///Atributos
		const string Tipo;
		//cPais* Pais;

		///Const. y Dest.
		cTropa( int tam);
		virtual ~cTropa();

		///Metodos
		
		
	protected:
		///Atributos
		//const int Max_Uni;
		//const int Min_Uni;
		
	
};
#endif // !defined(EA_8A40037E_4D59_4c58_A939_91FA7C445ABE__INCLUDED_)
