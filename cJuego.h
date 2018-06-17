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
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define N_MAX_TURNOS 500
#define N_MAX_JUGADORES 2
#define N_RONDAS 10
#define N_PAISES_TOTALES 13
#define N_MAX_ATAQUES 3

using namespace std;

class cPais;
class cTropa;
class cJuego : public cListaT<cJugador>
{

public:
	///Atributos
	int Ronda;
	cJugador* Jugador_de_turno;
	cListaT<cPais> *Paises;
	
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
		void AsignarTropas(int n=1);	
		
		//Durante Juego
		cPais* Buscar_p_atacante(int k);
		cPais* Buscar_p_atacado(cPais* atacante);
		cTropa* Buscar_t_atacante(int k,  cPais* atacante);
		cTropa* Buscar_t_atacada(int k, cPais* atacado);
		cTropa* PedirTropaDistribucion(int tipo, int k);
		void Movilizar_tropas(int k);
		void AgregarTropaaPais(int k, int tam_tropa,cPais* pais, int aleatorio);

		//getters
		int getRonda();	
		cJugador* getJugador_de_turno() { return Jugador_de_turno; }
		
		//setters	
		void setJugador_de_turno(cJugador* j) {	Jugador_de_turno = j;}

		//extras
		void ReasignarPais(cPais* atacado, cPais* atacante);
		void CambiarTurno(cJugador **Jugador, int k);
		void Imprimir();
		void ImprimirGanador();

};
#endif // !defined(EA_25249AF9_B8BF_441f_95EC_C0B1C8876E76__INCLUDED_)

bool repetidos(int n, int num[]);