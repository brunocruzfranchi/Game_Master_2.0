///////////////////////////////////////////////////////////
//  cJuego.cpp
//  Implementation of the Class cJuego
//  Created on:      01-Jun.-2018 2:57:07 p. m.
//  Original author: Alumnos
///////////////////////////////////////////////////////////

#include "cJuego.h"
#include "cPais.h"
#include "cUnidades.h"
#include "cTropa.h"
#include "cTropaArqueros.h"
#include "cTropaCaballeros.h"
#include "cTropaMagos.h"
#include <exception>
#include <stdlib.h>
#include <random>

#define N_TROPAS_INICIAL 10

using namespace std;
enum PAISES{ARGENTINA = 0, BOLIVIA, BRASIL, CHILE, COLOMBIA, ECUADOR, GUYANA, PARAGUAY, PERU, SURINAM, URUGUAY, VENEZUELA, GUAYANAFRANCESA};

cJuego::cJuego(string * n,int cant_jug):cListaT<cJugador>(cant_jug) {
	try {
		CrearJugadores(n,cant_jug);
	}
	catch (exception* x) {
		cout << x->what() << endl;
	}
	try {
		CrearPaises();
	}
	catch (exception* x) {
		cout << x->what() << endl;
	}
}

cJuego::~cJuego() {

	delete Jugador_de_turno;
	
}

//CREAR
void cJuego::CrearJugadores(string * nombres, int n) {
	
	for (int i = 0; i < n; i++) {
		AgregarItem(new cJugador(i, nombres[i]));
	}
}

void cJuego::CrearPaises() {

//	Paises = new cListaT<cPais>(N_PAISES_TOTALES);
	cPais *paises[N_PAISES_TOTALES];
	//Genero los paises
	for (int i = 0; i < N_PAISES_TOTALES; i++) {
		int opcion = i;
		switch (i) {
		case ARGENTINA:
			//Argentina
			paises[0] = new cPais("Argentina");
			break;
		case BOLIVIA:
			//Bolivia
			paises[1] = new cPais("Bolivia");
			break;
		case BRASIL:
			//Brasil
			paises[2] = new cPais("Brasil");
			break;
		case CHILE:
			//Chile
			paises[3] = new cPais("Chile");
			break;
		case COLOMBIA:
			//Colombia
			paises[4] = new cPais("Colombia");
			break;
		case ECUADOR:
			//Ecuador
			paises[5] = new cPais("Ecuador");
			break;
		case GUYANA:
			//Guyana
			paises[6] = new cPais("Guyana");
			break;
		case PARAGUAY:
			//Paraguay
			paises[7] = new cPais("Paraguay");
			break;
		case PERU:
			//Peru
			paises[8] = new cPais("Peru");
			break;
		case SURINAM:
			//Surinam
			paises[9] = new cPais("Surinam");
			break;
		case URUGUAY:
			//Uruguay
			paises[10] = new cPais("Uruguay");
			break;
		case VENEZUELA:
			//Venezuela
			paises[11] = new cPais("Venezuela");
			break;
		case GUAYANAFRANCESA:
			//Guayana Francesa
			paises[12] = new cPais("Guayana Francesa");
			break;
		default:
			break;
		}
		Paises = paises[0]->getLista_Paises();
	}

	//Genero mapa con paises limitrofes
	for (int i = 0; i < N_PAISES_TOTALES; i++) {
		int opcion = i;
		switch (i) {
		case ARGENTINA:
			//Argentina
			*(paises[0]) + (paises[3]);
			*(paises[0]) + (paises[2]);
			*(paises[0]) + (paises[1]);
			*(paises[0]) + (paises[10]);
			*(paises[0]) + (paises[7]);
			break;
		case BOLIVIA:
			//Bolivia
			*(paises[1]) + (paises[0]);
			*(paises[1]) + (paises[7]);
			*(paises[1]) + (paises[2]);
			*(paises[1]) + (paises[3]);
			*(paises[1]) + (paises[8]);
			break;
		case BRASIL:
			//Brasil
			*(paises[2]) + (paises[10]);
			*(paises[2]) + (paises[0]);
			*(paises[2]) + (paises[7]);
			*(paises[2]) + (paises[1]);
			*(paises[2]) + (paises[8]);
			*(paises[2]) + (paises[11]);
			*(paises[2]) + (paises[4]);
			*(paises[2]) + (paises[12]);
			*(paises[2]) + (paises[6]);
			*(paises[2]) + (paises[9]);
			break;
		case CHILE:
			//Chile
			*(paises[3]) + (paises[8]);
			*(paises[3]) + (paises[1]);
			*(paises[3]) + (paises[0]);
			break;
		case COLOMBIA:
			//Colombia
			*(paises[4]) + (paises[11]);
			*(paises[4]) + (paises[5]);
			*(paises[4]) + (paises[8]);
			*(paises[4]) + (paises[2]);
			break;
		case ECUADOR:
			//Ecuador
			*(paises[5]) + (paises[8]);
			*(paises[5]) + (paises[4]);
			break;
		case GUYANA:
			//Guyana
			*(paises[6]) + (paises[9]);
			*(paises[6]) + (paises[2]);
			*(paises[6]) + (paises[11]);
			break;
		case PARAGUAY:
			//Paraguay
			*(paises[7]) + (paises[1]);
			*(paises[7]) + (paises[2]);
			*(paises[7]) + (paises[0]);
			break;
		case PERU:
			//Peru
			*(paises[8]) + (paises[5]);
			*(paises[8]) + (paises[4]);
			*(paises[8]) + (paises[2]);
			*(paises[8]) + (paises[1]);
			*(paises[8]) + (paises[3]);
			break;
		case SURINAM:
			//Surinam
			*(paises[9]) + (paises[6]);
			*(paises[9]) + (paises[2]);
			*(paises[9]) + (paises[12]);
			break;
		case URUGUAY:
			//Uruguay
			*(paises[10]) + (paises[0]);
			*(paises[10]) + (paises[2]);
			break;
		case VENEZUELA:
			//Venezuela
			*(paises[11]) + (paises[4]);
			*(paises[11]) + (paises[2]);
			*(paises[11]) + (paises[6]);
			break;
		case GUAYANAFRANCESA:
			//Guayana Francesa
			*(paises[12]) + (paises[9]);
			*(paises[12]) + (paises[2]);
			break;
		default:
			break;
		}
	}

	//For agregando los pais a lista paises;
/*	for (int i = 0; i < N_PAISES_TOTALES; i++){
		*(Paises) +( paises[i]);
	}
	*/
} //listo

