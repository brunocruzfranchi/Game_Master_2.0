///////////////////////////////////////////////////////////
//  cJuego.cpp
//  Implementation of the Class cJuego
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////

#include "cJuego.h"
#include <iostream>
#define N_MAX_TURNOS 500
#define N_MAX_JUGADORES 2
using namespace std;

cJuego::cJuego() {
}

cJuego::~cJuego() {
}

void cJuego::AsignarPaises(cJugador jugador) {
	
}

void cJuego::AsignarTropas(cJugador jugador) {

}

void cJuego::CambiarPais(cPais* pais, cJugador* ganador) {

}

void cJuego::CrearJugadores(int n) {

	cJugador** jugadores = new cJugador*[n];
	for (int i = 0; i < n; i++) {
		//jugadores[i] = cJugador(i);
	}
}

void cJuego::CrearPaises(cListaT<cPais> *listapaises) {
	cPais** paises = new cPais*[12];
	paises[0] = new cPais("Argentina");
	paises[1] = new cPais("Bolivia");
	paises[2] = new cPais("Brasil");
	paises[3] = new cPais("Chile");
	paises[4] = new cPais("Colombia");
	paises[5] = new cPais("Ecuador");
	paises[6] = new cPais("Guyana");
	paises[7] = new cPais("Paraguay");
	paises[8] = new cPais("Peru");
	paises[9] = new cPais("Surinam");
	paises[10] = new cPais("Uruguay");
	paises[11] = new cPais("Venezuela");
	for (int i = 0; i < 12; i++)
		listapaises->AgregarItem(paises[i]);
}

int cJuego::getRondas() {
	return Rondas;
}


int cJuego::Jugar() {
	int opcion;
	for (Rondas = 0; Rondas < N_MAX_TURNOS; Rondas++)	{
		//Turnos
		for ( int k = 0; k < N_MAX_JUGADORES; k++)
		{
			CambiarTurno(/*lista jugadores del template*/, k);
			//Listar paises dominados y pedir atacante
			//Listo y pido tropa (magos,arqueros,caballeros);
		}
		
		if (Rondas == 10)
		{
			cout << endl << "Desea continuar el juego?" << endl
				<< " Presione 1 para finalizar. Cualquier otra tecla para continuar" << endl;
			cin >> opcion;
			cout << endl;
			if (opcion == 1)
			{
				ImprimirGanador();
				return 0; // conviene usar una excepcion?
			}
		}
	}

	return 0;
}

void cJuego::CambiarTurno(cJugador** Jugador, int k) {
	Jugador_de_turno = Jugador[k];
}

void cJuego::Iniciar_Partida() {
	
}

void cJuego::ImprimirGanador() {
	//determinar ganador e imprimir
};
