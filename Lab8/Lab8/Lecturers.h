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
	/// Summary for Lecturers
	/// </summary>
	public ref class Lecturers : public MaterialForm
	{
	private: Form^ main;
	bool isnew = true;
	int selected = 0;
	Lecturer^ curlec;
	private: System::Windows::Forms::ComboBox^ t_dep;

	private: MaterialSkin::Controls::MaterialLabel^ materialLabel8;
	private: MaterialSkin::Controls::MaterialRaisedButton^ t_save;
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
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::ColumnHeader^ columnHeader4;
	private: System::Windows::Forms::ColumnHeader^ columnHeader5;
	private: System::Windows::Forms::ColumnHeader^ columnHeader6;
	private: System::Windows::Forms::ColumnHeader^ columnHeader7;
	private: System::Windows::Forms::ColumnHeader^ columnHeader8;
	private: System::Windows::Forms::ColumnHeader^ columnHeader9;
	private: System::Windows::Forms::ColumnHeader^ columnHeader10;
	private: System::Windows::Forms::ComboBox^ t_type;
	private: MaterialSkin::Controls::MaterialLabel^ materialLabel9;
		   DBContext^ db;
	public:
		Lecturers(void)
		{
			InitializeComponent();
			MaterialSkinManager^ materialSkinManager = MaterialSkinManager::Instance;
			materialSkinManager->AddFormToManage(this);
			materialSkinManager->Theme = MaterialSkinManager::Themes::LIGHT;
			db = gcnew DBContext();
			for each (Lecturer ^ f in db->alllecturers)
			{
				String^ desc = f->getDescryptor();
				String^ d = "";
				if (desc == "Lecturer")d = L"Викладач";
				if (desc == "SeniorLecturer")d = L"Старший викладач";
				if (desc == "AssociateProfessor")d = L"Доцент";
				materialListView1->Items->Add((gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(11) {
					L"",
						f->id.ToString(), d, f->lastName, f->firstName, f->middleName, f->getAge().ToString(),
						f->getHeight().ToString(), f->getColorOfEyes(), f->getColorOfHair(), f->getDepartmentId() == -1 ? L"Немає" : f->getDepartment()->name
				}, -1, System::Drawing::Color::Empty,
					System::Drawing::Color::Transparent, nullptr)));
			}
			for each (Department ^ d in db->departments)
			{
				t_dep->Items->Add(d->name);
			}
		}
		Lecturers(Form^ _main) :Lecturers()
		{
			main = _main;

		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Lecturers()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->t_dep = (gcnew System::Windows::Forms::ComboBox());
			this->materialLabel8 = (gcnew MaterialSkin::Controls::MaterialLabel());
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
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader10 = (gcnew System::Windows::Forms::ColumnHeader());
			this->t_type = (gcnew System::Windows::Forms::ComboBox());
			this->materialLabel9 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->SuspendLayout();
			// 
			// t_dep
			// 
			this->t_dep->BackColor = System::Drawing::SystemColors::Control;
			this->t_dep->FormattingEnabled = true;
			this->t_dep->Location = System::Drawing::Point(463, 185);
			this->t_dep->Name = L"t_dep";
			this->t_dep->Size = System::Drawing::Size(181, 21);
			this->t_dep->TabIndex = 54;
			// 
			// materialLabel8
			// 
			this->materialLabel8->AutoSize = true;
			this->materialLabel8->Depth = 0;
			this->materialLabel8->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel8->Location = System::Drawing::Point(374, 184);
			this->materialLabel8->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel8->Name = L"materialLabel8";
			this->materialLabel8->Size = System::Drawing::Size(71, 19);
			this->materialLabel8->TabIndex = 53;
			this->materialLabel8->Text = L"Кафедра";
			// 
			// t_save
			// 
			this->t_save->AutoSize = true;
			this->t_save->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->t_save->Depth = 0;
			this->t_save->Icon = nullptr;
			this->t_save->Location = System::Drawing::Point(971, 184);
			this->t_save->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_save->Name = L"t_save";
			this->t_save->Primary = true;
			this->t_save->Size = System::Drawing::Size(88, 36);
			this->t_save->TabIndex = 52;
			this->t_save->Text = L"Зберегти";
			this->t_save->UseVisualStyleBackColor = true;
			this->t_save->Click += gcnew System::EventHandler(this, &Lecturers::t_save_Click);
			// 
			// b_new
			// 
			this->b_new->AutoSize = true;
			this->b_new->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->b_new->Depth = 0;
			this->b_new->Icon = nullptr;
			this->b_new->Location = System::Drawing::Point(896, 184);
			this->b_new->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
			this->b_new->MouseState = MaterialSkin::MouseState::HOVER;
			this->b_new->Name = L"b_new";
			this->b_new->Primary = false;
			this->b_new->Size = System::Drawing::Size(68, 36);
			this->b_new->TabIndex = 51;
			this->b_new->Text = L"Новий";
			this->b_new->UseVisualStyleBackColor = true;
			this->b_new->Click += gcnew System::EventHandler(this, &Lecturers::b_new_Click);
			// 
			// materialLabel7
			// 
			this->materialLabel7->AutoSize = true;
			this->materialLabel7->Depth = 0;
			this->materialLabel7->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel7->Location = System::Drawing::Point(12, 184);
			this->materialLabel7->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel7->Name = L"materialLabel7";
			this->materialLabel7->Size = System::Drawing::Size(113, 19);
			this->materialLabel7->TabIndex = 50;
			this->materialLabel7->Text = L"Колір волосся";
			this->materialLabel7->Click += gcnew System::EventHandler(this, &Lecturers::materialLabel7_Click);
			// 
			// t_coh
			// 
			this->t_coh->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_coh->Depth = 0;
			this->t_coh->Hint = L"";
			this->t_coh->Location = System::Drawing::Point(131, 180);
			this->t_coh->MaxLength = 32767;
			this->t_coh->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_coh->Name = L"t_coh";
			this->t_coh->PasswordChar = '\0';
			this->t_coh->SelectedText = L"";
			this->t_coh->SelectionLength = 0;
			this->t_coh->SelectionStart = 0;
			this->t_coh->Size = System::Drawing::Size(213, 23);
			this->t_coh->TabIndex = 49;
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
			this->materialLabel6->Location = System::Drawing::Point(753, 130);
			this->materialLabel6->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel6->Name = L"materialLabel6";
			this->materialLabel6->Size = System::Drawing::Size(87, 19);
			this->materialLabel6->TabIndex = 48;
			this->materialLabel6->Text = L"Колір очей";
			// 
			// t_coe
			// 
			this->t_coe->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_coe->Depth = 0;
			this->t_coe->Hint = L"";
			this->t_coe->Location = System::Drawing::Point(846, 130);
			this->t_coe->MaxLength = 32767;
			this->t_coe->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_coe->Name = L"t_coe";
			this->t_coe->PasswordChar = '\0';
			this->t_coe->SelectedText = L"";
			this->t_coe->SelectionLength = 0;
			this->t_coe->SelectionStart = 0;
			this->t_coe->Size = System::Drawing::Size(213, 23);
			this->t_coe->TabIndex = 47;
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
			this->materialLabel5->Location = System::Drawing::Point(412, 130);
			this->materialLabel5->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel5->Name = L"materialLabel5";
			this->materialLabel5->Size = System::Drawing::Size(45, 19);
			this->materialLabel5->TabIndex = 46;
			this->materialLabel5->Text = L"Зріст";
			// 
			// t_h
			// 
			this->t_h->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_h->Depth = 0;
			this->t_h->Hint = L"";
			this->t_h->Location = System::Drawing::Point(510, 130);
			this->t_h->MaxLength = 32767;
			this->t_h->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_h->Name = L"t_h";
			this->t_h->PasswordChar = '\0';
			this->t_h->SelectedText = L"";
			this->t_h->SelectionLength = 0;
			this->t_h->SelectionStart = 0;
			this->t_h->Size = System::Drawing::Size(213, 23);
			this->t_h->TabIndex = 45;
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
			this->materialLabel4->Location = System::Drawing::Point(91, 130);
			this->materialLabel4->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel4->Name = L"materialLabel4";
			this->materialLabel4->Size = System::Drawing::Size(30, 19);
			this->materialLabel4->TabIndex = 44;
			this->materialLabel4->Text = L"Вік";
			// 
			// t_a
			// 
			this->t_a->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_a->Depth = 0;
			this->t_a->Hint = L"";
			this->t_a->Location = System::Drawing::Point(176, 130);
			this->t_a->MaxLength = 32767;
			this->t_a->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_a->Name = L"t_a";
			this->t_a->PasswordChar = '\0';
			this->t_a->SelectedText = L"";
			this->t_a->SelectionLength = 0;
			this->t_a->SelectionStart = 0;
			this->t_a->Size = System::Drawing::Size(213, 23);
			this->t_a->TabIndex = 43;
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
			this->materialLabel3->Location = System::Drawing::Point(746, 81);
			this->materialLabel3->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel3->Name = L"materialLabel3";
			this->materialLabel3->Size = System::Drawing::Size(94, 19);
			this->materialLabel3->TabIndex = 42;
			this->materialLabel3->Text = L"По-батькові";
			// 
			// t_mn
			// 
			this->t_mn->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_mn->Depth = 0;
			this->t_mn->Hint = L"";
			this->t_mn->Location = System::Drawing::Point(846, 81);
			this->t_mn->MaxLength = 32767;
			this->t_mn->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_mn->Name = L"t_mn";
			this->t_mn->PasswordChar = '\0';
			this->t_mn->SelectedText = L"";
			this->t_mn->SelectionLength = 0;
			this->t_mn->SelectionStart = 0;
			this->t_mn->Size = System::Drawing::Size(213, 23);
			this->t_mn->TabIndex = 41;
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
			this->materialLabel2->Location = System::Drawing::Point(425, 81);
			this->materialLabel2->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel2->Name = L"materialLabel2";
			this->materialLabel2->Size = System::Drawing::Size(35, 19);
			this->materialLabel2->TabIndex = 40;
			this->materialLabel2->Text = L"Ім\'я";
			// 
			// t_fn
			// 
			this->t_fn->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_fn->Depth = 0;
			this->t_fn->Hint = L"";
			this->t_fn->Location = System::Drawing::Point(510, 81);
			this->t_fn->MaxLength = 32767;
			this->t_fn->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_fn->Name = L"t_fn";
			this->t_fn->PasswordChar = '\0';
			this->t_fn->SelectedText = L"";
			this->t_fn->SelectionLength = 0;
			this->t_fn->SelectionStart = 0;
			this->t_fn->Size = System::Drawing::Size(213, 23);
			this->t_fn->TabIndex = 39;
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
			this->materialLabel1->Location = System::Drawing::Point(91, 81);
			this->materialLabel1->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel1->Name = L"materialLabel1";
			this->materialLabel1->Size = System::Drawing::Size(78, 19);
			this->materialLabel1->TabIndex = 38;
			this->materialLabel1->Text = L"Прізвище";
			// 
			// t_ln
			// 
			this->t_ln->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_ln->Depth = 0;
			this->t_ln->Hint = L"";
			this->t_ln->Location = System::Drawing::Point(176, 81);
			this->t_ln->MaxLength = 32767;
			this->t_ln->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_ln->Name = L"t_ln";
			this->t_ln->PasswordChar = '\0';
			this->t_ln->SelectedText = L"";
			this->t_ln->SelectionLength = 0;
			this->t_ln->SelectionStart = 0;
			this->t_ln->Size = System::Drawing::Size(213, 23);
			this->t_ln->TabIndex = 37;
			this->t_ln->TabStop = false;
			this->t_ln->UseSystemPasswordChar = false;
			// 
			// materialListView1
			// 
			this->materialListView1->Activation = System::Windows::Forms::ItemActivation::OneClick;
			this->materialListView1->BackColor = System::Drawing::Color::DarkRed;
			this->materialListView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->materialListView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(11) {
				this->columnHeader0,
					this->columnHeader1, this->columnHeader2, this->columnHeader3, this->columnHeader4, this->columnHeader5, this->columnHeader6,
					this->columnHeader7, this->columnHeader8, this->columnHeader9, this->columnHeader10
			});
			this->materialListView1->Depth = 0;
			this->materialListView1->Font = (gcnew System::Drawing::Font(L"Roboto", 32, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(204)));
			this->materialListView1->ForeColor = System::Drawing::SystemColors::Info;
			this->materialListView1->FullRowSelect = true;
			this->materialListView1->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->materialListView1->HideSelection = false;
			this->materialListView1->Location = System::Drawing::Point(117, 249);
			this->materialListView1->MouseLocation = System::Drawing::Point(-1, -1);
			this->materialListView1->MouseState = MaterialSkin::MouseState::OUT;
			this->materialListView1->Name = L"materialListView1";
			this->materialListView1->OwnerDraw = true;
			this->materialListView1->Size = System::Drawing::Size(1084, 299);
			this->materialListView1->TabIndex = 36;
			this->materialListView1->UseCompatibleStateImageBehavior = false;
			this->materialListView1->View = System::Windows::Forms::View::Details;
			this->materialListView1->ItemActivate += gcnew System::EventHandler(this, &Lecturers::materialListView1_ItemActivate);
			// 
			// columnHeader0
			// 
			this->columnHeader0->Text = L"";
			this->columnHeader0->Width = 0;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"id";
			this->columnHeader1->Width = 38;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Тип викладача";
			this->columnHeader2->Width = 234;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Прізвище";
			this->columnHeader3->Width = 156;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Ім\'я";
			this->columnHeader4->Width = 69;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"По-батькові";
			this->columnHeader5->Width = 190;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"Вік";
			this->columnHeader6->Width = 57;
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"Зріст";
			this->columnHeader7->Width = 89;
			// 
			// columnHeader8
			// 
			this->columnHeader8->Text = L"Колір очей";
			this->columnHeader8->Width = 174;
			// 
			// columnHeader9
			// 
			this->columnHeader9->Text = L"Колір волосся";
			this->columnHeader9->Width = 229;
			// 
			// columnHeader10
			// 
			this->columnHeader10->Text = L"Кафедра";
			this->columnHeader10->Width = 144;
			// 
			// t_type
			// 
			this->t_type->BackColor = System::Drawing::SystemColors::Control;
			this->t_type->FormattingEnabled = true;
			this->t_type->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Викладач", L"Старший викладач", L"Доцент" });
			this->t_type->Location = System::Drawing::Point(463, 222);
			this->t_type->Name = L"t_type";
			this->t_type->Size = System::Drawing::Size(181, 21);
			this->t_type->TabIndex = 56;
			// 
			// materialLabel9
			// 
			this->materialLabel9->AutoSize = true;
			this->materialLabel9->Depth = 0;
			this->materialLabel9->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel9->Location = System::Drawing::Point(336, 224);
			this->materialLabel9->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel9->Name = L"materialLabel9";
			this->materialLabel9->Size = System::Drawing::Size(121, 19);
			this->materialLabel9->TabIndex = 55;
			this->materialLabel9->Text = L"Ранг викладача";
			// 
			// Lecturers
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1256, 593);
			this->Controls->Add(this->t_type);
			this->Controls->Add(this->materialLabel9);
			this->Controls->Add(this->t_dep);
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
			this->Name = L"Lecturers";
			this->Text = L"Lecturers";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Lecturers::Lecturers_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void materialLabel7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void b_new_Click(System::Object^ sender, System::EventArgs^ e) {
	t_ln->Clear(); t_fn->Clear(); t_mn->Clear(); t_a->Clear();
	t_h->Clear(); t_coe->Clear(); t_coh->Clear(); t_dep->SelectedIndex = -1; t_type->SelectedIndex = 0;
	t_type->Enabled = true;
	isnew = true;
	curlec = nullptr;
}
private: System::Void t_save_Click(System::Object^ sender, System::EventArgs^ e) {
	if (isnew)
	{
		int k = t_type->SelectedIndex;
		Lecturer^ f;
		String^ desc = "";
		if(k==0)desc=L"Викладач",f = gcnew Lecturer(t_ln->Text, t_fn->Text, t_mn->Text, int::Parse(t_a->Text), int::Parse(t_h->Text), t_coe->Text, t_coh->Text);
		if (k == 1)desc = L"Старший викладач", f = gcnew SeniorLecturer(t_ln->Text, t_fn->Text, t_mn->Text, int::Parse(t_a->Text), int::Parse(t_h->Text), t_coe->Text, t_coh->Text);
		if (k == 2)desc = L"Доцент", f = gcnew AssociateProfessor(t_ln->Text, t_fn->Text, t_mn->Text, int::Parse(t_a->Text), int::Parse(t_h->Text), t_coe->Text, t_coh->Text);
		db->departments[this->t_dep->SelectedIndex]->enrollLecturer(f);		

		db->alllecturers->Add(f);
		if (k == 0)db->lecturers->Add(f);
		if (k == 1)db->lecturers->Add(f), db->seniorlecturers->Add(dynamic_cast<SeniorLecturer^>(f));
		if (k == 2)db->lecturers->Add(f), db->seniorlecturers->Add(dynamic_cast<SeniorLecturer^>(f)), db->associateprofessors->Add(dynamic_cast<AssociateProfessor^>(f));
		
		materialListView1->Items->Add((gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(11) {
			L"",
				f->id.ToString(),desc, f->lastName, f->firstName, f->middleName, f->getAge().ToString(),
				f->getHeight().ToString(), f->getColorOfEyes(), f->getColorOfHair(), f->getDepartmentId() == -1 ? L"Немає" : f->getDepartment()->name
		}, -1, System::Drawing::Color::Empty,
			System::Drawing::Color::Transparent, nullptr)));
	}
	else
	{
		curlec->lastName = t_ln->Text;
		curlec->firstName = t_fn->Text;
		curlec->middleName = t_mn->Text;
		curlec->setData(int::Parse(t_a->Text), int::Parse(t_h->Text));
		curlec->setEyesHair(t_coe->Text, t_coh->Text);
		if (curlec->getDepartmentId() != -1)
		{
			curlec->getDepartment()->deductLecturer(curlec);
		}
		this->db->departments[t_dep->SelectedIndex]->enrollLecturer(curlec);
		String^ text = L"Викладач";
		if (curlec->getDescryptor() == "SeniorLecturer")text = L"Старший викладач";
		if (curlec->getDescryptor() == "AssociateProfessor")text = L"Доцент";
		materialListView1->Items[selected] = ((gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(11) {
			L"",
				curlec->id.ToString(), text,t_ln->Text, t_fn->Text, t_mn->Text, t_a->Text, t_h->Text, t_coe->Text, t_coh->Text, t_dep->Text
		}, -1, System::Drawing::Color::Empty,
			System::Drawing::Color::Transparent, nullptr)));

	}
	MessageBox::Show(this, "Успішно збережено", "OK", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void Lecturers_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	db->saveChanges();
	delete db;
	this->main->Show();
}
private: System::Void materialListView1_ItemActivate(System::Object^ sender, System::EventArgs^ e) {
	isnew = false;
	selected = materialListView1->SelectedIndices[0];
	curlec = db->alllecturers[materialListView1->SelectedIndices[0]];
	t_ln->Text = curlec->lastName;
	t_fn->Text = curlec->firstName;
	t_mn->Text = curlec->middleName;
	t_a->Text = curlec->getAge().ToString();
	t_h->Text = curlec->getHeight().ToString();
	t_coe->Text = curlec->getColorOfEyes();
	t_coh->Text = curlec->getColorOfHair();
	t_dep->SelectedIndex = curlec ->getDepartmentId() == -1 ? -1 : curlec->getDepartmentId();
	t_type->Enabled = false;
	String^ desc = curlec->getDescryptor();
	int d = 0;
	if (desc == "Lecturer")d = 0;
	if (desc == "SeniorLecturer")d = 1;
	if (desc == "AssociateLecturer")d = 2;
	t_type->SelectedIndex = d;
}
};
}
