///////////////////////////////////////////////////////////
//  cTropaArqueros.cpp
//  Implementation of the Class cTropaArqueros
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#include "cTropaArqueros.h"


cTropaArqueros::cTropaArqueros( int tam, cPais* pais):cTropa("Arqueros", tam, pais){

}


cTropaArqueros::~cTropaArqueros(){

}

bool cTropaArqueros::Atacar(cTropa* atacado){

	//TODO: Ver todo este metodo 

	string opcion = atacado->getTipo();
	float Incremento;
	int NuevoATTotal;

	if (opcion == "arqueros") {
		Incremento = 0;
	}
		
	if (opcion == "magos") {
		Incremento = 0.25;

	}
	
	if (opcion == "caballeros") {
		Incremento = -0.25;

	}

	NuevoATTotal = ATTotal + ATTotal * Incremento;

	//ATACO
	atacado->RecibirDanio((int)NuevoATTotal);


	//SEGUNDA PROBABILIDAD DE ATAQUE	(SUPER OP)
	int aux_ataque2;
	float AT_2ataque=0;

	for (int i = 0; i <CA; i++)
	{
		Incremento = 0.5;
		aux_ataque2 = rand() % 100;

		cArqueros* aux = dynamic_cast<cArqueros*>(vector[i]);

		if (aux_ataque2 < aux->get2AT()) {
			AT_2ataque = AT_2ataque + vector[i]->getAT() + vector[i]->getAT()*Incremento;
		}
	}

	atacado->RecibirDanio((int)AT_2ataque);

	if (atacado->getCA() == 0)
		return true;
		//El Jugador ha ganado devolver TRUE para realizar la Reubicacion de las tropas

	//if (atacado->getCA() > 0) 
	//Contraatacar(atacado);
	//devolver false para indicar que el ataque no fue exitoso y que la topa recibio daño
}

void cTropaArqueros::Contraatacar(cTropa * atacante) {

	string opcion = atacante->getTipo();

	float Incremento;

	int NuevoATTotal;

	if (opcion == "arqueros")
		Incremento = 0;

	if (opcion == "magos")
		Incremento = 0.25;

	if (opcion == "caballeros")
		Incremento = -0.25;

	NuevoATTotal = ATTotal + ATTotal * Incremento;

	//ATACO
	atacante->RecibirDanio((int)NuevoATTotal);
		
	
	//El Jugador ha ganado devolver TRUE para realizar la Reubicacion de las tropas

	//if (atacado->getCA() > 0) 
	//Contraatacar(atacado);
	//devolver false para indicar que el ataque no fue exitoso y que la topa recibio daño
}
