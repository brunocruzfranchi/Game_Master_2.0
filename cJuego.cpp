///////////////////////////////////////////////////////////
//  cJuego.cpp
//  Implementation of the Class cJuego
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////

#include "cJuego.h"


using namespace std;

cJuego::cJuego(int cant_jug) {
	CrearJugadores(cant_jug);
	CrearPaises();

}
cJuego::~cJuego() {
}

void cJuego::AsignarPaises(cJugador *Jug) {

	int aux, aleatorio=0,tam_tropa, max, min, M;
	string * tipo;

	aux = getCA();
	(aux % 2 != 0) ? aux--:0;
	aux = aux / 2;

	for (int i = 0; i < aux; i++)
	{
		srand(time(NULL));
		aleatorio = rand() % 3;
		if (aleatorio == 0)
		{
			min = 20;
			max = 40;
			*(tipo) = "Magos";
		}
		if (aleatorio == 1)
		{
			min = 15;
			max = 40;
			*(tipo) = "Arqueros";
		}
		if (aleatorio == 2)
		{
			min = 10;
			max = 20;
			*(tipo) = "Caballeros";
		}

		tam_tropa = min + rand() % (max -min+1);

	}
}

void cJuego::AsignarTropas(cJugador *Jug) {
	
}

void cJuego::ReasignarPais(cPais* pais, cJugador* ganador) {

	pais->setJugador(ganador->getN_Jugador());//sacar lista del perdedor
}

void cJuego::CrearJugadores(int n) {

	Jugadores = new cListaT<cJugador>(n);

	for (int i = 0; i < n; i++) {
		Jugadores->AgregarItem(new cJugador(i));
	}
}

void cJuego::CrearPaises()//Que es lo que hace esta funcion crear los paises individualmente o crear una lista de paises para ser usada 
{
	Paises=new cListaT<cPais>(13);//
	
	cPais *paises[N_PAISES_TOTALES];
	paises[0]=new cPais("Argentina");
	paises[1]=new cPais("Bolivia");
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
	paises[12] = new cPais("Guayana Francesa");
	//genero mapa con paises limitrofes

	paises[12]->AgregarItem(paises[9]);
	paises[12]->AgregarItem(paises[2]);
	paises[11]->AgregarItem(paises[4]);
	paises[11]->AgregarItem(paises[2]);
	paises[11]->AgregarItem(paises[6]);
	paises[10]->AgregarItem(paises[0]);
	paises[10]->AgregarItem(paises[2]);
	paises[9]->AgregarItem(paises[6]);
	paises[9]->AgregarItem(paises[2]);
	paises[9]->AgregarItem(paises[12]);
	paises[8]->AgregarItem(paises[5]);
	paises[8]->AgregarItem(paises[4]);
	paises[8]->AgregarItem(paises[2]);
	paises[8]->AgregarItem(paises[1]);
	paises[8]->AgregarItem(paises[3]);
	paises[7]->AgregarItem(paises[1]);
	paises[7]->AgregarItem(paises[2]);
	paises[7]->AgregarItem(paises[0]);
	paises[6]->AgregarItem(paises[9]);
	paises[6]->AgregarItem(paises[2]);
	paises[6]->AgregarItem(paises[11]);
	paises[5]->AgregarItem(paises[8]);
	paises[5]->AgregarItem(paises[4]);
	paises[4]->AgregarItem(paises[11]);
	paises[4]->AgregarItem(paises[5]);
	paises[4]->AgregarItem(paises[8]);
	paises[4]->AgregarItem(paises[2]);
	paises[3]->AgregarItem(paises[8]);
	paises[3]->AgregarItem(paises[1]);
	paises[3]->AgregarItem(paises[0]);
	paises[0]->AgregarItem(paises[3]);
	paises[0]->AgregarItem(paises[2]);
	paises[0]->AgregarItem(paises[1]);
	paises[0]->AgregarItem(paises[10]);
	paises[0]->AgregarItem(paises[7]);
	paises[1]->AgregarItem(paises[0]);
	paises[1]->AgregarItem(paises[7]);
	paises[1]->AgregarItem(paises[2]);
	paises[1]->AgregarItem(paises[3]);
	paises[1]->AgregarItem(paises[8]);
	paises[2]->AgregarItem(paises[10]);
	paises[2]->AgregarItem(paises[0]);
	paises[2]->AgregarItem(paises[7]);
	paises[2]->AgregarItem(paises[1]);
	paises[2]->AgregarItem(paises[8]);
	paises[2]->AgregarItem(paises[11]);
	paises[2]->AgregarItem(paises[4]);
	paises[2]->AgregarItem(paises[12]);
	paises[2]->AgregarItem(paises[10]);
	paises[2]->AgregarItem(paises[6]);
	paises[2]->AgregarItem(paises[9]);

	//for agregando pais a lista paises;
} 


int cJuego::Jugar() {
	int opcion;
	for (Ronda = 1; Ronda <= N_MAX_TURNOS; Ronda++)	{

		
		//Turnos
		for ( int k = 0; k < Jugadores->getCA(); k++)
		{
			for (int h  = 0; h < N_MAX_ATAQUES; h++)
			{
				//CambiarTurno(/*lista jugadores del template*/, k);
				//Listar paises dominados y pedir atacante
				//Pido tropa (magos,arqueros,caballeros);
				//preguntar continuar atacando? if==no break;
			}
			
		}
		if (Ronda == N_RONDAS)
				{
					cout << endl << "Desea continuar el juego?" << endl
						<< " Presione 1 para finalizar. Cualquier otra tecla para continuar" << endl;
					cin >> opcion;
					cout << endl;
					if (opcion == 1)
					{
						ImprimirGanador();
						return 0; // conviene usar una excepcion?
					}
				}
		
		//Repartir paises

		for (int k = 0; k < N_MAX_JUGADORES; k++)
		{
			//Mover  Tropas
		}
		
	}

	return 0;
}

void cJuego::CambiarTurno(cJugador** Jugador, int k) {
	Jugador_de_turno = Jugador[k];
}

void cJuego::Iniciar_Partida() {
	
	//asignar paises inicia
	
	//asignacion inicial de tropas
	//bienvenido, juego iniciado
	//
}

void cJuego::ImprimirGanador() {
	//determinar ganador e imprimir
};


int cJuego::getRonda() {
	return Ronda;
}
