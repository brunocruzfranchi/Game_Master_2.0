///////////////////////////////////////////////////////////
//  cJuego.cpp
//  Implementation of the Class cJuego
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////

#include "cJuego.h"


using namespace std;

cJuego::cJuego(int cant_jug):cListaT<cJugador>(cant_jug) {
	CrearJugadores(cant_jug);
	CrearPaises();
}

cJuego::~cJuego() {
}

//CREAR
void cJuego::CrearJugadores(int n) {
	
	for (int i = 0; i < n; i++) {
		string aux = to_string(i);
		AgregarItem(new cJugador(aux));
	}
}

void cJuego::CrearPaises() {

	Paises = new cListaT<cPais>(N_PAISES_TOTALES);
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
	if (Jug->getN_Jugador() == "0")
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

	for(int k = 0; k < CA ; k++ )
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

			tam_tropa = min + rand() % (max - min + 1);//genero tropa
			
			cout << endl << "Tropa generada" << endl <<
				"Tipo: " << tipo << setw(8) << "Numero de Unidades: " << tam_tropa
				<< endl;

			string opcion_pais;
			int aux;
			int opcion_distribuir;

			do//listo y pido pais
			{
				vector[k]->PaisesDominados->Listar();
				cout << "En que país quiere ubicar su tropa?" << endl<< "Ingrese el nombre del pais: ";
				cin >> opcion_pais;
				cout << endl;
				aux = getItemPos(opcion_pais);
			} while (aux == INT_MAX);// busco la posicion en la lista INT_MAX si no se encontro => vuelvo a pedir
			cPais*pais = vector[k]->PaisesDominados->BuscarItem(opcion_pais);//busco el pais elegido y lo guardo en un puntero
			do {
				cout << endl<<"Distribucion de tropa" << endl
					<<" 1. Mantener como tropa separada"<<endl
					<<"2. Sumar a tropa existente"<<endl;
				cin >> opcion_distribuir; cout << endl;
				
				string opcion_tropa;
				if (opcion_distribuir == 1)
				{
					cTropa *tropa;//= cTropa(tipo, tam_tropa, pais);//No me deja crear tropa
					vector[k]->AgregarItem(tropa);
					cout << endl << "Tropa agregada satisfactoriamente" << endl;
				}
				if (opcion_distribuir == 2)
				{
					//elegir tropa
					vector[k]->ImprimirTropasenPais(pais);
					cout <<endl<< "A que tropa desea sumarlo?" << endl;
					int aux;
					do {
							cin >> opcion_tropa; cout << endl; //pido clave de la tropa
							aux = vector[k]-> getItemPos(opcion_tropa);

						} while (aux == INT_MAX);

						cUnidades*u = &cUnidades(tipo);
						for (int j = 0; j < tam_tropa; j++)
						{
							
							vector[k]->getItem(aux)->AgregarItem(u);
						}

						cout << endl << "Tropa distribuida satisfactoriamente" << endl;
				}
					

			} while (opcion_distribuir != 1 && opcion_distribuir != 2);
					
		}
		system("cls");
	}
	
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

		for (int k = 0; k < (getCA()); k++)
		{
			for (int h = 0; h < N_MAX_ATAQUES; h++)
			{
				CambiarTurno(vector, k);
				vector[k]->PaisesDominados->Listar();
				string opcion_pais_atacante, opcion_pais_atacado;
				int pos_atacante, pos_atacado;
				int opcion_distribuir;
				cPais*pais_atacado;
				do//listo y pido pais atacante
				{
					vector[k]->PaisesDominados->Listar();
					cout << "Con que país quiere atacar?" << endl << "Ingrese el nombre del pais: ";
					cin >> opcion_pais_atacante;
					cout << endl;
					pos_atacante = vector[k]->getPaisesD()->getItemPos(opcion_pais_atacante);
				} while (pos_atacante == INT_MAX);// busco la posicion en la lista INT_MAX si no se encontro => vuelvo a pedir
				cPais*pais_atacante = vector[k]->PaisesDominados->BuscarItem(opcion_pais_atacante);//busco el pais elegido y lo guardo en un puntero
				do//listo y pido pais atacado
				{
					pais_atacante->ListarPosiblesAtaques();
					cout << "Que país quiere atacar?" << endl << "Ingrese el nombre del pais: ";
					cin >> opcion_pais_atacado;
					cout << endl;
					pos_atacado = pais_atacante->getItemPos(opcion_pais_atacado);
					if (pos_atacado != INT_MAX)
					{
						pais_atacado = pais_atacante->getItem(pos_atacado);
						if (pais_atacante->getJugador() == pais_atacado->getJugador())
							pos_atacado == INT_MAX;
					}
				} while (pos_atacado == INT_MAX);// busco la posicion en la lista INT_MAX si no se encontro => vuelvo a pedir

				cTropa* atacante;
				string opcion_tropa;

				//pido tropa atacante

				ImprimirTropasenPais(pais_atacante);

				cout << "Con que tropa desea atacar? " << endl << "Ingrese clave de la tropa: ";
				int aux_tropa_atacante;
				do {
					cin >> opcion_tropa; cout << endl; //pido clave de la tropa
					aux_tropa_atacante = vector[k]->getItemPos(opcion_tropa);
					if (vector[k]->getItem(aux_tropa_atacante)->getPais() != pais_atacante)//chequeo que la tropa este en mi pais atacante
						aux_tropa_atacante = INT_MAX;
					else
						atacante = vector[k]->getItem(aux_tropa_atacante);
				} while (aux_tropa_atacante == INT_MAX);

				//pedir tropa atacada
				cTropa*atacada;
				string opcion_tropa;
				//pido tropa atacada

				ImprimirTropasenPais(pais_atacado);

				cout << "A que tropa desea atacar? " << endl << "Ingrese clave de la tropa: ";
				int aux_tropa_atacada;
				do {
					cin >> opcion_tropa; cout << endl; //pido clave de la tropa
					aux_tropa_atacada = vector[k]->getItemPos(opcion_tropa);
					if (vector[k]->getItem(aux_tropa_atacada)->getPais() != pais_atacado)//chequeo que la tropa este en mi pais atacante
						aux_tropa_atacada = INT_MAX;
					else
						atacada = vector[k]->getItem(aux_tropa_atacada);
				} while (aux_tropa_atacada == INT_MAX);


				///ataque-contraataque

				int at_disp = N_MAX_ATAQUES - h - 1;
				int opc_continuar=0;
				do {
					cout << endl << "Desea continuar atacando? ( " << at_disp << " ataques disponibles)" 
						<< endl<<"1. Si"<<endl<<"2. No"<<endl;
					cin >> opc_continuar; cout << endl;
				} while (opc_continuar != 1 && opc_continuar != 2);

					if (opc_continuar == 2)break;
			}
			int op;
			do {
				cout << endl << "Desea movilizar tropas?" << endl << "1. Si" << endl << "2.No" << endl;
				cin >> op; cout << endl;
				string pais_origen,pais_destino;
				int pos_origen,pos_destino;
				if (op == 1) {

					do//listo y pido pais origen
					{
						vector[k]->PaisesDominados->Listar();
						cout << "Desde que país quiere movilizar tropas?" << endl << "Ingrese el nombre del pais: ";
						cin >> pais_origen;
						cout << endl;
						pos_origen = vector[k]->getPaisesD()->getItemPos(pais_origen);
					} while (pos_origen == INT_MAX);
					bool aux;
					cPais*origen = vector[k]->getPaisesD()->getItem(pos_origen);
					cPais*destino;
					do//listo y pido pais atacado
					{
						aux=origen->ListarPosiblesMov();
						if (aux == false) break;//no hay paises limitrofes del mismo jugador
						cout << "A que país quiere movilizar tropas?" << endl << "Ingrese el nombre del pais: ";
						cin >> pais_destino;
						cout << endl;
						pos_destino = origen->getItemPos(pais_destino);
						if (pos_destino != INT_MAX)
						{
							destino = origen->getItem(pos_origen);
							if (origen->getJugador() != destino->getJugador())
							{
								pos_destino == INT_MAX;
								vector[k]->MoverTropas(destino, origen);//movilizo tropas
							}
						}
					} while (pos_destino == INT_MAX);

					op = 2;
				}
				system("pause");
				system("cls");

			} while (op != 2);



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
		
			
	}

	return 0;
}

void cJuego::CambiarTurno(cJugador** Jugador, int k){
	Jugador_de_turno = Jugador[k];
}

void cJuego::Imprimir(){

}

void cJuego::Iniciar_Partida() {
	//Jugadores
	cJugador* Jug1 = getItem(0);
	cJugador* Jug2 = getItem(1);

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