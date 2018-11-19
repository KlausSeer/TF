#pragma once
#include "Arbol_Escenario.h"
#include<ctime>


	Arbol_Escenario::Node::Node(int profundidad, Escenario* element, Node* padre, Node* left, Node* right) {
		this->profundidad = profundidad;
		this->element = element;
		Father_Esc = padre; // Apunta a su padre tambien
		left_Child_Esc = left;
		right_Child_Esc = right;

	}


	Arbol_Escenario::Arbol_Escenario() {
		root = new Node(1,new Escenario(2, 1), nullptr, nullptr, nullptr); // Prof o Nivel del nodo raiz es 1
		current = root;
	}

	Arbol_Escenario::Node* Arbol_Escenario::return_Current_Tree() { // Para saber en donde estamos
		return this->current;
	}

	void Arbol_Escenario::Mostrar(Graphics^G, Bitmap^ bg1, Bitmap^bmpM, Bitmap^bmpS, Bitmap^bmpB, Bitmap^bmpT, Bitmap^ bmpPor, Bitmap^ bmpA, Bitmap^ bmpP, Bitmap^ bmpV, Bitmap^bmpPlayer, Bitmap^bmpPro)
	{
		current->element->Mostrar(G, bg1, bmpM, bmpS, bmpB, bmpT, bmpPor, bmpA, bmpP, bmpV, bmpPlayer, bmpPro);
	}

	void Arbol_Escenario::manage_Tree(Rectangle& UbicacionJugador) { //Esta funcion es llamada para ver si hay colision. Si hay colision con los portales, cambia de escenarios. Si al cambia no hay escenario, agrega Escenarios si no hay naa.
		
		int prof = this->current->profundidad;
		
		switch (this->current->element->ver_Contact_con_Portales(UbicacionJugador))
		{
		case 1: //hacia arriba
			this->current->element->deActive();
			current->element->GetPLayer()->SetTransform(Form_Width / 2, Form_Height / 2);
				this->current = current->Father_Esc;
			break;
		case 2: //Portal abajo izquierda
			current->element->GetPLayer()->SetTransform(Form_Width / 2, Form_Height / 2);
			if (this->current->left_Child_Esc == nullptr) {
				this->current->element->deActive();

				this->current->left_Child_Esc = new Node(prof+1,new Escenario(3, prof+1), this->current, nullptr, nullptr); //Se pasa el valor de profundidad del nodo como nivel del escenario;
			}
			this->current = current->left_Child_Esc;

			break;
		case 3: //Portal abajo derecha
			current->element->GetPLayer()->SetTransform(Form_Width / 2, Form_Height / 2);
			if (this->current->right_Child_Esc == nullptr) {
				this->current->element->deActive();

				this->current->right_Child_Esc = new Node(prof+1,new Escenario(3, prof+1), this->current, nullptr, nullptr);//Se pasa el valor de profundidad del nodo como nivel del escenario;
			}
			this->current = current->right_Child_Esc;

			break;
		default:
			break;
		}

	} 


	void Arbol_Escenario::tree_Random_node(int a, int b, int c) { // Los tres parametros que deben ingresarse

		int _a = a % 5; // Numero de veces hacia un nodo padre
		int _b = b % 5; // Numero de veces hacia un nodo hijo derecho
		int _c = c % 5; // Numero de veces hacia un nodo hijo izquierdo

		srand(time(NULL));

		int n = 300;

		for (int i = 0; i < n; i++) {

			int random_num = 1 + rand() % 3; // Numero aleatorio para ver si vamos hacia el padre, hacia el hijo izq o al hijo der

			switch (random_num) {
			case 1: // Hacia el padre

				if (_a > 0) {
					if (this->current->Father_Esc != nullptr) { //Si es que hay padre, nos movemos al padre
						this->current = this->current->Father_Esc;
						_a -= 1;
					}

				}

				break;
			case 2: // Hacia el hijo der
				if (_b > 0) {
					if (this->current->left_Child_Esc != nullptr) { //Si es que hay hijo, nos movemos al hijo
						this->current = this->current->left_Child_Esc;
					}
					else { // Si no hay hijo, lo creamos y nos movemos ahi
						int prof = this->current->profundidad;
						this->current->left_Child_Esc = new Node(prof + 1, new Escenario(3, prof + 1), this->current, nullptr, nullptr);
						this->current = this->current->left_Child_Esc;
					}
					_b -= 1;
				}

				break;

			case 3:
				if (_c > 0) {
					if (this->current->right_Child_Esc != nullptr) { //Si es que hay hijo, nos movemos al hijo
						this->current = this->current->right_Child_Esc;
					}
					else { // Si no hay hijo, lo creamos y nos movemos ahi
						int prof = this->current->profundidad;
						this->current->right_Child_Esc = new Node(prof + 1, new Escenario(3, prof + 1), this->current, nullptr, nullptr);
						this->current = this->current->right_Child_Esc;
					}
					_c -= 1;
				}

				break;

			default:
				break;
			}

		}
	}

	void Arbol_Escenario::CheckColision()
	{
		current->element->CheckColision();
	}

	Player * Arbol_Escenario::GetPLayer()
	{
		return current->element->GetPLayer();
	}


