///////////////////////////////////////////////////////////
//  cJuego.h
//  Implementation of the Class cJuego
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////

#if !defined(EA_25249AF9_B8BF_441f_95EC_C0B1C8876E76__INCLUDED_)
#define EA_25249AF9_B8BF_441f_95EC_C0B1C8876E76__INCLUDED_

#include "cJugador.h"
#include "cListaT.h"
#include <string>

using namespace std;

class cJuego : public cListaT<class T>
{

public:
	cJuego(int jugador = -1);
	virtual ~cJuego();
	void AsignarPaises(cJugador Jug);
	void AsignarTropas(cJugador Jug);
	void CambiarPais(cPais* pais, cJugador* ganador);
	void CrearJugadores(int n = 2);
	void CrearPaises(cListaT<cPais> *listapaises);
	int getRondas();
	int Jugar();
	void TurnoAtaque(cJugador **Jugador);
	int Rondas;
	int Jugador_de_turno;
	void Iniciar_Partida();
	void ImprimirGanador();
	int getJugador_de_turno() { return Jugador_de_turno; }
	void setJugador_de_turno(int j) {
		if (j == 0 || j == 1) Jugador_de_turno = j;
	}

};
#endif // !defined(EA_25249AF9_B8BF_441f_95EC_C0B1C8876E76__INCLUDED_)
