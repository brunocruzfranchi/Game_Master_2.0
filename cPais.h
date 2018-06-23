///////////////////////////////////////////////////////////
//  cPais.h
//  Implementation of the Class cPais
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#pragma once

#include "cListaT.h"
#include "cJugador.h"
#include <string>
#include <iostream>
#include <iomanip>
#define N_PAISES_TOTALES 13

using namespace std;


class cPais:public cListaT<cPais>{	
	private:
		/**
		* Este jugador es el que domina al pais
		*/

	public:
		///Atributos
		const string Clave;
		static cListaT<cPais> Lista_Paises;
		const string Nombre;
		cJugador* Jugador; //string Jugador;

		///Const. y Dest.
		cPais(string nombre);
		virtual ~cPais();

		///Metodos
			//Principales	
			void ListarPosiblesAtaques();
			bool ListarPosiblesMov();
			bool ListarLimitrofesPropios();
			bool Exiten_Tropas_en_el_Pais();

			bool TengoLimitrofesPropios();

			//Setters
			void setJugador(cJugador* j) { Jugador = j; }

			//Getters
			string getNJugador() { return Jugador->getN_Jugador(); }
			string getNombre() const { return Nombre; }
			cJugador* getJugador() { return Jugador; }
			static cListaT<cPais>*getLista_Paises() { return &Lista_Paises; }
		
			//Posibilidades
			//void Distribuir(cTropa* t);
			//cPais** getLimitrofes();

			//Lista Template
			string getclave() const { return Clave;}
			void Imprimir() { cout << setw(8) << Clave << setw(25) << Nombre << setw(8) << endl; }
			void Encabezado() { cout << setw(8) << "Clave" << setw(25) << "Nombre" << setw(8) << endl; }
			
};


