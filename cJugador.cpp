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

void cJugador::MoverTropas(cPais*ganado,cPais*atacante){
	int opcion_pais, opcion_mover, N_tropas=0, flag=0;
	N_tropas = Contar_e_ImpTropasenPais(atacante);
		
	for (int i = 0; i < N_tropas-1; i++)
	{
		if (flag != 0)
		{
			ImprimirTropasenPais(atacante);
		}
		flag++;
		cout << "Que tropa desea mover? " << endl;
		do {			
			cin >> opcion_pais; cout << endl;
						
		} while (opcion_pais < 1||opcion_pais>N_tropas);

		vector[opcion_pais]->setPais(ganado);

		cout <<endl<< "Tropa trasladada satisfactoriamente";
		do {
			cout << endl << "Desea mover mas tropas?" << endl << "1. Si " << endl << "2. No" << endl;
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
	cout << endl << "Tropas disponibles" << endl;
	for (int i = 0; i < CA; i++)
	{
		if (vector[i]->getPais() == pais)
		{
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



void cJugador::Imprimir()//terminar
{
	cout << "";
}
