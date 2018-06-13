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

//CREAR
void cJuego::CrearJugadores(int n) {

	Jugadores = new cListaT<cJugador>(n);

	for (int i = 0; i < n; i++) {
		//int to string???
		Jugadores->AgregarItem(new cJugador(i));
	}
}

void cJuego::CrearPaises() {
	Paises = new cListaT<cPais>();
	cPais *paises[N_PAISES_TOTALES];

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
	paises[12] = new cPais("Guayana Francesa");
	//genero mapa con paises limitrofes

	//Guayana Francesa
	paises[12]->AgregarItem(paises[9]);
	paises[12]->AgregarItem(paises[2]);
	//Venezuela
	paises[11]->AgregarItem(paises[4]);
	paises[11]->AgregarItem(paises[2]);
	paises[11]->AgregarItem(paises[6]);
	//Uruguay
	paises[10]->AgregarItem(paises[0]);
	paises[10]->AgregarItem(paises[2]);
	//Surinam
	paises[9]->AgregarItem(paises[6]);
	paises[9]->AgregarItem(paises[2]);
	paises[9]->AgregarItem(paises[12]);
	//Peru
	paises[8]->AgregarItem(paises[5]);
	paises[8]->AgregarItem(paises[4]);
	paises[8]->AgregarItem(paises[2]);
	paises[8]->AgregarItem(paises[1]);
	paises[8]->AgregarItem(paises[3]);
	//Paraguay
	paises[7]->AgregarItem(paises[1]);
	paises[7]->AgregarItem(paises[2]);
	paises[7]->AgregarItem(paises[0]);
	//Guyana
	paises[6]->AgregarItem(paises[9]);
	paises[6]->AgregarItem(paises[2]);
	paises[6]->AgregarItem(paises[11]);
	//Ecuador
	paises[5]->AgregarItem(paises[8]);
	paises[5]->AgregarItem(paises[4]);
	//Colombia
	paises[4]->AgregarItem(paises[11]);
	paises[4]->AgregarItem(paises[5]);
	paises[4]->AgregarItem(paises[8]);
	paises[4]->AgregarItem(paises[2]);
	//Chile
	paises[3]->AgregarItem(paises[8]);
	paises[3]->AgregarItem(paises[1]);
	paises[3]->AgregarItem(paises[0]);
	//Brasil
	paises[2]->AgregarItem(paises[10]);
	paises[2]->AgregarItem(paises[0]);
	paises[2]->AgregarItem(paises[7]);
	paises[2]->AgregarItem(paises[1]);
	paises[2]->AgregarItem(paises[8]);
	paises[2]->AgregarItem(paises[11]);
	paises[2]->AgregarItem(paises[4]);
	paises[2]->AgregarItem(paises[12]);
	paises[2]->AgregarItem(paises[6]);
	paises[2]->AgregarItem(paises[9]);
	//Bolivia
	paises[1]->AgregarItem(paises[0]);
	paises[1]->AgregarItem(paises[7]);
	paises[1]->AgregarItem(paises[2]);
	paises[1]->AgregarItem(paises[3]);
	paises[1]->AgregarItem(paises[8]);
	//Argentina
	paises[0]->AgregarItem(paises[3]);
	paises[0]->AgregarItem(paises[2]);
	paises[0]->AgregarItem(paises[1]);
	paises[0]->AgregarItem(paises[10]);
	paises[0]->AgregarItem(paises[7]);

	//for agregando pais a lista paises;
	for (int i = 0; i < 13; i++){
		Paises->AgregarItem(paises[i]);
	}
} //listo

//ASIGNACIONES
void cJuego::AsignarPaises(cJugador *Jug) {

	int n, num[N_PAISES_TOTALES];
	for (int i = 0; i<N_PAISES_TOTALES; i++)						//Genero un array de numero aleatorios y no repetidos
	{
		do
			n = rand() % N_PAISES_TOTALES/*+1?*/;
		while (repetidos(n, num));
		num[i] = n;
	}
	if (Jug->getN_Jugador() == 0)//????
		for(int i = 0; i < 7; i++){
			cPais* aux = Paises->getItem(num[i]);
			Jug->PaisesDominados->AgregarItem(aux);
		}
	else
		for (int i = 7; i < N_PAISES_TOTALES; i++) {
			cPais* aux2 = Paises->getItem(num[i]);
			Jug->PaisesDominados->AgregarItem(aux2);
		}
}