//ASIGNACIONES
void cJuego::AsignarPaises() {
	
	int jugadores = N_MAX_JUGADORES;

	int n, num[N_PAISES_TOTALES];	
	
	for (int i = 0; i<N_PAISES_TOTALES; i++)						//Genero un array de numero aleatorios y no repetidos
	{
		do
			n = rand() % N_PAISES_TOTALES;
		while (repetidos(n, num));
		num[i] = n;
	}

	int i = 0, pos = 0;

	do{
		*(vector[pos]->PaisesDominados) + ((*Paises) [(num[i])]);
		((*(Paises))[(num[i])])->setJugador(vector[pos]);
		if (vector[pos]->PaisesDominados->getCA() == 7)
			pos++;
		i++;
	} while (i < N_PAISES_TOTALES);
	
	/*
	int i, pos = 0;
	int jugadores = N_MAX_JUGADORES;

	for (i = 0; i < N_PAISES_TOTALES; i++){
		pos = rand() % 2;
		*(vector[pos]->PaisesDominados)+(*(Paises)==(i));
		(*(Paises)==i)->setJugador(vector[pos]);
		if (vector[pos]->PaisesDominados->getCA() == 7)
			break;
	}

	pos = (pos + 1) % 2;

	if (i < N_PAISES_TOTALES)

		for (int h = i + 1; h < N_PAISES_TOTALES; h++)
		{
			*(vector[pos]->PaisesDominados) + (*(Paises) == i);
		}
	*/

	/*
	if (Jug->getN_Jugador() == "1")
		for(int i = 0; i < 7; i++){
			cPais* aux = Paises->getItem(num[i]);
			Jug->PaisesDominados->AgregarItem(aux);
		}
	if(Jug->getN_Jugador() == "2")
		for (int i = 7; i < N_PAISES_TOTALES; i++) {
			cPais* aux2 = Paises->getItem(num[i]);
			Jug2->PaisesDominados->AgregarItem(aux2);
		}*/
}

void cJuego::AsignarTropas(int n) {

	for (unsigned int k = 0; k < CA; k++)
	{
		cout << "Turno Jugador " << vector[k]->getN_Jugador() << endl;
		
		int aux_ca = vector[k]->PaisesDominados->getCA();
		
		(aux_ca % 2 != 0) ? aux_ca = aux_ca / 2 : aux_ca = (aux_ca - 1) / 2;
		
		(n == 0) ? aux_ca = N_TROPAS_INICIAL : 0;

		int aleatorio = -1, tam_tropa, min, max;
		string tipo, nombre_pais;
		cPais* asignado = NULL;

		for (int i = 0; i < aux_ca; i++)
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
				"Tipo: " << tipo << setw(40) << "Numero de Unidades: " << tam_tropa
				<< endl;

			string opcion_pais;
			int aux = -1, opcion_distribuir = -1;

			do //listo y pido pais
			{
				cListaT<cPais>* PaisesDominados = vector[k]->getPaisesD();
				PaisesDominados->Listar();

				cout << "En que pais quiere ubicar su tropa?" << endl << "Ingrese la clave del pais: ";
				cin >> opcion_pais;
				cout << endl;

				aux = vector[k]->PaisesDominados->getItemPos(opcion_pais);

			} while (aux == INT_MAX);// busco la posicion en la lista INT_MAX si no se encontro => vuelvo a pedir

			cPais* pais = vector[k]->PaisesDominados->BuscarItem(opcion_pais); //busco el pais elegido y lo guardo en un puntero

			do {
				cout << endl << "  Distribucion de tropa" << endl
					<< " 1. Mantener como tropa separada" << endl
					<< " 2. Sumar a tropa existente" << endl;
				cin >> opcion_distribuir; cout << endl;

				string opcion_tropa;

				if (opcion_distribuir == 1) {

					AgregarTropaaPais(k, tam_tropa, pais, aleatorio);

				}
				if (opcion_distribuir == 2)
				{
					//elegir tropa
					if (vector[k]->Contar_Tropas_en_Pais(pais, tipo) == 0) {
						getchar();
						AgregarTropaaPais(k, tam_tropa, pais, aleatorio);
						cout << endl << "No se encontraron tropas del mismo tipo disponibles. Su tropa fue agregada como unidad separada" << endl;
						system("pause");
						system("cls");
						break;
					}
					vector[k]->ImprimirTropasenPais(pais, tipo);
					cTropa * tropa_agregar = PedirTropaDistribucion(aleatorio, k);
					tropa_agregar->Distribuir(aleatorio, tam_tropa);
				}

				system("cls");

			} while (opcion_distribuir != 1 && opcion_distribuir != 2);
		}

		system("cls");
	}

}

