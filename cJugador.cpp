///////////////////////////////////////////////////////////
//  cJugador.cpp
//  Implementation of the Class cJugador
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#include "cJugador.h"


cJugador::cJugador(string n_jugador):N_jugador(n_jugador){
	this->PaisesDominados = new cListaT<cPais>();
}

cJugador::~cJugador(){

}

void cJugador::Distribuir(cTropa* t){

}

void cJugador::MoverTropas(cTropa* t){

}

void cJugador::Imprimir()
{
	cout<< 
}
