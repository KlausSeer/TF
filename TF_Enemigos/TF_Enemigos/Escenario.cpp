#include "Escenario.h"

Escenario::Escenario(int nportales, int _nivel){
	
	this->nivel = _nivel;

	player = new Player(Form_Width / 2, Form_Height / 2);

	//srand(time(0));
	this->n_fondo = 0;

	int n = 4 * nivel - 1; // para determinar el numero de enemigos
	laHorda = new Horde(n,n, Form_Width, Form_Height); // n es numerodeenemigos, width ,heigt 
	
	portales = new VectPortales(nportales);

	items = new VecItems(n % 7, Form_Width, Form_Height);  //TIENE DOS CONSTRUCTORES ?
	
}



void Escenario::Mostrar(Graphics^G, Bitmap^ bg1, Bitmap^bmpM, Bitmap^bmpS, Bitmap^bmpB, Bitmap^bmpT, Bitmap^ bmpPor, Bitmap^ bmpA, Bitmap^ bmpP, Bitmap^ bmpV, Bitmap^bmpPlayer, Bitmap^bmpPro) {
	//Dibuja Fondo
	//switch (n_fondo) {
	//	case 0 : G->DrawImage(bg1, Rectangle(0,0,Form_Width,Form_Height)); break;
	//	default: break;
	//}

	laHorda->CheckLive();
	laHorda->CheckLiveEnemies();
	items->CheckLive();

	G->DrawImage(bg1, Rectangle(0, 0, Form_Width, Form_Height)); 
	// Dibuja Horda
	laHorda->Mostrar(G, bmpM, bmpS,bmpB, bmpT); 

	//Dibuja los portales
	portales->Mostrar(G, bmpPor);

	//Dibujar portales
	items->Mostrar(G, bmpA, bmpP, bmpV);

	player->drawPlayer(G, bmpPlayer);
	player->animateProyectil(G, bmpPro);
}

int Escenario::ver_Contact_con_Portales(Rectangle UbicacionJugador){

	return this->portales->ver_Contact_con_Portales(UbicacionJugador);

}

Player * Escenario::GetPLayer()
{
	return player;
}

void Escenario::CheckColision()
{
	for each (Enemigo* var in laHorda->getHorde())
	{
		Rectangle rec(var->getX(), var->getY(), var->getL(), var->getL());
		if (player->Colision(rec))
			var->setVivo(false);
	}

	for each (Objeto* var in items->GetItems())
	{
		Rectangle rec(var->getX(), var->getY(), var->getR(), var->getR());
		if (player->Colision(rec))
		{
			switch (var->getTag())
			{
			case 10: player->Recargar();  break;
			case 11:   break;
			case 12: player->VidaExtra();  break;
			default:
				break;
			}
			var->setLive(false);
		}
			
	}
}

void Escenario::deActive()
{
	laHorda->deActive();
	items->deActive();
}
