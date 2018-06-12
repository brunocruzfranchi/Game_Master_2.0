///////////////////////////////////////////////////////////
//  cTropa.cpp
//  Implementation of the Class cTropa
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: julie
///////////////////////////////////////////////////////////

#include "cTropa.h"

cTropa::cTropa(string tipo,int tam):cListaT<cUnidades>(tam) ,Tipo(tipo){ //como inicializo las unidades de la lista? 
	int atq = 0;
	for (int  i = 0; i < tam; i++)
	{
		vector[i] = &cUnidades(tipo);
	}

	for (int i = 0; i < CA; i++) {

		atq = atq + vector[i]->getAT;
	}

	this->ATTotal = atq;
}

cTropa::~cTropa(){
}
void cTropa::Atacar()
{
	


}

void cTropa::RecibirDanio(int danio)
{
	
}

void cTropa::Morir(cUnidades * u)
{
	ATTotal = ATTotal - u->getAT();
	u->Claves_en_uso->Eliminar(u->getclave());
	Eliminar(u);
}
