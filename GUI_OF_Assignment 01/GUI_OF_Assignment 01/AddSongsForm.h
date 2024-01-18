#pragma once
#include<fstream>
#include<vector>

//std::vector <std::string> usbarr;
namespace GUIOFAssignment01 {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddSongsForm
	/// </summary>
	public ref class AddSongsForm : public System::Windows::Forms::Form
	{
		std::string* arrrr;
		int dirsize;
		std::ofstream* file;
	public:
		AddSongsForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		AddSongsForm(std::vector <std::string> arr,int size,std::ofstream* file2)
		{
			InitializeComponent();
			arrrr = new std::string[size];
			dirsize = size;
			file = file2;
			for (int i = 0; i < size; i++)
			{
				arrrr[i] = arr[i];
				String^ str = gcnew String(arr[i].c_str());
				ALLSongs->Items->Add(str);
			}
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddSongsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ ALLSongs;
	protected:
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ALLSongs = (gcnew System::Windows::Forms::ListBox());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// ALLSongs
			// 
			this->ALLSongs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ALLSongs->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->ALLSongs->FormattingEnabled = true;
			this->ALLSongs->ItemHeight = 20;
			this->ALLSongs->Location = System::Drawing::Point(3, -1);
			this->ALLSongs->Name = L"ALLSongs";
			this->ALLSongs->Size = System::Drawing::Size(344, 364);
			this->ALLSongs->TabIndex = 0;
			this->ALLSongs->SelectedIndexChanged += gcnew System::EventHandler(this, &AddSongsForm::ALLSongs_SelectedIndexChanged);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(353, 126);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(53, 4);
			this->checkedListBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(135, 369);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 35);
			this->button1->TabIndex = 2;
			this->button1->Text = L"ADD";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &AddSongsForm::button1_Click);
			// 
			// AddSongsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(351, 404);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->ALLSongs);
			this->Name = L"AddSongsForm";
			this->Text = L"AddSongsForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ALLSongs_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		button1->Enabled = true;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int s_index = ALLSongs->SelectedIndex;
		for (int i = 0; i < dirsize; i++)
		{
			if (arrrr[s_index] == arrrr[i])
			{
				*file << arrrr[s_index];
				*file << std::endl;
			}
		}
		this->Close();
	}
};
}
