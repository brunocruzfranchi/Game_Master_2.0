///////////////////////////////////////////////////////////
//  cTropaCaballeros.cpp
//  Implementation of the Class cTropaCaballeros
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#include "cTropaCaballeros.h"
#include "cTropaArqueros.h"
#include "cTropaMagos.h"

cTropaCaballeros::cTropaCaballeros(int tam, cPais*pais) :cTropa("Caballeros", tam, pais) {
}

cTropaCaballeros::~cTropaCaballeros() {
}

bool cTropaCaballeros::Atacar(cTropa* atacado) {

	cTropaArqueros* aux_atacadoa = dynamic_cast<cTropaArqueros*>(atacado);
	if (aux_atacadoa != NULL) {

		string tipo = aux_atacadoa->getTipo();
		float aumento = Incremento(tipo);

		float NuevoATTotal = 0;
		NuevoATTotal = ATTotal + ATTotal * aumento;

		//ATACO
		aux_atacadoa->RecibirDanio((int)NuevoATTotal);

		//QUE PASO EN EL ATAQUE?
		if (aux_atacadoa->getCA() == 0) {
			cout << "Usted ha ganado el ataque." << endl;
			return true;
			//El jugador ha ganado, devolver TRUE para realizar la reubicacion de las tropas en el pais conquistado
		}
		if (aux_atacadoa->getCA() > 0) {
			*(aux_atacadoa)<<this;
			return false;
			//devolver FALSE para indicar que el ataque no fue exitoso y que la tropa recibio daño
		}
	}

	cTropaMagos* aux_atacadom = dynamic_cast<cTropaMagos*>(atacado);
	if (aux_atacadom != NULL) {

		string tipo = aux_atacadom->getTipo();
		float aumento = Incremento(tipo);

		float NuevoATTotal = 0;
		NuevoATTotal = ATTotal + ATTotal * aumento;

		//ATACO
		aux_atacadom->RecibirDanio((int)NuevoATTotal);

		//QUE PASO EN EL ATAQUE?

		if (aux_atacadom->getCA() == 0) {
			cout << "Usted ha ganado el ataque." << endl;
			return true;
			//El jugador ha ganado, devolver TRUE para realizar la reubicacion de las tropas en el pais conquistado
		}

		if (aux_atacadom->getCA() > 0) {
			*(aux_atacadom)<<this;
			return false;
			//devolver FALSE para indicar que el ataque no fue exitoso y que la tropa recibio daño
		}
	}

	cTropaCaballeros* aux_atacadoc = dynamic_cast<cTropaCaballeros*>(atacado);
	if (aux_atacadoc != NULL) {

		string tipo = aux_atacadoc->getTipo();
		float aumento = Incremento(tipo);

		float NuevoATTotal = 0;
		NuevoATTotal = ATTotal + ATTotal * aumento;

		//ATACO
		aux_atacadoc->RecibirDanio((int)NuevoATTotal);

		//QUE PASO EN EL ATAQUE?
		if (aux_atacadoc->getCA() == 0) {
			cout << "Usted ha ganado el ataque." << endl;
			return true;
			//El jugador ha ganado, devolver TRUE para realizar la reubicacion de las tropas en el pais conquistado
		}
		if (aux_atacadoc->getCA() > 0) {
			*(aux_atacadoc) << this;
			return false;
			//devolver FALSE para indicar que el ataque no fue exitoso y que la tropa recibio daño
		}
	}

	return false;
}

void cTropaCaballeros::Contraatacar(cTropa* atacante) {

	cTropaArqueros* aux_atacadoa = dynamic_cast<cTropaArqueros*>(atacante);
	if (aux_atacadoa != NULL) {

		string tipo = aux_atacadoa->getTipo();
		float aumento = Incremento(tipo);
		float NuevoATTotal = 0;
		NuevoATTotal = ATTotal + ATTotal * aumento;

		//ATACO
		aux_atacadoa->RecibirDanio((int)NuevoATTotal);

		//QUE PASO EN EL CONTRAATAQUE?
		if (aux_atacadoa->getCA() == 0)
			cout << "Su tropa no sobrevivio al contrataque" << endl;
		if (aux_atacadoa->getCA() > 0)
			cout << "Su tropa sobrevivio al contrataque" << endl;
	}

	cTropaMagos* aux_atacadom = dynamic_cast<cTropaMagos*>(atacante);
	if (aux_atacadom != NULL) {

		string tipo = aux_atacadom->getTipo();
		float aumento = Incremento(tipo);
		float NuevoATTotal = 0;
		NuevoATTotal = ATTotal + ATTotal * aumento;

		//ATACO
		aux_atacadom->RecibirDanio((int)NuevoATTotal);

		//QUE PASO EN EL CONTRAATAQUE?
		if (aux_atacadom->getCA() == 0)
			cout << "Su tropa no sobrevivio al contrataque" << endl;
		if (aux_atacadom->getCA() > 0)
			cout << "Su tropa sobrevivio al contrataque" << endl;
	}

	cTropaCaballeros* aux_atacadoc = dynamic_cast<cTropaCaballeros*>(atacante);
	if (aux_atacadoc != NULL) {

		string tipo = aux_atacadoc->getTipo();
		float aumento = Incremento(tipo);
		float NuevoATTotal = 0;
		NuevoATTotal = ATTotal + ATTotal * aumento;

		//ATACO
		aux_atacadoc->RecibirDanio((int)NuevoATTotal);

		//QUE PASO EN EL CONTRAATAQUE?
		if (aux_atacadoc->getCA() == 0)
			cout << "Su tropa no sobrevivio al contrataque" << endl;
		if (aux_atacadoc->getCA() > 0)
			cout << "Su tropa sobrevivio al contrataque" << endl;
	}
}

float cTropaCaballeros::Incremento(string tipo) {

	float incre = 0;
	if (tipo == "Arqueros" || tipo == "arqueros") 
		incre = 0.25;


	if (tipo == "Magos" || tipo == "magos")
		incre = -0.25;


	if (tipo == "Caballeros" || tipo == "caballeros")
		return incre;

	return incre;
}
