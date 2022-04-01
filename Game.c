#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
int retornarValor();
void mostrarCartas();
void llenarJugador();


int main(int argc, char *argv[]) {
	srand(time(NULL));   // Initialization, should only be called once.
	
	bool barajaM[52];
	bool barajaO[52];
	bool stock[52];
	int ultimaCarta = -1;
	
	int buscador;
	for (buscador = 0; buscador < 52; buscador++){	
		barajaM[buscador] = 0;
		barajaO[buscador] = 0;
		stock[buscador]= 1;
	}
	
	llenarJugador(barajaM, stock);
	llenarJugador(barajaO, stock);
	mostrarCartas(barajaO);
	scanf("%d");
	return 0;
}

int retornarValor(int indice){
	return indice/4;
}

void llenarJugador(bool* barajaJugador, bool* barajaMadre) {
	int contador = 0;
	while (contador <5) {
		int r = rand() % 52;
		bool cartaExiste = barajaMadre[r];
		if (cartaExiste) { // non determinisic
			barajaMadre[r] = false;
			barajaJugador[r] = true;
			contador++;
		}      
	}
}

void mostrarCartas(bool* jugador) {
	int i;
	printf("Usted tiene las cartas:");

	for (i = 0; i < 52; i++){	
		if(jugador[i]) {
			printf("%d, ", retornarValor(i));	
		}
	}
}

