#pragma once
#include <windows.h>
#include <SFML/Graphics.hpp>
#include <time.h>

void move(float [100][2],int, float [2],int*); // funkcja odpowiadaj�ca za ruch w�a


namespace Snake {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace sf;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		int score, direction; // wynik
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczy�� wszystkie u�ywane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;


	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs�ugi projektanta � nie nale�y modyfikowa�
		/// jej zawarto�ci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(80, 190);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(175, 40);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Graj";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(80, 250);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(175, 40);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Instrukcja";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(80, 370);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(175, 40);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Wyjd� z gry";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(80, 310);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(175, 40);
			this->button4->TabIndex = 3;
			this->button4->Text = L"O autorach";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(700, 525);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Snake - the game";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		/*
		 * Tutaj jest kod gry (u�yciem biblioteki SFML 2.5.1)
		 */
		srand((unsigned)time(NULL));
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
		RenderWindow gameWindow(VideoMode(700, 525), "Snake - the game");
		sf::Image icon;
		icon.loadFromFile("app_icon.png");
		gameWindow.setIcon(171, 153, icon.getPixelsPtr());
		Texture snake_t;
		snake_t.loadFromFile("snake.bmp");
		Texture snake_bg_t;
		snake_bg_t.loadFromFile("snake_bg.bmp");
		Sprite snake_s(snake_t);
		Sprite snake_bg_s(snake_bg_t);
		Clock snake_stoper;
		float timer = 0, delay = 0.1;
		float s_coor[100][2];
		s_coor[0][0] = 0;
		s_coor[0][1] = 0;
		float f[2];
		f[0] = 25;
		f[1] = 25;
		int* p_score;
		p_score = &score;
		while (gameWindow.isOpen())
		{
			float running_time = snake_stoper.getElapsedTime().asSeconds();
			snake_stoper.restart();
			timer += running_time;

			Event event_snake;
			while (gameWindow.pollEvent(event_snake))
			{
				if (event_snake.type == Event::Closed)
					gameWindow.close();

			} //while

			if (Keyboard::isKeyPressed(Keyboard::Down)) direction = 0;
			if (Keyboard::isKeyPressed(Keyboard::Left)) direction = 1;
			if (Keyboard::isKeyPressed(Keyboard::Up)) direction = 2;
			if (Keyboard::isKeyPressed(Keyboard::Right)) direction = 3;

			gameWindow.clear();

			if (timer > delay) { timer = 0; move(s_coor,direction,f,p_score); }
			
			for (int i = 0; i < 28; i++)
			{
				for (int j = 0; j < 21; j++)
				{
					snake_bg_s.setPosition(i * 25, j * 25);
					gameWindow.draw(snake_bg_s);
				}
			}
			
			for (int i = 0; i < score+1; i++)
			{
				snake_s.setPosition(s_coor[i][1], s_coor[i][0]);
				gameWindow.draw(snake_s);
			}

			snake_s.setPosition(f[1], f[0]);
			gameWindow.draw(snake_s);

			gameWindow.display();
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Form^ Instrukcja = gcnew Form;
		Instrukcja->Width = 700;
		Instrukcja->Height = 525;
		Instrukcja->Text = "Snake - the game";
		Instrukcja->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		Instrukcja->ControlBox = false;
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
		Instrukcja->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
		Instrukcja->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
		Button^ przycisk = gcnew Button;
		przycisk->Text = "Powr�t";
		przycisk->Location = Point(150, 420);
		przycisk->Size = System::Drawing::Size(130, 35);
		Instrukcja->Controls->Add(przycisk);

		przycisk->DialogResult = System::Windows::Forms::DialogResult::OK;
		Instrukcja->ShowDialog();
		Instrukcja->Close();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			System::Windows::Forms::DialogResult odp =
				MessageBox::Show("Czy na pewno chcesz opu�ci� program?", "Wyj�cie", MessageBoxButtons::YesNo);
			switch (odp)
			{
			case System::Windows::Forms::DialogResult::Yes:
			exit(0);
			case System::Windows::Forms::DialogResult::No: {}
		}
	}

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	Label^ info1 = gcnew Label;
	info1->Text = "Autorzy:\nArkadiusz Fatyga\nMaciej Jurczyk\n\n\nProgram zosta� wykonany w ramach zaliczenia przedmiotu Programowanie 2, wydz.Matematyka Stosowana, POL �L.\n\nWszelkie prawa zgodnie z licencj� MIT.\n\nCzerwiec 2020 r.";
	info1->Location = Point(40, 145);
	info1->Size = System::Drawing::Size(350, 400);
	info1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(238)));
	info1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(253)), static_cast<System::Int32>(static_cast<System::Byte>(236)),
		static_cast<System::Int32>(static_cast<System::Byte>(166)));

	Form^ Autorzy = gcnew Form;
	Autorzy->Width = 700;
	Autorzy->Height = 525;
	Autorzy->Text = "Snake - the game";
	Autorzy->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
	Autorzy->MaximizeBox = false;
	Autorzy->MinimizeBox = false;
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
	Autorzy->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
	Autorzy->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
	
	Button^ przycisk = gcnew Button;
	przycisk->Text = "Powr�t";
	przycisk->Location = Point(150, 420);
	przycisk->Size = System::Drawing::Size(130, 35);
	przycisk->DialogResult = System::Windows::Forms::DialogResult::OK;

	Autorzy->Controls->Add(przycisk);
	Autorzy->Controls->Add(info1);
	Autorzy->ShowDialog();
	Autorzy->Close();
}
};
}
