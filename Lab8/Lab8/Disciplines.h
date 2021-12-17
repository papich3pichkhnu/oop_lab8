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
	/// Summary for Disciplines
	/// </summary>
	public ref class Disciplines : public MaterialForm
	{
	private: Form^ main;
		   bool isnew = true;
		   int selected = 0;
		   Discipline^ curdis;
	private: System::Windows::Forms::ComboBox^ t_dep;

	private: MaterialSkin::Controls::MaterialLabel^ materialLabel8;
	private: MaterialSkin::Controls::MaterialRaisedButton^ t_save;
	private: MaterialSkin::Controls::MaterialFlatButton^ b_new;






	private: MaterialSkin::Controls::MaterialLabel^ materialLabel4;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_nk;

	private: MaterialSkin::Controls::MaterialLabel^ materialLabel3;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_nc;

	private: MaterialSkin::Controls::MaterialLabel^ materialLabel2;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_tc;


	private: MaterialSkin::Controls::MaterialLabel^ materialLabel1;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_name;

	private: MaterialSkin::Controls::MaterialListView^ materialListView1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader0;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::ColumnHeader^ columnHeader4;
	private: System::Windows::Forms::ColumnHeader^ columnHeader5;
	private: System::Windows::Forms::ColumnHeader^ columnHeader6;
	private: System::Windows::Forms::ColumnHeader^ columnHeader7;
	private: MaterialSkin::Controls::MaterialLabel^ materialLabel5;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_nh;






		   DBContext^ db;
	public:
		Disciplines(void)
		{
			InitializeComponent();
			MaterialSkinManager^ materialSkinManager = MaterialSkinManager::Instance;
			materialSkinManager->AddFormToManage(this);
			materialSkinManager->Theme = MaterialSkinManager::Themes::LIGHT;
			db = gcnew DBContext();
			for each (Discipline ^ f in db->disciplines)
			{
				materialListView1->Items->Add((gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(8) {
					L"",
						f->id.ToString(), f->name, f->typeOfControl, f->getCredits().ToString(),
						f->getNumberOfControlWorks().ToString(), f->getNumberOfHours().ToString(), f->departmentId == -1 ? L"Немає" : f->department->name
						
				}, -1, System::Drawing::Color::Empty,
					System::Drawing::Color::Transparent, nullptr)));
			}
			for each (Department ^ f in db->departments)
			{
				t_dep->Items->Add(f->name);
			}
		}
		Disciplines(Form^ _main) :Disciplines()
		{
			main = _main;

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Disciplines()
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
			this->materialLabel4 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_nk = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialLabel3 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_nc = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialLabel2 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_tc = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialLabel1 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_name = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialListView1 = (gcnew MaterialSkin::Controls::MaterialListView());
			this->columnHeader0 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->materialLabel5 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_nh = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// t_dep
			// 
			this->t_dep->BackColor = System::Drawing::SystemColors::Control;
			this->t_dep->FormattingEnabled = true;
			this->t_dep->Location = System::Drawing::Point(536, 193);
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
			this->materialLabel8->Location = System::Drawing::Point(406, 193);
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
			this->t_save->Location = System::Drawing::Point(965, 193);
			this->t_save->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_save->Name = L"t_save";
			this->t_save->Primary = true;
			this->t_save->Size = System::Drawing::Size(88, 36);
			this->t_save->TabIndex = 52;
			this->t_save->Text = L"Зберегти";
			this->t_save->UseVisualStyleBackColor = true;
			this->t_save->Click += gcnew System::EventHandler(this, &Disciplines::t_save_Click);
			// 
			// b_new
			// 
			this->b_new->AutoSize = true;
			this->b_new->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->b_new->Depth = 0;
			this->b_new->Icon = nullptr;
			this->b_new->Location = System::Drawing::Point(890, 193);
			this->b_new->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
			this->b_new->MouseState = MaterialSkin::MouseState::HOVER;
			this->b_new->Name = L"b_new";
			this->b_new->Primary = false;
			this->b_new->Size = System::Drawing::Size(68, 36);
			this->b_new->TabIndex = 51;
			this->b_new->Text = L"Новий";
			this->b_new->UseVisualStyleBackColor = true;
			this->b_new->Click += gcnew System::EventHandler(this, &Disciplines::b_new_Click);
			// 
			// materialLabel4
			// 
			this->materialLabel4->AutoSize = true;
			this->materialLabel4->Depth = 0;
			this->materialLabel4->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel4->Location = System::Drawing::Point(66, 139);
			this->materialLabel4->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel4->Name = L"materialLabel4";
			this->materialLabel4->Size = System::Drawing::Size(98, 19);
			this->materialLabel4->TabIndex = 44;
			this->materialLabel4->Text = L"Кількість КР";
			// 
			// t_nk
			// 
			this->t_nk->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_nk->Depth = 0;
			this->t_nk->Hint = L"";
			this->t_nk->Location = System::Drawing::Point(170, 139);
			this->t_nk->MaxLength = 32767;
			this->t_nk->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_nk->Name = L"t_nk";
			this->t_nk->PasswordChar = '\0';
			this->t_nk->SelectedText = L"";
			this->t_nk->SelectionLength = 0;
			this->t_nk->SelectionStart = 0;
			this->t_nk->Size = System::Drawing::Size(213, 23);
			this->t_nk->TabIndex = 43;
			this->t_nk->TabStop = false;
			this->t_nk->UseSystemPasswordChar = false;
			// 
			// materialLabel3
			// 
			this->materialLabel3->AutoSize = true;
			this->materialLabel3->Depth = 0;
			this->materialLabel3->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel3->Location = System::Drawing::Point(740, 90);
			this->materialLabel3->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel3->Name = L"materialLabel3";
			this->materialLabel3->Size = System::Drawing::Size(141, 19);
			this->materialLabel3->TabIndex = 42;
			this->materialLabel3->Text = L"Кількість кредитів";
			// 
			// t_nc
			// 
			this->t_nc->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_nc->Depth = 0;
			this->t_nc->Hint = L"";
			this->t_nc->Location = System::Drawing::Point(890, 90);
			this->t_nc->MaxLength = 32767;
			this->t_nc->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_nc->Name = L"t_nc";
			this->t_nc->PasswordChar = '\0';
			this->t_nc->SelectedText = L"";
			this->t_nc->SelectionLength = 0;
			this->t_nc->SelectionStart = 0;
			this->t_nc->Size = System::Drawing::Size(213, 23);
			this->t_nc->TabIndex = 41;
			this->t_nc->TabStop = false;
			this->t_nc->UseSystemPasswordChar = false;
			// 
			// materialLabel2
			// 
			this->materialLabel2->AutoSize = true;
			this->materialLabel2->Depth = 0;
			this->materialLabel2->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel2->Location = System::Drawing::Point(389, 90);
			this->materialLabel2->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel2->Name = L"materialLabel2";
			this->materialLabel2->Size = System::Drawing::Size(111, 19);
			this->materialLabel2->TabIndex = 40;
			this->materialLabel2->Text = L"Тип контролю";
			// 
			// t_tc
			// 
			this->t_tc->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_tc->Depth = 0;
			this->t_tc->Hint = L"";
			this->t_tc->Location = System::Drawing::Point(504, 90);
			this->t_tc->MaxLength = 32767;
			this->t_tc->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_tc->Name = L"t_tc";
			this->t_tc->PasswordChar = '\0';
			this->t_tc->SelectedText = L"";
			this->t_tc->SelectionLength = 0;
			this->t_tc->SelectionStart = 0;
			this->t_tc->Size = System::Drawing::Size(213, 23);
			this->t_tc->TabIndex = 39;
			this->t_tc->TabStop = false;
			this->t_tc->UseSystemPasswordChar = false;
			// 
			// materialLabel1
			// 
			this->materialLabel1->AutoSize = true;
			this->materialLabel1->Depth = 0;
			this->materialLabel1->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel1->Location = System::Drawing::Point(85, 90);
			this->materialLabel1->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel1->Name = L"materialLabel1";
			this->materialLabel1->Size = System::Drawing::Size(53, 19);
			this->materialLabel1->TabIndex = 38;
			this->materialLabel1->Text = L"Назва";
			// 
			// t_name
			// 
			this->t_name->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_name->Depth = 0;
			this->t_name->Hint = L"";
			this->t_name->Location = System::Drawing::Point(170, 90);
			this->t_name->MaxLength = 32767;
			this->t_name->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_name->Name = L"t_name";
			this->t_name->PasswordChar = '\0';
			this->t_name->SelectedText = L"";
			this->t_name->SelectionLength = 0;
			this->t_name->SelectionStart = 0;
			this->t_name->Size = System::Drawing::Size(213, 23);
			this->t_name->TabIndex = 37;
			this->t_name->TabStop = false;
			this->t_name->UseSystemPasswordChar = false;
			// 
			// materialListView1
			// 
			this->materialListView1->Activation = System::Windows::Forms::ItemActivation::OneClick;
			this->materialListView1->BackColor = System::Drawing::Color::DarkRed;
			this->materialListView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->materialListView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(8) {
				this->columnHeader0,
					this->columnHeader1, this->columnHeader2, this->columnHeader3, this->columnHeader4, this->columnHeader5, this->columnHeader6,
					this->columnHeader7
			});
			this->materialListView1->Depth = 0;
			this->materialListView1->Font = (gcnew System::Drawing::Font(L"Roboto", 32, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(204)));
			this->materialListView1->ForeColor = System::Drawing::SystemColors::Info;
			this->materialListView1->FullRowSelect = true;
			this->materialListView1->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->materialListView1->HideSelection = false;
			this->materialListView1->Location = System::Drawing::Point(111, 258);
			this->materialListView1->MouseLocation = System::Drawing::Point(-1, -1);
			this->materialListView1->MouseState = MaterialSkin::MouseState::OUT;
			this->materialListView1->Name = L"materialListView1";
			this->materialListView1->OwnerDraw = true;
			this->materialListView1->Size = System::Drawing::Size(942, 299);
			this->materialListView1->TabIndex = 36;
			this->materialListView1->UseCompatibleStateImageBehavior = false;
			this->materialListView1->View = System::Windows::Forms::View::Details;
			this->materialListView1->ItemActivate += gcnew System::EventHandler(this, &Disciplines::materialListView1_ItemActivate);
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
			this->columnHeader2->Text = L"Назва";
			this->columnHeader2->Width = 103;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Тип контролю";
			this->columnHeader3->Width = 224;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Кількість кредитів";
			this->columnHeader4->Width = 289;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"Кількість КР";
			this->columnHeader5->Width = 200;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"Кількість годин";
			this->columnHeader6->Width = 144;
			// 
			// materialLabel5
			// 
			this->materialLabel5->AutoSize = true;
			this->materialLabel5->Depth = 0;
			this->materialLabel5->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel5->Location = System::Drawing::Point(400, 139);
			this->materialLabel5->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel5->Name = L"materialLabel5";
			this->materialLabel5->Size = System::Drawing::Size(121, 19);
			this->materialLabel5->TabIndex = 56;
			this->materialLabel5->Text = L"Кількість годин";
			// 
			// t_nh
			// 
			this->t_nh->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->t_nh->Depth = 0;
			this->t_nh->Hint = L"";
			this->t_nh->Location = System::Drawing::Point(527, 139);
			this->t_nh->MaxLength = 32767;
			this->t_nh->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_nh->Name = L"t_nh";
			this->t_nh->PasswordChar = '\0';
			this->t_nh->SelectedText = L"";
			this->t_nh->SelectionLength = 0;
			this->t_nh->SelectionStart = 0;
			this->t_nh->Size = System::Drawing::Size(213, 23);
			this->t_nh->TabIndex = 55;
			this->t_nh->TabStop = false;
			this->t_nh->UseSystemPasswordChar = false;
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"Кафедра";
			// 
			// Disciplines
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1125, 598);
			this->Controls->Add(this->materialLabel5);
			this->Controls->Add(this->t_nh);
			this->Controls->Add(this->t_dep);
			this->Controls->Add(this->materialLabel8);
			this->Controls->Add(this->t_save);
			this->Controls->Add(this->b_new);
			this->Controls->Add(this->materialLabel4);
			this->Controls->Add(this->t_nk);
			this->Controls->Add(this->materialLabel3);
			this->Controls->Add(this->t_nc);
			this->Controls->Add(this->materialLabel2);
			this->Controls->Add(this->t_tc);
			this->Controls->Add(this->materialLabel1);
			this->Controls->Add(this->t_name);
			this->Controls->Add(this->materialListView1);
			this->Name = L"Disciplines";
			this->Text = L"Disciplines";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Disciplines::Disciplines_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void b_new_Click(System::Object^ sender, System::EventArgs^ e) {
		t_name->Clear(); t_tc->Clear(); t_nc->Clear(); t_nk->Clear();
		t_dep->SelectedIndex = -1;
		isnew = true;
		curdis = nullptr;
	}
