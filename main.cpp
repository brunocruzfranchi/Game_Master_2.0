#include <string>
#include <iostream>
#include <ctime>
#include "cListaT.h"
#include "Funciones.h"
#define N_PAISES_TOTALES 12

int main() {

	int estado_juego;
	cListaT <cPais> Paises(N_PAISES_TOTALES);
	cListaT <cJugador> Jugadores(2);
	cJuego Juego;

	Juego = GenerarJuego();

	Generar_Paises(Paises);
	GenerarJugadores(Jugadores);
	Juego.Iniciar_Partida();
	estado_juego = Juego.Jugar();

	return 0;
}
