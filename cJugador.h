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
class cJugador : public cListaT<class T>
{

public:
	cListaT<class cTropa> *Tropas;
	///Atributos
	///Const. y Dest.
	cJugador(int n_jugador);

	virtual ~cJugador();
	const int N_jugador;

	void Distribuir(cTropa* t);
	void MoverTropas(cTropa* t);
	int getN_Jugador() const { return N_jugador; }
	cListaT<class cTropa> *getTropas() { return Tropas; }// manejo de tipos de punteros

};
#endif // !defined(EA_ECAD8CBF_DBA6_4277_A538_57274982E741__INCLUDED_)