private: System::Void t_save_Click(System::Object^ sender, System::EventArgs^ e) {
	if (isnew)
	{
		Discipline^ f = gcnew Discipline(t_name->Text,db->departments[t_dep->SelectedIndex],t_tc->Text,
			int::Parse(t_nc->Text),int::Parse(t_nh->Text),int::Parse(t_nk->Text));		
		db->disciplines->Add(f);
		materialListView1->Items->Add((gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(8) {
			L"",
				f->id.ToString(), f->name, f->typeOfControl, f->getCredits().ToString(),
				f->getNumberOfControlWorks().ToString(), f->getNumberOfHours().ToString(), f->departmentId == -1 ? L"Немає" : f->department->name

		}, -1, System::Drawing::Color::Empty,
			System::Drawing::Color::Transparent, nullptr)));
	}
	else
	{
		curdis->name = t_name->Text;
		curdis->credits = int::Parse(t_nc->Text);
		curdis->numberOfHours = int::Parse(t_nh->Text);
		curdis->numberOfControlWorks = int::Parse(t_nk->Text);
		curdis->typeOfControl = t_tc->Text;
		curdis->department = db->departments[t_dep->SelectedIndex];
		curdis->departmentId = t_dep->SelectedIndex;
		materialListView1->Items[selected]=((gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(8) {
			L"",
				curdis->id.ToString(), curdis->name, curdis->typeOfControl, curdis->getCredits().ToString(),
				curdis->getNumberOfControlWorks().ToString(), curdis->getNumberOfHours().ToString(), curdis->departmentId == -1 ? L"Немає" : curdis->department->name

		}, -1, System::Drawing::Color::Empty,
			System::Drawing::Color::Transparent, nullptr)));

	}
	MessageBox::Show(this, "Успішно збережено", "OK", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void materialListView1_ItemActivate(System::Object^ sender, System::EventArgs^ e) {
	isnew = false;
	selected = materialListView1->SelectedIndices[0];
	curdis = db->disciplines[materialListView1->SelectedIndices[0]];
	t_name->Text = curdis->name;
	t_nc->Text = curdis->getCredits().ToString();
	t_nh->Text = curdis->getNumberOfHours().ToString();
	t_nk->Text = curdis->getNumberOfControlWorks().ToString();
	t_tc->Text = curdis->typeOfControl;
	t_dep->SelectedIndex = curdis->departmentId == -1 ? -1 : curdis->departmentId;
}
private: System::Void Disciplines_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	db->saveChanges();
	delete db;
	this->main->Show();
}
};
}
