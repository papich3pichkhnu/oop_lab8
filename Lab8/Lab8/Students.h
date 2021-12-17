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
	/// Summary for Students
	/// </summary>
	public ref class Students : public MaterialForm
	{
	private: Form^ main;
		   bool isnew = true;
		   int selected = 0;
		   Student^ curstud;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;


		   DBContext^ db;
	public:
		Students(void)
		{
			InitializeComponent();
			MaterialSkinManager^ materialSkinManager = MaterialSkinManager::Instance;
			materialSkinManager->AddFormToManage(this);
			materialSkinManager->Theme = MaterialSkinManager::Themes::LIGHT;
			
			db = gcnew DBContext();
			for each (Student ^ f in db->students)
			{
				materialListView1->Items->Add((gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(10) {
					L"",
						f->id.ToString(), f->lastName, f->firstName, f->middleName, f->getAge().ToString(),
						f->getHeight().ToString(), f->getColorOfEyes(), f->getColorOfHair(), f->getFacultyId() == -1 ? L"Немає" : f->getFaculty()->abbreviature
				}, -1, System::Drawing::Color::Empty,
					System::Drawing::Color::Transparent, nullptr)));
			}
			for each (Faculty ^ f in db->faculties)
			{
				t_fac->Items->Add(f->abbreviature);
			}
		}
		Students(Form^ _main) :Students()
		{
			main = _main;

		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Students()
		{
			if (components)
			{
				delete components;
			}
		}
	private: MaterialSkin::Controls::MaterialRaisedButton^ t_save;
	protected:
	private: MaterialSkin::Controls::MaterialFlatButton^ b_new;
	private: MaterialSkin::Controls::MaterialLabel^ materialLabel7;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_coh;

	private: MaterialSkin::Controls::MaterialLabel^ materialLabel6;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_coe;

	private: MaterialSkin::Controls::MaterialLabel^ materialLabel5;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_h;

	private: MaterialSkin::Controls::MaterialLabel^ materialLabel4;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_a;

	private: MaterialSkin::Controls::MaterialLabel^ materialLabel3;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_mn;

	private: MaterialSkin::Controls::MaterialLabel^ materialLabel2;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_fn;

	private: MaterialSkin::Controls::MaterialLabel^ materialLabel1;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_ln;

	private: MaterialSkin::Controls::MaterialListView^ materialListView1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader0;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;

	private: System::Windows::Forms::ColumnHeader^ columnHeader3;

	private: System::Windows::Forms::ColumnHeader^ columnHeader4;

	private: System::Windows::Forms::ColumnHeader^ columnHeader5;

	private: System::Windows::Forms::ColumnHeader^ columnHeader6;

	private: System::Windows::Forms::ColumnHeader^ columnHeader7;

	private: System::Windows::Forms::ColumnHeader^ columnHeader8;

	private: System::Windows::Forms::ColumnHeader^ columnHeader9;

	private: MaterialSkin::Controls::MaterialLabel^ materialLabel8;
	private: System::Windows::Forms::ComboBox^ t_fac;



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
			this->t_save = (gcnew MaterialSkin::Controls::MaterialRaisedButton());
			this->b_new = (gcnew MaterialSkin::Controls::MaterialFlatButton());
			this->materialLabel7 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_coh = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialLabel6 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_coe = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialLabel5 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_h = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialLabel4 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_a = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialLabel3 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_mn = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialLabel2 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_fn = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialLabel1 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_ln = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialListView1 = (gcnew MaterialSkin::Controls::MaterialListView());
			this->columnHeader0 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
			this->materialLabel8 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_fac = (gcnew System::Windows::Forms::ComboBox());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// t_save
			// 
			this->t_save->AutoSize = true;
			this->t_save->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->t_save->Depth = 0;
			this->t_save->Icon = nullptr;
			this->t_save->Location = System::Drawing::Point(925, 208);
			this->t_save->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_save->Name = L"t_save";
			this->t_save->Primary = true;
			this->t_save->Size = System::Drawing::Size(88, 36);
			this->t_save->TabIndex = 33;
			this->t_save->Text = L"Зберегти";
			this->t_save->UseVisualStyleBackColor = true;
			this->t_save->Click += gcnew System::EventHandler(this, &Students::t_save_Click);
			// 
			// b_new
			// 
			this->b_new->AutoSize = true;
			this->b_new->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->b_new->Depth = 0;
			this->b_new->Icon = nullptr;
			this->b_new->Location = System::Drawing::Point(850, 208);
			this->b_new->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
			this->b_new->MouseState = MaterialSkin::MouseState::HOVER;
			this->b_new->Name = L"b_new";
			this->b_new->Primary = false;
			this->b_new->Size = System::Drawing::Size(68, 36);
			this->b_new->TabIndex = 32;
			this->b_new->Text = L"Новий";
			this->b_new->UseVisualStyleBackColor = true;
			this->b_new->Click += gcnew System::EventHandler(this, &Students::b_new_Click);
			// 
			// materialLabel7
			// 
			this->materialLabel7->AutoSize = true;
			this->materialLabel7->Depth = 0;
			this->materialLabel7->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel7->Location = System::Drawing::Point(13, 208);
			this->materialLabel7->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel7->Name = L"materialLabel7";
			this->materialLabel7->Size = System::Drawing::Size(113, 19);
			this->materialLabel7->TabIndex = 31;
			this->materialLabel7->Text = L"Колір волосся";
			// 
			// t_coh
			// 
			this->t_coh->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_coh->Depth = 0;
			this->t_coh->Hint = L"";
			this->t_coh->Location = System::Drawing::Point(132, 204);
			this->t_coh->MaxLength = 32767;
			this->t_coh->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_coh->Name = L"t_coh";
			this->t_coh->PasswordChar = '\0';
			this->t_coh->SelectedText = L"";
			this->t_coh->SelectionLength = 0;
			this->t_coh->SelectionStart = 0;
			this->t_coh->Size = System::Drawing::Size(213, 23);
			this->t_coh->TabIndex = 30;
			this->t_coh->TabStop = false;
			this->t_coh->UseSystemPasswordChar = false;
			// 
			// materialLabel6
			// 
			this->materialLabel6->AutoSize = true;
			this->materialLabel6->Depth = 0;
			this->materialLabel6->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel6->Location = System::Drawing::Point(707, 154);
			this->materialLabel6->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel6->Name = L"materialLabel6";
			this->materialLabel6->Size = System::Drawing::Size(87, 19);
			this->materialLabel6->TabIndex = 29;
			this->materialLabel6->Text = L"Колір очей";
			// 
			// t_coe
			// 
			this->t_coe->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_coe->Depth = 0;
			this->t_coe->Hint = L"";
			this->t_coe->Location = System::Drawing::Point(800, 154);
			this->t_coe->MaxLength = 32767;
			this->t_coe->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_coe->Name = L"t_coe";
			this->t_coe->PasswordChar = '\0';
			this->t_coe->SelectedText = L"";
			this->t_coe->SelectionLength = 0;
			this->t_coe->SelectionStart = 0;
			this->t_coe->Size = System::Drawing::Size(213, 23);
			this->t_coe->TabIndex = 28;
			this->t_coe->TabStop = false;
			this->t_coe->UseSystemPasswordChar = false;
			// 
			// materialLabel5
			// 
			this->materialLabel5->AutoSize = true;
			this->materialLabel5->Depth = 0;
			this->materialLabel5->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel5->Location = System::Drawing::Point(366, 154);
			this->materialLabel5->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel5->Name = L"materialLabel5";
			this->materialLabel5->Size = System::Drawing::Size(45, 19);
			this->materialLabel5->TabIndex = 27;
			this->materialLabel5->Text = L"Зріст";
			// 
			// t_h
			// 
			this->t_h->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_h->Depth = 0;
			this->t_h->Hint = L"";
			this->t_h->Location = System::Drawing::Point(464, 154);
			this->t_h->MaxLength = 32767;
			this->t_h->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_h->Name = L"t_h";
			this->t_h->PasswordChar = '\0';
			this->t_h->SelectedText = L"";
			this->t_h->SelectionLength = 0;
			this->t_h->SelectionStart = 0;
			this->t_h->Size = System::Drawing::Size(213, 23);
			this->t_h->TabIndex = 26;
			this->t_h->TabStop = false;
			this->t_h->UseSystemPasswordChar = false;
			// 
			// materialLabel4
			// 
			this->materialLabel4->AutoSize = true;
			this->materialLabel4->Depth = 0;
			this->materialLabel4->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel4->Location = System::Drawing::Point(45, 154);
			this->materialLabel4->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel4->Name = L"materialLabel4";
			this->materialLabel4->Size = System::Drawing::Size(30, 19);
			this->materialLabel4->TabIndex = 25;
			this->materialLabel4->Text = L"Вік";
			// 
			// t_a
			// 
			this->t_a->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_a->Depth = 0;
			this->t_a->Hint = L"";
			this->t_a->Location = System::Drawing::Point(130, 154);
			this->t_a->MaxLength = 32767;
			this->t_a->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_a->Name = L"t_a";
			this->t_a->PasswordChar = '\0';
			this->t_a->SelectedText = L"";
			this->t_a->SelectionLength = 0;
			this->t_a->SelectionStart = 0;
			this->t_a->Size = System::Drawing::Size(213, 23);
			this->t_a->TabIndex = 24;
			this->t_a->TabStop = false;
			this->t_a->UseSystemPasswordChar = false;
			// 
			// materialLabel3
			// 
			this->materialLabel3->AutoSize = true;
			this->materialLabel3->Depth = 0;
			this->materialLabel3->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel3->Location = System::Drawing::Point(700, 105);
			this->materialLabel3->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel3->Name = L"materialLabel3";
			this->materialLabel3->Size = System::Drawing::Size(94, 19);
			this->materialLabel3->TabIndex = 23;
			this->materialLabel3->Text = L"По-батькові";
			// 
			// t_mn
			// 
			this->t_mn->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_mn->Depth = 0;
			this->t_mn->Hint = L"";
			this->t_mn->Location = System::Drawing::Point(800, 105);
			this->t_mn->MaxLength = 32767;
			this->t_mn->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_mn->Name = L"t_mn";
			this->t_mn->PasswordChar = '\0';
			this->t_mn->SelectedText = L"";
			this->t_mn->SelectionLength = 0;
			this->t_mn->SelectionStart = 0;
			this->t_mn->Size = System::Drawing::Size(213, 23);
			this->t_mn->TabIndex = 22;
			this->t_mn->TabStop = false;
			this->t_mn->UseSystemPasswordChar = false;
			// 
			// materialLabel2
			// 
			this->materialLabel2->AutoSize = true;
			this->materialLabel2->Depth = 0;
			this->materialLabel2->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel2->Location = System::Drawing::Point(379, 105);
			this->materialLabel2->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel2->Name = L"materialLabel2";
			this->materialLabel2->Size = System::Drawing::Size(35, 19);
			this->materialLabel2->TabIndex = 21;
			this->materialLabel2->Text = L"Ім\'я";
			// 
			// t_fn
			// 
			this->t_fn->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_fn->Depth = 0;
			this->t_fn->Hint = L"";
			this->t_fn->Location = System::Drawing::Point(464, 105);
			this->t_fn->MaxLength = 32767;
			this->t_fn->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_fn->Name = L"t_fn";
			this->t_fn->PasswordChar = '\0';
			this->t_fn->SelectedText = L"";
			this->t_fn->SelectionLength = 0;
			this->t_fn->SelectionStart = 0;
			this->t_fn->Size = System::Drawing::Size(213, 23);
			this->t_fn->TabIndex = 20;
			this->t_fn->TabStop = false;
			this->t_fn->UseSystemPasswordChar = false;
			// 
			// materialLabel1
			// 
			this->materialLabel1->AutoSize = true;
			this->materialLabel1->Depth = 0;
			this->materialLabel1->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel1->Location = System::Drawing::Point(45, 105);
			this->materialLabel1->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel1->Name = L"materialLabel1";
			this->materialLabel1->Size = System::Drawing::Size(78, 19);
			this->materialLabel1->TabIndex = 19;
			this->materialLabel1->Text = L"Прізвище";
			// 
			// t_ln
			// 
			this->t_ln->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_ln->Depth = 0;
			this->t_ln->Hint = L"";
			this->t_ln->Location = System::Drawing::Point(130, 105);
			this->t_ln->MaxLength = 32767;
			this->t_ln->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_ln->Name = L"t_ln";
			this->t_ln->PasswordChar = '\0';
			this->t_ln->SelectedText = L"";
			this->t_ln->SelectionLength = 0;
			this->t_ln->SelectionStart = 0;
			this->t_ln->Size = System::Drawing::Size(213, 23);
			this->t_ln->TabIndex = 18;
			this->t_ln->TabStop = false;
			this->t_ln->UseSystemPasswordChar = false;
			// 
			// materialListView1
			// 
			this->materialListView1->Activation = System::Windows::Forms::ItemActivation::OneClick;
			this->materialListView1->BackColor = System::Drawing::Color::DarkRed;
			this->materialListView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->materialListView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(10) {
				this->columnHeader0,
					this->columnHeader1, this->columnHeader2, this->columnHeader3, this->columnHeader4, this->columnHeader5, this->columnHeader6,
					this->columnHeader7, this->columnHeader8, this->columnHeader9
			});
			this->materialListView1->Depth = 0;
			this->materialListView1->Font = (gcnew System::Drawing::Font(L"Roboto", 32, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(204)));
			this->materialListView1->ForeColor = System::Drawing::SystemColors::Info;
			this->materialListView1->FullRowSelect = true;
			this->materialListView1->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->materialListView1->HideSelection = false;
			this->materialListView1->Location = System::Drawing::Point(71, 273);
			this->materialListView1->MouseLocation = System::Drawing::Point(-1, -1);
			this->materialListView1->MouseState = MaterialSkin::MouseState::OUT;
			this->materialListView1->Name = L"materialListView1";
			this->materialListView1->OwnerDraw = true;
			this->materialListView1->Size = System::Drawing::Size(942, 299);
			this->materialListView1->TabIndex = 17;
			this->materialListView1->UseCompatibleStateImageBehavior = false;
			this->materialListView1->View = System::Windows::Forms::View::Details;
			this->materialListView1->ItemActivate += gcnew System::EventHandler(this, &Students::materialListView1_ItemActivate);
			// 
			// columnHeader0
			// 
			this->columnHeader0->Text = L"";
			this->columnHeader0->Width = 0;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Прізвище";
			this->columnHeader2->Width = 156;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Ім\'я";
			this->columnHeader3->Width = 69;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"По-батькові";
			this->columnHeader4->Width = 190;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"Вік";
			this->columnHeader5->Width = 57;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"Зріст";
			this->columnHeader6->Width = 89;
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"Колір очей";
			this->columnHeader7->Width = 174;
			// 
			// columnHeader8
			// 
			this->columnHeader8->Text = L"Колір волосся";
			this->columnHeader8->Width = 229;
			// 
			// columnHeader9
			// 
			this->columnHeader9->Text = L"Факультет";
			this->columnHeader9->Width = 169;
			// 
			// materialLabel8
			// 
			this->materialLabel8->AutoSize = true;
			this->materialLabel8->Depth = 0;
			this->materialLabel8->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel8->Location = System::Drawing::Point(366, 208);
			this->materialLabel8->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel8->Name = L"materialLabel8";
			this->materialLabel8->Size = System::Drawing::Size(83, 19);
			this->materialLabel8->TabIndex = 34;
			this->materialLabel8->Text = L"Факультет";
			// 
			// t_fac
			// 
			this->t_fac->BackColor = System::Drawing::SystemColors::Control;
			this->t_fac->FormattingEnabled = true;
			this->t_fac->Location = System::Drawing::Point(496, 208);
			this->t_fac->Name = L"t_fac";
			this->t_fac->Size = System::Drawing::Size(181, 21);
			this->t_fac->TabIndex = 35;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"id";
			this->columnHeader1->Width = 38;
			// 
			// Students
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1207, 624);
			this->Controls->Add(this->t_fac);
			this->Controls->Add(this->materialLabel8);
			this->Controls->Add(this->t_save);
			this->Controls->Add(this->b_new);
			this->Controls->Add(this->materialLabel7);
			this->Controls->Add(this->t_coh);
			this->Controls->Add(this->materialLabel6);
			this->Controls->Add(this->t_coe);
			this->Controls->Add(this->materialLabel5);
			this->Controls->Add(this->t_h);
			this->Controls->Add(this->materialLabel4);
			this->Controls->Add(this->t_a);
			this->Controls->Add(this->materialLabel3);
			this->Controls->Add(this->t_mn);
			this->Controls->Add(this->materialLabel2);
			this->Controls->Add(this->t_fn);
			this->Controls->Add(this->materialLabel1);
			this->Controls->Add(this->t_ln);
			this->Controls->Add(this->materialListView1);
			this->Name = L"Students";
			this->Text = L"Students";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Students::Students_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Students::Students_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Students_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void b_new_Click(System::Object^ sender, System::EventArgs^ e) {
	t_ln->Clear(); t_fn->Clear(); t_mn->Clear(); t_a->Clear();
	t_h->Clear(); t_coe->Clear(); t_coh->Clear(); t_fac->SelectedIndex = -1;
	isnew = true;
	curstud = nullptr;
}
private: System::Void t_save_Click(System::Object^ sender, System::EventArgs^ e) {
	if (isnew)
	{
		Student^ f = gcnew Student(t_ln->Text, t_fn->Text, t_mn->Text, int::Parse(t_a->Text), int::Parse(t_h->Text), t_coe->Text, t_coh->Text);
		db->faculties[this->t_fac->SelectedIndex]->enrollStudent(f);
		db->students->Add(f);
		materialListView1->Items->Add((gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(10) {
			L"",
				f->id.ToString(), f->lastName, f->firstName, f->middleName, f->getAge().ToString(),
				f->getHeight().ToString(), f->getColorOfEyes(), f->getColorOfHair(), f->getFacultyId() == -1 ? L"Немає" : f->getFaculty()->abbreviature
		}, -1, System::Drawing::Color::Empty,
			System::Drawing::Color::Transparent, nullptr)));
	}
	else
	{
		curstud->lastName = t_ln->Text;
		curstud->firstName = t_fn->Text;
		curstud->middleName = t_mn->Text;
		curstud->setData(int::Parse(t_a->Text), int::Parse(t_h->Text));
		curstud->setEyesHair(t_coe->Text, t_coh->Text);
		if (curstud->getFacultyId() != -1)
		{
			curstud->getFaculty()->deductStudent(curstud);
		}
		this->db->faculties[t_fac->SelectedIndex]->enrollStudent(curstud);
		materialListView1->Items[selected] = ((gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(10) {
			L"",
				curstud->id.ToString(), t_ln->Text, t_fn->Text, t_mn->Text, t_a->Text, t_h->Text, t_coe->Text, t_coh->Text, t_fac->Text
		}, -1, System::Drawing::Color::Empty,
			System::Drawing::Color::Transparent, nullptr)));

	}
	MessageBox::Show(this, "Успішно збережено", "OK", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void materialListView1_ItemActivate(System::Object^ sender, System::EventArgs^ e) {
	isnew = false;
	selected = materialListView1->SelectedIndices[0];
	curstud = db->students[materialListView1->SelectedIndices[0]];
	t_ln->Text = curstud->lastName;
	t_fn->Text = curstud ->firstName;
	t_mn->Text = curstud->middleName;
	t_a->Text = curstud->getAge().ToString();
	t_h->Text = curstud->getHeight().ToString();
	t_coe->Text = curstud->getColorOfEyes();
	t_coh->Text = curstud->getColorOfHair();
	t_fac->SelectedIndex = curstud->getFacultyId() == -1 ? -1 : curstud->getFacultyId();
}
private: System::Void Students_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	db->saveChanges();
	delete db;
	this->main->Show();
}
};
}
