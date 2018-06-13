///////////////////////////////////////////////////////////
//  cTropaCaballeros.cpp
//  Implementation of the Class cTropaCaballeros
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#include "cTropaCaballeros.h"

cTropaCaballeros::cTropaCaballeros(int tam/*int max, int min, string tipo*/):cTropa(tam){
}

cTropaCaballeros::~cTropaCaballeros(){

}

void cTropaCaballeros::Atacar(cTropa * atacado){

	string opcion = atacado->Tipo;

	if (opcion == "arqueros") {
		//Primero ataco a la tropa
		//Si esta sobrevivio, me haces el contraataque
		//Sino tengo que hacer la reubicacion de las tropas

		//Como los caballeros son fuertes contra los arqueros el ATTotal incrementa en un 25% 

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

	if (opcion == "magos") {
		//Primero ataco a la tropa
		//Si esta sobrevivio, me haces el contraataque
		//Sino tengo que hacer la reubicacion de las tropas
		
		//Como los caballeros son debiles contra los magos el ATTotal disminuye en un 25% 

		int NuevoATTotal = ATTotal - ATTotal * 0.25;

		atacado->RecibirDanio((int)NuevoATTotal);
	
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
		
		atacado->RecibirDanio(ATTotal);

		if (atacado->getCA() == 0) {
			//El Jugador ha ganado devolver TRUE para realizar la Reubicacion de las tropas
		}

		if (atacado->getCA() > 0) {
			atacado->Contraatacar(/*como accedo a mi misma tropa?*/);
			//devolver false para indicar que el ataque no fue exitoso y que la topa recibio daño
		}

	}
}

void cTropaCaballeros::Contratacar(cTropa * tt)
{
}
