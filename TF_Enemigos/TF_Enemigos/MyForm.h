#pragma once
#include "Juego.h"
#include <time.h>

namespace TF_Enemigos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Xml;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			G = this->CreateGraphics();
			espaceBuffer = BufferedGraphicsManager::Current;
			BG = espaceBuffer->Allocate(G, ClientRectangle);
			MeleBitmap = gcnew Bitmap("MeleSprite.png");
			ShootBitmap = gcnew Bitmap("ShootSprite.png");
			BulletBitmap = gcnew Bitmap("BulletSprite.png");
			background = gcnew Bitmap("background.jpg");
			AmmoBitmap = gcnew Bitmap("AmmoSprite.png");
			LifeBitmap = gcnew Bitmap("LifeSprite.png");
			PointsBitmap = gcnew Bitmap("PointsSprite.png");
			TPBitmap = gcnew Bitmap("TPSprite.png");
			PlayerBitmap = gcnew Bitmap("PlayerSprite.png");
			ProyectilBitmap = gcnew Bitmap("ProyectilSprite.png");
			GOBitmap = gcnew Bitmap("GameOver.jpeg"); 
			GameManager = new Juego();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Graphics^ G;
		BufferedGraphics^ BG;
		Bitmap^ MeleBitmap;
		Bitmap^ ShootBitmap;
		Bitmap^ background;
		Bitmap^ BulletBitmap;
		Bitmap^ AmmoBitmap;
		Bitmap^ LifeBitmap;
		Bitmap^ PointsBitmap;
		Bitmap^ TPBitmap;
		Bitmap^ PlayerBitmap;
		Bitmap^ ProyectilBitmap;
		Bitmap^ GOBitmap;
		Juego* GameManager;
		bool Delay = false;
		
	private: System::Windows::Forms::Timer^  deltaTime;
	private: System::Windows::Forms::Timer^  PhysicsTime;
			 BufferedGraphicsContext^ espaceBuffer;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Método necesario para admitir el Diseñador. No se puede modificar
			 /// el contenido de este método con el editor de código.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->deltaTime = (gcnew System::Windows::Forms::Timer(this->components));
				 this->PhysicsTime = (gcnew System::Windows::Forms::Timer(this->components));
				 this->SuspendLayout();
				 // 
				 // deltaTime
				 // 
				 this->deltaTime->Enabled = true;
				 this->deltaTime->Tick += gcnew System::EventHandler(this, &MyForm::deltaTime_Tick);
				 // 
				 // PhysicsTime
				 // 
				 this->PhysicsTime->Enabled = true;
				 this->PhysicsTime->Tick += gcnew System::EventHandler(this, &MyForm::PhysicsTime_Tick);
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(284, 262);
				 this->Name = L"MyForm";
				 this->Text = L"MyForm";
				 this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
				 this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
				 this->ResumeLayout(false);

			 }
#pragma endregion
	private: System::Void deltaTime_Tick(System::Object^  sender, System::EventArgs^  e) {
		//horde->CheckLive();
		//GameManager->Lose(BG->Graphics, GOBitmap);
		if (GameManager->getPlay()) {
			GameManager->doTasks();
			BG->Graphics->Clear(Color::Black);
			//BG->Graphics->DrawImage(background, 0.0f, 0.0f, G->VisibleClipBounds.Width, G->VisibleClipBounds.Height);
			GameManager->Mostrar(BG->Graphics, background, MeleBitmap, ShootBitmap, BulletBitmap, TPBitmap, TPBitmap, AmmoBitmap, PointsBitmap, LifeBitmap, PlayerBitmap, ProyectilBitmap);
		}BG->Render(G);
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::D)
		{
			Delay = !Delay;
			return;
		}
		
		if (e->KeyCode == Keys::Y){ // TECLA PARA GUARDAR ------------------------------------>
			this->GameManager->retorna_Tree()->save_tree();
			return;
		}
		
		if (!Delay)
			GameManager->Mover(e->KeyCode);
		else
			GameManager->MoverT(e->KeyCode);
	}
	private: System::Void PhysicsTime_Tick(System::Object^  sender, System::EventArgs^  e) {
		GameManager->CheckProyectiles();
		GameManager->CheckColisions();
	}
};
}
