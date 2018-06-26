///////////////////////////////////////////////////////////
//  cPais.cpp
//  Implementation of the Class cPais
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: gasto
///////////////////////////////////////////////////////////

#include "cPais.h"
#include "cJugador.h"

cListaT<cPais> cPais::Lista_Paises = cListaT<cPais>(N_PAISES_TOTALES);

cPais::cPais(string nombre):Nombre(nombre),Clave(to_string(Lista_Paises.getCA()+1)){

	Lista_Paises.AgregarItem(this);

}

cPais::~cPais(){
}

void cPais::ListarPosiblesAtaques(){
	/*int cont = 0;
	for (int i = 0; i < CA; i++) 
		if (vector[i]->getJugador() != Jugador)
			cont++;

	if (cont == 0){
			throw new exception("No hay paises para atacar");
		return false;
	}
	
	cout << "Paises disponibles para atacar" << endl;
	*/

	for (unsigned int i = 0; i < CA; i++) {
		if (vector[i]->getJugador() != Jugador){
			vector[i]->Imprimir();
		}
	}
//	return true;
}

bool cPais::ListarPosiblesMov(){

	bool flag = false;
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getJugador() == Jugador)
		{
			Imprimir();
			Jugador->ImprimirTropasenPais(Nombre);
			flag = true;
		}
	}
	return flag;
}

bool cPais::ListarLimitrofesPropios() {

	bool flag = false;
	for (unsigned int i = 0; i < CA; i++) {
		if (vector[i]->getJugador() == Jugador) {
			vector[i]->Imprimir();
			flag = true;
		}
	}
	return flag;
}

bool cPais::Exiten_Tropas_en_el_Pais()
{
	bool flag = false;
	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->getJugador() == Jugador)
		{
			int cont = Jugador->Contar_Tropas_en_Pais(Nombre);
			if(cont > 0)
				flag = true;
		}
	}
	return flag;
}

bool cPais::TengoLimitrofesPropios() {

	bool flag = false;
	for (unsigned int i = 0; i < CA; i++) {
		if (vector[i]->getJugador() == Jugador) {
			flag = true;
		}
	}
	return flag;
}

/*
void cPais::Distribuir(cTropa* t){

}

cPais** cPais::getLimitrofes(){
	return  NULL;
}

void cPais::setLimitrofes(cPais** limitrofes){
	//Limitrofes = limitrofes;
}

void cPais::setTropa(cTropa** m){
	//Magos = m;
}
*/