#include <string>
#include <iostream>
#include <ctime>
#include "cJuego.h"
#include "Funciones.h"
#define N_JUGADORES 2

int main() {
	system("mode con: cols=1280 lines=720");

	//Inicio Programa
		srand(time(NULL));
		int estado_juego;
		int cant_jug = N_MAX_JUGADORES;

		string n[N_JUGADORES];
	
		cin >> n; //sobrecarga cin
		cJuego* Juego = new cJuego(n,cant_jug);
		system("cls");

	//Inicio Simulador
		Juego->Bienvenida();
		Juego->Iniciar_Partida();			
		estado_juego = Juego->Jugar();
		Juego->CerrarJuego();
	
		delete n;
		delete Juego;

	return 0;
}
