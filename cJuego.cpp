///////////////////////////////////////////////////////////
//  cJuego.cpp
//  Implementation of the Class cJuego
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////

#include "cJuego.h"
#include <iostream>

using namespace std;

cJuego::cJuego(int cant_jug) {
	CrearJugadores(cant_jug);
	CrearPaises();

}
cJuego::~cJuego() {
}

void cJuego::AsignarPaises(cJugador *jugador) {
	
}

void cJuego::AsignarTropas(cJugador *jugador) {
	
}

void cJuego::CambiarPais(cPais* pais, cJugador* ganador) {
	pais->setJugador(ganador->getN_Jugador());//sacar lista del perdedor
}

void cJuego::CrearJugadores(int n) {

	Jugadores = new cListaT<cJugador>(n);
	for (int i = 0; i < n; i++) {
		Jugadores->AgregarItem(new cJugador(i));
	}
}

void cJuego::CrearPaises()//Que es lo que hace esta funcion crear los paises individualmente o crear una lista de paises para ser usada 
{
	Paises=new cListaT<cPais>(12);//
	cPais *pais;
	
	cPais *paises[N_PAISES_TOTALES];
	paises[0]=new cPais("Argentina");
	paises[1]=new cPais("Bolivia");
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

	//genero mapa con paises limitrofes
	paises[0]->AgregarItem(paises[3]);


	//for agregando pais a lista paises;
} 

int cJuego::getRonda() {
	return Ronda;
}

int cJuego::Jugar() {
	int opcion;
	for (Ronda = 1; Ronda <= N_MAX_TURNOS; Ronda++)	{

		
		//Turnos
		for ( int k = 0; k < Jugadores->getCA(); k++)
		{
			//CambiarTurno(/*lista jugadores del template*/, k);
			//Listar paises dominados y pedir atacante
			//Pido tropa (magos,arqueros,caballeros);
		}
		if (Ronda == N_RONDAS)
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
		
		//Repartir paises

		for (int k = 0; k < N_MAX_JUGADORES; k++)
		{
			//Mover  Tropas
		}
		
	}

	return 0;
}

void cJuego::CambiarTurno(cJugador** Jugador, int k) {
	Jugador_de_turno = Jugador[k];
}

void cJuego::Iniciar_Partida() {
	
	//asignar paises inicial
	//asignacion inicial de tropas
	//bienvenido, juego iniciado
	//
}

void cJuego::ImprimirGanador() {
	//determinar ganador e imprimir
};
