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
	/// Summary for Exam
	/// </summary>
	public ref class ExamsForm : public MaterialForm
	{
	private:
	private: Form^ main;
		   bool isnew = true;
		   int selected = 0;
		   Department^ curdep;
	private: System::Windows::Forms::ComboBox^ t_stud;
	private: System::Windows::Forms::ComboBox^ t_lec;


	private: MaterialSkin::Controls::MaterialLabel^ materialLabel8;
	private: MaterialSkin::Controls::MaterialLabel^ materialLabel7;
	private: MaterialSkin::Controls::MaterialRaisedButton^ t_save;
	private: MaterialSkin::Controls::MaterialListView^ materialListView1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader0;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader10;
	private: System::Windows::Forms::ColumnHeader^ columnHeader11;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::ColumnHeader^ columnHeader4;
	private: System::Windows::Forms::ComboBox^ t_dis;

	private: MaterialSkin::Controls::MaterialLabel^ materialLabel1;








		   DBContext^ db;
	public:
		ExamsForm(void)
		{
			InitializeComponent();
			MaterialSkinManager^ materialSkinManager = MaterialSkinManager::Instance;
			materialSkinManager->AddFormToManage(this);
			materialSkinManager->Theme = MaterialSkinManager::Themes::LIGHT;
			db = gcnew DBContext();
			for each (Exam ^ f in db->exams)
			{
				materialListView1->Items->Add((gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(7) {
					L"",
						f->id.ToString(), f->student->getFullName(), f->lecturer->getFullName(),
						f->discipline->name, f->mark.ToString(), f->date

				}, -1, System::Drawing::Color::Empty,
					System::Drawing::Color::Transparent, nullptr)));
			}
			for each (Student ^ f in db->students)
			{
				t_stud->Items->Add(f->getFullName());
			}
			for each (Lecturer ^ f in db->seniorlecturers)
			{
				t_lec->Items->Add(f->getFullName());
			}
			for each (Discipline ^ f in db->disciplines)
			{
				t_dis->Items->Add(f->name);
			}
		}
		ExamsForm(Form^ _main) :ExamsForm()
		{
			main = _main;

		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ExamsForm()
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
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->t_stud = (gcnew System::Windows::Forms::ComboBox());
			this->t_lec = (gcnew System::Windows::Forms::ComboBox());
			this->materialLabel8 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->materialLabel7 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->t_save = (gcnew MaterialSkin::Controls::MaterialRaisedButton());
			this->materialListView1 = (gcnew MaterialSkin::Controls::MaterialListView());
			this->columnHeader0 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader10 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader11 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->t_dis = (gcnew System::Windows::Forms::ComboBox());
			this->materialLabel1 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->SuspendLayout();
			// 
			// t_stud
			// 
			this->t_stud->BackColor = System::Drawing::SystemColors::Control;
			this->t_stud->FormattingEnabled = true;
			this->t_stud->Location = System::Drawing::Point(141, 86);
			this->t_stud->Name = L"t_stud";
			this->t_stud->Size = System::Drawing::Size(211, 21);
			this->t_stud->TabIndex = 59;
			// 
			// t_lec
			// 
			this->t_lec->BackColor = System::Drawing::SystemColors::Control;
			this->t_lec->FormattingEnabled = true;
			this->t_lec->Location = System::Drawing::Point(475, 89);
			this->t_lec->Name = L"t_lec";
			this->t_lec->Size = System::Drawing::Size(211, 21);
			this->t_lec->TabIndex = 58;
			// 
			// materialLabel8
			// 
			this->materialLabel8->AutoSize = true;
			this->materialLabel8->Depth = 0;
			this->materialLabel8->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel8->Location = System::Drawing::Point(386, 89);
			this->materialLabel8->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel8->Name = L"materialLabel8";
			this->materialLabel8->Size = System::Drawing::Size(77, 19);
			this->materialLabel8->TabIndex = 57;
			this->materialLabel8->Text = L"Викладач";
			// 
			// materialLabel7
			// 
			this->materialLabel7->AutoSize = true;
			this->materialLabel7->Depth = 0;
			this->materialLabel7->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel7->Location = System::Drawing::Point(54, 85);
			this->materialLabel7->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel7->Name = L"materialLabel7";
			this->materialLabel7->Size = System::Drawing::Size(66, 19);
			this->materialLabel7->TabIndex = 56;
			this->materialLabel7->Text = L"Студент";
			// 
			// t_save
			// 
			this->t_save->AutoSize = true;
			this->t_save->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->t_save->Depth = 0;
			this->t_save->Icon = nullptr;
			this->t_save->Location = System::Drawing::Point(890, 140);
			this->t_save->MouseState = MaterialSkin::MouseState::HOVER;
			this->t_save->Name = L"t_save";
			this->t_save->Primary = true;
			this->t_save->Size = System::Drawing::Size(92, 36);
			this->t_save->TabIndex = 61;
			this->t_save->Text = L"Провести";
			this->t_save->UseVisualStyleBackColor = true;
			this->t_save->Click += gcnew System::EventHandler(this, &ExamsForm::t_save_Click);
			// 
			// materialListView1
			// 
			this->materialListView1->Activation = System::Windows::Forms::ItemActivation::OneClick;
			this->materialListView1->BackColor = System::Drawing::Color::DarkRed;
			this->materialListView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->materialListView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {
				this->columnHeader0,
					this->columnHeader1, this->columnHeader10, this->columnHeader11, this->columnHeader2, this->columnHeader3, this->columnHeader4
			});
			this->materialListView1->Depth = 0;
			this->materialListView1->Font = (gcnew System::Drawing::Font(L"Roboto", 32, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::World,
				static_cast<System::Byte>(204)));
			this->materialListView1->ForeColor = System::Drawing::SystemColors::Info;
			this->materialListView1->FullRowSelect = true;
			this->materialListView1->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->materialListView1->HideSelection = false;
			this->materialListView1->Location = System::Drawing::Point(36, 205);
			this->materialListView1->MouseLocation = System::Drawing::Point(-1, -1);
			this->materialListView1->MouseState = MaterialSkin::MouseState::OUT;
			this->materialListView1->Name = L"materialListView1";
			this->materialListView1->OwnerDraw = true;
			this->materialListView1->Size = System::Drawing::Size(942, 299);
			this->materialListView1->TabIndex = 60;
			this->materialListView1->UseCompatibleStateImageBehavior = false;
			this->materialListView1->View = System::Windows::Forms::View::Details;
			this->materialListView1->ItemActivate += gcnew System::EventHandler(this, &ExamsForm::materialListView1_ItemActivate);
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
			// columnHeader10
			// 
			this->columnHeader10->Text = L"Студент";
			this->columnHeader10->Width = 132;
			// 
			// columnHeader11
			// 
			this->columnHeader11->Text = L"Викладач";
			this->columnHeader11->Width = 156;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Предмет";
			this->columnHeader2->Width = 145;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Оцінка";
			this->columnHeader3->Width = 113;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Дата";
			this->columnHeader4->Width = 85;
			// 
			// t_dis
			// 
			this->t_dis->BackColor = System::Drawing::SystemColors::Control;
			this->t_dis->FormattingEnabled = true;
			this->t_dis->Location = System::Drawing::Point(796, 90);
			this->t_dis->Name = L"t_dis";
			this->t_dis->Size = System::Drawing::Size(211, 21);
			this->t_dis->TabIndex = 63;
			// 
			// materialLabel1
			// 
			this->materialLabel1->AutoSize = true;
			this->materialLabel1->Depth = 0;
			this->materialLabel1->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel1->Location = System::Drawing::Point(707, 90);
			this->materialLabel1->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel1->Name = L"materialLabel1";
			this->materialLabel1->Size = System::Drawing::Size(71, 19);
			this->materialLabel1->TabIndex = 62;
			this->materialLabel1->Text = L"Предмет";
			// 
			// Exams
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1019, 531);
			this->Controls->Add(this->t_dis);
			this->Controls->Add(this->materialLabel1);
			this->Controls->Add(this->t_save);
			this->Controls->Add(this->materialListView1);
			this->Controls->Add(this->t_stud);
			this->Controls->Add(this->t_lec);
			this->Controls->Add(this->materialLabel8);
			this->Controls->Add(this->materialLabel7);
			this->Name = L"Exams";
			this->Text = L"Exams";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ExamsForm::Exams_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void materialListView1_ItemActivate(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void t_save_Click(System::Object^ sender, System::EventArgs^ e) {
		Exam^ f = gcnew Exam(db->students[t_stud->SelectedIndex], db->seniorlecturers[t_lec->SelectedIndex], db->disciplines[t_dis->SelectedIndex]);
		db->exams->Add(f);
		db->seniorlecturers[t_lec->SelectedIndex]->setExamSign(f);
		MessageBox::Show(this, "Екзамен підписано викладачем " + db->seniorlecturers[t_lec->SelectedIndex]->getFullName(), "OK", MessageBoxButtons::OK, MessageBoxIcon::Information);
		int score = f->takeExam(DateTime::Now.ToString());
		if (score < 3)
		{
			MessageBox::Show(this, "Студента " + db->students[t_stud->SelectedIndex]->getFullName() + " виключено за неуспішність", "Повідомлення", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else MessageBox::Show(this, "Студент " + db->students[t_stud->SelectedIndex]->getFullName() + " набрав бал " + score.ToString(), "Повідомлення", MessageBoxButtons::OK, MessageBoxIcon::Information);
		materialListView1->Items->Add((gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(7) {
			L"",
				f->id.ToString(), f->student->getFullName(), f->lecturer->getFullName(),
				f->discipline->name, f->mark.ToString(), f->date

		}, -1, System::Drawing::Color::Empty,
			System::Drawing::Color::Transparent, nullptr)));
	}
	private: System::Void Exams_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		db->saveChanges();
		delete db;
		this->main->Show();
	}
	};
}
