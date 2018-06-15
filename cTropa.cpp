///////////////////////////////////////////////////////////
//  cTropa.cpp
//  Implementation of the Class cTropa
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: julie
///////////////////////////////////////////////////////////

#include "cTropa.h"
#include "cMagos.h"
#include "cArqueros.h"
#include "cCaballeros.h"

unsigned int cTropa::Contador = 0;

cTropa::cTropa(string tipo,int tam,cPais*pais):cListaT<cUnidades>(tam),Tipo(tipo),Clave(to_string(Contador)){ 
	
	int atq = 0;
	int hpp = 0;
//cambiar constructor
	if(tipo=="Magos")
	for (int  i = 0; i < tam; i++)
	{
		vector[i] = new cMagos();
	}
	if (tipo == "Arqueros")
		for (int i = 0; i < tam; i++)
		{
			vector[i] = new cArqueros();
		}
	if (tipo == "Caballeros")
		for (int i = 0; i < tam; i++)
		{
			vector[i] = new cCaballeros();
		}

	for (int i = 0; i < CA; i++) {

		atq = atq + vector[i]->getAT();
		hpp = hpp + vector[i]->getHP();
	}

	this->ATTotal = atq;
	this->HPTotal = hpp;
	this->Pais = pais;
	Contador++;
	
}

cTropa::~cTropa(){

}

void cTropa::RecibirDanio(int danio)
{
	cUnidades*min;
	int cont = 0;
	do {
		min = getHPMinimo();				//Busco la unidad de menor HP

		if (danio >= min->getHP())
		{
			danio = danio - min->getHP();
			Morir(min);
			//cont++;
		}
		else
		{
			int aux = min->getHP();
			min->setHP(aux - danio);
			danio = danio - aux;

			if (min->getHP() < 10)
			{
				Morir(min);
				//cont++;
			}
		}

	} while (danio > 0);

	//return cont;
}

void cTropa::Morir(cUnidades * u)
{
	ATTotal = ATTotal - u->getHP();
	u->Contador--;
	Eliminar(u);
}
