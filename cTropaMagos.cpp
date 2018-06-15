///////////////////////////////////////////////////////////
//  cTropaMagos.cpp
//  Implementation of the Class cTropaMagos
//  Created on:      01-Jun.-2018 2:57:08 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#include "cTropaMagos.h"


cTropaMagos::cTropaMagos(int tam):cTropa(tam){

}



cTropaMagos::~cTropaMagos(){

}

void cTropaMagos::Atacar(cTropa * atacado){

	string opcion = atacado->Tipo;

	if (opcion == "arqueros") {

		for 
		//Primero ataco a la tropa
		//Si esta sobrevivio, me haces el contraataque
		//Sino tengo que hacer la reubicacion de las tropas

		//Como los magos son debiles contra los arqueros el ATTotal decrementa en un 25% 

		int NuevoATTotal = ATTotal - ATTotal * 0.25;

		//TODO: DETERMINAR COMO VOY A HACER PARA QUE EL MAGO ATAQUE DIRECTAMENTE CON EL MISMO AT A TODAS LAS UNIDADES
		//TODO: VOY A TENER QUE HACER UN VIRTUAL DE RECIBIR ATAQUE?
	
		atacado->RecibirDanio((int)NuevoATTotal);

		if (atacado->getCA() == 0) {
			//El Jugador ha ganado devolver TRUE para realizar la Reubicacion de las tropas
		}

		if (atacado->getCA() > 0) {
			atacado->Contraatacar(/*como accedo a mi misma tropa?*/);
			//devolver false para indicar que el ataque no fue exitoso y que la topa recibio daño
		}

	}

	if (opcion == "magos") {
		//Primero ataco a la tropa
		//Si esta sobrevivio, me haces el contraataque
		//Sino tengo que hacer la reubicacion de las tropas

		atacado->RecibirDanio(ATTotal);

		if (atacado->getCA() == 0) {
			//El Jugador ha ganado devolver TRUE para realizar la Reubicacion de las tropas
		}

		if (atacado->getCA() > 0) {
			atacado->Contraatacar(/*como accedo a mi misma tropa?*/);
			//devolver false para indicar que el ataque no fue exitoso y que la topa recibio daño
		}

	}

	if (opcion == "caballeros") {

		//Primero ataco a la tropa
		//Si esta sobrevivio, me haces el contraataque
		//Sino tengo que hacer la reubicacion de las tropas

		//Como los magos son fuertes contra los caballeros el ATTotal aumenta en un 25% 

		int NuevoATTotal = ATTotal + ATTotal * 0.25;

		atacado->RecibirDanio((int)NuevoATTotal);

		if (atacado->getCA() == 0) {
			//El Jugador ha ganado devolver TRUE para realizar la Reubicacion de las tropas
		}

		if (atacado->getCA() > 0) {
			atacado->Contraatacar(/*como accedo a mi misma tropa?*/);
			//devolver false para indicar que el ataque no fue exitoso y que la topa recibio daño
		}

	}
}

void cTropaMagos::Contraatacar(cTropa * t){
	
}