void cJuego::AsignarTropas() {

	for(int k=0;k<CA;k++ )
	{
		int aux = vector[k]->PaisesDominados->getCA();
		(aux % 2 != 0) ? aux = aux / 2 : aux = (aux - 1) / 2;
		int aleatorio = -1, tam_tropa, min, max;
		string tipo,nombre_pais;
		cPais*asignado;
		for (int i = 0; i < aux; i++)
		{
			srand(time(NULL));
			aleatorio = rand() % 3;
			switch (aleatorio)
			{
			case 0:
				min = 20;
				max = 40;
				tipo = "Magos";
				break;
			case 1:
				min = 15;
				max = 30;
				tipo = "Arqueros";
				break;
			case 2:
				min = 10;
				max = 20;
				tipo = "Caballeros";
				break;
			default:
				break;
			}
			tam_tropa = min + rand() % (max - min + 1);
			
			//preguntar pais
			
			vector[k]->AgregarItem(&cTropa(tipo, tam_tropa, asignado));
		}
	}

	/*
	int aux, aleatorio = -1, tam_tropa, max, min, M;
	string tipo;
	aux = getCA();
	(aux % 2 != 0) ? aux-- : 0;
	aux = aux / 2;

	for (int i = 0; i < aux; i++)
	{
		aleatorio = rand() % 3;
		switch (aleatorio)
		{
			case 0:
				min = 20;
				max = 40;
				tipo = "Magos";
				break;
			case 1:
				min = 15;
				max = 40;
				tipo = "Arqueros";
				break;
			case 2:
				min = 10;
				max = 20;
				tipo = "Caballeros";
				break;
			default:
				break;
		}
		tam_tropa = min + rand() % (max - min + 1);
	}
	*/ 
}

void cJuego::ReasignarPais(cPais* atacado, cPais* atacante) { //listo
		
	cJugador *ganador = BuscarItem(atacante->getJugador()->getN_Jugador());
	
	cJugador*perdedor = BuscarItem(atacado->getJugador()->getN_Jugador());

	perdedor->PaisesDominados->Eliminar(atacado);
	atacado->setJugador(ganador);
	ganador->MoverTropas(atacado, atacante);
} //listo

//PARTIDA
int cJuego::Jugar() {
	int opcion;
	for (Ronda = 1; Ronda <= N_MAX_TURNOS; Ronda++)	{
		//Turnos
		AsignarTropas();// asigno tropas al principio de la ronda
		for ( int k = 0; k < (Jugadores->getCA()); k++)
		{
			for (int h  = 0; h < N_MAX_ATAQUES; h++)
			{
				CambiarTurno(vector, k);
				vector[k]->getPaisesD()->Listar();//?? not sure yet
				//pedir atacante
				//Pido tropa (magos,arqueros,caballeros);
				//ataque-contraataque
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

void cJuego::Imprimir()
{
}

void cJuego::Iniciar_Partida() {
	//Jugadores
	cJugador* Jug1 = Jugadores->getItem(0);
	cJugador* Jug2 = Jugadores->getItem(1);

	//Asignacion de Paises
	AsignarPaises(Jug1);
	AsignarPaises(Jug2);

	//Asignacion inicial de tropas


	//bienvenido, juego iniciado*/



}

int cJuego::getRonda() {
	return Ronda;
}

//IMPRIMIR
void cJuego::ImprimirGanador() {
	//determinar ganador e imprimir
}

//EXTERNA
bool repetidos(int n, int num[])
{
	for (int i = 0; i<N_PAISES_TOTALES; i++)
		if (n == num[i])
			return true;
	return false;
}