///////////////////////////////////////////////////////////
//  cJugador.h
//  Implementation of the Class cJugador
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////
#pragma once
#if !defined(EA_ECAD8CBF_DBA6_4277_A538_57274982E741__INCLUDED_)
#define EA_ECAD8CBF_DBA6_4277_A538_57274982E741__INCLUDED_


#include "cListaT.h"
#include <iostream>
#include <string>
#include <stdlib.h>
//hereda una lista en la que voy a acargar los paises dominados

using namespace std;
class cPais;
class cJuego;
class cJugador:public cListaT<class cTropa>{

public:
	///Atributos
	const string N_jugador;
	cListaT<cPais>* PaisesDominados;

	///Const. y Dest.
	cJugador(int n_jugador);
	virtual ~cJugador();

	///Metodos
		//principales
		void MoverTropas(cPais *pais, cPais*atacante);

		void ImprimirTropas(cPais * atacante, cPais * atacado);

		void ImprimirTropasenPais(cPais*pais);
		void ImprimirTropasenPais(string nombre);
		void ImprimirTropasenPais(string nombre,string tipo);
		void ImprimirTropasenPais(cPais*pais,string tipo);

		int getATTOTAL();
		int Contar_e_ImpTropasenPais(cPais*pais);
		int Contar_Tropas_en_Pais(cPais*pais);
		int Contar_Tropas_en_Pais(cPais*pais,string tipo);
		int Contar_Tropas_en_Pais(string nombre);

		//getters
		string getN_Jugador() const { return N_jugador; }
		cListaT<cPais> *getPaisesD() { return PaisesDominados; }	// manejo de tipos de punteros

		//setters
		//void setPaisesD(cListaT<class cPais> *listad) { PaisesDominados = listad; }

		//Lista Template
		string getclave() { return N_jugador; }
		void ImprimirJugador() { cout << "Jugador " << N_jugador << endl;}
		void Imprimir();
	//	void operator+(cPais * item);
		//void operator+(cTropa * item);
};
#endif // !defined(EA_ECAD8CBF_DBA6_4277_A538_57274982E741__INCLUDED_)
