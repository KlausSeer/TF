#include "Portal.h"
#include "Horda.h"
#include <vector>
#include <ctime>

#define Form_Width 1200 
#define Form_Height 670 

class Escenario
{
	std::vector<Portal*> portales;
	Horda* laHorda;
	int n_fondo;
	int nivel; 
	/*
	n_fondo es un indice para escoger la imagen del escenario
	por el momento solo tenemos 1 imagen,
	si se quiere agregar más, modifique funcion Mostrar y el Contructor de Escenario
	*/
public:
	Escenario(int _nportales, int nivel); // probablemente el nivel del escenario sera la profundidad en la que esta su nodo en el arbol
	~Escenario();

	void Mostrar(Graphics^G, Bitmap^ bg1,Bitmap^bmpM, Bitmap^bmpS, Bitmap^bmpB); // Se deben dibujar el escenario, los portales, los enemigos(Horda)
	int ver_Contact_con_Portales(Rectangle UbicacionJugador); // esta funcion para saber si se ha cruzado un portal (-1: No cruzo, 1: Hacia el nodo padre, 2: nodo hijo izq, 3: nodo hijo der)

private:
	void inicializarPortales(int n);
};
