///////////////////////////////////////////////////////////
//  cPais.cpp
//  Implementation of the Class cPais
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#include "cPais.h"

cListaT<cPais> cPais::Lista_Paises = cListaT<cPais>(N_PAISES_TOTALES);

cPais::cPais(string nombre):Nombre(nombre){

	Lista_Paises.AgregarItem(&cPais(nombre));// loop infinito???

}

cPais::~cPais(){
}

/*
void cPais::Distribuir(cTropa* t){

}

cPais** cPais::getLimitrofes(){
	return  NULL;
}

void cPais::setLimitrofes(cPais** limitrofes){
	//Limitrofes = limitrofes;
}

void cPais::setTropa(cTropa** m){
	//Magos = m;
}
*/