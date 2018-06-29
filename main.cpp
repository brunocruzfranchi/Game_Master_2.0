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
		string** n= new string*;
		for (int i=0; i < cant_jug; i++)
			n[i] = new string;
		cin >> n;
		cJuego* Juego = new cJuego(n,cant_jug);
		system("cls");
	//Inicio Simulador
		Juego->Bienvenida();
		Juego->Iniciar_Partida();			//si es static la accedo desde todo el juego o se la paso a Juego
		estado_juego = Juego->Jugar();
		Juego->CerrarJuego();
		for (int i = 0; i < cant_jug; i++) {
			delete n[i];
		}
		delete n;
		delete Juego;

	return 0;
}
