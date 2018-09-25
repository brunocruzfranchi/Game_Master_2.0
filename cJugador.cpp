///////////////////////////////////////////////////////////
//  cJugador.cpp
//  Implementation of the Class cJugador
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////


#include "cTropa.h"
#include "cPais.h"
#define N_MINIMO_TROPAS_ATAQUE 2
cJugador::cJugador(int n_jugador, string nombre):N_jugador(to_string(n_jugador+1)), Nombre(nombre){
	
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

void cJugador::ImprimirTropas(cPais* atacante, cPais* atacado){

	cout << setw(20) << "   Tropas disponibles en: " << atacante->getNombre() << right << setw(80) << "|    Tropas disponibles en:" << atacado->getNombre() << endl;
 	vector[0]->EncabazadoTropas();
	cout << "               |";
	vector[0]->EncabazadoTropas();

	cJugador* jug_atacado = atacado->getJugador();

	int CA_MAX = CA;
	int CA_atacado = jug_atacado->getCA();
	if (CA_MAX < CA_atacado)
		CA_MAX = CA_atacado;

	for (unsigned int i = 0; i < CA_MAX; i++) {

		int cont = 0;
		int cont1 = 0;
		cout << endl;
		
		if (i < CA) {
			if (vector[i]->getPais()->getclave() == atacante->getclave())
			{
				cout<<*vector[i];
				cout << setw(16) << "|";
				cont++;
			}
		}

		if (cont == 0) {
			cout << setw(90) << "|";
		}

	 	if (i < CA_atacado) {
			if (jug_atacado->vector[i]->getPais()->getclave() == atacado->getclave())
			{
				cout<<*(jug_atacado->vector[i]);
				cont1++;
				cout << setw(16) << "|";
			}
		}
		if (cont == 0 && cont1 == 0) {
			cout << setw(90) << "|";
		}
		if(cont1 == 0)
			cout << setw(90) << "|";
	}

	cout << endl;
}

void cJugador::ImprimirTropasenPais(cPais * pais)
{
	cout << endl << "Tropas disponibles en "<< pais->getNombre() << endl;

	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getPais()->getclave() == pais->getclave())
		{
			cout<<*vector[i];
		}
	}
}

void cJugador::ImprimirTropasenPais(string nombre)
{
	cout << endl << "Tropas disponibles en " << nombre << endl;
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getPais()->getNombre() == nombre)
		{
			cout<<*vector[i];
		}
	}
}

void cJugador::ImprimirTropasenPais(string nombre, string tipo)
{
	cout << endl << "Tropas disponibles en " << nombre <<" del tipo "<<tipo<< endl;
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getPais()->getNombre() == nombre)
		{
			if (vector[i]->getTipo() == tipo)
			cout<<*vector[i];
		}
	}
}

void cJugador::ImprimirTropasenPais(cPais* pais, string tipo){

	cout << endl << "Tropas disponibles en " << pais->getNombre() << " del tipo " << tipo << endl;
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getPais()->getclave() == pais->getclave())
		{
			if (vector[i]->getTipo() == tipo)
				cout<<*vector[i];
		}
	}
}

int cJugador::getATTOTAL()
{
	int acum = 0;
	for (unsigned int i = 0; i < CA; i++)
	{
		acum = vector[i]->getATTotal()+acum;
	}
	return acum;
}

int cJugador::Contar_e_ImpTropasenPais(cPais * pais)
{
	cout << endl << "Tropas disponibles" << endl;
	int N_tropas = 0;
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getPais() == pais)
		{
			cout<<*vector[i];
			N_tropas++;
		}
	}
	return N_tropas;
}

int cJugador::Contar_Tropas_en_Pais(cPais * pais)
{
	int N_tropas = 0;
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getPais() == pais)
		{
			N_tropas++;
		}
	}
	return N_tropas;
}

int cJugador::Contar_Tropas_en_Pais(cPais * pais, string tipo)
{
	int N_tropas = 0;
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getPais() == pais)
		{
			if(vector[i]->getTipo()==tipo)
			N_tropas++;
		}
	}
	return N_tropas;
	return 0;
}

int cJugador::Contar_Tropas_en_Pais(string nombre)
{
	int cont = 0;
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getPais()->getNombre() == nombre)
		{
			cont++;
		}
	}

	return cont;
}

bool cJugador::TropamePertenece(string c)
{
	cTropa* aux=BuscarItem(c);
	if (aux != NULL)
		return true;
	else
	return false;
}

void cJugador::ListarPosiblesAtacantes()
{
	for (int i = 0; i < PaisesDominados->getCA(); i++)
	{
		if (PaisValidoparaAtaque((*PaisesDominados)[i]->getclave())==true)
			((*PaisesDominados)[i])->Imprimir();
	}
}

bool cJugador::PaisValidoparaAtaque(string c)
{
	
	bool aux1 = false;
	cPais*pais = PaisesDominados->BuscarItem(c);
	//Limitrofe no propios
	for (int i = 0; i < pais->getCA(); i++)
	{
		if ((*pais)[i]->getJugador() != this)
		{
			aux1 = true;
			break;
		}
	}
	//Tiene que tener mas de una tropa en el pais
	if (Contar_Tropas_en_Pais(pais->getNombre()) < N_MINIMO_TROPAS_ATAQUE)
		return false;

		return aux1;

}

void cJugador::Imprimir()//terminar
{
	cout << "";
}

//void cJugador::operator+(cPais * item)
//{
//	PaisesDominados->AgregarItem(item);
//}
//
//void cJugador::operator+(cTropa * item)
//{
//	vector[]
//}
