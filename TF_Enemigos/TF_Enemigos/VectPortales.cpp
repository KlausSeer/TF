
#include "VectPortales.h"

	VectPortales::VectPortales(int n) {
		inicializarPortales(n);
	}

	void VectPortales::inicializarPortales(int n) {

		if (n == 3) {
			this->portales.push_back(new Portal((Form_Width / 2) - 7, 0,1)); //Portal superior central (para regresar al escenario anterior); 
		}

		this->portales.push_back(new Portal((Form_Width / 10), (Form_Height - 25), 2)); // Portal inferior izq
		this->portales.push_back(new Portal((Form_Width / 1.2), (Form_Height - 25), 3)); // Portal inferior der

	}

	void VectPortales::Mostrar(Graphics^ G, Bitmap^ bmpPor) {
		for each (Portal* var in portales) {
			var->Mostrar(G, bmpPor);
		}
	}

	int VectPortales::ver_Contact_con_Portales(Rectangle UbicacionJugador) {
		for each(Portal* var in portales) {
			if (var->Contact_Player(UbicacionJugador)) {
				return var->getId();
			}

		}

		return -1;
	}

	std::vector<Portal*> VectPortales::getPortales()
	{
		return portales;
	}
