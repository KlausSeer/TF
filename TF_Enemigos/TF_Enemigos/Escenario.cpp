#include "Escenario.h"

Escenario::Escenario(int nportales, int _nivel){
	inicializarPortales(nportales);

	srand(time(0));
	this->n_fondo = rand () % 1;

	this->nivel = _nivel;

	int n = 4*nivel - 1; // para determinar el numero de enemigos
	this->laHorda = new Horde(n, 15,15); // n es numerodeenemigos, width ,heigt 

}

void Escenario::inicializarPortales(int n) {
	
	if (n == 3) {
		portales.push_back(new Portal((Form_Width / 2) - 7, 0)); //Portal superior central (para regresar al escenario anterior); 
	}

	this->portales.push_back(new Portal((Form_Width / 10), (Form_Height - 25))); // Portal inferior izq
	this->portales.push_back(new Portal((Form_Width / 1.2), (Form_Height - 25))); // Portal inferior der
	
}

void Escenario::Mostrar(Graphics^G, Bitmap^ bg1,Bitmap^bmpM, Bitmap^bmpS, Bitmap^bmpB, Bitmap^bmpT){

	switch (n_fondo) {
		case 0 : G->DrawImage(bg1, Rectangle(0,0,Form_Width,Form_Height)); break;
		default: break;
	} //Dibuja Fondo

	laHorda->Mostrar(G, bmpM, bmpS,bmpB, bmpT); // Dibuja Horda

	for each (Portal* var in portales){
		var->Mostrar(G, bmpB);
	} //Dibuja los portales

}

int Escenario::ver_Contact_con_Portales(Rectangle UbicacionJugador){

	int i = 0;
	for each(Portal* var in portales){
		i+=1;
		if(var->Contact_Player(UbicacionJugador)){
			return i;
		}

	}

	return -1;
}
