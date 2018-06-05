///////////////////////////////////////////////////////////
//  cUnidades.cpp
//  Implementation of the Class cUnidades
//  Created on:      01-Jun.-2018 2:57:08 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#include "cUnidades.h"


cUnidades::cUnidades(){
}

cUnidades::~cUnidades(){
}

int cUnidades::getAT(){
	return AT;
}


int cUnidades::getHP(){
	return HP;
}

string cUnidades::getTipo(){
	return Tipo;
}


void cUnidades::setAT(int at){
	AT=at;
}


void cUnidades::setHP(int hp){
	HP=hp;
}