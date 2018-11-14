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

	void Arbol_Escenario::tree_Random_node(int a, int b, int c){ // Los tres parametros que deben ingresarse para teletransportar

	int _a = a%5; // Numero de veces hacia un nodo padre
	int _b = b%5; // Numero de veces hacia un nodo hijo derecho
	int _c = c%5; // Numero de veces hacia un nodo hijo izquierdo

	srand(time(NULL));

	int n = _a+_b+_c;

	for (int i =0; i<n;i++){
		
		int random_num = 1 + srand()%3; // Numero aleatorio para ver si vamos hacia el padre, hacia el hijo izq o al hijo der

		switch random_num {
			case 1: // Hacia el padre

				if(_a>0){
					if(this->current->Father_Esc !=nullptr){ //Si es que hay padre, nos movemos al padre
						this->current = this->current->Father_Esc;
						_a-=1;
					}
					
				}
				
				break;
			case 2: // Hacia el hijo der
				if(_b>0){
					if(this->current->left_Child_Esc !=nullptr){ //Si es que hay hijo, nos movemos al hijo
						this->current = this->current->left_Child_Esc;
					}else{ // Si no hay hijo, lo creamos y nos movemos ahi
						this->current->left_Child_Esc = new Node(new Escenario(3, 4), this->current, nullptr, nullptr);
						this->current = this->current->left_Child_Esc;
					}	
					_b-=1;
				}
				
				break;

			case 3: 
				if(_c>0){
					if(this->current->right_Child_Esc != nullptr){ //Si es que hay hijo, nos movemos al hijo
						this->current = this->current->right_Child_Esc;
					}else{ // Si no hay hijo, lo creamos y nos movemos ahi
						this->current->right_Child_Esc= new Node(new Escenario(3, 4), this->current, nullptr, nullptr);
						this->current = this->current->right_Child_Esc;
					}	
					_c-=1;
				}

				break;
				
			default://
				break;
		}

	}



