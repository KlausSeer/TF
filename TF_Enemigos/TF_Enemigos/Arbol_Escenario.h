#pragma once

#include "Escenario.h"

class Arbol_Escenario {

	struct Node {
		Escenario* element;
		Node* Father_Esc;
		Node* left_Child_Esc;
		Node* right_Child_Esc;
		int profundidad;
		Node(int profundidad, Escenario* element, Node* padre, Node* left, Node* right);
	};

	Node* root;
	Node* current;


public:

	Arbol_Escenario();

	Node* return_Current_Tree();

	void Mostrar(Graphics^G, Bitmap^ bg1, Bitmap^bmpM, Bitmap^bmpS, Bitmap^bmpB, Bitmap^bmpT, Bitmap^ bmpPor, Bitmap^ bmpA, Bitmap^ bmpP, Bitmap^ bmpV, Bitmap^bmpPlayer, Bitmap^bmpPro);

	void manage_Tree(Rectangle UbicacionJugador); // Si toca el portal cambio de escenario

	void tree_Random_node(int a, int b, int c); // parametros de teletransportación

	void CheckColision();

	Player* GetPLayer();
};
