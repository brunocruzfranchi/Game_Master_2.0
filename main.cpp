#include <string>
#include <iostream>
#include <ctime>
#include "cListaT.h"
#include "Funciones.h"
#define N_PAISES_TOTALES 12
#define N_MAX_JUGADORES 2

int main() {

	int estado_juego;
	cListaT <cPais> Paises(N_PAISES_TOTALES);
	cListaT <cJugador> Jugadores(N_MAX_JUGADORES);

	cJuego* Juego = new cJuego;	

	Generar_Paises(Paises);								
	Juego->Iniciar_Partida();
	estado_juego = Juego->Jugar();

	return 0;
}
