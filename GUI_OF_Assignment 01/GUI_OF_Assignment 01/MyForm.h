#pragma once
#include"Header.h"
#include"AddSongsForm.h"
#include<fstream>
#include<msclr/marshal_cppstd.h>
using namespace msclr::interop;

In_Car_AP ap;

namespace GUIOFAssignment01 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ PowerButton;
	private: System::Windows::Forms::RadioButton^ ONButton;
	private: System::Windows::Forms::RadioButton^ OFFButton;
	private: System::Windows::Forms::TextBox^ NameTitleBox;


	protected:

	protected:









	private: System::Windows::Forms::RadioButton^ USBButton;

	private: System::Windows::Forms::RadioButton^ CDButton;
	private: System::Windows::Forms::RadioButton^ UnMounted;


	private: System::Windows::Forms::RadioButton^ Mounted;

	private: System::Windows::Forms::ListBox^ PlayList;
	private: System::Windows::Forms::TextBox^ PlayingSongBox;
	private: System::Windows::Forms::TextBox^ CompanyModelTextBox;




	private: System::Windows::Forms::PictureBox^ PreviousButton;

	private: System::Windows::Forms::PictureBox^ NextButton;
	private: System::Windows::Forms::PictureBox^ PlayButton;




	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::PictureBox^ MountButton;
	private: System::Windows::Forms::PictureBox^ PauseButton;


	private: System::Windows::Forms::RadioButton^ IsPlaying;



	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Timer^ Time;
	private: System::Windows::Forms::Label^ SearchLabel;
	private: System::Windows::Forms::TextBox^ SearchTextBox;
	private: System::Windows::Forms::PictureBox^ SearchButton;

	private: System::Windows::Forms::PictureBox^ ShuffleButton;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ RefreshButton;
	private: System::Windows::Forms::Button^ DeleteButton;







	private: System::ComponentModel::IContainer^ components;




	protected:


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->PowerButton = (gcnew System::Windows::Forms::PictureBox());
			this->ONButton = (gcnew System::Windows::Forms::RadioButton());
			this->OFFButton = (gcnew System::Windows::Forms::RadioButton());
			this->NameTitleBox = (gcnew System::Windows::Forms::TextBox());
			this->USBButton = (gcnew System::Windows::Forms::RadioButton());
			this->CDButton = (gcnew System::Windows::Forms::RadioButton());
			this->UnMounted = (gcnew System::Windows::Forms::RadioButton());
			this->Mounted = (gcnew System::Windows::Forms::RadioButton());
			this->PlayList = (gcnew System::Windows::Forms::ListBox());
			this->PlayingSongBox = (gcnew System::Windows::Forms::TextBox());
			this->CompanyModelTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PreviousButton = (gcnew System::Windows::Forms::PictureBox());
			this->NextButton = (gcnew System::Windows::Forms::PictureBox());
			this->PlayButton = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->MountButton = (gcnew System::Windows::Forms::PictureBox());
			this->PauseButton = (gcnew System::Windows::Forms::PictureBox());
			this->IsPlaying = (gcnew System::Windows::Forms::RadioButton());
			this->Time = (gcnew System::Windows::Forms::Timer(this->components));
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->SearchLabel = (gcnew System::Windows::Forms::Label());
			this->SearchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SearchButton = (gcnew System::Windows::Forms::PictureBox());
			this->ShuffleButton = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->RefreshButton = (gcnew System::Windows::Forms::PictureBox());
			this->DeleteButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PowerButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PreviousButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NextButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PlayButton))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MountButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PauseButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SearchButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ShuffleButton))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RefreshButton))->BeginInit();
			this->SuspendLayout();
			// 
			// PowerButton
			// 
			this->PowerButton->BackColor = System::Drawing::Color::Transparent;
			this->PowerButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PowerButton.Image")));
			this->PowerButton->Location = System::Drawing::Point(12, 61);
			this->PowerButton->Name = L"PowerButton";
			this->PowerButton->Size = System::Drawing::Size(57, 55);
			this->PowerButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PowerButton->TabIndex = 5;
			this->PowerButton->TabStop = false;
			this->PowerButton->Click += gcnew System::EventHandler(this, &MyForm::PowerButton_Click);
			// 
			// ONButton
			// 
			this->ONButton->AutoCheck = false;
			this->ONButton->AutoSize = true;
			this->ONButton->BackColor = System::Drawing::Color::Transparent;
			this->ONButton->ForeColor = System::Drawing::Color::Pink;
			this->ONButton->Location = System::Drawing::Point(4, 11);
			this->ONButton->Name = L"ONButton";
			this->ONButton->Size = System::Drawing::Size(50, 21);
			this->ONButton->TabIndex = 6;
			this->ONButton->Text = L"ON";
			this->ONButton->UseVisualStyleBackColor = false;
			this->ONButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::ONButton_CheckedChanged);
			// 
			// OFFButton
			// 
			this->OFFButton->AutoCheck = false;
			this->OFFButton->AutoSize = true;
			this->OFFButton->BackColor = System::Drawing::Color::Transparent;
			this->OFFButton->Checked = true;
			this->OFFButton->ForeColor = System::Drawing::Color::Pink;
			this->OFFButton->Location = System::Drawing::Point(69, 11);
			this->OFFButton->Name = L"OFFButton";
			this->OFFButton->Size = System::Drawing::Size(56, 21);
			this->OFFButton->TabIndex = 7;
			this->OFFButton->TabStop = true;
			this->OFFButton->Text = L"OFF";
			this->OFFButton->UseVisualStyleBackColor = false;
			this->OFFButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::RadioButton2_CheckedChanged);
			// 
			// NameTitleBox
			// 
			this->NameTitleBox->BackColor = System::Drawing::Color::MidnightBlue;
			this->NameTitleBox->Cursor = System::Windows::Forms::Cursors::No;
			this->NameTitleBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NameTitleBox->ForeColor = System::Drawing::Color::Pink;
			this->NameTitleBox->Location = System::Drawing::Point(217, 0);
			this->NameTitleBox->Name = L"NameTitleBox";
			this->NameTitleBox->Size = System::Drawing::Size(242, 34);
			this->NameTitleBox->TabIndex = 8;
			this->NameTitleBox->Text = L"In-Car Audio-Player";
			this->NameTitleBox->TextChanged += gcnew System::EventHandler(this, &MyForm::c);
			// 
			// USBButton
			// 
			this->USBButton->AutoCheck = false;
			this->USBButton->AutoSize = true;
			this->USBButton->ForeColor = System::Drawing::Color::Pink;
			this->USBButton->Location = System::Drawing::Point(96, 17);
			this->USBButton->Name = L"USBButton";
			this->USBButton->Size = System::Drawing::Size(57, 21);
			this->USBButton->TabIndex = 9;
			this->USBButton->Text = L"USB";
			this->USBButton->UseVisualStyleBackColor = true;
			this->USBButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::USBButton_CheckedChanged);
			// 
			// CDButton
			// 
			this->CDButton->AutoCheck = false;
			this->CDButton->AutoSize = true;
			this->CDButton->ForeColor = System::Drawing::Color::Pink;
			this->CDButton->Location = System::Drawing::Point(6, 17);
			this->CDButton->Name = L"CDButton";
			this->CDButton->Size = System::Drawing::Size(48, 21);
			this->CDButton->TabIndex = 10;
			this->CDButton->Text = L"CD";
			this->CDButton->UseVisualStyleBackColor = true;
			this->CDButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::CDButton_CheckedChanged);
			// 
			// UnMounted
			// 
			this->UnMounted->AutoCheck = false;
			this->UnMounted->AutoSize = true;
			this->UnMounted->ForeColor = System::Drawing::Color::Pink;
			this->UnMounted->Location = System::Drawing::Point(6, 40);
			this->UnMounted->Name = L"UnMounted";
			this->UnMounted->Size = System::Drawing::Size(102, 21);
			this->UnMounted->TabIndex = 11;
			this->UnMounted->Text = L"UnMounted";
			this->UnMounted->UseVisualStyleBackColor = true;
			// 
			// Mounted
			// 
			this->Mounted->AutoCheck = false;
			this->Mounted->AutoSize = true;
			this->Mounted->ForeColor = System::Drawing::Color::Pink;
			this->Mounted->Location = System::Drawing::Point(6, 13);
			this->Mounted->Name = L"Mounted";
			this->Mounted->Size = System::Drawing::Size(84, 21);
			this->Mounted->TabIndex = 12;
			this->Mounted->Text = L"Mounted";
			this->Mounted->UseVisualStyleBackColor = true;
			this->Mounted->CheckedChanged += gcnew System::EventHandler(this, &MyForm::Mounted_CheckedChanged);
			// 
			// PlayList
			// 
			this->PlayList->BackColor = System::Drawing::Color::MidnightBlue;
			this->PlayList->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PlayList->ForeColor = System::Drawing::Color::Pink;
			this->PlayList->FormattingEnabled = true;
			this->PlayList->HorizontalScrollbar = true;
			this->PlayList->ItemHeight = 17;
			this->PlayList->Location = System::Drawing::Point(457, 232);
			this->PlayList->Name = L"PlayList";
			this->PlayList->Size = System::Drawing::Size(223, 242);
			this->PlayList->TabIndex = 13;
			this->PlayList->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// PlayingSongBox
			// 
			this->PlayingSongBox->BackColor = System::Drawing::Color::MidnightBlue;
			this->PlayingSongBox->Cursor = System::Windows::Forms::Cursors::No;
			this->PlayingSongBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->PlayingSongBox->ForeColor = System::Drawing::Color::Pink;
			this->PlayingSongBox->Location = System::Drawing::Point(98, 169);
			this->PlayingSongBox->Name = L"PlayingSongBox";
			this->PlayingSongBox->Size = System::Drawing::Size(375, 27);
			this->PlayingSongBox->TabIndex = 14;
			this->PlayingSongBox->TextChanged += gcnew System::EventHandler(this, &MyForm::PlayingSongBox_TextChanged_2);
			// 
			// CompanyModelTextBox
			// 
			this->CompanyModelTextBox->BackColor = System::Drawing::SystemColors::HotTrack;
			this->CompanyModelTextBox->Cursor = System::Windows::Forms::Cursors::No;
			this->CompanyModelTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->CompanyModelTextBox->Location = System::Drawing::Point(12, 488);
			this->CompanyModelTextBox->Name = L"CompanyModelTextBox";
			this->CompanyModelTextBox->Size = System::Drawing::Size(164, 27);
			this->CompanyModelTextBox->TabIndex = 15;
			this->CompanyModelTextBox->Text = L"Audionic/2010";
			this->CompanyModelTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::CompanyModelTextBox_TextChanged);
			// 
			// PreviousButton
			// 
			this->PreviousButton->BackColor = System::Drawing::Color::Transparent;
			this->PreviousButton->Enabled = false;
			this->PreviousButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PreviousButton.Image")));
			this->PreviousButton->Location = System::Drawing::Point(156, 359);
			this->PreviousButton->Name = L"PreviousButton";
			this->PreviousButton->Size = System::Drawing::Size(56, 50);
			this->PreviousButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PreviousButton->TabIndex = 16;
			this->PreviousButton->TabStop = false;
			this->PreviousButton->Click += gcnew System::EventHandler(this, &MyForm::PreviousButton_Click);
			// 
			// NextButton
			// 
			this->NextButton->BackColor = System::Drawing::Color::Transparent;
			this->NextButton->Enabled = false;
			this->NextButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"NextButton.Image")));
			this->NextButton->Location = System::Drawing::Point(327, 359);
			this->NextButton->Name = L"NextButton";
			this->NextButton->Size = System::Drawing::Size(52, 50);
			this->NextButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->NextButton->TabIndex = 17;
			this->NextButton->TabStop = false;
			this->NextButton->Click += gcnew System::EventHandler(this, &MyForm::NextButton_Click);
			// 
			// PlayButton
			// 
			this->PlayButton->BackColor = System::Drawing::Color::Transparent;
			this->PlayButton->Enabled = false;
			this->PlayButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PlayButton.Image")));
			this->PlayButton->Location = System::Drawing::Point(227, 351);
			this->PlayButton->Name = L"PlayButton";
			this->PlayButton->Size = System::Drawing::Size(82, 68);
			this->PlayButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PlayButton->TabIndex = 18;
			this->PlayButton->TabStop = false;
			this->PlayButton->Click += gcnew System::EventHandler(this, &MyForm::PlayButton_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Controls->Add(this->OFFButton);
			this->groupBox1->Controls->Add(this->ONButton);
			this->groupBox1->Cursor = System::Windows::Forms::Cursors::PanNW;
			this->groupBox1->Location = System::Drawing::Point(87, 61);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(142, 38);
			this->groupBox1->TabIndex = 19;
			this->groupBox1->TabStop = false;
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::Transparent;
			this->groupBox2->Controls->Add(this->USBButton);
			this->groupBox2->Controls->Add(this->CDButton);
			this->groupBox2->Location = System::Drawing::Point(486, 40);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(155, 53);
			this->groupBox2->TabIndex = 0;
			this->groupBox2->TabStop = false;
			this->groupBox2->Enter += gcnew System::EventHandler(this, &MyForm::groupBox2_Enter);
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::Color::Transparent;
			this->groupBox3->Controls->Add(this->UnMounted);
			this->groupBox3->Controls->Add(this->Mounted);
			this->groupBox3->Location = System::Drawing::Point(571, 101);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(109, 74);
			this->groupBox3->TabIndex = 0;
			this->groupBox3->TabStop = false;
			this->groupBox3->Enter += gcnew System::EventHandler(this, &MyForm::groupBox3_Enter);
			// 
			// MountButton
			// 
			this->MountButton->BackColor = System::Drawing::Color::Transparent;
			this->MountButton->Enabled = false;
			this->MountButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MountButton.Image")));
			this->MountButton->Location = System::Drawing::Point(415, 40);
			this->MountButton->Name = L"MountButton";
			this->MountButton->Size = System::Drawing::Size(65, 55);
			this->MountButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->MountButton->TabIndex = 20;
			this->MountButton->TabStop = false;
			this->MountButton->Click += gcnew System::EventHandler(this, &MyForm::MountButton_Click);
			// 
			// PauseButton
			// 
			this->PauseButton->BackColor = System::Drawing::Color::Transparent;
			this->PauseButton->Enabled = false;
			this->PauseButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PauseButton.Image")));
			this->PauseButton->Location = System::Drawing::Point(227, 351);
			this->PauseButton->Name = L"PauseButton";
			this->PauseButton->Size = System::Drawing::Size(82, 68);
			this->PauseButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PauseButton->TabIndex = 21;
			this->PauseButton->TabStop = false;
			this->PauseButton->Visible = false;
			this->PauseButton->Click += gcnew System::EventHandler(this, &MyForm::PauseButton_Click);
			// 
			// IsPlaying
			// 
			this->IsPlaying->AutoCheck = false;
			this->IsPlaying->AutoSize = true;
			this->IsPlaying->BackColor = System::Drawing::Color::Transparent;
			this->IsPlaying->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->IsPlaying->ForeColor = System::Drawing::Color::Pink;
			this->IsPlaying->Location = System::Drawing::Point(195, 197);
			this->IsPlaying->Name = L"IsPlaying";
			this->IsPlaying->Size = System::Drawing::Size(184, 29);
			this->IsPlaying->TabIndex = 23;
			this->IsPlaying->TabStop = true;
			this->IsPlaying->Text = L"SoundIsPlaying";
			this->IsPlaying->UseVisualStyleBackColor = false;
			this->IsPlaying->CheckedChanged += gcnew System::EventHandler(this, &MyForm::IsPlaying_CheckedChanged);
			// 
			// Time
			// 
			this->Time->Enabled = true;
			this->Time->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(156, 293);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(223, 23);
			this->progressBar1->Step = 1;
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar1->TabIndex = 24;
			this->progressBar1->Click += gcnew System::EventHandler(this, &MyForm::progressBar1_Click);
			// 
			// SearchLabel
			// 
			this->SearchLabel->AutoSize = true;
			this->SearchLabel->BackColor = System::Drawing::Color::Transparent;
			this->SearchLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SearchLabel->ForeColor = System::Drawing::Color::Pink;
			this->SearchLabel->Location = System::Drawing::Point(454, 211);
			this->SearchLabel->Name = L"SearchLabel";
			this->SearchLabel->Size = System::Drawing::Size(66, 18);
			this->SearchLabel->TabIndex = 25;
			this->SearchLabel->Text = L"Search:";
			this->SearchLabel->Click += gcnew System::EventHandler(this, &MyForm::SearchLabel_Click);
			// 
			// SearchTextBox
			// 
			this->SearchTextBox->BackColor = System::Drawing::Color::MidnightBlue;
			this->SearchTextBox->ForeColor = System::Drawing::Color::Pink;
			this->SearchTextBox->Location = System::Drawing::Point(517, 211);
			this->SearchTextBox->Name = L"SearchTextBox";
			this->SearchTextBox->Size = System::Drawing::Size(124, 22);
			this->SearchTextBox->TabIndex = 26;
			// 
			// SearchButton
			// 
			this->SearchButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SearchButton.Image")));
			this->SearchButton->Location = System::Drawing::Point(646, 208);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(33, 25);
			this->SearchButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->SearchButton->TabIndex = 27;
			this->SearchButton->TabStop = false;
			this->SearchButton->Click += gcnew System::EventHandler(this, &MyForm::SearchButton_Click);
			// 
			// ShuffleButton
			// 
			this->ShuffleButton->Enabled = false;
			this->ShuffleButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ShuffleButton.Image")));
			this->ShuffleButton->Location = System::Drawing::Point(236, 424);
			this->ShuffleButton->Name = L"ShuffleButton";
			this->ShuffleButton->Size = System::Drawing::Size(62, 50);
			this->ShuffleButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->ShuffleButton->TabIndex = 28;
			this->ShuffleButton->TabStop = false;
			this->ShuffleButton->Click += gcnew System::EventHandler(this, &MyForm::ShuffleButton_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::MidnightBlue;
			this->button1->ForeColor = System::Drawing::Color::Pink;
			this->button1->Location = System::Drawing::Point(459, 480);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(81, 29);
			this->button1->TabIndex = 29;
			this->button1->Text = L"AddSong";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// RefreshButton
			// 
			this->RefreshButton->BackColor = System::Drawing::Color::Transparent;
			this->RefreshButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RefreshButton.Image")));
			this->RefreshButton->Location = System::Drawing::Point(415, 232);
			this->RefreshButton->Name = L"RefreshButton";
			this->RefreshButton->Size = System::Drawing::Size(43, 31);
			this->RefreshButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->RefreshButton->TabIndex = 30;
			this->RefreshButton->TabStop = false;
			this->RefreshButton->Click += gcnew System::EventHandler(this, &MyForm::RefreshButton_Click);
			// 
			// DeleteButton
			// 
			this->DeleteButton->BackColor = System::Drawing::Color::MidnightBlue;
			this->DeleteButton->ForeColor = System::Drawing::Color::Pink;
			this->DeleteButton->Location = System::Drawing::Point(546, 480);
			this->DeleteButton->Name = L"DeleteButton";
			this->DeleteButton->Size = System::Drawing::Size(115, 29);
			this->DeleteButton->TabIndex = 31;
			this->DeleteButton->Text = L"DeleteSong";
			this->DeleteButton->UseVisualStyleBackColor = false;
			this->DeleteButton->Click += gcnew System::EventHandler(this, &MyForm::DeleteButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(692, 523);
			this->Controls->Add(this->DeleteButton);
			this->Controls->Add(this->RefreshButton);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->ShuffleButton);
			this->Controls->Add(this->SearchButton);
			this->Controls->Add(this->SearchTextBox);
			this->Controls->Add(this->SearchLabel);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->IsPlaying);
			this->Controls->Add(this->PauseButton);
			this->Controls->Add(this->MountButton);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->PlayButton);
			this->Controls->Add(this->NextButton);
			this->Controls->Add(this->PreviousButton);
			this->Controls->Add(this->CompanyModelTextBox);
			this->Controls->Add(this->PlayingSongBox);
			this->Controls->Add(this->PlayList);
			this->Controls->Add(this->NameTitleBox);
			this->Controls->Add(this->PowerButton);
			this->Cursor = System::Windows::Forms::Cursors::PanNW;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PowerButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PreviousButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NextButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PlayButton))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MountButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PauseButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SearchButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ShuffleButton))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->RefreshButton))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}



	private: System::Void PowerButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (OFFButton->Checked == true)
		{
			MountButton->Enabled = true;
			OFFButton->Checked = false;
			ONButton->Checked = true;
			UnMounted->Checked = true;
			if (USBButton->Checked == true || CDButton->Checked == true)
			{
				IsPlaying->Checked = true;
				Mounted->Checked = true;
				UnMounted->Checked = false;
				if (USBButton->Checked == true)
				{
					string s = ap.PlayMusicUSB();
					String^ str2 = gcnew String(s.c_str());
					PlayingSongBox->Text = str2;
				}
				else if (CDButton->Checked == true)
				{
					string s = ap.PlayMusicCD();
					String^ str2 = gcnew String(s.c_str());
					PlayingSongBox->Text = str2;

				}
				PlayButton->Enabled = true;
				PauseButton->Enabled = true;
				NextButton->Enabled = true;
				PreviousButton->Enabled = true;

			}
		}
		else if(ONButton->Checked == true)
		{
			OFFButton->Checked = true;
			ONButton->Checked = false;
			UnMounted->Checked = false;
			Mounted->Checked = false;
			IsPlaying->Checked = false;
			PlayButton->Enabled = false;
			PauseButton->Enabled = false;
			PreviousButton->Enabled = false;
			NextButton->Enabled = false;
			if (USBButton->Checked == true)
			{
				ap.CloseMusicUSB();
			}
			else if (CDButton->Checked==true)
			{
				ap.CloseMusicCD();
			}
		}
	}