void cJuego::AsignacionTropasInicial() {

	for (unsigned int k = 0; k < CA; k++)
	{
		cListaT<cPais>* PaisesD = vector[k]->getPaisesD();
		int aux_ca_paises = PaisesD->getCA();
		int aleatorio = -1;
		int tam_tropa, min, max;
		int i = 0, pos = 0;
		string tipo;

		for (i = 0; i < N_TROPAS_INICIAL; i++, pos++) {

			if (pos == aux_ca_paises)
				pos = 0;

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

			cPais* pais = PaisesD->getItem(pos);

			AgregarTropaInicial(k, tam_tropa, pais, aleatorio);
		}

		//PaisesD->Listar();
		//for (i = 0; i < aux_ca_paises; i++){
		//	cPais* aux = PaisesD->getItem(i);
		//	cout << aux->getNJugador() << endl;
		//	vector[k]->ImprimirTropasenPais(aux);
		//}
	}
}

void cJuego::ReasignarPais(cPais* atacado, cPais* atacante) { //listo
		
	cJugador *ganador = BuscarItem(atacante->getJugador()->getN_Jugador());

	cJugador *perdedor = BuscarItem(atacado->getJugador()->getN_Jugador());

	(*(perdedor->PaisesDominados)) - (atacado);

	atacado->setJugador(ganador);

	ganador->MoverTropas(atacado, atacante);

	cout << endl<<"Ha dominado " << atacado->getclave();


} //listo

//PARTIDA
void cJuego::Iniciar_Partida() {
	//Jugadores
	cJugador* Jug1 = operator[](0);
	cJugador* Jug2 = operator[](1);

	//Asignacion de Paises
	try{AsignarPaises();
	}
	catch (exception* e) {
		cout << e->what() << endl;
		system("pause");
	}

	//Asignacion inicial de tropas
	//AsignarTropas(0);
	AsignacionTropasInicial();

	//TODO INICIAR TROPAS AL INICIO DE LA PARTIDA

	//bienvenido, juego iniciado*/
}

int cJuego::Jugar() {

	int opcion;

	for (Ronda = 1; Ronda <= N_MAX_TURNOS; Ronda++)	{
		
		//Turnos

		if (Ronda!=1) 
			AsignarTropas();// asigno tropas al principio de la ronda

		for (unsigned int k = 0; k < CA; k++)
		{
			for (unsigned int h = 0; h < N_MAX_ATAQUES; h++)
			{
				//Hacer el cambio de turno

				*(this) == k; //sobrecarga cambiar turno

				//Buscar pais atacado, pais atacante, tropa atacante, tropa atacado

				cPais* pais_atacante = Buscar_p_atacante(k);									//busco el pais elegido y lo guardo en un puntero

				cPais* pais_atacado = Buscar_p_atacado(pais_atacante);							//buscar pais atacada

				cTropa* tropa_atacante = Buscar_t_atacante(k, pais_atacante,pais_atacado);		//pedir tropa atacante

				cTropa* tropa_atacada = Buscar_t_atacada(k,pais_atacante, pais_atacado);		//pedir tropa atacada

				//Ataque y Contraataque
				if (tropa_atacada != NULL)
				{
					bool aux_exito = *(tropa_atacante) >> (tropa_atacada);

					if (pais_atacado->getCA() == 0) {
						*pais_atacado = pais_atacante->getJugador();
						pais_atacante->getJugador()->MoverTropas(pais_atacado, pais_atacante);
					}
					
				}

				cJugador*jugador_atacado = pais_atacado->getJugador();
				if (jugador_atacado->getCA() == 0)
				{
					ImprimirGanador();
					CerrarJuego();
				}
				int at_disp = N_MAX_ATAQUES - h - 1;

				int opc_continuar = 0;

				if (at_disp > 0)
				{
					do {
						cout << endl << "Desea continuar atacando? ( " << at_disp << " ataques disponibles)"
							<< endl << "1. Si" << endl << "2. No" << endl;
						cin >> opc_continuar; cout << endl;
					} while (opc_continuar != 1 && opc_continuar != 2);

					if (opc_continuar == 2)
						break;
				}
			}

			int op;
			bool aux=false;
			do {
				cout << endl << "  Desea movilizar tropas?" << endl << "  1. Si" << endl << "  2. No" << endl;
				cin >> op; cout << endl;

				if (op == 1) {
					do
					{
						aux=Movilizar_tropas(k);
						op = 2;
					} while (aux == false);
				}

				system("pause");
				system("cls");

			} while (op != 2);

		}

		if (Ronda == N_RONDAS){
			
			cout << endl << "Desea continuar el juego?" << endl
			<< " Presione 1 para finalizar. Cualquier otra tecla para continuar" << endl;
			cin >> opcion;
			cout << endl;
			if (opcion == 1){
				ImprimirGanador();
				CerrarJuego();		// conviene usar una excepcion?
			}
		}
	}

	return 0;
}

