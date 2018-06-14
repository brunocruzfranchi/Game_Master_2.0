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
#include <iomanip>
#include <stdlib.h>
using namespace std;

class cTropa:public cListaT<class cUnidades>{

	public:
		///Atributos
		//agregar numero de serie o simil???
		const string Tipo;
		int ATTotal;
		int HPTotal;
		cPais* Pais;

		///Const. y Dest.
		cTropa(string tipo, int tam, cPais* pais);
		virtual ~cTropa();

		///Metodos
		virtual void Atacar(cTropa* atacado) = 0;
		virtual void Contraatacar(cTropa* t) = 0;
		virtual void RecibirDanio(int danio);
		

		void Morir(cUnidades * u);
		void setPais(cPais*p) { Pais = p; };
		
		///getters
		cPais*getPais() { return Pais; }
		string getNombrePais() { return Pais->getNombre(); }

		///Template
		string getclave() { return Tipo; }
		void Imprimir() { cout <<"  Tipo: "<< Tipo << setw(8)<<
			"Ataque Total: "<< ATTotal <<setw(8) << 
			"Vida Total: " << HPTotal << setw(8)<<
			"N de Unidades en la tropa: "<< CA << endl; }
		
	protected:
		///Atributos
		//const int Max_Uni;
		//const int Min_Uni;
			
};
#endif // !defined(EA_8A40037E_4D59_4c58_A939_91FA7C445ABE__INCLUDED_)
