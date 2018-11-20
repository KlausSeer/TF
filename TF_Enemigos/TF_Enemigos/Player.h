#pragma once
#include <vector>

enum Direction { Zero, Up, Down, Left, Right };

#define ProyectilW 35 //tamaño del proyectil
#define ProyectilH 25
#define PersonajeW 45
#define PersonajeH 35
#define SubimagenesX 3
#define SubimagenesY 4


using namespace System::Windows::Forms;
using namespace std;
using namespace System::Drawing;

class Proyectil
{
	int dpx;
	int dpy;
	short indProyX;
	short indProyY;
	bool enabled = true;
	Direction dir;
	Rectangle proyectilImagen;
public:
	Proyectil(short x, short y, Direction d) {
		this->proyectilImagen = Rectangle(x, y, ProyectilW, ProyectilH);
		this->indProyX = 0;
		this->indProyY = 0;
		dir = d;
	}
	~Proyectil() {}
	bool Colision(Rectangle otraImagen) {
		return this->proyectilImagen.IntersectsWith(otraImagen);
	}
	Rectangle getRectSubImgProy(Bitmap^ img) { //Para saber en que Fragmento de la imagen del proyectil esta
		short ancho = img->Width / 4;
		short alto = img->Height / 4;
		return	Rectangle(this->indProyX * ancho, this->indProyY*alto, ancho, alto);
	}
	void drawProyectil(Graphics^ buffer1, Bitmap^ img) {
		//img->MakeTransparent(img->GetPixel(0, 0));
		buffer1->DrawImage(img, this->proyectilImagen, this->getRectSubImgProy(img), GraphicsUnit::Pixel);
		proyectilImagen.X += dpx;
		proyectilImagen.Y += dpy;

	}
	int getX() { return this->proyectilImagen.X; }
	int getY() { return this->proyectilImagen.Y; }
	void moveProyectil(Graphics^ buffer1, Bitmap^ img) {
		switch (dir)
		{
		case Direction::Up:
			this->indProyY = 3;
			if (this->indProyX >= 0 && this->indProyX < 3) { indProyX++; }
			else { indProyX = 0; }
			this->dpx = 0;
			this->dpy = -10;
			break;
		case Direction::Down:
			this->indProyY = 2;
			if (this->indProyX >= 0 && this->indProyX < 3) { indProyX++; }
			else { indProyX = 0; }
			this->dpx = 0;
			this->dpy = 10;
			break;
		case Direction::Left:
			this->indProyY = 1;
			if (this->indProyX >= 0 && this->indProyX < 3) { indProyX++; }
			else { indProyX = 0; }
			this->dpx = -10;
			this->dpy = 0;
			break;
		case Direction::Right:
			this->indProyY = 0;
			if (this->indProyX >= 0 && this->indProyX < 3) { indProyX++; }
			else { indProyX = 0; }
			this->dpx = 10;
			this->dpy = 0;
			break;

		}
		drawProyectil(buffer1, img);
	}

	bool getEnabled()
	{
		return enabled;
	}

	void setEnabled(bool b)
	{
		enabled = b;
	}

	//Falta tiempo de recarga

};

class Player
{
	bool Movimiento = false;
	short indSpriteX;
	short indSpriteY;
	int dx;
	int dy;
	int vidas;
	int velocity = 5;
	bool Vivo;
	Rectangle playerImagen;
	vector<Proyectil*>proyectiles;
	unsigned int maxMuniciones;
	int municiones;
	Direction TeclaEnd; //para saber en que tecla terminó
public:
	Direction direccion;
	Player(int x, int y) {
		this->Vivo = true;
		this->playerImagen.X = x;
		this->playerImagen.Y = y;
		this->playerImagen.Width = PersonajeW;
		this->playerImagen.Height = PersonajeH;
		this->maxMuniciones = 10;
		this->vidas = 3;
		this->municiones = maxMuniciones;
		this->TeclaEnd = Direction::Down;
		this->direccion = Direction::Right;
		this->indSpriteX = 1;
		this->indSpriteY = 2;
	}
	~Player() {
		for (unsigned short i = 0; i < this->proyectiles.size(); i++)
			delete this->proyectiles[i];
	}

	void CheckPVivos()
	{
		std::vector<Proyectil*>::iterator i = proyectiles.begin();
		while (i != proyectiles.end())
		{
			if ((*i)->getEnabled() == false)
			{
				delete (*i);
				i = proyectiles.erase(i);
			}
			else ++i;
		}
	}

	bool getVivo()
	{
		return Vivo;
	}