//JUEGO
void cJuego::CambiarTurno(cJugador** Jugador, int k){

	ImprimirTurnoAtarque();

	Jugador_de_turno = Jugador[k];

	if (Jugador[k]->getclave() == "1")
		PrintJug1();
	else
		PrintJug2();

	/*cout << endl << "Jugador de turno: Jugador " << Jugador[k]->getclave() <<endl;
	*/
}

int cJuego::getRonda() {
	return Ronda;
}

//BUSQUEDA DE TROPAS Y PAISES 
cPais* cJuego::Buscar_p_atacante(int k){

	cPais* aux_atacante=NULL;
	string opcion_pais_atacante;
	int pos_atacante=INT_MAX;
	

	do {		
		//listo y pido pais atacante
		EncabezadoPais();
		vector[k]->ListarPosiblesAtacantes();
		cout << endl;
		cout << fixed;
		cout << setw(30) << right << "Con que pais quiere atacar?" << endl << setw(30) << "Ingrese la clave del pais: ";
		cin >> opcion_pais_atacante;
		cout << endl;
		if (vector[k]->PaisValidoparaAtaque(opcion_pais_atacante) == true)
		{
	
			pos_atacante = vector[k]->getPaisesD()->getItemPos(opcion_pais_atacante);
			getchar();
			if(pos_atacante!=INT_MAX)
			aux_atacante = vector[k]->PaisesDominados->BuscarItem(opcion_pais_atacante);

			/*
			//EXISTEN TROPAS?
			try {
				 {
					string nombre = aux_atacante->getNombre();
					throw nombre;
				}
			}
			catch (string nombre) {
				cout << "El pais " << nombre << " no posee tropas. Por favor, seleccione otro pais." << endl;
				system("pause");
				pos_atacante = INT_MAX;
				system("cls");
			}*/
		}
		else
			pos_atacante == INT_MAX;

		if (pos_atacante == INT_MAX) {
			system("cls");
			ImprimirTurnoAtarque();
			ImprimirJugador(k);
		}

	} while (pos_atacante == INT_MAX);	// busco la posicion en la lista INT_MAX si no se encontro => vuelvo a pedir
	
	return aux_atacante;
}

cPais* cJuego::Buscar_p_atacado(cPais* atacante){

	cPais* aux_atacado = NULL;

	int pos_atacado;
	string opcion_pais_atacado;

	do//listo y pido pais atacado
	{
		cout << "\t\t" << endl;
		
		atacante->ListarPosiblesAtaques();
		cout << setw(26) << right << "Que pais quiere atacar?" << endl << setw(30) << "Ingrese la clave del pais: ";
		cin >> opcion_pais_atacado;
		cout << endl;

		pos_atacado = atacante->getItemPos(opcion_pais_atacado);

		if (pos_atacado != INT_MAX) {
			aux_atacado = (*(atacante)) [(pos_atacado)];
			if (atacante->getJugador() == aux_atacado->getJugador())
				pos_atacado = INT_MAX;
		}
		/*
		//EXISTEN TROPAS?
		try{
			bool estado = aux_atacado->Exiten_Tropas_en_el_Pais();
			if (estado == false) {
				string nombre = aux_atacado->getNombre();
				throw nombre;
			}
		}
		catch (string nombre) {
			cout << "El pais " << nombre << " no posee tropas. Por favor, seleccione otro pais." << endl;
			system("pause");
			pos_atacado = INT_MAX;
			system("cls");
		}*/
		
	} while (pos_atacado == INT_MAX);// busco la posicion en la lista INT_MAX si no se encontro => vuelvo a pedir

	return aux_atacado;
}

cTropa* cJuego::Buscar_t_atacante(int k, cPais* atacante,cPais* atacado){

	string opcion_tropa;
	cTropa* tropa_atacante = NULL;
	//pido tropa atacante

	/*
	vector[k]->ImprimirTropasenPais(atacante);
	cout << endl << "Posibles tropas de ataque " << endl;
	atacado->getJugador()->ImprimirTropasenPais(atacado);
	*/

	system("cls");
	ImprimirTurnoAtarque();
	ImprimirJugador(k);

	vector[k]->ImprimirTropas(atacante, atacado);

	int aux_tropa_atacante;

	do {
		cout << "Con que tropa desea atacar? " << endl << "Ingrese clave de la tropa: ";
		cin >> opcion_tropa; cout << endl; //pido clave de la tropa
		aux_tropa_atacante = vector[k]->getItemPos(opcion_tropa);
		if (vector[k]->TropamePertenece(opcion_tropa) == true)
		{
			if ((*vector[k])[(aux_tropa_atacante)]->getPais() != atacante)//chequeo que la tropa este en mi pais atacante !!!!
				aux_tropa_atacante = INT_MAX;
			else
				tropa_atacante = (*vector[k])[(aux_tropa_atacante)];
		}
		else
			aux_tropa_atacante == INT_MAX;
	} while (aux_tropa_atacante == INT_MAX);
		
	return tropa_atacante;

}

