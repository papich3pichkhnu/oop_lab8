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
	/// Summary for Departments
	/// </summary>
	public ref class Departments : public MaterialForm
	{
		private: Form^ main;
			   bool isnew = true;
		   int selected = 0;
		   Department^ curdep;
	private: System::Windows::Forms::ComboBox^ t_fac;
	private: MaterialSkin::Controls::MaterialLabel^ materialLabel8;
	private: MaterialSkin::Controls::MaterialRaisedButton^ t_save;
	private: MaterialSkin::Controls::MaterialFlatButton^ b_new;
	private: MaterialSkin::Controls::MaterialLabel^ materialLabel7;


	private: MaterialSkin::Controls::MaterialLabel^ materialLabel1;
	private: MaterialSkin::Controls::MaterialSingleLineTextField^ t_name;

	private: MaterialSkin::Controls::MaterialListView^ materialListView1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader0;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::ColumnHeader^ columnHeader10;
	private: System::Windows::Forms::ComboBox^ t_head;
		   DBContext^ db;
	public:
		Departments(void)
		{
			InitializeComponent();
			MaterialSkinManager^ materialSkinManager = MaterialSkinManager::Instance;
			materialSkinManager->AddFormToManage(this);
			materialSkinManager->Theme = MaterialSkinManager::Themes::LIGHT;
			db = gcnew DBContext();
			for each (Department ^ f in db->departments)
			{
				materialListView1->Items->Add((gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(5) {
					L"", f->id.ToString(), f->name, f->getFacultyId() == -1 ? L"Немає" : f->getFaculty()->abbreviature,
						f->lecturerId == -1 ? L"Немає" : f->headOfDepartment->getFullName()
				}, -1, System::Drawing::Color::Empty,
					System::Drawing::Color::Transparent, nullptr)));
			}
			for each (Faculty ^ f in db->faculties)
			{
				t_fac->Items->Add(f->abbreviature);
			}
			for each (Lecturer ^ f in db->associateprofessors)
			{
				t_head->Items->Add(f->getFullName());
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Departments()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
		Departments(Form^ _main) :Departments()
		{
			main = _main;

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
			this->t_fac = (gcnew System::Windows::Forms::ComboBox());
			this->materialLabel8 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_save = (gcnew MaterialSkin::Controls::MaterialRaisedButton());
			this->b_new = (gcnew MaterialSkin::Controls::MaterialFlatButton());
			this->materialLabel7 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->materialLabel1 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_name = (gcnew MaterialSkin::Controls::MaterialSingleLineTextField());
			this->materialListView1 = (gcnew MaterialSkin::Controls::MaterialListView());
			this->columnHeader0 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader10 = (gcnew System::Windows::Forms::ColumnHeader());
			this->t_head = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// t_fac
			// 
			this->t_fac->BackColor = System::Drawing::SystemColors::Control;
			this->t_fac->FormattingEnabled = true;
			this->t_fac->Location = System::Drawing::Point(502, 151);
			this->t_fac->Name = L"t_fac";
			this->t_fac->Size = System::Drawing::Size(211, 21);
			this->t_fac->TabIndex = 54;
			// 
			// materialLabel8
			// 
			this->materialLabel8->AutoSize = true;
			this->materialLabel8->Depth = 0;
			this->materialLabel8->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel8->Location = System::Drawing::Point(413, 151);
			this->materialLabel8->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel8->Name = L"materialLabel8";
			this->materialLabel8->Size = System::Drawing::Size(83, 19);
			this->materialLabel8->TabIndex = 53;
			this->materialLabel8->Text = L"Факультет";
			// 
			// t_save
			// 
			this->t_save->AutoSize = true;
			this->t_save->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->t_save->Depth = 0;
			this->t_save->Icon = nullptr;
			this->t_save->Location = System::Drawing::Point(963, 194);
			this->t_save->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_save->Name = L"t_save";
			this->t_save->Primary = true;
			this->t_save->Size = System::Drawing::Size(88, 36);
			this->t_save->TabIndex = 52;
			this->t_save->Text = L"Зберегти";
			this->t_save->UseVisualStyleBackColor = true;
			this->t_save->Click += gcnew System::EventHandler(this, &Departments::t_save_Click);
			// 
			// b_new
			// 
			this->b_new->AutoSize = true;
			this->b_new->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->b_new->Depth = 0;
			this->b_new->Icon = nullptr;
			this->b_new->Location = System::Drawing::Point(888, 194);
			this->b_new->Margin = System::Windows::Forms::Padding(4, 6, 4, 6);
			this->b_new->MouseState = MaterialSkin::MouseState::HOVER;
			this->b_new->Name = L"b_new";
			this->b_new->Primary = false;
			this->b_new->Size = System::Drawing::Size(68, 36);
			this->b_new->TabIndex = 51;
			this->b_new->Text = L"Новий";
			this->b_new->UseVisualStyleBackColor = true;
			this->b_new->Click += gcnew System::EventHandler(this, &Departments::b_new_Click);
			// 
			// materialLabel7
			// 
			this->materialLabel7->AutoSize = true;
			this->materialLabel7->Depth = 0;
			this->materialLabel7->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel7->Location = System::Drawing::Point(81, 147);
			this->materialLabel7->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel7->Name = L"materialLabel7";
			this->materialLabel7->Size = System::Drawing::Size(80, 19);
			this->materialLabel7->TabIndex = 50;
			this->materialLabel7->Text = L"Завідувач";
			// 
			// materialLabel1
			// 
			this->materialLabel1->AutoSize = true;
			this->materialLabel1->Depth = 0;
			this->materialLabel1->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel1->Location = System::Drawing::Point(83, 91);
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
			this->t_name->Location = System::Drawing::Point(168, 91);
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
			this->materialListView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->columnHeader0,
					this->columnHeader1, this->columnHeader2, this->columnHeader3, this->columnHeader10
			});
			this->materialListView1->Depth = 0;
			this->materialListView1->Font = (gcnew System::Drawing::Font(L"Roboto", 32, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(204)));
			this->materialListView1->ForeColor = System::Drawing::SystemColors::Info;
			this->materialListView1->FullRowSelect = true;
			this->materialListView1->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->materialListView1->HideSelection = false;
			this->materialListView1->Location = System::Drawing::Point(109, 259);
			this->materialListView1->MouseLocation = System::Drawing::Point(-1, -1);
			this->materialListView1->MouseState = MaterialSkin::MouseState::OUT;
			this->materialListView1->Name = L"materialListView1";
			this->materialListView1->OwnerDraw = true;
			this->materialListView1->Size = System::Drawing::Size(942, 299);
			this->materialListView1->TabIndex = 36;
			this->materialListView1->UseCompatibleStateImageBehavior = false;
			this->materialListView1->View = System::Windows::Forms::View::Details;
			this->materialListView1->ItemActivate += gcnew System::EventHandler(this, &Departments::materialListView1_ItemActivate);
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
			this->columnHeader3->Text = L"Факультет";
			this->columnHeader3->Width = 169;
			// 
			// columnHeader10
			// 
			this->columnHeader10->Text = L"Завідувач";
			this->columnHeader10->Width = 160;
			// 
			// t_head
			// 
			this->t_head->BackColor = System::Drawing::SystemColors::Control;
			this->t_head->FormattingEnabled = true;
			this->t_head->Location = System::Drawing::Point(168, 148);
			this->t_head->Name = L"t_head";
			this->t_head->Size = System::Drawing::Size(211, 21);
			this->t_head->TabIndex = 55;
			// 
			// Departments
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1154, 622);
			this->Controls->Add(this->t_head);
			this->Controls->Add(this->t_fac);
			this->Controls->Add(this->materialLabel8);
			this->Controls->Add(this->t_save);
			this->Controls->Add(this->b_new);
			this->Controls->Add(this->materialLabel7);
			this->Controls->Add(this->materialLabel1);
			this->Controls->Add(this->t_name);
			this->Controls->Add(this->materialListView1);
			this->Name = L"Departments";
			this->Text = L"Departments";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Departments::Departments_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Departments::Departments_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Departments_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void b_new_Click(System::Object^ sender, System::EventArgs^ e) {
	t_name->Clear(); t_fac->SelectedIndex = 0; t_head->SelectedIndex = 0;
	isnew = true;
	curdep = nullptr;
}
private: System::Void t_save_Click(System::Object^ sender, System::EventArgs^ e) {
	if (isnew)
	{
		Department^ f = gcnew Department(t_name->Text);
		f->setHeadOfDepartment(dynamic_cast<AssociateProfessor^>(db->alllecturers[db->associateprofessors[t_head->SelectedIndex]->id]));
		db->faculties[this->t_fac->SelectedIndex]->addDepartment(f);
		db->departments->Add(f);
		materialListView1->Items->Add((gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(5) {
			L"", f->id.ToString(), f->name, f->getFacultyId() == -1 ? L"Немає" : f->getFaculty()->abbreviature,
				f->lecturerId == -1 ? L"Немає" : f->headOfDepartment->getFullName()
		}, -1, System::Drawing::Color::Empty,
			System::Drawing::Color::Transparent, nullptr)));		
	}
	else
	{
		curdep->name = t_name->Text;
		if (curdep->getFacultyId() != -1)
		{
			curdep->getFaculty()->deleteDepartment(curdep);
		}
		curdep->setHeadOfDepartment(dynamic_cast<AssociateProfessor^>(db->alllecturers[db->associateprofessors[t_head->SelectedIndex]->id]));
		db->faculties[t_fac->SelectedIndex]->addDepartment(curdep);		
		materialListView1->Items[selected] = ((gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(5) {
			L"", curdep->id.ToString(), t_name->Text, curdep->getFacultyId() == -1 ? L"Немає" : curdep->getFaculty()->abbreviature,
				curdep->headOfDepartment->getFullName()
		}, -1, System::Drawing::Color::Empty,
			System::Drawing::Color::Transparent, nullptr)));

	}
	MessageBox::Show(this, "Успішно збережено", "OK", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void materialListView1_ItemActivate(System::Object^ sender, System::EventArgs^ e) {
	isnew = false;
	selected = materialListView1->SelectedIndices[0];
	curdep = db->departments[materialListView1->SelectedIndices[0]];
	t_name->Text = curdep->name;
	t_fac->SelectedIndex = curdep->getFacultyId() == -1 ? -1 : curdep->getFacultyId();
	t_head->SelectedIndex = curdep->lecturerId == -1 ? -1 : curdep->headOfDepartment->associd;
	/*if (curdep->lecturerId == -1)t_head->SelectedIndex = -1; else {
		int ind = 0;
		for each (AssociateProfessor ^ a in db->associateprofessors)
		{
			if (a->id == curdep->lecturerId)break;
			ind++;
		}
		t_head->SelectedIndex = ind;
	}*/
}
private: System::Void Departments_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	db->saveChanges();
	delete db;
	this->main->Show();
}	
};
}
