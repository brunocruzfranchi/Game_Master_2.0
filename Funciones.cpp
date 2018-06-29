
#include "Funciones.h"
#define N_JUGADORES 2
istream & operator>>(istream & in, string * n)
{
	int i = 0;
	cout << endl << "Bienvenido" << endl;
	do
	{	cout << "Ingrese en nombre del Jugador " << i + 1 << ": "<<endl;
		cin >> n[i];
		cout << endl;
		i++;
	} while (i<N_JUGADORES);
	return in;
}