cTropa* cJuego::Buscar_t_atacada(int h, cPais*atacante, cPais * atacado){

	string opcion_tropa;
	cTropa* tropa_atacada = NULL;
	int k = getItemPos(atacado->getNJugador());
	
	//vector[k]->ImprimirTropasenPais(atacado);
	bool tropas_atacado = atacado->Exiten_Tropas_en_el_Pais();
	if (tropas_atacado == false)
	{
		ReasignarPais(atacado, atacante);
		
		return NULL;
	}
	
	int aux_tropa_atacada;
	do {
		cout << endl << "Ingrese la clave de la tropa que desea atacar: ";
		cin >> opcion_tropa; cout << endl; //pido clave de la tropa
		aux_tropa_atacada = vector[k]->getItemPos(opcion_tropa);
		if(aux_tropa_atacada!=INT_MAX)
		if (vector[k]->TropamePertenece(opcion_tropa) == true)
		{
			if ((*vector[k])[(aux_tropa_atacada)]->getPais() != atacado)//chequeo que la tropa este en mi pais atacante
				aux_tropa_atacada = INT_MAX;
			else
				tropa_atacada = (*vector[k])[(aux_tropa_atacada)];
		}
		else
			aux_tropa_atacada == INT_MAX;
	} while (aux_tropa_atacada == INT_MAX);

	return tropa_atacada;
}

//MOVILIZACION 
cTropa * cJuego::PedirTropaDistribucion(int tipo, int k)
{
	string opcion_tropa;
	
	cout << endl << "A que tropa desea sumarlo?" << endl;
	int aux;
	do {
		cin >> opcion_tropa; cout << endl; //pido clave de la tropa
		aux = vector[k]->getItemPos(opcion_tropa);
		//dynamic cast
		if (aux != INT_MAX) {//si lo encontre chequeo que sea del tipo correcto
			cTropaArqueros* aux_a = dynamic_cast<cTropaArqueros*>((*vector[k])[ (aux)]);
			cTropaMagos* aux_m = dynamic_cast<cTropaMagos*>((*vector[k])[(aux)]);
			cTropaCaballeros* aux_c = dynamic_cast<cTropaCaballeros*>((*vector[k])[(aux)]);
			switch (tipo) {
			case 0:
				if (aux_a != NULL || aux_c != NULL)
					aux = INT_MAX;
				break;
			case 1:
				if (aux_c != NULL || aux_m != NULL)
					aux = INT_MAX;
				break;
			case 2:
				if (aux_m != NULL || aux_a != NULL)
					aux = INT_MAX;
				break;
			}
		}
		cout << endl;
	} while (aux == INT_MAX);

	cTropa* tropa_agregar = (*vector[k])[ aux];
	return tropa_agregar;
}

bool cJuego::Movilizar_tropas(int k){

	string pais_origen, pais_destino;
	int pos_origen, pos_destino;
	
	bool aux;
	bool aux1 = false;
	do //listo y pido pais origen
	{
		vector[k]->PaisesDominados->Listar();
		cout << "Desde que pais quiere movilizar tropas?" << endl << "Ingrese la clave del pais: ";
		cin >> pais_origen;
		cout << endl;
		pos_origen = vector[k]->getPaisesD()->getItemPos(pais_origen);
		cPais* origen = (*(vector[k]->getPaisesD()))[ pos_origen];
		aux = origen->TengoLimitrofesPropios();
		if (aux == false) {
			cout << endl << "No hay paises a los que movilizar" << endl;
			break;
			return false;
		}//no hay paises limitrofes del mismo jugador
	} while (pos_origen == INT_MAX);

	cPais* origen = (*(vector[k]->getPaisesD()))[pos_origen];
	cPais* destino;

	do{ //listo y pido pais atacado
		aux = origen->ListarLimitrofesPropios();
		cout << "A que pais quiere movilizar tropas?" << endl << "Ingrese la clave del pais: ";
		cin >> pais_destino;
		cout << endl;
		pos_destino = vector[k]->getPaisesD()->getItemPos(pais_destino);
		if (pos_destino != INT_MAX)
		{
			destino = (*(vector[k]->getPaisesD()))[ pos_destino];
			if (origen->getJugador() == destino->getJugador()) {
				aux1=vector[k]->MoverTropas(destino, origen);//movilizo tropas
				if(aux1 == false)  return false;
			}
			else
				pos_destino = INT_MAX;
		}

	} while (pos_destino == INT_MAX);

	return true;
}

void cJuego::AgregarTropaaPais(int k, int tam_tropa, cPais * pais, int aleatorio)
{
	cTropa* tropa_m = new cTropaMagos(tam_tropa, pais);
	cTropa* tropa_a = new cTropaArqueros(tam_tropa, pais);
	cTropa* tropa_c = new cTropaCaballeros(tam_tropa, pais);

	switch (aleatorio) {

	case 0:
		*(vector[k]) + (tropa_m);
		cout << endl << "Tropa agregada satisfactoriamente" << endl;
		break;

	case 1:
		*(vector[k]) + (tropa_a);
		cout << endl << "Tropa agregada satisfactoriamente" << endl;
		break;

	case 2:
		*(vector[k]) + (tropa_c);
		cout << endl << "Tropa agregada satisfactoriamente" << endl;
		break;
	}
}

