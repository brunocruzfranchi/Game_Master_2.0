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

#include <stdio.h>
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


class cTropa;
class cJugador;
class cJuego : public cListaT<cJugador>{
	friend class cPais;
public:
	///Atributos
	int Ronda;
	cJugador* Jugador_de_turno;
	cListaT<cPais> *Paises;
	
	///Const y Dest
	cJuego(string*n,int cant_jug=2);
	virtual ~cJuego();

	///Metodos
		//Crear
		void CrearJugadores( string *nombres, int n = 2);
		void CrearPaises();	

		//Inicio Juego
		int Jugar();
		void Iniciar_Partida();
		void AsignarPaises();
		void AsignarTropas(int n=1);
		void AsignacionTropasInicial();
		void Bienvenida();
		
		//Durante Juego
		cPais* Buscar_p_atacante(int k);
		cPais* Buscar_p_atacado(cPais* atacante);
		cTropa* Buscar_t_atacante(int k, cPais* atacante,cPais * atacado);
		cTropa* Buscar_t_atacada(int h, cPais*atacante,cPais* atacado);
		cTropa* PedirTropaDistribucion(int tipo, int k);
		void Movilizar_tropas(int k);
		void AgregarTropaaPais(int k, int tam_tropa,cPais* pais, int aleatorio);

		void AgregarTropaInicial(int k, int tam_tropa, cPais * pais, int aleatorio);

		//getters
		int getRonda();	
		cJugador* getJugador_de_turno() { return Jugador_de_turno; }
		
		//setters	
		void setJugador_de_turno(cJugador* j) {	Jugador_de_turno = j;}

		//extras
		void ReasignarPais(cPais* atacado, cPais* atacante);
		void CambiarTurno(cJugador **Jugador, int k);
		void CerrarJuego();
		cJugador* getGanador();
		cJugador* Desempate(cJugador*j1, cJugador*j2);
		cJugador* BuscarMax();
		void operator == (int k);

		//Imprimir
		void Imprimir();
		void ImprimirGanador();
		void ImprimirTurnoAtarque();
		void ImprimirJugador(int k);
		void PrintJug1();
		void PrintJug2();
		void GanadorJug1();
		void GanadorJug2();
		void EncabezadoPais();

};
#endif // !defined(EA_25249AF9_B8BF_441f_95EC_C0B1C8876E76__INCLUDED_)

bool repetidos(int n, int num[]);