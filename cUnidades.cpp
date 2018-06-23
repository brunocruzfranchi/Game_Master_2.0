///////////////////////////////////////////////////////////
//  cUnidades.cpp
//  Implementation of the Class cUnidades
//  Created on:      01-Jun.-2018 2:57:08 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////
#pragma once
#include "cUnidades.h"
#include <ctime>
#define at_Magos 10
#define AT_Magos 20
#define hp_Magos 40
#define HP_Magos 60
#define at_Arqueros 20
#define AT_Arqueros 30
#define hp_Arqueros 60
#define HP_Arqueros 80
#define at_Caballeros 30
#define AT_Caballeros 40
#define hp_Caballeros 80
#define HP_Caballeros 100

const char cadena[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "0123456789" };

unsigned int cUnidades::Contador = 0;

cUnidades::cUnidades(string tipo):Tipo(tipo),Clave(to_string(Contador)){

	int at, hp, maxat, minat, minhp,maxhp;

	if (tipo == "Magos")
	{
		minat = at_Magos;
		maxat = AT_Magos;
		minhp = hp_Magos;
		maxhp = HP_Magos;

	}
	if (tipo == "Arqueros")
	{
		minat = at_Arqueros;
		maxat =AT_Arqueros;
		minhp = hp_Arqueros;
		maxhp = HP_Arqueros;

	}
	if (tipo == "Caballeros")


	{
		minat = at_Caballeros	;
		maxat = AT_Caballeros;
		minhp = hp_Caballeros;
		maxhp = HP_Caballeros;

	}
	at = minat + rand() % (maxat - minat + 1);
	hp = minhp + rand() % (maxhp - minhp + 1);
	this->AT = at;
	this->HP = hp;
	Contador++;
}

cUnidades::~cUnidades(){
}

bool cUnidades::DisminuirHP(int v)
{
	HP=HP-v;
	if (HP < 10)  
		return false;
	else
		return true;
		
}

int cUnidades::getAT(){return AT;}

int cUnidades::getHP(){return HP;}

void cUnidades::setAT(int at){AT=at;}

void cUnidades::setHP(int hp){HP=hp;}

