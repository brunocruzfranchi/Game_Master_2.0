#include <string>
#include <iostream>
#include <ctime>
#include "cJuego.h"
#include "Funciones.h"


int main() {
	system("mode con: cols=1280 lines=720");

	//Inicio Programa
		srand(time(NULL));
		int estado_juego;
		int cant_jug = N_MAX_JUGADORES;
		cJuego* Juego = new cJuego(cant_jug);

	//Inicio Simulador
		Juego->Bienvenida();
		Juego->Iniciar_Partida();			//si es static la accedo desde todo el juego o se la paso a Juego
		estado_juego = Juego->Jugar();
		Juego->CerrarJuego();
		delete Juego;

	return 0;
}
