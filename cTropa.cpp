///////////////////////////////////////////////////////////
//  cTropa.cpp
//  Implementation of the Class cTropa
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: julie
///////////////////////////////////////////////////////////

#include "cTropa.h"

const char cadena[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "0123456789" };

cListaT<string> cUnidades::Claves_en_uso = cListaT<string>(COD_MAX);

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

	int aux, flag = 0;
	string * aux_p;

	while (flag == 0)
	{

		Clave = " ";
		//srand(time(NULL));
		for (unsigned int i = 0; i < N_COD; i++)
		{
			aux = rand() % (sizeof(cadena) - 1);
			Clave += cadena[aux];
		}
		unsigned int h;
		for (h = 0; h < Claves_en_uso.getCA(); h++)
		{
			if (*(Claves_en_uso.getItem(h)) == Clave)
				break;
		}

		aux_p = Claves_en_uso.BuscarItem(Clave); // busco repetidos

		if (aux_p == NULL)// no encontre repetidos
		{
			flag = 1;

			Claves_en_uso.AgregarItem(&Clave);// agrego a lista static
		}
	}

	delete aux_p;
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
	u->Claves_en_uso.Eliminar(u->Clave);
	Eliminar(u);
}
