#include "Escenario.h"

Escenario::Escenario(int nportales, int _nivel){
	
	this->nivel = _nivel;

	srand(time(0));
	this->n_fondo = rand() % 1;

	int n = 4 * nivel - 1; // para determinar el numero de enemigos
	this->laHorda = new Horde(n, 15, 15); // n es numerodeenemigos, width ,heigt 
	
	this->portales = new VectPortales(nportales);

	this->items = new VecItems(n % 7, Form_Width, Form_Height);  //TIENE DOS CONSTRUCTORES ?
	
}



void Escenario::Mostrar(Graphics^G, Bitmap^ bg1,Bitmap^bmpM, Bitmap^bmpS, Bitmap^bmpB, Bitmap^bmpT, Bitmap^ bmpPor, Bitmap^ bmpA, Bitmap^ bmpP, Bitmap^ bmpV){
	//Dibuja Fondo
	switch (n_fondo) {
		case 0 : G->DrawImage(bg1, Rectangle(0,0,Form_Width,Form_Height)); break;
		default: break;
	}
	// Dibuja Horda
	laHorda->Mostrar(G, bmpM, bmpS,bmpB, bmpT); 

	//Dibuja los portales
	this->portales->Mostrar(G, bmpPor);

	//Dibujar portales
	this->items->Mostrar(G, bmpA, bmpP, bmpV);

}

int Escenario::ver_Contact_con_Portales(Rectangle UbicacionJugador){

	return this->portales->ver_Contact_con_Portales(UbicacionJugador);

}
