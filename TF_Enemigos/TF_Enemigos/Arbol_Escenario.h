#pragma once

#include "Escenario.h"

class Arbol_Escenario {

	struct Node {
		Escenario* element;
		Node* Father_Esc;
		Node* left_Child_Esc;
		Node* right_Child_Esc;

		Node(Escenario* element, Node* padre, Node* left, Node* right);
	};

	Node* root;
	Node* current;


public:

	Arbol_Escenario();

	Node* return_Current_Tree();

	void manage_Tree(Rectangle UbicacionJugador);



};
