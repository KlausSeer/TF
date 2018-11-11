
#include "VectPortales.h"

	VectPortales::VectPortales(int n) {
		inicializarPortales(n);
	}

	void VectPortales::inicializarPortales(int n) {

		if (n == 3) {
			this->portales.push_back(new Portal((Form_Width / 2) - 7, 0)); //Portal superior central (para regresar al escenario anterior); 
		}

		this->portales.push_back(new Portal((Form_Width / 10), (Form_Height - 25))); // Portal inferior izq
		this->portales.push_back(new Portal((Form_Width / 1.2), (Form_Height - 25))); // Portal inferior der

	}

	void VectPortales::Mostrar(Graphics^ G, Bitmap^ bmpPor) {
		for each (Portal* var in portales) {
			var->Mostrar(G, bmpPor);
		}
	}

	int VectPortales::ver_Contact_con_Portales(Rectangle UbicacionJugador) {

		int i = 0;
		for each(Portal* var in portales) {
			i += 1;
			if (var->Contact_Player(UbicacionJugador)) {
				return i;
			}

		}

		return -1;
	}
