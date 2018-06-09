///////////////////////////////////////////////////////////
//  cPais.h
//  Implementation of the Class cPais
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#pragma once

#include "cListaT.h"
#include "cTropa.h"
#include <string>
#include <iostream>
using namespace std;

class cPais:public cListaT<cPais>{	
	private:
		/**
		* Este jugador es el que domina al pais
		*/

	public:
		///Atributos
		//static cListaT<cPais> *Lista_Paises;
		const string Nombre;
		int Jugador;

		///Const. y Dest.
		cPais(string nombre);
		virtual ~cPais();

		///Metodos
			//Principales
			//Setters
			void setJugador(int j) { Jugador = j; }

			//Getters
			int getJugador() { return Jugador; }
			string getNombre() const { return Nombre; }
		
			//Posibilidades
			//void Distribuir(cTropa* t);
			//cPais** getLimitrofes();

			//Lista Template
			string getclave() { return Nombre;}
			void Imprimir() { cout << Nombre << endl; }
			
};


