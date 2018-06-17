///////////////////////////////////////////////////////////
//  cTropaMagos.cpp
//  Implementation of the Class cTropaMagos
//  Created on:      01-Jun.-2018 2:57:08 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#include "cTropaCaballeros.h"
#include "cTropaArqueros.h"
#include "cTropaMagos.h"

cTropaMagos::cTropaMagos(int tam,cPais*pais):cTropa("Magos",tam,pais){

}

cTropaMagos::~cTropaMagos(){

}

/*
bool cTropaMagos::Atacar(cTropa * atacado) {

	//TODO: DETERMINAR COMO VOY A HACER PARA QUE EL MAGO ATAQUE DIRECTAMENTE CON EL MISMO AT A TODAS LAS UNIDADES

	cTropaArqueros* aux_atacadoa = dynamic_cast<cTropaArqueros*>(atacado);
	if (aux_atacadoa != NULL) {

		string tipo = aux_atacadoa->getTipo();
		float aumento = Incremento(tipo);
		int NuevoATTotal;

		NuevoATTotal = ATTotal + ATTotal * aumento;

		//ATACO
		//aux_atacadoa->RecibirDanio((int)NuevoATTotal); // Este recibir ataque tiene que ser diferente

		//QUE PASO EN EL ATAQUE?

		if (aux_atacadoa->getCA() == 0)
			return true;
		//El jugador ha ganado, devolver TRUE para realizar la reubicacion de las tropas en el pais conquistado

		if (aux_atacadoa->getCA() > 0) {
			aux_atacadoa->Contraatacar(this);
			return false;
			//devolver FALSE para indicar que el ataque no fue exitoso y que la tropa recibio da�o
		}
	}

	cTropaMagos* aux_atacadom = dynamic_cast<cTropaMagos*>(atacado);
	if (aux_atacadom != NULL) {

		string tipo = aux_atacadom->getTipo();
		float aumento = Incremento(tipo);
		int NuevoATTotal;

		NuevoATTotal = ATTotal + ATTotal * aumento;

		//ATACO
		//aux_atacadom->RecibirDanio((int)NuevoATTotal);

		//QUE PASO EN EL ATAQUE?

		if (aux_atacadom->getCA() == 0) {
			cout << "Usted ha ganado el ataque." << endl;
			return true;
			//El jugador ha ganado, devolver TRUE para realizar la reubicacion de las tropas en el pais conquistado
		}
		if (aux_atacadom->getCA() > 0) {
			aux_atacadom->Contraatacar(this);
			return false;
			//devolver FALSE para indicar que el ataque no fue exitoso y que la tropa recibio da�o
		}
	}

	cTropaCaballeros* aux_atacadoc = dynamic_cast<cTropaCaballeros*>(atacado);
	if (aux_atacadoc != NULL) {

		string tipo = aux_atacadoc->getTipo();
		float aumento = Incremento(tipo);
		int NuevoATTotal;

		NuevoATTotal = ATTotal + ATTotal * aumento;

		//ATACO
		//aux_atacadoc->RecibirDanio(NuevoATTotal);

		//QUE PASO EN EL ATAQUE?

		if (aux_atacadoc->getCA() == 0)
			return true;
		//El jugador ha ganado, devolver TRUE para realizar la reubicacion de las tropas en el pais conquistado

		if (aux_atacadoc->getCA() > 0) {
			aux_atacadoc->Contraatacar(this);
			return false;
			//devolver FALSE para indicar que el ataque no fue exitoso y que la tropa recibio da�o
		}
	}
}
*/

bool cTropaMagos::Atacar(cTropa * atacado)
{
	return false;
}

void cTropaMagos::Contratacar(cTropa* atacante) {

	cTropaArqueros* aux_atacadoa = dynamic_cast<cTropaArqueros*>(atacante);
	if (aux_atacadoa != NULL) {

		string tipo = aux_atacadoa->getTipo();
		float aumento = Incremento(tipo);
		int NuevoATTotal;

		NuevoATTotal = ATTotal + (int)(ATTotal*aumento);

		//ATACO
		aux_atacadoa->RecibirDanio(NuevoATTotal);

		//QUE PASO EN EL CONTRAATAQUE?
		aux_atacadoa->RecibirDanio(ATTotal);
		if (aux_atacadoa->getCA() == 0)
			cout << "Su tropa no sobrevivio al contrataque" << endl;
		if (aux_atacadoa->getCA() > 0)
			cout << "Su tropa sobrevivio al contrataque" << endl;
	}

	cTropaMagos* aux_atacadom = dynamic_cast<cTropaMagos*>(atacante);
	if (aux_atacadom != NULL) {

		string tipo = aux_atacadom->getTipo();
		float aumento = Incremento(tipo);
		int NuevoATTotal;
		NuevoATTotal = ATTotal + (int)(ATTotal*aumento);

		//ATACO
		aux_atacadoa->RecibirDanio(NuevoATTotal);

		//QUE PASO EN EL CONTRAATAQUE?
		aux_atacadom->RecibirDanio(ATTotal);
		if (aux_atacadom->getCA() == 0)
			cout << "Su tropa no sobrevivio al contrataque" << endl;
		if (aux_atacadom->getCA() > 0)
			cout << "Su tropa sobrevivio al contrataque" << endl;
	}

	cTropaCaballeros* aux_atacadoc = dynamic_cast<cTropaCaballeros*>(atacante);
	if (aux_atacadoc != NULL) {

		string tipo = aux_atacadoc->getTipo();
		float aumento = Incremento(tipo);

		int NuevoATTotal;

		NuevoATTotal = ATTotal + (int)(ATTotal*aumento);

		//ATACO
		aux_atacadoa->RecibirDanio(NuevoATTotal);

		//QUE PASO EN EL CONTRAATAQUE?
		aux_atacadoc->RecibirDanio(ATTotal);
		if (aux_atacadoc->getCA() == 0)
			cout << "Su tropa no sobrevivio al contrataque" << endl;
		if (aux_atacadoc->getCA() > 0)
			cout << "Su tropa sobrevivio al contrataque" << endl;
	}

}

float cTropaMagos::Incremento(string tipo)
{
	if (tipo == "arqueros")
		return -0.25;

	if (tipo == "magos")
		return 0;

	if (tipo == "caballeros")
		return 0.25;
}
