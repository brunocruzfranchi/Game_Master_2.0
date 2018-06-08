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
//hereda una lista en la que voy a acargar los paises dominados

class cJugador:public cListaT<cTropa>
{

public:
	///Atributos
	const int N_jugador;
	//cListaT<cTropa>* Tropas;
	//TIENE COMO 

	///Const. y Dest.
	cJugador(int n_jugador);
	virtual ~cJugador();

	///Metodos
		//principales
		void Distribuir(cTropa* t);
		void MoverTropas(cTropa* t);

		//getters
		int getN_Jugador() const { return N_jugador; }
		//cListaT<class cTropa> *getTropas() { return Lista; }	// manejo de tipos de psunteros
		//setters

};
#endif // !defined(EA_ECAD8CBF_DBA6_4277_A538_57274982E741__INCLUDED_)
