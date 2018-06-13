///////////////////////////////////////////////////////////
//  cTropa.cpp
//  Implementation of the Class cTropa
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: julie
///////////////////////////////////////////////////////////

#include "cTropa.h"

cTropa::cTropa(string tipo,int tam,cPais*pais):cListaT<cUnidades>(tam),Tipo(tipo){ //como inicializo las unidades de la lista? 
	int atq = 0;
	int hpp = 0;

	for (int  i = 0; i < tam; i++)
	{
		vector[i] = &cUnidades(tipo);
	}

	for (int i = 0; i < CA; i++) {

		atq = atq + vector[i]->getAT();
		hpp = hpp + vector[i]->getHP();
	}

	this->ATTotal = atq;
	this->HPTotal = hpp;
	this->Pais = pais;
}

cTropa::~cTropa(){

}

void cTropa::RecibirDanio(int danio)
{
	cUnidades*min;

	do {
		min = getHPMinimo();				//Busco la unidad de menor HP

		if (danio >= min->getHP())
		{
			danio = danio - min->getHP();
			Morir(min);
		}
		else
		{
			int aux = min->getHP();
			min->setHP(aux - danio);
			danio = danio - aux;

			if(min->getHP()<10) 
				Morir(min);
		}

	} while (danio > 0);


}

void cTropa::Morir(cUnidades * u)
{
	ATTotal = ATTotal - u->getHP();
	u->Claves_en_uso.Eliminar(u->Clave);
	Eliminar(u);
}
