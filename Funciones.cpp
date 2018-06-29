
#include "Funciones.h"
#define N_JUGADORES 2
istream & operator>>(istream & in, string ** n)
{
	cout << endl << "Bienvenido" << endl;
	for (int i = 0; i < N_JUGADORES; i++)
	{
		cout << "Ingrese en nombre del Jugador " << i + 1 << ": "<<endl;
		getchar();
		cin >> &n[i];
		cout << endl;
	}
	return in;
}
