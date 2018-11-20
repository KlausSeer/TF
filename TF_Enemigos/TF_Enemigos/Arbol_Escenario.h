#pragma once

#include "Escenario.h"

using namespace System::IO;
using namespace System::Xml;

class Arbol_Escenario {

	struct Node {
		Escenario* element;
		Node* Father_Esc;
		Node* left_Child_Esc;
		Node* right_Child_Esc;
		int profundidad;
		int id; // 1: Nodo izquierdo, 2:Nodo derecho ---->
		Node(int profundidad, Escenario* element, Node* padre, Node* left, Node* right , int id); //
	};

	Node* root;
	Node* current;
	Node* auxCurrent;
	int puntos;

public:

	Arbol_Escenario();

	Node* return_Current_Tree();

	void Mostrar(Graphics^G, Bitmap^ bg1, Bitmap^bmpM, Bitmap^bmpS, Bitmap^bmpB, Bitmap^bmpT, Bitmap^ bmpPor, Bitmap^ bmpA, Bitmap^ bmpP, Bitmap^ bmpV, Bitmap^bmpPlayer, Bitmap^bmpPro);

	void manage_Tree(Rectangle& UbicacionJugador); // Si toca el portal cambio de escenario

	void tree_Random_node(int a, int b, int c); // parametros de teletransportación

	void CheckColision();

	void Puntaje(int n);

	bool getVivo();

	void Damage();

	void CheckProyectiles();

	void save_inOrder_Tree(Node* node,XmlWriter^ writer) {

			if (node != nullptr) {
				save_inOrder_Tree(node->left_Child_Esc, writer);
				save_Node(node, writer, node->profundidad, node->id);
				save_inOrder_Tree(node->right_Child_Esc, writer);
			}

	}

	void save_tree() {

		XmlWriter^ writer = XmlWriter::Create("Archivo.xml");
		writer->WriteStartElement("DATA");
		save_inOrder_Tree(this->auxCurrent, writer);
		writer->WriteEndElement();

		writer->Close();

		delete writer;


	}



	
	void save_Node(Node* node, XmlWriter^ writer, int nivel, int id) {

		writer->WriteStartElement("Node");
		writer->WriteString(nivel.ToString() + id.ToString()); // nivel y id (1: node izq , 2: node der)
		writer->WriteEndElement();

		writer->WriteStartElement("Profundidad");
		writer->WriteString(node->profundidad.ToString()); // Prof
		writer->WriteEndElement();


		writer->WriteStartElement("NShooter"); //<---------------------
		writer->WriteString(node->element->getHorda()->GetShooter().ToString());// <<<<-- Implementar una funcion que retorne el numero de Enemigos Shooters
		writer->WriteEndElement();

		writer->WriteStartElement("NMele");
		writer->WriteString(node->element->getHorda()->GetMele().ToString()); //<<<--Implementar una funcion que retorne el numero de Enemigos Melee
		writer->WriteEndElement();
		


	}

	Player* GetPLayer();
};
