///////////////////////////////////////////////////////////
//  cUnidades.cpp
//  Implementation of the Class cUnidades
//  Created on:      01-Jun.-2018 2:57:08 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#include "cUnidades.h"


cUnidades::cUnidades(string tipo):Tipo(tipo){
	int at, hp, maxat, minat, minhp,maxhp;
	if (tipo == "Magos")
	{
		minat = 10;
		maxat = 20;
		minhp = 40;
		maxhp = 60;

	}
	if (tipo == "Arqueros")
	{
		minat = 20;
		maxat = 30;
		minhp = 60;
		maxhp = 80;

	}
	if (tipo == "Caballeros")
	{
		minat = 30;
		maxat = 40;
		minhp = 80;
		maxhp = 100;

	}

	at = minat + rand() % (maxat - minat + 1);
	hp = minhp + rand() % (maxhp - minhp + 1);
	this->AT = at;
	this->HP = hp;
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