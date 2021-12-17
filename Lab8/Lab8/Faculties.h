#pragma once
#include "DBContext.h"
using namespace MaterialSkin;
using namespace MaterialSkin::Controls;
namespace Lab8 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Lab8DomainCore;
	/// <summary>
	/// Summary for Faculties
	/// </summary>
	///

	public ref class Faculties : public MaterialForm
	{
	public:
		Faculties(void)
		{
			InitializeComponent();
			MaterialSkinManager^ materialSkinManager = MaterialSkinManager::Instance;
			materialSkinManager->AddFormToManage(this);
			materialSkinManager->Theme = MaterialSkinManager::Themes::LIGHT;
			db = gcnew DBContext();
			for each (Faculty ^ f in db->faculties)
			{
				materialListView1->Items->Add((gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(9) {
					L"",
						f->id.ToString(), f->facultyName, f->abbreviature, f->decane,f->yearOfCreating.ToString(),
						f->numOfSpecs.ToString(), f->telephoneNumber, f->email
				}, -1, System::Drawing::Color::Empty,
					System::Drawing::Color::Transparent, nullptr)));
			}
		}
		Faculties(Form^ _main) :Faculties()
		{
			main = _main;
			
		}
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_name;
	private: bool isnew = true;
	private: int selected = 0;
	public:

	public:
	private: MaterialSkin::Controls::MaterialLabel^ materialLabel1;
	private: MaterialSkin::Controls::MaterialLabel^ materialLabel2;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_abbr;

	private: MaterialSkin::Controls::MaterialLabel^ materialLabel3;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_dec;

	private: MaterialSkin::Controls::MaterialLabel^ materialLabel4;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_yr;

	private: MaterialSkin::Controls::MaterialLabel^ materialLabel5;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_nc;

	private: MaterialSkin::Controls::MaterialLabel^ materialLabel6;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_tel;

	private: MaterialSkin::Controls::MaterialLabel^ materialLabel7;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_email;
	private: MaterialSkin::Controls::MaterialFlatButton^ b_new;
	private: MaterialSkin::Controls::MaterialRaisedButton^ t_save;

	private: DBContext^ db;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Faculties()
		{
			if (components)
			{
				delete components;
			}
		}
	private: MaterialSkin::Controls::MaterialListView^ materialListView1;
	//private: ListView^ materialListView1;
	protected:
	private: System::Windows::Forms::ColumnHeader^ columnHeader0;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::ColumnHeader^ columnHeader4;
	private: System::Windows::Forms::ColumnHeader^ columnHeader5;
	private: System::Windows::Forms::ColumnHeader^ columnHeader6;
	private: System::Windows::Forms::ColumnHeader^ columnHeader7;

	private: Form^ main;
	private: System::Windows::Forms::ColumnHeader^ columnHeader9;
	private: System::Windows::Forms::ColumnHeader^ columnHeader8;
	private: Faculty^ curfac;






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
			this->materialListView1 = (gcnew MaterialSkin::Controls::MaterialListView());
			this->columnHeader0 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->t_name = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialLabel1 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->materialLabel2 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_abbr = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialLabel3 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_dec = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialLabel4 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_yr = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialLabel5 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_nc = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialLabel6 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_tel = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialLabel7 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_email = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->b_new = (gcnew MaterialSkin::Controls::MaterialFlatButton());
			this->t_save = (gcnew MaterialSkin::Controls::MaterialRaisedButton());
			this->SuspendLayout();
			// 
			// materialListView1
			// 
			this->materialListView1->Activation = System::Windows::Forms::ItemActivation::OneClick;
			this->materialListView1->BackColor = System::Drawing::Color::DarkRed;
			this->materialListView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->materialListView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(9) {
				this->columnHeader0,
					this->columnHeader1, this->columnHeader2, this->columnHeader3, this->columnHeader4, this->columnHeader5, this->columnHeader6,
					this->columnHeader7, this->columnHeader9
			});
			this->materialListView1->Depth = 0;
			this->materialListView1->Font = (gcnew System::Drawing::Font(L"Roboto", 32, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(204)));
			this->materialListView1->ForeColor = System::Drawing::SystemColors::Info;
			this->materialListView1->FullRowSelect = true;
			this->materialListView1->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->materialListView1->HideSelection = false;
			this->materialListView1->Location = System::Drawing::Point(41, 244);
			this->materialListView1->MouseLocation = System::Drawing::Point(-1, -1);
			this->materialListView1->MouseState = MaterialSkin::MouseState::OUT;
			this->materialListView1->Name = L"materialListView1";
			this->materialListView1->OwnerDraw = true;
			this->materialListView1->Size = System::Drawing::Size(942, 299);
			this->materialListView1->TabIndex = 0;
			this->materialListView1->UseCompatibleStateImageBehavior = false;
			this->materialListView1->View = System::Windows::Forms::View::Details;
			this->materialListView1->ItemActivate += gcnew System::EventHandler(this, &Faculties::materialListView1_ItemActivate);
			// 
			// columnHeader0
			// 
			this->columnHeader0->Text = L"";
			this->columnHeader0->Width = 0;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"id";
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Назва";
			this->columnHeader2->Width = 103;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Абревіатура";
			this->columnHeader3->Width = 194;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Декан";
			this->columnHeader4->Width = 105;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"Рік ств.";
			this->columnHeader5->Width = 123;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"К-ть спец.";
			this->columnHeader6->Width = 161;
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"Телефон";
			this->columnHeader7->Width = 143;
			// 
			// columnHeader9
			// 
			this->columnHeader9->Text = L"E-mail";
			this->columnHeader9->Width = 100;
			// 
			// t_name
			// 
			this->t_name->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_name->Depth = 0;
			this->t_name->Hint = L"";
			this->t_name->Location = System::Drawing::Point(100, 93);
			this->t_name->MaxLength = 32767;
			this->t_name->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_name->Name = L"t_name";
			this->t_name->PasswordChar = '\0';
			this->t_name->SelectedText = L"";
			this->t_name->SelectionLength = 0;
			this->t_name->SelectionStart = 0;
			this->t_name->Size = System::Drawing::Size(213, 23);
			this->t_name->TabIndex = 1;
			this->t_name->TabStop = false;
			this->t_name->UseSystemPasswordChar = false;
			// 
			// materialLabel1
			// 
			this->materialLabel1->AutoSize = true;
			this->materialLabel1->Depth = 0;
			this->materialLabel1->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel1->Location = System::Drawing::Point(15, 93);
			this->materialLabel1->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel1->Name = L"materialLabel1";
			this->materialLabel1->Size = System::Drawing::Size(53, 19);
			this->materialLabel1->TabIndex = 2;
			this->materialLabel1->Text = L"Назва";
			// 
			// materialLabel2
			// 
			this->materialLabel2->AutoSize = true;
			this->materialLabel2->Depth = 0;
			this->materialLabel2->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel2->Location = System::Drawing::Point(349, 93);
			this->materialLabel2->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel2->Name = L"materialLabel2";
			this->materialLabel2->Size = System::Drawing::Size(47, 19);
			this->materialLabel2->TabIndex = 4;
			this->materialLabel2->Text = L"Аббр.";
			// 
			// t_abbr
			// 
			this->t_abbr->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_abbr->Depth = 0;
			this->t_abbr->Hint = L"";
			this->t_abbr->Location = System::Drawing::Point(434, 93);
			this->t_abbr->MaxLength = 32767;
			this->t_abbr->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_abbr->Name = L"t_abbr";
			this->t_abbr->PasswordChar = '\0';
			this->t_abbr->SelectedText = L"";
			this->t_abbr->SelectionLength = 0;
			this->t_abbr->SelectionStart = 0;
			this->t_abbr->Size = System::Drawing::Size(213, 23);
			this->t_abbr->TabIndex = 3;
			this->t_abbr->TabStop = false;
			this->t_abbr->UseSystemPasswordChar = false;
			// 
			// materialLabel3
			// 
			this->materialLabel3->AutoSize = true;
			this->materialLabel3->Depth = 0;
			this->materialLabel3->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel3->Location = System::Drawing::Point(685, 93);
			this->materialLabel3->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel3->Name = L"materialLabel3";
			this->materialLabel3->Size = System::Drawing::Size(53, 19);
			this->materialLabel3->TabIndex = 6;
			this->materialLabel3->Text = L"Декан";
			// 
			// t_dec
			// 
			this->t_dec->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_dec->Depth = 0;
			this->t_dec->Hint = L"";
			this->t_dec->Location = System::Drawing::Point(770, 93);
			this->t_dec->MaxLength = 32767;
			this->t_dec->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_dec->Name = L"t_dec";
			this->t_dec->PasswordChar = '\0';
			this->t_dec->SelectedText = L"";
			this->t_dec->SelectionLength = 0;
			this->t_dec->SelectionStart = 0;
			this->t_dec->Size = System::Drawing::Size(213, 23);
			this->t_dec->TabIndex = 5;
			this->t_dec->TabStop = false;
			this->t_dec->UseSystemPasswordChar = false;
			// 
			// materialLabel4
			// 
			this->materialLabel4->AutoSize = true;
			this->materialLabel4->Depth = 0;
			this->materialLabel4->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel4->Location = System::Drawing::Point(15, 142);
			this->materialLabel4->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel4->Name = L"materialLabel4";
			this->materialLabel4->Size = System::Drawing::Size(62, 19);
			this->materialLabel4->TabIndex = 8;
			this->materialLabel4->Text = L"Рік ств.";
			// 
			// t_yr
			// 
			this->t_yr->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_yr->Depth = 0;
			this->t_yr->Hint = L"";
			this->t_yr->Location = System::Drawing::Point(100, 142);
			this->t_yr->MaxLength = 32767;
			this->t_yr->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_yr->Name = L"t_yr";
			this->t_yr->PasswordChar = '\0';
			this->t_yr->SelectedText = L"";
			this->t_yr->SelectionLength = 0;
			this->t_yr->SelectionStart = 0;
			this->t_yr->Size = System::Drawing::Size(213, 23);
			this->t_yr->TabIndex = 7;
			this->t_yr->TabStop = false;
			this->t_yr->UseSystemPasswordChar = false;
			// 
			// materialLabel5
			// 
			this->materialLabel5->AutoSize = true;
			this->materialLabel5->Depth = 0;
			this->materialLabel5->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel5->Location = System::Drawing::Point(336, 142);
			this->materialLabel5->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel5->Name = L"materialLabel5";
			this->materialLabel5->Size = System::Drawing::Size(80, 19);
			this->materialLabel5->TabIndex = 10;
			this->materialLabel5->Text = L"К-ть спец.";
			// 
			// t_nc
			// 
			this->t_nc->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_nc->Depth = 0;
			this->t_nc->Hint = L"";
			this->t_nc->Location = System::Drawing::Point(434, 142);
			this->t_nc->MaxLength = 32767;
			this->t_nc->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_nc->Name = L"t_nc";
			this->t_nc->PasswordChar = '\0';
			this->t_nc->SelectedText = L"";
			this->t_nc->SelectionLength = 0;
			this->t_nc->SelectionStart = 0;
			this->t_nc->Size = System::Drawing::Size(213, 23);
			this->t_nc->TabIndex = 9;
			this->t_nc->TabStop = false;
			this->t_nc->UseSystemPasswordChar = false;
			// 
			// materialLabel6
			// 
			this->materialLabel6->AutoSize = true;
			this->materialLabel6->Depth = 0;
			this->materialLabel6->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel6->Location = System::Drawing::Point(685, 142);
			this->materialLabel6->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel6->Name = L"materialLabel6";
			this->materialLabel6->Size = System::Drawing::Size(72, 19);
			this->materialLabel6->TabIndex = 12;
			this->materialLabel6->Text = L"Телефон";
			// 
			// t_tel
			// 
			this->t_tel->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_tel->Depth = 0;
			this->t_tel->Hint = L"";
			this->t_tel->Location = System::Drawing::Point(770, 142);
			this->t_tel->MaxLength = 32767;
			this->t_tel->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_tel->Name = L"t_tel";
			this->t_tel->PasswordChar = '\0';
			this->t_tel->SelectedText = L"";
			this->t_tel->SelectionLength = 0;
			this->t_tel->SelectionStart = 0;
			this->t_tel->Size = System::Drawing::Size(213, 23);
			this->t_tel->TabIndex = 11;
			this->t_tel->TabStop = false;
			this->t_tel->UseSystemPasswordChar = false;
			// 
			// materialLabel7
			// 
			this->materialLabel7->AutoSize = true;
			this->materialLabel7->Depth = 0;
			this->materialLabel7->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel7->Location = System::Drawing::Point(349, 196);
			this->materialLabel7->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel7->Name = L"materialLabel7";
			this->materialLabel7->Size = System::Drawing::Size(51, 19);
			this->materialLabel7->TabIndex = 14;
			this->materialLabel7->Text = L"E-mail";
			// 
			// t_email
			// 
			this->t_email->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_email->Depth = 0;
			this->t_email->Hint = L"";
			this->t_email->Location = System::Drawing::Point(434, 196);
			this->t_email->MaxLength = 32767;
			this->t_email->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_email->Name = L"t_email";
			this->t_email->PasswordChar = '\0';
			this->t_email->SelectedText = L"";
			this->t_email->SelectionLength = 0;
			this->t_email->SelectionStart = 0;
			this->t_email->Size = System::Drawing::Size(213, 23);
			this->t_email->TabIndex = 13;
			this->t_email->TabStop = false;
			this->t_email->UseSystemPasswordChar = false;
			// 
			// b_new
			// 
			this->b_new->AutoSize = true;
			this->b_new->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->b_new->Depth = 0;
			this->b_new->Icon = nullptr;
			this->b_new->Location = System::Drawing::Point(820, 196);
			this->b_new->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
			this->b_new->MouseState = MaterialSkin::MouseState::HOVER;
			this->b_new->Name = L"b_new";
			this->b_new->Primary = false;
			this->b_new->Size = System::Drawing::Size(68, 36);
			this->b_new->TabIndex = 15;
			this->b_new->Text = L"Новий";
			this->b_new->UseVisualStyleBackColor = true;
			this->b_new->Click += gcnew System::EventHandler(this, &Faculties::b_new_Click);
			// 
			// t_save
			// 
			this->t_save->AutoSize = true;
			this->t_save->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->t_save->Depth = 0;
			this->t_save->Icon = nullptr;
			this->t_save->Location = System::Drawing::Point(895, 196);
			this->t_save->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_save->Name = L"t_save";
			this->t_save->Primary = true;
			this->t_save->Size = System::Drawing::Size(88, 36);
			this->t_save->TabIndex = 16;
			this->t_save->Text = L"Зберегти";
			this->t_save->UseVisualStyleBackColor = true;
			this->t_save->Click += gcnew System::EventHandler(this, &Faculties::t_save_Click);
			// 
			// Faculties
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1005, 582);
			this->Controls->Add(this->t_save);
			this->Controls->Add(this->b_new);
			this->Controls->Add(this->materialLabel7);
			this->Controls->Add(this->t_email);
			this->Controls->Add(this->materialLabel6);
			this->Controls->Add(this->t_tel);
			this->Controls->Add(this->materialLabel5);
			this->Controls->Add(this->t_nc);
			this->Controls->Add(this->materialLabel4);
			this->Controls->Add(this->t_yr);
			this->Controls->Add(this->materialLabel3);
			this->Controls->Add(this->t_dec);
			this->Controls->Add(this->materialLabel2);
			this->Controls->Add(this->t_abbr);
			this->Controls->Add(this->materialLabel1);
			this->Controls->Add(this->t_name);
			this->Controls->Add(this->materialListView1);
			this->Name = L"Faculties";
			this->Text = L"Faculties";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Faculties::Faculties_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Faculties::Faculties_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Faculties_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void Faculties_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	db->saveChanges();
	delete db;
	this->main->Show();
}
private: System::Void materialListView1_ItemActivate(System::Object^ sender, System::EventArgs^ e) {
	isnew = false;
	selected = materialListView1->SelectedIndices[0];
	curfac = db->faculties[materialListView1->SelectedIndices[0]];
	t_name->Text = curfac->facultyName;
	t_abbr->Text= curfac->abbreviature ;
	t_dec->Text= curfac->decane;
	t_yr->Text= curfac->yearOfCreating.ToString();
	t_nc->Text=curfac->numOfSpecs.ToString();
	t_tel->Text= curfac->telephoneNumber;
	t_email->Text=curfac->email;
}
private: System::Void b_new_Click(System::Object^ sender, System::EventArgs^ e) {
	t_name->Clear(); t_dec->Clear(); t_yr->Clear(); t_abbr->Clear();
	t_nc->Clear(); t_tel->Clear(); t_email->Clear();
	isnew = true;
	curfac = nullptr;
}
private: System::Void t_save_Click(System::Object^ sender, System::EventArgs^ e) {
	if (isnew)
	{
		Faculty^ f = gcnew Faculty(t_name->Text, t_abbr->Text, t_dec->Text, int::Parse(t_yr->Text), int::Parse(t_nc->Text), t_tel->Text, t_email->Text);
		db->faculties->Add(f);
		materialListView1->Items->Add((gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(9) {
			L"",
				f->id.ToString(), t_name->Text, t_abbr->Text, t_dec->Text, t_yr->Text, t_nc->Text, t_tel->Text, t_email->Text
		}, -1, System::Drawing::Color::Empty,
			System::Drawing::Color::Transparent, nullptr)));
	}
	else
	{
		curfac->facultyName = t_name->Text;
		curfac->abbreviature = t_abbr->Text;
		curfac->decane = t_dec->Text;
		curfac->yearOfCreating = int::Parse(t_yr->Text);
		curfac->numOfSpecs = int::Parse(t_nc->Text);
		curfac->telephoneNumber = t_tel->Text;
		curfac->email = t_email->Text;
		materialListView1->Items[selected]=((gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(9) {
			L"",
				curfac->id.ToString(), t_name->Text, t_abbr->Text, t_dec->Text, t_yr->Text, t_nc->Text, t_tel->Text, t_email->Text
		}, -1, System::Drawing::Color::Empty,
			System::Drawing::Color::Transparent, nullptr)));

	}
	MessageBox::Show(this, "Успішно збережено", "OK", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
};
}