void cJuego::AgregarTropaInicial(int k, int tam_tropa, cPais * pais, int aleatorio){
	cTropa* tropa_m = new cTropaMagos(tam_tropa, pais);
	cTropa* tropa_a = new cTropaArqueros(tam_tropa, pais);
	cTropa* tropa_c = new cTropaCaballeros(tam_tropa, pais);

	switch (aleatorio) {

	case 0:
		*(vector[k]) + (tropa_m);
		break;

	case 1:
		*(vector[k]) + (tropa_a);
		break;

	case 2:
		*(vector[k]) + (tropa_c);
		break;
	}
}


//FUNCIONES APARTE
cJugador * cJuego::getGanador()
{
	cJugador*Ganador = NULL;

	for (unsigned int k = 0; k < CA; k++)
	{
		if (vector[k]->PaisesDominados->getCA() == N_PAISES_TOTALES)
		{
			Ganador = vector[k];
		}
	}
	if (Ganador == NULL)
	{
		Ganador = BuscarMax();

	}


	return Ganador;
}

cJugador * cJuego::Desempate(cJugador*j1, cJugador*j2)
{
	//se desempata por ataque

	if (j1->getATTOTAL() < j2->getATTOTAL())
		return j2;
	if (j1->getATTOTAL() > j2->getATTOTAL())
		return j1;
	if (j1->getATTOTAL() == j2->getATTOTAL())
	{
		cout << endl << "Ha habido un empate entre los jugadores " << j1->getN_Jugador() << " y " << j2->getN_Jugador() << endl;
		return NULL;
	}

	return NULL;
}

cJugador * cJuego::BuscarMax()
{
	cJugador*Ganador = vector[0];

	for (unsigned int i = 0; i < CA; i++)
	{
		if (vector[i]->PaisesDominados->getCA() > Ganador->PaisesDominados->getCA())
		{
			Ganador = vector[i];

		}
	}
	for (unsigned int k = 0; k < CA; k++)
	{
		if (Ganador->PaisesDominados->getCA() == vector[k]->PaisesDominados->getCA())
			if (Ganador->getN_Jugador() != vector[k]->getN_Jugador())
			{
				Ganador = Desempate(Ganador, vector[k]);
				if (Ganador == NULL)
					break;
			}
	}

	return Ganador;
}

void cJuego::operator==(int k)
{
	CambiarTurno(getvector(), k);
}

//IMPRIMIR
void cJuego::Imprimir() {
}

