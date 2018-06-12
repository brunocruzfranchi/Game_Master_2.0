///////////////////////////////////////////////////////////
//  cTropa.cpp
//  Implementation of the Class cTropa
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: julie
///////////////////////////////////////////////////////////

#include "cTropa.h"

cTropa::cTropa(int tam):cListaT<cUnidades>(tam){
	
}

cTropa::~cTropa(){
}
void cTropa::Atacar()
{
	int ataque_total = 0;

	for (int  i = 0; i < getCA(); i++)
	{
		/*ataque_total=*/
	}


}

void cTropa::RecibirDanio(int danio)
{
	
}
