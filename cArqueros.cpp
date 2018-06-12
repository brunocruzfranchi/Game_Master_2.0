///////////////////////////////////////////////////////////
//  cArqueros.cpp
//  Implementation of the Class cArqueros
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////

#include "cArqueros.h"

cArqueros::cArqueros(string tipo):cUnidades(tipo){
	
	srand(time(NULL));
	this->Prob_2AT = rand() % 101;

}

cArqueros::~cArqueros(){
}

void cArqueros::Atacar(cTropa * atacado)
{
}

void cArqueros::Contraatacar(cTropa * t)
{
}
