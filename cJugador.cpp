///////////////////////////////////////////////////////////
//  cJugador.cpp
//  Implementation of the Class cJugador
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////


#include "cTropa.h"
#include "cPais.h"

cJugador::cJugador(int n_jugador):N_jugador(to_string(n_jugador+1)){
	
	this->PaisesDominados = new cListaT<cPais>(N_PAISES_TOTALES);
}

cJugador::~cJugador(){

}



void cJugador::MoverTropas(cPais*ganado , cPais*atacante){

	string opcion_tropa;
	int opcion_mover, N_tropas = 0, flag = 0;

	N_tropas = Contar_e_ImpTropasenPais(atacante);
		
	for (int i = 0; i < N_tropas-1; i++)
	{
		if (flag != 0)
		{
			ImprimirTropasenPais(atacante);
		}

		flag++;
		cout << "Que tropa desea mover? " << endl;
		int aux;
		do {			
			cin >> opcion_tropa; cout << endl; //pido clave de la tropa
			aux = getItemPos(opcion_tropa);

		} while (aux==INT_MAX);
		
		vector[aux]->setPais(ganado);
		cout <<endl<< "Tropa trasladada satisfactoriamente";

		do {
			cout << endl << "Desea mover mas tropas de "<<atacante->getNombre()<<" a "<<ganado->getNombre()<<"?" << endl << "1. Si " << endl << "2. No" << endl;
			cin >> opcion_mover; cout << endl;
			if(opcion_mover==2)
			{
				system ("cls");
				return;
			}
		} while (opcion_mover != 1);
		
		system("cls");
	}

	cout <<endl<< "No es posible mover mas tropas" << endl;
}

void cJugador::ImprimirTropasenPais(cPais * pais)
{
	cout << endl << "Tropas disponibles en "<<pais->getNombre() << endl;
	for (int i = 0; i < CA; i++)
	{
		if (vector[i]->getPais()->getclave() == pais->getclave())
		{
			vector[i]->Imprimir();
		}
	}
}

void cJugador::ImprimirTropasenPais(string nombre)
{
	cout << endl << "Tropas disponibles en " << nombre << endl;
	for (int i = 0; i < CA; i++)
	{
		if (vector[i]->getPais()->getNombre() == nombre)
		{
			vector[i]->Imprimir();
		}
	}
}

void cJugador::ImprimirTropasenPais(string nombre, string tipo)
{
	cout << endl << "Tropas disponibles en " << nombre <<" del tipo "<<tipo<< endl;
	for (int i = 0; i < CA; i++)
	{
		if (vector[i]->getPais()->getNombre() == nombre)
		{
			if (vector[i]->getTipo() == tipo)
			vector[i]->Imprimir();
		}
	}
}

void cJugador::ImprimirTropasenPais(cPais * pais, string tipo)
{

	cout << endl << "Tropas disponibles en " << pais->getNombre() << " del tipo " << tipo << endl;
	for (int i = 0; i < CA; i++)
	{
		if (vector[i]->getPais()->getclave() == pais->getclave())
		{
			if(vector[i]->getTipo()==tipo)
			vector[i]->Imprimir();
		}
	}
}

int cJugador::Contar_e_ImpTropasenPais(cPais * pais)
{
	cout << endl << "Tropas disponibles" << endl;
	int N_tropas = 0;
	for (int i = 0; i < CA; i++)
	{
		if (vector[i]->getPais() == pais)
		{
			vector[i]->Imprimir();
			N_tropas++;
		}
	}
	return N_tropas;
}

int cJugador::Contar_Tropas_en_Pais(cPais * pais)
{
	int N_tropas = 0;
	for (int i = 0; i < CA; i++)
	{
		if (vector[i]->getPais() == pais)
		{
			N_tropas++;
		}
	}
	return N_tropas;
}

int cJugador::Contar_Tropas_en_Pais(string nombre)
{
	int cont = 0;
	for (int i = 0; i < CA; i++)
	{
		if (vector[i]->getPais()->getNombre() == nombre)
		{
			cont++;
		}
	}

	return cont;
}

void cJugador::Imprimir()//terminar
{
	cout << "";
}
