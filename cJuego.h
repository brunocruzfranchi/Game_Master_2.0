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

#define N_MAX_TURNOS 500
#define N_MAX_JUGADORES 2
#define N_RONDAS 10
#define N_PAISES_TOTALES 13

using namespace std;

class cJuego : public cListaT<class T>
{

public:
	///Atributos
	
	int Ronda;
	cJugador* Jugador_de_turno;
	cListaT<cPais> *Paises;
	cListaT<cJugador> *Jugadores;
	///Const y Dest
	cJuego(int cant_jug=2);
	virtual ~cJuego();

	///Metodos
		//Crear
		void CrearJugadores(int n = 2);								
		void CrearPaises();	

		//Inicio Juego
		int Jugar();
		void Iniciar_Partida();
		void AsignarPaises(cJugador *Jug);							
		void AsignarTropas(cJugador *Jug);	
		
		//getters
		int getRonda();	
		cJugador* getJugador_de_turno() { return Jugador_de_turno; }
		
		//setters	
		void setJugador_de_turno(cJugador* j) {	Jugador_de_turno = j;}

		//Extras
		void ReasignarPais(cPais* pais, cJugador* ganador);
		void CambiarTurno(cJugador **Jugador, int k);
		void ImprimirGanador();



};
#endif // !defined(EA_25249AF9_B8BF_441f_95EC_C0B1C8876E76__INCLUDED_)
