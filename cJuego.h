///////////////////////////////////////////////////////////
//  cJuego.h
//  Implementation of the Class cJuego
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////

#if !defined(EA_25249AF9_B8BF_441f_95EC_C0B1C8876E76__INCLUDED_)
#define EA_25249AF9_B8BF_441f_95EC_C0B1C8876E76__INCLUDED_

#include "cJugador.h"
#include "cListaT.h"
#include <string>

using namespace std;

class cJuego : public cListaT<class T>
{

public:
	cJuego();
	virtual ~cJuego();
	void AsignarPaises(cJugador Jug);
	void AsignarTropas(cJugador Jug);
	void CambiarPais(cPais* pais, cJugador* ganador);
	void CrearJugadores(int n = 2);
	void CrearPaises();
	int getRondas();
	void Jugar();
	void TurnoAtaque(cJugador Jug1, cJugador Jug2);
	int Rondas;

};
#endif // !defined(EA_25249AF9_B8BF_441f_95EC_C0B1C8876E76__INCLUDED_)
