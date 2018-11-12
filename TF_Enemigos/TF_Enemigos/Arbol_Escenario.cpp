#pragma once
#include "Arbol_Escenario.h"



	Arbol_Escenario::Node::Node(Escenario* element, Node* padre, Node* left, Node* right) {
	this->element = element;
	this->Father_Esc = padre; // Apunta a su padre tambien
	this->left_Child_Esc = left;
	this->right_Child_Esc = right;

	}


	Arbol_Escenario::Arbol_Escenario() {
		this->root = new Node(new Escenario(2, 5), nullptr, nullptr, nullptr); // ver nivel
		this->current = root;
	}

	Arbol_Escenario::Node* Arbol_Escenario::return_Current_Tree() { // Para saber en donde estamos
		return this->current;
	}

	void Arbol_Escenario::manage_Tree(Rectangle UbicacionJugador) { //Esta funcion es llamada para ver si hay colision con los portales y agrega Escenarios si no hay naa.

		switch (this->current->element->ver_Contact_con_Portales(UbicacionJugador))
		{
		case 1: //hacia arriba
			if (this->current->Father_Esc == nullptr) {
				// Creo que nunca se dara esta condicion
			}

			this->current = current->Father_Esc;

			break;
		case 2: //Portal abajo izquierda
			if (this->current->left_Child_Esc == nullptr) {
				this->current->left_Child_Esc = new Node(new Escenario(3, 4), this->current, nullptr, nullptr); //chequear lo de niveles (constructor de escenario)
			}
			this->current = current->left_Child_Esc;
			break;
		case 3: //Portal abajo derecha
			if (this->current->right_Child_Esc == nullptr) {
				this->current->right_Child_Esc = new Node(new Escenario(3, 4), this->current, nullptr, nullptr);//chequear lo de niveles (constructor de escenario)
			}
			this->current = current->right_Child_Esc;
			break;
		default:
			break;
		}

	} 



