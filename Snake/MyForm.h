#pragma once
#include <iostream>
#include <windows.h>

bool instr=0, ext=0;

namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
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

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
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
			this->button3->Location = System::Drawing::Point(80, 310);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(175, 40);
			this->button3->TabIndex = 2;
			this->button3->Text = L"WyjdŸ z gry";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(700, 525);
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
		Form^ Graj = gcnew Form;
		Graj->Width = 700;
		Graj->Height = 525;
		Graj->Text = "Snake - the game";
		Graj->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		MainBis();
		Graj->Show();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		/*MessageBox::Show(
			"zawartoœæ tekstowa instrukcji",
			"Instrukcja",
			MessageBoxButtons::OK
		);*/

		Form^ Instrukcja = gcnew Form;
		Instrukcja->Width = 700;
		Instrukcja->Height = 525;
		Instrukcja->Text = "Snake - the game";
		Instrukcja->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		Instrukcja->MaximizeBox = false;
		Instrukcja->MinimizeBox = false;
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
		Instrukcja->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
		Button^ przycisk = gcnew Button;
		przycisk->Text = "OK";
		przycisk->Location = Point(150, 420);
		przycisk->Size = System::Drawing::Size(130, 35);
		Instrukcja->Controls->Add(przycisk);
		Instrukcja->Show();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			System::Windows::Forms::DialogResult odp =
				MessageBox::Show("Czy na pewno chcesz opuœciæ program?", "Wyjœcie", MessageBoxButtons::YesNo);
			switch (odp)
			{
			case System::Windows::Forms::DialogResult::Yes:
			exit(0);
			case System::Windows::Forms::DialogResult::No: {}
		}
	}

};
}
