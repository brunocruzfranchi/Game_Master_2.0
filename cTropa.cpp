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
#define N_MAX_UNIDADES_EN_TROPA 500

unsigned int cTropa::Contador = 0;

cTropa::cTropa(string tipo,int tam,cPais*pais):cListaT<cUnidades>(N_MAX_UNIDADES_EN_TROPA),Tipo(tipo),Clave(to_string(Contador)){ 
	
	int atq = 0, hp=0;
	
//cambiar constructor
	if(tipo=="Magos")
	for (int  i = 0; i < tam; i++)
	{
		AgregarItem( new cMagos());
	}
	if (tipo == "Arqueros")
		for (int i = 0; i < tam; i++)
		{
			AgregarItem( new cArqueros());
		}
	if (tipo == "Caballeros")
		for (int i = 0; i < tam; i++)
		{
			AgregarItem( new cCaballeros());
		}

	for (int i = 0; i < CA; i++) {

		atq = atq + vector[i]->getAT();
		hp = hp + vector[i]->getHP();
		
	}

	this->ATTotal = atq;
	this->HPTotal = hp;
	this->Pais = pais;
	Contador++;
	
}

cTropa::~cTropa(){

}

void cTropa::Contraatacar(cTropa * atacante)
{
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
			HPTotal = HPTotal - danio;
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

void cTropa::Distribuir(int tipo, int tam)
{
	if (tipo == 0)
	{
		for (int i = 0; i < tam; i++)
		{
			cMagos*u_m = new cMagos();
			AgregarItem(u_m);
			operator++(u_m->getHP());
		}
	}

	if (tipo == 1)
	{
		for (int i = 0; i < tam; i++)
		{
			cArqueros*u_a = new cArqueros();
			AgregarItem(u_a);
			operator++(u_a->getHP());
		}
	}

	if (tipo == 2)
	{
		for (int i = 0; i < tam; i++)
		{
			cCaballeros*u_c = new cCaballeros();
			AgregarItem(u_c);
			operator++(u_c->getHP());
		}
	}
	
	cout << endl << "Tropa distribuida satisfactoriamente" << endl;

}

void cTropa::Morir(cUnidades * u)
{
	ATTotal = ATTotal - u->getAT();
	HPTotal = HPTotal - u->getHP();
	u->Contador--;
	operator-(u);
}
void cTropa::operator++ (int hpu) {
	//AGREGA A VIDA TOTAL

	HPTotal = HPTotal + hpu;
}

bool cTropa::operator>(cTropa * t)
{
	bool aux=Atacar(t);
	return aux;
}

void cTropa::operator<(cTropa * t)
{
	Contraatacar(t);
}

void cTropa::operator!=(int i)
{
	RecibirDanio(i);
}
