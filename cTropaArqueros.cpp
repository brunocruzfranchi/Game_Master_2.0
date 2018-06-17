///////////////////////////////////////////////////////////
//  cTropaArqueros.cpp
//  Implementation of the Class cTropaArqueros
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#include "cTropaArqueros.h"
#include "cTropaMagos.h"
#include "cTropaCaballeros.h"

cTropaArqueros::cTropaArqueros( int tam, cPais* pais):cTropa("Arqueros", tam, pais){

}

cTropaArqueros::~cTropaArqueros(){

}

bool cTropaArqueros::Atacar(cTropa* atacado) {

	cTropaArqueros* aux_atacadoa = dynamic_cast<cTropaArqueros*>(atacado);
	if (aux_atacadoa != NULL){
		
		string tipo = aux_atacadoa->getTipo();
		float aumento = Incremento(tipo);
		int NuevoATTotal;

		NuevoATTotal = ATTotal + (int)(ATTotal*aumento);

		//ATACO
		aux_atacadoa->RecibirDanio(NuevoATTotal);

		//SEGUNDA PROBABILIDAD DE ATAQUE	(SUPER OP)

		Segundo_AT(aux_atacadoa);

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
	if (aux_atacadom != NULL){

		string tipo = aux_atacadom->getTipo();
		float aumento = Incremento(tipo);
		int NuevoATTotal;

		NuevoATTotal = ATTotal + (int)(ATTotal*aumento);

		//ATACO
		aux_atacadoa->RecibirDanio(NuevoATTotal);

		//SEGUNDA PROBABILIDAD DE ATAQUE	(SUPER OP)

		Segundo_AT(aux_atacadom);

		//QUE PASO EN EL ATAQUE?
		if (aux_atacadom->getCA() == 0){
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
	if (aux_atacadoc != NULL){

		string tipo = aux_atacadoc->getTipo();
		float aumento = Incremento(tipo);
		int NuevoATTotal;

		NuevoATTotal = ATTotal + (int)(ATTotal*aumento);

		//ATACO
		aux_atacadoa->RecibirDanio(NuevoATTotal);

		//SEGUNDA PROBABILIDAD DE ATAQUE	(SUPER OP)

		Segundo_AT(aux_atacadoc);

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

void cTropaArqueros::Contraatacar(cTropa* atacante) {

	/*cTropaArqueros* aux_atacadoa = dynamic_cast<cTropaArqueros*>(atacante); 
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
	if(aux_atacadoc != NULL) {

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
			cout << "Su tropa sobrevivio al contrataque" << endl;*/
	}
/*
	if (opcion == "magos")
		Incremento = 0.25;*/

float cTropaArqueros::Incremento(string tipo){

	if (tipo == "arqueros")
		return 0;

	if (tipo == "magos")
		return 0.25;

	if (tipo == "caballeros")
		return -0.25;

}

void cTropaArqueros::Segundo_AT(cTropa* atacado){
	int aux_ataque2;
	float AT_2ataque = 0;
	float aumento;
	for (int i = 0; i <CA; i++)
	{
		aumento = 0.5;
		aux_ataque2 = rand() % 101;

		cArqueros* aux = dynamic_cast<cArqueros*>(vector[i]);

		if (aux_ataque2 < aux->get2AT()) {
			AT_2ataque = AT_2ataque + vector[i]->getAT() + vector[i]->getAT()*aumento;
		}
	}
	atacado->RecibirDanio((int)AT_2ataque);
}