	int getVidas()
	{
		return vidas;
	}

	void Damage()
	{
		vidas--;
	}

	void Kill()
	{
		Vivo = false;
	}

	void Recargar()
	{
		municiones = maxMuniciones;
	}

	void VidaExtra()
	{
		vidas++;
	}

	Rectangle getRectSubImagen(Bitmap^ img) { //Para saber en que Fragmento de la imagen esta
		short ancho = img->Width / SubimagenesX;
		short alto = img->Height / SubimagenesY;
		return	Rectangle(this->indSpriteX * ancho, this->indSpriteY*alto, ancho, alto);
	}


	Rectangle getPlayerImagen() { return this->playerImagen; }
	vector<Proyectil*>getProyectiles() { return this->proyectiles; }

	bool Colision(Rectangle otraImagen) {
		return this->playerImagen.IntersectsWith(otraImagen);
	}
	void drawPlayer(Graphics^ buffer1, Bitmap^ img) // animación del personaje
	{
		img->MakeTransparent(img->GetPixel(0, 0));
		buffer1->DrawImage(img, this->playerImagen, this->getRectSubImagen(img), GraphicsUnit::Pixel);
	}

	void SetTransform(int x, int y)
	{
		playerImagen.X = x;
		playerImagen.Y = y;
	}

	void movePlayer(Keys k) //movimiento del personaje
	{
		
		switch (k)
		{
		case Keys::Up:
			direccion = Direction::Up;
			Movimiento = true;
			break;
		case Keys::Down:
			direccion = Direction::Down;
			Movimiento = true;
			break;
		case Keys::Left:
			direccion = Direction::Left;
			Movimiento = true;
			break;
		case Keys::Right:
			direccion = Direction::Right;
			Movimiento = true;
			break;
		case Keys::Z:
			shootProyectiles();
			break;
		default:
			break;
		}

		switch (direccion)
		{
		case Direction::Up:
			this->indSpriteY = 3;
			if (this->indSpriteX >= 0 && this->indSpriteX < 2)
			{
				indSpriteX++;
			}
			else
			{
				indSpriteX = 1;
			}
			this->dx = 0;
			this->dy = -velocity;
			break;
		case Direction::Down:
			this->indSpriteY = 0;
			if (this->indSpriteX >= 0 && this->indSpriteX < 2) { indSpriteX++; }
			else
			{
				indSpriteX = 1;
			}
			this->dx = 0;
			this->dy = velocity;
			break;

		case Direction::Left:
			this->indSpriteY = 1;
			if (this->indSpriteX >= 0 && this->indSpriteX < 2)
			{
				indSpriteX++;
			}
			else
			{
				indSpriteX = 1;
			}
			this->dx = -velocity;
			this->dy = 0;
			break;
		case Direction::Right:
			this->indSpriteY = 2;
			if (this->indSpriteX >= 0 && this->indSpriteX < 2)
			{
				indSpriteX++;
			}
			else
			{
				indSpriteX = 1;
			}
			this->dx = velocity;
			this->dy = 0;
			break;
		}
		if (Movimiento)
		{
			playerImagen.X += dx;
			playerImagen.Y += dy;
			Movimiento = false;
		}
		//drawPlayer(buffer1, img);
	}
	void shootProyectiles() { //generación de proyectiles-cambiar
		if (municiones > 0) {
			Proyectil* proy = new Proyectil(this->playerImagen.X, this->playerImagen.Y, this->direccion);
			this->proyectiles.push_back(proy);
			municiones--;
		}
		
	}


	void animateProyectil(Graphics^ buffer, Bitmap^ img) { //animación del proyectil
		for (unsigned short i = 0; i < this->proyectiles.size(); i++)
		{
			this->proyectiles[i]->moveProyectil(buffer, img);

			if (this->proyectiles[i]->getX() > buffer->VisibleClipBounds.Width && this->proyectiles[i]->getX()< 0)
			{
				//delete this->proyectiles[i];
				//this->proyectiles.erase(this->proyectiles.begin() + i);
				eliminateProyectil(i);
			}
			else if (this->proyectiles[i]->getY() > buffer->VisibleClipBounds.Height && this->proyectiles[i]->getX() < 0)
			{
				//delete this->proyectiles[i];
				//this->proyectiles.erase(this->proyectiles.begin() + i);
				eliminateProyectil(i);
			}


		}
	}

	void eliminateProyectil(int i) {
		delete this->proyectiles.at(i);
		this->proyectiles.erase(this->proyectiles.begin() + i);
	}

};