private: System::Void RadioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void PreviousButton_Click(System::Object^ sender, System::EventArgs^ e) {
	PauseButton->Visible = true;
	PlayButton->Visible = false;
	if (USBButton->Checked == true)
	{
		string s = ap.PreviousMusicUSB();
		String^ str2 = gcnew String(s.c_str());
		PlayingSongBox->Text = str2;
		PlayList->SetSelected(ap.GetIndexUSB(s), true);
	}
	else if (CDButton->Checked == true)
	{
		string s = ap.PreviousMusicCD();
		String^ str2 = gcnew String(s.c_str());
		PlayingSongBox->Text = str2;
		PlayList->SetSelected(ap.GetIndexCD(s), true);
	}
}
private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox3_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Mounted_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ONButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	//if (ONButton->Checked == true)
	//{
	//	ONButton->Enabled = true;
	//	USBButton->Enabled = true;
	//	CDButton->Enabled = true;
	//	UnMounted->Enabled = true;
	//	Mounted->Enabled = true;
	//}
}
private: System::Void CDButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (ONButton->Checked == true)
	{
		if (CDButton->Checked == true)
		{
			UnMounted->Checked = false;
			Mounted->Checked = true;
		}
	}
}
private: System::Void USBButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (ONButton->Checked == true)
	{
		if (USBButton->Checked == true)
		{
			UnMounted->Checked = false;
			Mounted->Checked = true;
		}
	}
}
private: System::Void NameTitleBox_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void CompanyModelTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	ap.getname();
	ap.getmodel_no();
}
private: System::Void PlayButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ONButton->Checked == true)
	{
		PauseButton->Visible = true;
		PlayButton->Visible = false;
		IsPlaying->Checked = true;
		if (USBButton->Checked == true)
		{
			string s = ap.PlayMusicUSB();
			String^ str2 = gcnew String(s.c_str());
			PlayingSongBox->Text = str2;
		}
		else if (CDButton->Checked == true)
		{
			string s = ap.PlayMusicCD();
			String^ str2 = gcnew String(s.c_str());
			PlayingSongBox->Text = str2;
		}
	}
}
private: System::Void MountButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ONButton->Checked == true)
	{
		PlayButton->Enabled = true;
		PauseButton->Enabled = true;
		NextButton->Enabled = true;
		PreviousButton->Enabled = true;
		ShuffleButton->Enabled = true;
		CD obj1;
		std::ifstream file;
		std::string k;
		if (USBButton->Checked == false && CDButton->Checked == false)
		{
			CDButton->Checked = true;
			if (Mounted->Checked == true)
			{
				obj1.openCD();
				String^ str3 = gcnew String(CDarr[0].c_str());
				PlayList->Items->Add(str3);
				IsPlaying->Checked = true;
				obj1.SavePlayListCD(CDarr[0]);
				CDplaylist.push_back(CDarr[0]);
				string s = ap.PlayMusicCD();
				String^ str2 = gcnew String(s.c_str());
				PlayingSongBox->Text = str2;
				PlayList->SetSelected(ap.GetIndexCD(s), true);
			}
		}
		else if (USBButton->Checked == true && CDButton->Checked == false)
		{
			USBButton->Checked = false;
			CDButton->Checked = true;
			if (Mounted->Checked == true)
			{
				
				ap.CloseMusicUSB();
				PlayList->Items->Clear();
				String^ str3 = gcnew String(CDarr[0].c_str());
				PlayList->Items->Add(str3);
				file.open("PlayListCD.txt");
				while (getline(file, k))
				{
					String^ str = gcnew String(k.c_str());
					if(k!=CDarr[0])
					PlayList->Items->Add(str);
				}
				IsPlaying->Checked = true;
				string s = ap.PlayMusicCD();
				String^ str2 = gcnew String(s.c_str());
				PlayingSongBox->Text = str2;
				PlayList->SetSelected(ap.GetIndexCD(s), true);
			}
		}
		else if (USBButton->Checked == false && CDButton->Checked == true)
		{
			USBButton->Checked = true;
			CDButton->Checked = false;
			if (Mounted->Checked == true)
			{
				static int j = 0;
				ap.CloseMusicCD();
				PlayList->Items->Clear();
				USB obj2;
				if (j == 0)
				{
					obj2.openUSB();
					String^ str3 = gcnew String(USBarr[0].c_str());
					PlayList->Items->Add(str3);
					obj2.SavePlayListUSB(USBarr[0]);
					USBplaylist.push_back(USBarr[0]);
				}
				else
				{
					String^ str3 = gcnew String(USBarr[0].c_str());
					PlayList->Items->Add(str3);
				}
				file.open("PlayListUSB.txt");
				while (getline(file, k))
				{
					String^ str = gcnew String(k.c_str());
					if (k != USBarr[0])
						PlayList->Items->Add(str);
				}
				IsPlaying->Checked = true;
				string s = ap.PlayMusicUSB();
				String^ str2 = gcnew String(s.c_str());
				PlayingSongBox->Text = str2;
				PlayList->SetSelected(ap.GetIndexUSB(s), true);
				j++;
			}
		}
	}
}
private: System::Void PauseButton_Click(System::Object^ sender, System::EventArgs^ e) {
	PlayButton->Visible = true;
	PauseButton->Visible = false;
	if (USBButton->Checked == true)
	{
		IsPlaying->Checked = false;
		string s = ap.PauseMusicUSB();
		String^ str2 = gcnew String(s.c_str());
		PlayingSongBox->Text = str2;
	}
	else if (CDButton->Checked == true)
	{
		IsPlaying->Checked = false;
		string s = ap.PauseMusicCD();
		String^ str2 = gcnew String(s.c_str());
		PlayingSongBox->Text = str2;
	}
}
private: System::Void IsPlaying_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (IsPlaying->Checked == true)
	{
		PauseButton->Visible = true;
		PlayButton->Visible = false;
	}
	else if (IsPlaying->Checked == false)
	{
		PlayButton->Visible = true;
		PauseButton->Visible = false;
	}
}
private: System::Void NextButton_Click(System::Object^ sender, System::EventArgs^ e) {
	PauseButton->Visible = true;
	PlayButton->Visible = false;
	if (USBButton->Checked == true)
	{
		string s = ap.NextMusicUSB();
		String^ str2 = gcnew String(s.c_str());
		PlayingSongBox->Text = str2;
		PlayList->SetSelected(ap.GetIndexUSB(s), true);
	}
	else if (CDButton->Checked == true)
	{
		string s = ap.NextMusicCD();
		String^ str2 = gcnew String(s.c_str());
		PlayingSongBox->Text = str2;
		PlayList->SetSelected(ap.GetIndexCD(s), true);
	}
}
private: System::Void PlayingSongBox_TextChanged_2(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void SearchLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ShuffleButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ONButton->Checked == true)
	{
		if (CDButton->Checked == true)
		{
			string s = ap.ShuffleCD();
			String^ str2 = gcnew String(s.c_str());
			PlayingSongBox->Text = str2;
			PlayList->SetSelected(ap.GetIndexCD(s), true);
		}
		else if (USBButton->Checked == true)
		{
			string s = ap.ShuffleUSB();
			String^ str2 = gcnew String(s.c_str());
			PlayingSongBox->Text = str2;
			PlayList->SetSelected(ap.GetIndexUSB(s), true);
		}
		PauseButton->Visible = true;
		PlayButton->Visible = false;
	}
}
private: System::Void SearchButton_Click(System::Object^ sender, System::EventArgs^ e) {
	int result = PlayList->FindStringExact(SearchTextBox->Text);
	if (result >= 0)
	{
		PlayList->SetSelected(result, true);
		SearchTextBox->Text = "Found!!";
	}
	else
	{
		SearchTextBox->Text = "Song Not Found!!";
	}
}
private: System::Void c(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	std::ofstream file1;
	if (CDButton->Checked == true)
	{
		file1.open("PlayListCD.txt", std::ios::app);
		AddSongsForm^ add = gcnew AddSongsForm(CDarr,dirSizeCD,&file1);
		add->ShowDialog();
	}
	else if (USBButton->Checked == true)
	{
		file1.open("PlayListUSB.txt", std::ios::app);
		AddSongsForm^ add = gcnew AddSongsForm(USBarr,dirSizeUSB,&file1);
		add->ShowDialog();
	}
}
private: System::Void RefreshButton_Click(System::Object^ sender, System::EventArgs^ e) {
	std::ifstream file;
	std::string k;
	if (CDButton->Checked == true)
	{
		file.open("PlayListCD.txt");
		while (getline(file, k))
		{
			String^ str = gcnew String(k.c_str());
			for (int i = 0; i < PlayList->Items->Count; i++)
			{
				if (str != PlayList->Items[i]->ToString())
				{
					if (i == ((PlayList->Items->Count) - 1))
					{
						PlayList->Items->Add(str);
						CDplaylist.push_back(k);
						listSizeCD++;
					}
				}
				else
				{
					i = PlayList->Items->Count;
				}
			}
		}

	}
	else if (USBButton->Checked == true)
	{
		file.open("PlayListUSB.txt");
		while (getline(file, k))
		{
			for (int i = 0; i < PlayList->Items->Count; i++)
			{
				String^ str = gcnew String(k.c_str());
				if (str != PlayList->Items[i]->ToString())
				{
					if (i == ((PlayList->Items->Count) - 1))
					{
						PlayList->Items->Add(str);
						USBplaylist.push_back(k);
						listSizeUSB++;
					}
				}
				else
				{
					i = PlayList->Items->Count;
				}
			}
		}
	}
	file.close();
}
private: System::Void DeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
	std::ofstream out("tempfile.txt", ios::app);
	std::ifstream in;
	std::string k;
	int s_index = PlayList->SelectedIndex;
	String^ str = PlayList->Items[s_index]->ToString();
	std::string s = marshal_as<std::string>(str);
	if (CDButton->Checked == true)
	{
		ap.CloseMusicCD();
		in.open("PlayListCD.txt");
		while (getline(in, k))
		{
			if (s != k)
			{
				out << k << std::endl;
			}
		}
		out.close();
		in.close();
		remove("PlayListCD.txt");
		rename("tempfile.txt", "PlayListCD.txt");
		CDplaylist.erase(CDplaylist.begin() + s_index);
		listSizeCD--;
		std::string s = ap.PlayMusicCD();
		String^ str = gcnew String(s.c_str());
		PlayingSongBox->Text = str;
		PlayList->SetSelected(ap.GetIndexCD(s), true);
	}
	else if (USBButton->Checked == true)
	{
		ap.CloseMusicUSB();
		in.open("PlayListUSB.txt");
		while (getline(in, k))
		{
			if (s != k)
			{
				out << k << std::endl;
			}
		}
		out.close();
		in.close();
		remove("PlayListUSB.txt");
		rename("tempfile.txt", "PlayListUSB.txt");
		USBplaylist.erase(USBplaylist.begin() + (s_index - 1));
		listSizeUSB--;
		std::string s = ap.PlayMusicUSB();
		String^ str = gcnew String(s.c_str());
		PlayingSongBox->Text = str;
		PlayList->SetSelected(ap.GetIndexUSB(s), true);
	}
	PlayList->Items->RemoveAt(s_index);
}
};
}