void cJuego::Bienvenida() {

	cout << "  BIENVENIDOS A : " << endl;

	cout << R"(                                                                                                                                         
  -------------------------------------------------------------------------------------------------------------------------------------------------- 
  |      .#&@@@&&.      ,%%%%      ,%%%%,   ,%%%%*  %%%%%%%%%%       %%%%%    %%%%%      ,%%%%,      .&@@@   ,%%%%%%%%%%% %%%%%%%%%%  %%%%%%%%*    |  
  |    @@@@@@@@@@*     ,@@@@@@     (@@@@@   @@@@@,  @@@@@@@@@@      .@@@@@   @@@@@@     ,@@@@@@     @@@@@@@@ /@@@@@@@@@@& @@@@@@@@@@  @@@@@@@@@@&  | 
  |  .@@@@            *@@@ @@@#    %@@@@@, @@@&@@.  @@@@            *@@%@@% #@@#@@@    *@@@ &@@@    @@@@         @@@@     @@@&        @@@,   @@@&  | 
  |  &@@@.  /@@@@@   (@@@,,/@@@.   @@@,@@@/@@*&@@.  @@@@@@@@@       #@@,@@@.@@&/@@&   .@@@*,,@@@#    #@@@@,      @@@&     @@@@@@@@&   @@@.@@@@@,   | 
  |  /@@@#    @@@%  &@@@@@@@@@@@   @@& @@@@@& @@@   @@@%            @@@..@@@@@ (@@%  /@@@@@@@@@@@*      @@@@     @@@#     @@@*        @@@  @@@%    | 
  |   /@@@@@@@@@@( @@@@,     @@@@  @@% ,@@@@  @@@  .@@@@@@@@@&      @@@  @@@@. %@@% (@@@,     @@@@ /@@@@@@@#    .@@@(    .@@@@@@@@@/ .@@@  ,@@@(   | 
  |      ./%%%/*. ,,,,.      .,,,. ,,.  ,,,.  ,,,  .,,,,,,,,,.      ,,,  .,,,  ,,,..,,,.       ,,,, /#%%/.      .,,,.    .,,,,,,,,,  .,,,   ,,,,   |
  -------------------------------------------------------------------------------------------------------------------------------------------------- 
)" << '\n';

	cout << R"( 
	                                                                                                                                                               
                                                                                                                         (,*                                    
     BIENVENIDOS JUGADORES.                                                                                           .*,,////////                               
     CADA UNO DE USTEDES COMIENZA CON 5 PAISES Y 10 TROPAS. CADA TROPA ES DE UN UNICO TIPO DE UNIDAD Y               *,,,,,(%////(#&                            
     POSEE DE 10-20 UNIDADES SI SON CABALLEROS, 15-30 SI SON ARQUEROS Y 20-40 SI SON MAGOS                         #,,,,,,@/(///(%(((/                        
                                                                                                                  (..(,,,#//////////////                       
     EN CADA TURNO, CADA JUGADOR PUEDE REALIZAR HASTA 3 ATAQUES DESDE UN PAIS A UN PAIS VECINO QUE               *.#####(/////////////%(//,                   
     NO CONTROLE. SI EL ATACANTE GANA Y EL ATACADO SE QUEDA SIN TROPAS, EL JUGADOR GANA EL PAIS Y PUEDE          #####&///////////////////////(               
     MOVER LA CANTIDAD DE TROPAS QUE DESEE A ESE PAIS.                                                             .####/////////////////////////(             
                                                                                                                    *#####***////////////////////              
     AL COMIENZO DE CADA RONDA, CADA JUGADOR OBTIENE (CA DE PAISES / 2) TROPAS ALETORIAS. EL JUGADOR                  .####/*****///////////////                
     DEBE INDICAR EN QUE PAIS QUIERE COLOCAR CADA TROPA Y SI QUIERE MANTENERLA COMO UN GRUPO SEPARADO O                 *#*******&////////////                 
     SUMARLA A UNA TROPA YA EXISTENTE EN ESE PAIS.                                                                       &%****((&///////////(                 
                                                                                                                         (,%///((((/////////#                  
     CARACTERISTICAS DE LAS UNIDADES:                                                                                    **//////((#///%                       
                                                                                                                         ,////////&////                        
     - LOS CABALLEROS TIENEN UN ATAQUE (AT) ENTRE 30-40 Y ENTRE 80 Y 100 DE VIDA (HP).                                    &///////%%/&.                         
                                                                                                                         *(//////(%%                            
     - LOS ARQUEROS TIENEN UN ATAQUE (AT) ENTRE 20-30 Y ENTRE 60 Y 80 DE VIDA (HP).                                     ,///////(                              
                                                                                                                        *///%/                                 
     - LOS MAGOS TIENEN UN ATAQUE (AT) ENTRE 10-20 Y ENTRE 40 Y 60 DE VIDA (HP)                                        .&///#                                  
                                                                                                                       %,//&                                   
                                                                                                                       @%/(                                    
                                                                                                                        #&(                                    
       
                                                                HABILIDADES Y DEBILIDADES                                                                      
                             @@@@@@@&                             
                           @         &@                         - LOS CABALLEROS, TIENEN UN CONTRATAQUE CON UN 25% DE AUMENTO DE DAÑO CADA VEZ QUE SE 
                         @@    @@%@    @                          LOS ATACO. LOS CABALLEROS SON FUERTES A LOS ARQUEROS.                              
                         @    @         @                         
                         @   .@         @                       - LOS ARQUEROS SON UNIDADES QUE ALEATORIAMENTE PUEDEN ATACAR UNA SEGUNDA VEZ CON UN 50% 
                         @,   &@@@@    @                          DE AUMENTO DE DAÑO Y SON FUERTES CONTRA LOS MAGOS.
                         /@@          @%                          
                        /@@@\@@@...@@#%@.                       - LOS MAGOS SON UNIDADES QUE ATACAN EN ZONA, ES DECIR ATACAN A TODAS LAS UNIDADES 
                       @@@@            '@&                        ENEMIGAS EN EL CAMPO DE BATALLA. POR SU PARTE LOS MAGOS SON FUERTES FRENTE A LOS CABALLEROS.
                     #@ .*               @                       
                    @,                     @ @                  - SER FUERTE FRENTE A OTRA CLASE SIGNIFICA QUE SE OBTIENE UN 25% DE AUMENTO DE INCREMENTO EN EL ATAQUE. 
                   @@                     %@@@@                   
                 .@                          @@(@@@                 
             (@@------@@                    @@      @@             
            @  &&    @  @                 @/     %    (@           
           @   @&   @ @  @#/%            @/     @.%    .@          
          ,@   @ @  @ %   @@@@@@@@@@@@@@@@     @...@    @          
           @   @  @@  @  *@\@            @    @   @@@   @          
           %@            @                @            @           
             @&        @@                  @@        @@            
                @@@@@#                        &@@@@@               
 
)" << '\n';

	system("pause");
	system("cls");
}

void cJuego::ImprimirGanador() {

	cJugador* Ganador;
	Ganador = getGanador();
	if (Ganador != NULL) {

		string ganador = Ganador->getclave();

		if (ganador == "1")
			GanadorJug1();
		else
			GanadorJug2();
	}

	system("pause");
}

void cJuego::ImprimirTurnoAtarque() {
	cout << endl << R"(  
   -------------------------------------------------------------------------------------------------------------------------------------------------
   |                                                                                                                              %&&%      %&&%   |
   | %%%%%%%(%%%   %%  %%&&%   %%%   %%    *@@%       %%&&&*   %%%%%%%       %%%   %%%%%%%,   %%%      ,@@&    %%%   %%  %%%%%%   #&&&%    %&&&#   |
   |   .@@   @@@   @@ .@@  @@@ @@@@  @@  @@@  &@@     @@   @@@ @@@          @@@@#    @@@     @@#@@   @@@  (@@, @@@   @@ .@@@        #&&&( (&&&     |
   |   *@@   @@@  ,@@ *@@&@@@  @@ @@ @@ @@@    @@@    @@   @@@ @@@'''      @@%%@@    @@@    @@%%@@/ @@@    @@@ @@@  ,@@ *@@@'''        #&&%&&      | 
   |   &@@   @@@  @@@ &@@ @@&  @@  @@@@ .@@@  @@@     @@..@@@. @@@@@@@   ,@@   &@@   @@@   @@*  .@@  @@@  @@@, @@@  @@@ &@@@@@@        %&%&%       |
   |    --     ----                        ----                                                        ----      ----             #%#%&%   %&%#%#  |
   ------------------------------------------------------------------------------------------------------------------------------ *(%#     #%/*) ---    
)" << '\n';

	/*

	cout << endl << R"(
	..,               .,,
	,...,         ....,
	,,....      ....,
	@@@@@@@/@@.  @@% @@@@@&  @@@.  @@. .&@@@@*     @@@@@&,  @@@@@@.      @@@   @@@@@@@/  ,@@@     %@@@@*  /@@   @@ *@@@@@@        .,....  ,..,,
	/@@   @@   @@/ @@. ,@& @@@@, @@ %@&   %@@    @@,  @@& @@/         @@,@@    /@@     @@#@%  %@@   %@@ #@@  .@@ /@@               ,..,..,.
	#@@   @@   @@, @@ @@,  @@ @@/@@ @@.   ,@@    @@.  &@@ @@@@@*     @@@@@@%   #@@   .@@@@@@* @@/   ,@@ &@&  *@@ (@@@@@             ...,,
	&@&   @@@@@@@  @@  @@  @@  %@@@  @@@@@@@     @@@@@@&  @@@@@@    @@/   @@/  &@&  /@@   ,@@. @@@@@@@@,/@@@@@@% &@@@@@%      .*, ..., .,., .**
	***,      ***,
	.##/**,    **,##/
	,***             .***
	*.                ,
	)" << '\n';
	*/
}

void cJuego::ImprimirJugador(int k) {
	if (vector[k]->getclave() == "1")
		PrintJug1();
	else
		PrintJug2();
}

void cJuego::PrintJug1() {
	cout << endl << R"(                                                                                                    
     @@                        @@               @@@             
     @@ @@  @@  @@@@@ @@@@  @@@@@ @@@@& @@@,   #/@%             
     @@ @@  @@ @@  @@ @..@  @@  @ @* @@ @@ '     @@              
   @@@   @@.@   &@.@@ @@ @  @@,@@ .@@@- @@       @@              
                 @@@@                                            
  )" << '\n';
}

void cJuego::PrintJug2() {
	cout << endl << R"(                                                                                                    
                                                                     
    @@                        @@              @@@@             
    @@ @@  @@  @@@@@ @@@@  @@@@@ @@@@& @@@,     @@             
    @@ @@  @/ @@  @@ @..@  @@  @ @* @@ @@ '   @@              
  @@@   @@.@   &@.@@ @@ @  @@,@@ .@@@- @@    @@@@@             
                @@@@                                            
                                                                     
    )" << '\n';
}

void cJuego::GanadorJug1() {
	cout << endl << R"(                                                                                                                                                                                                             
         &@@@(                         @@                       @@                         @@                 @@@      
       @@%      @@@@  @@@@@  @@@@*  @@@@@  @@@&  @@@#   @@      @@ @@  @@  @@@@@ @@@@@  @@@@@  @@@@  @@@@    @@@&      
       @@  @@@  @@@@ *@@ @@. &@@@@ @@  @@.@@  @@ @@            .@@ @@  @@ @@  @@ ,@@@@ @@  @@ @@  @@ @@       @@,      
       (@@@@@@ @@&@@ @@  @@ @@@ @@ @@@@@@ @@@@@  @@     @@   @@@@, @@@@@@ @@@@@&*@@%@@ @@@@@@ @@@@@/ @@       @@       
                                                                          @@&@@,                                                                               
  )" << '\n';
}

void cJuego::GanadorJug2() {
	cout << endl << R"(                                                                                                    
         &@@@(                         @@                       @@                         @@               (@@@&      
       @@%      @@@@  @@@@@  @@@@*  @@@@@  @@@&  @@@#   @@      @@ @@  @@  @@@@@ @@@@@  @@@@@  @@@@  @@@@      @@@     
       @@  @@@  @@@@ *@@ @@. &@@@@ @@  @@.@@  @@ @@            .@@ @@  @@ @@  @@ ,@@@@ @@  @@ @@  @@ @@      ,@@       
       (@@@@@@ @@&@@ @@  @@ @@@ @@ @@@@@@ @@@@@  @@     @@   @@@@, @@@@@@ @@@@@&*@@%@@ @@@@@@ @@@@@/ @@     @@@@@*     
                                                                          @@&@@,                                                                               
  )" << '\n';
}

void cJuego::EncabezadoPais()
{
	cout << setw(8) << "Clave" << setw(25) << "Nombre del Pais" << setw(8) << endl;
}

//FINAL
void cJuego::CerrarJuego(){
}

//EXTERNA
bool repetidos(int n, int num[])
{
	for (int i = 0; i<N_PAISES_TOTALES; i++)
		if (n == num[i])
			return true;

	return false;
}


