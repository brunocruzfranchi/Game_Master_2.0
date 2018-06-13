///////////////////////////////////////////////////////////
//  cUnidades.cpp
//  Implementation of the Class cUnidades
//  Created on:      01-Jun.-2018 2:57:08 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#include "cUnidades.h"
#include <ctime>

const char cadena[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "0123456789" };

cListaT<string> cUnidades::Claves_en_uso = cListaT<string>(COD_MAX);



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
	srand(time(NULL));
	at = minat + rand() % (maxat - minat + 1);
	srand(time(NULL));
	hp = minhp + rand() % (maxhp - minhp + 1);
	this->AT = at;
	this->HP = hp;
	
	int aux, flag = 0;
	cUnidades * aux_p;

	while (flag == 0)
		{
			
			Clave = "";
			srand(time(NULL));
			for (unsigned int i = 0; i < N_COD; i++)
			{
				aux = rand() % (sizeof(cadena) - 1);
				Clave += cadena[aux];
			}
			/*unsigned int h;
			for (h = 0; h < Claves_en_uso[0]->CA; h++)
			{
				if (Claves_en_uso[h] == Clave)
					break;
			}
			*/

			aux_p=Claves_en_uso->BuscarItem(Clave); // busco repetidos

			if (aux_p==NULL)// no encontre repetidos
			{
				flag = 1;

				Claves_en_uso->AgregarItem(Clave);// agrego a lista static
			}


		}
		
	delete aux_p;
}

cUnidades::~cUnidades(){
}

bool cUnidades::DisminuirHP(int v)
{
	HP=HP-v;
	if (HP < 10)  return false;
	else
	 return true;
		
}

int cUnidades::getAT(){	return AT;}

int cUnidades::getHP(){	return HP;}

void cUnidades::setAT(int at){	AT=at;}

void cUnidades::setHP(int hp){	HP=hp;}

