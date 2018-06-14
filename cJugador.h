///////////////////////////////////////////////////////////
//  cJugador.h
//  Implementation of the Class cJugador
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#if !defined(EA_ECAD8CBF_DBA6_4277_A538_57274982E741__INCLUDED_)
#define EA_ECAD8CBF_DBA6_4277_A538_57274982E741__INCLUDED_

#include "cPais.h"
#include "cListaT.h"
#include <iostream>
#include <string>
#include <stdlib.h>
//hereda una lista en la que voy a acargar los paises dominados

using namespace std;

class cJugador:public cListaT<class cTropa>{

public:
	///Atributos
	const string N_jugador;
	cListaT<cPais>* PaisesDominados;

	///Const. y Dest.
	cJugador(string n_jugador);
	virtual ~cJugador();

	///Metodos
		//principales
		void Distribuir(cTropa* t);
		void MoverTropas(cPais*pais, cPais*atacante);
		void ImprimirTropasenPais(cPais*pais);
		void ImprimirTropasenPais(string nombre);
		int Contar_e_ImpTropasenPais(cPais*pais);

		//getters
		string getN_Jugador() const { return N_jugador; }
		cListaT<class cPais> *getPaisesD() { return PaisesDominados; }	// manejo de tipos de psunteros

		//setters
		//void setPaisesD(cListaT<class cPais> *listad) { PaisesDominados = listad; }

		//Lista Template
		string getclave() { return N_jugador; }
		void ImprimirJugador() { cout << "Jugador " << N_jugador << endl;}
		void Imprimir();

};
#endif // !defined(EA_ECAD8CBF_DBA6_4277_A538_57274982E741__INCLUDED_)
