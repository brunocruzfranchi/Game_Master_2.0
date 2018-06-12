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
#include <iostream>

using namespace std;

class cTropa : public cListaT<class cUnidades>
{
	public:
		///Atributos
		const string Tipo;
		//cPais* Pais;

		///Const. y Dest.
		cTropa(int tam);
		virtual ~cTropa();

		///Metodos
		virtual void Atacar();
		virtual void RecibirDanio(int danio);
		
		///Template
		
		void Imprimir() { cout << Tipo << endl; }
		
	protected:
		///Atributos
		//const int Max_Uni;
		//const int Min_Uni;
		
	
};
#endif // !defined(EA_8A40037E_4D59_4c58_A939_91FA7C445ABE__INCLUDED_)
