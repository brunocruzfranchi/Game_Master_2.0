///////////////////////////////////////////////////////////
//  cListaT.h
//  Implementation of the Class cListaT
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////

#if !defined(EA_B9741D49_13D8_46c1_8B11_F0F70B4304B8__INCLUDED_)
#define EA_B9741D49_13D8_46c1_8B11_F0F70B4304B8__INCLUDED_

/**
 * Hacer un metodo Random
 */
#pragma once
#define NMAX 10

#include <string>

using namespace std;
template<class T>
class cListaT
{
protected:
	T **vector;
	unsigned int CA, TAM;


	void Redimensionalizar();
public:
	cListaT(unsigned int TAM = NMAX);
	~cListaT();

	bool AgregarItem(T *item);
	bool AgregarItemOrdenado(const T *item);

	T* Quitar(string clave);
	T* Quitar(const T *item);
	T* QuitarenPos(unsigned int pos);

	void Eliminar(string clave);
	void Eliminar(const T *item);
	void Eliminar(unsigned int pos);

	void Listar();
	T* BuscarItem(string clave);
	T* getItem(unsigned int pos);

	unsigned int getItemPos(string clave);

	unsigned int getCA();
	unsigned int getTAM();
};dif // !defined(EA_B9741D49_13D8_46c1_8B11_F0F70B4304B8__INCLUDED_)
