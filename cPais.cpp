///////////////////////////////////////////////////////////
//  cPais.cpp
//  Implementation of the Class cPais
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#include "cPais.h"


cPais::cPais(string nombre):Nombre(nombre){

}

cPais::~cPais(){

}

void cPais::Distribuir(cTropa* t){

}

cPais** cPais::getLimitrofes(){
	return  NULL;
}

/**
 * ESTE ES CONST
 */

const string cPais::getNombre(){

	return  NULL;
}

void cPais::setLimitrofes(cPais** limitrofes){
	Limitrofes = limitrofes;
}

void cPais::setTropa(cTropa** m){
	Magos = m;
}