///////////////////////////////////////////////////////////
//  cTropaMagos.cpp
//  Implementation of the Class cTropaMagos
//  Created on:      01-Jun.-2018 2:57:08 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#include "cTropaCaballeros.h"
#include "cTropaArqueros.h"
#include "cTropaMagos.h"

cTropaMagos::cTropaMagos(int tam, cPais*pais) :cTropa("Magos", tam, pais) {

}

cTropaMagos::~cTropaMagos() {

}


bool cTropaMagos::Atacar(cTropa * atacado) {

	//TODO: DETERMINAR COMO VOY A HACER PARA QUE EL MAGO ATAQUE DIRECTAMENTE CON EL MISMO AT A TODAS LAS UNIDADES

	cTropaArqueros* aux_atacadoa = dynamic_cast<cTropaArqueros*>(atacado);
	if (aux_atacadoa != NULL) {

		string tipo = aux_atacadoa->getTipo();
		float aumento = Incremento(tipo);
		cPais* pais_atacado = atacado->getPais();
		float NuevoATTotal;
		NuevoATTotal = ATTotal + ATTotal * aumento;

		AtaqueMagico(pais_atacado, (int)NuevoATTotal);

		//QUE PASO EN EL ATAQUE?
		if (aux_atacadoa->getCA() == 0) {
			cout << "Usted ha ganado el ataque." << endl;
			return true;
			//El jugador ha ganado, devolver TRUE para realizar la reubicacion de las tropas en el pais conquistado
		}

		if (aux_atacadoa->getCA() > 0) {
			*(aux_atacadoa) << this;
			return false;
			//devolver FALSE para indicar que el ataque no fue exitoso y que la tropa recibio da�o
		}
	}

	cTropaMagos* aux_atacadom = dynamic_cast<cTropaMagos*>(atacado);
	if (aux_atacadom != NULL) {

		string tipo = aux_atacadom->getTipo();
		float aumento = Incremento(tipo);
		cPais* pais_atacado = atacado->getPais();
		float NuevoATTotal;
		NuevoATTotal = ATTotal + ATTotal * aumento;

		AtaqueMagico(pais_atacado, (int)NuevoATTotal);

		//QUE PASO EN EL ATAQUE?
		if (aux_atacadom->getCA() == 0) {
			cout << "Usted ha ganado el ataque." << endl;
			return true;
			//El jugador ha ganado, devolver TRUE para realizar la reubicacion de las tropas en el pais conquistado
		}

		if (aux_atacadom->getCA() > 0) {
			*(aux_atacadom) << this;
			return false;
			//devolver FALSE para indicar que el ataque no fue exitoso y que la tropa recibio da�o
		}
	}

	cTropaCaballeros* aux_atacadoc = dynamic_cast<cTropaCaballeros*>(atacado);
	if (aux_atacadoc != NULL) {

		string tipo = aux_atacadoc->getTipo();
		float aumento = Incremento(tipo);
		cPais* pais_atacado = atacado->getPais();

		float NuevoATTotal = 0;
		NuevoATTotal = ATTotal + ATTotal * aumento;

		AtaqueMagico(pais_atacado, (int)NuevoATTotal);

		//QUE PASO EN EL ATAQUE?
		if (aux_atacadoc->getCA() == 0) {
			cout << "Usted ha ganado el ataque." << endl;
			return true;
			//El jugador ha ganado, devolver TRUE para realizar la reubicacion de las tropas en el pais conquistado
		}

		if (aux_atacadoc->getCA() > 0) {
			*(aux_atacadoc) << this;
			return false;
			//devolver FALSE para indicar que el ataque no fue exitoso y que la tropa recibio da�o
		}
	}

	return true;
}

void cTropaMagos::Contraatacar(cTropa* atacante) {

	cTropaArqueros* aux_atacadoa = dynamic_cast<cTropaArqueros*>(atacante);
	if (aux_atacadoa != NULL) {

		string tipo = aux_atacadoa->getTipo();
		float aumento = Incremento(tipo);

		float NuevoATTotal = 0;
		NuevoATTotal = ATTotal + ATTotal * aumento;

		//ATACO
		aux_atacadoa->RecibirDanio((int)NuevoATTotal);

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

float cTropaMagos::Incremento(string tipo) {
	float incre = 0;

	if (tipo == "Arqueros" || tipo == "arqueros")
		incre = -0.25;

	if (tipo == "Magos" || tipo == "magos")
		return incre;

	if (tipo == "Caballeros" || tipo == "caballeros")
		incre = 0.25;

	return incre;
}

void cTropaMagos::AtaqueMagico(cPais * pais, int ataque)
{
	cJugador* jugador = pais->getJugador();
	int N_tropas = jugador->Contar_Tropas_en_Pais(pais);
	int cont = 0;
	for (int i = 0; i < N_tropas; i++)
	{
		if ((*jugador)[i]->getPais() == pais){

			((*jugador)[i])->RecibirDanio(ataque);
			//*(*(jugador) == (i)) != (ataque);
			cont++;
		}
		if (cont == N_tropas)
			break;
	}

}

