
#include "Funciones.h"

void Generar_Paises(cListaT<cPaises> *paises){
    cPais** paises = new cPais*[12];	    //// Generacion de la lista Paises.
	paises[0] = new cPais("Argentina");
    paises[1] = new cPais("Bolivia");
    paises[2] = new cPais("Brasil");
    paises[3] = new cPais("Chile");
    paises[4] = new cPais("Colombia");
    paises[5] = new cPais("Ecuador");
    paises[6] = new cPais("Guyana");
    paises[7] = new cPais("Paraguay");
    paises[8] = new cPais("Peru");
    paises[9] = new cPais("Surinam");
    paises[10] = new cPais("Uruguay");
    paises[11] = new cPais("Venezuela");
    for (int i=0; i < 12; i++)  
        paises->AgregarItem(paises[i]);

    paises->Listar();
}