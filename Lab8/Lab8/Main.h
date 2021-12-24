#pragma once
#include "Faculties.h"
#include "Students.h"
#include "Departments.h"
#include "Lecturers.h"
#include "Disciplines.h"
#include "ExamsForm.h"

using namespace MaterialSkin;
using namespace MaterialSkin::Controls;
namespace Lab8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace Lab8DomainCore;
	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public MaterialForm
	{
	public:
		
		Main(void)
		{
			InitializeComponent();
			MaterialSkinManager^ materialSkinManager = MaterialSkinManager::Instance;
			materialSkinManager->AddFormToManage(this);
			materialSkinManager->Theme = MaterialSkinManager::Themes::LIGHT;			
			// Configure color schema
			
			/*materialSkinManager->ColorScheme = gcnew ColorScheme(
				Primary::Red400, Primary::Red500,
				Primary::Red200, Accent::LightBlue200,
				TextShade::BLACK
			);*/
			materialSkinManager->ColorScheme = gcnew ColorScheme(Primary::Red700, Primary::Red900, Primary::Red200, Accent::Blue700, TextShade::WHITE);
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}

	
	private: MaterialSkin::Controls::MaterialLabel^ materialLabel1;
	private: MaterialSkin::Controls::MaterialRaisedButton^ btn_faculties;
	private: MaterialSkin::Controls::MaterialRaisedButton^ btn_students;
	private: MaterialSkin::Controls::MaterialRaisedButton^ btn_disciplines;
	private: MaterialSkin::Controls::MaterialRaisedButton^ btn_departments;



	private: MaterialSkin::Controls::MaterialRaisedButton^ materialRaisedButton4;
	private: MaterialSkin::Controls::MaterialRaisedButton^ btn_lecturers;











	protected:












	protected:

	protected:

	protected:
	public: Faculty^ faculty;
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
			this->materialLabel1 = (gcnew MaterialSkin::Controls::MaterialLabel());
			this->btn_faculties = (gcnew MaterialSkin::Controls::MaterialRaisedButton());
			this->btn_students = (gcnew MaterialSkin::Controls::MaterialRaisedButton());
			this->btn_disciplines = (gcnew MaterialSkin::Controls::MaterialRaisedButton());
			this->btn_departments = (gcnew MaterialSkin::Controls::MaterialRaisedButton());
			this->materialRaisedButton4 = (gcnew MaterialSkin::Controls::MaterialRaisedButton());
			this->btn_lecturers = (gcnew MaterialSkin::Controls::MaterialRaisedButton());
			this->SuspendLayout();
			// 
			// materialLabel1
			// 
			this->materialLabel1->AutoSize = true;
			this->materialLabel1->Depth = 0;
			this->materialLabel1->Font = (gcnew System::Drawing::Font(L"Roboto", 11));
			this->materialLabel1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(222)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->materialLabel1->Location = System::Drawing::Point(141, 260);
			this->materialLabel1->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialLabel1->Name = L"materialLabel1";
			this->materialLabel1->Size = System::Drawing::Size(211, 19);
			this->materialLabel1->TabIndex = 0;
			this->materialLabel1->Text = L"Developed by Avsiievych V. © ";
			this->materialLabel1->Click += gcnew System::EventHandler(this, &Main::materialLabel1_Click);
			// 
			// btn_faculties
			// 
			this->btn_faculties->AutoSize = true;
			this->btn_faculties->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btn_faculties->Depth = 0;
			this->btn_faculties->Icon = nullptr;
			this->btn_faculties->Location = System::Drawing::Point(41, 90);
			this->btn_faculties->MouseState = MaterialSkin::MouseState::HOVER;
			this->btn_faculties->Name = L"btn_faculties";
			this->btn_faculties->Primary = true;
			this->btn_faculties->Size = System::Drawing::Size(111, 36);
			this->btn_faculties->TabIndex = 1;
			this->btn_faculties->Text = L"Факультети";
			this->btn_faculties->UseVisualStyleBackColor = true;
			this->btn_faculties->Click += gcnew System::EventHandler(this, &Main::btn_faculties_Click);
			// 
			// btn_students
			// 
			this->btn_students->AutoSize = true;
			this->btn_students->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btn_students->Depth = 0;
			this->btn_students->Icon = nullptr;
			this->btn_students->Location = System::Drawing::Point(273, 90);
			this->btn_students->MouseState = MaterialSkin::MouseState::HOVER;
			this->btn_students->Name = L"btn_students";
			this->btn_students->Primary = true;
			this->btn_students->Size = System::Drawing::Size(93, 36);
			this->btn_students->TabIndex = 2;
			this->btn_students->Text = L"Студенти";
			this->btn_students->UseVisualStyleBackColor = true;
			this->btn_students->Click += gcnew System::EventHandler(this, &Main::btn_students_Click);
			// 
			// btn_disciplines
			// 
			this->btn_disciplines->AutoSize = true;
			this->btn_disciplines->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btn_disciplines->Depth = 0;
			this->btn_disciplines->Icon = nullptr;
			this->btn_disciplines->Location = System::Drawing::Point(273, 147);
			this->btn_disciplines->MouseState = MaterialSkin::MouseState::HOVER;
			this->btn_disciplines->Name = L"btn_disciplines";
			this->btn_disciplines->Primary = true;
			this->btn_disciplines->Size = System::Drawing::Size(113, 36);
			this->btn_disciplines->TabIndex = 4;
			this->btn_disciplines->Text = L"Дисципліни";
			this->btn_disciplines->UseVisualStyleBackColor = true;
			this->btn_disciplines->Click += gcnew System::EventHandler(this, &Main::btn_disciplines_Click);
			// 
			// btn_departments
			// 
			this->btn_departments->AutoSize = true;
			this->btn_departments->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btn_departments->Depth = 0;
			this->btn_departments->Icon = nullptr;
			this->btn_departments->Location = System::Drawing::Point(41, 147);
			this->btn_departments->MouseState = MaterialSkin::MouseState::HOVER;
			this->btn_departments->Name = L"btn_departments";
			this->btn_departments->Primary = true;
			this->btn_departments->Size = System::Drawing::Size(86, 36);
			this->btn_departments->TabIndex = 3;
			this->btn_departments->Text = L"Кафедри";
			this->btn_departments->UseVisualStyleBackColor = true;
			this->btn_departments->Click += gcnew System::EventHandler(this, &Main::btn_departments_Click);
			// 
			// materialRaisedButton4
			// 
			this->materialRaisedButton4->AllowDrop = true;
			this->materialRaisedButton4->AutoSize = true;
			this->materialRaisedButton4->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->materialRaisedButton4->Depth = 0;
			this->materialRaisedButton4->Icon = nullptr;
			this->materialRaisedButton4->Location = System::Drawing::Point(273, 203);
			this->materialRaisedButton4->MouseState = MaterialSkin::MouseState::HOVER;
			this->materialRaisedButton4->Name = L"materialRaisedButton4";
			this->materialRaisedButton4->Primary = true;
			this->materialRaisedButton4->Size = System::Drawing::Size(94, 36);
			this->materialRaisedButton4->TabIndex = 6;
			this->materialRaisedButton4->Text = L"Екзамени";
			this->materialRaisedButton4->UseVisualStyleBackColor = true;
			this->materialRaisedButton4->Click += gcnew System::EventHandler(this, &Main::materialRaisedButton4_Click);
			// 
			// btn_lecturers
			// 
			this->btn_lecturers->AutoSize = true;
			this->btn_lecturers->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btn_lecturers->Depth = 0;
			this->btn_lecturers->Icon = nullptr;
			this->btn_lecturers->Location = System::Drawing::Point(41, 203);
			this->btn_lecturers->MouseState = MaterialSkin::MouseState::HOVER;
			this->btn_lecturers->Name = L"btn_lecturers";
			this->btn_lecturers->Primary = true;
			this->btn_lecturers->Size = System::Drawing::Size(100, 36);
			this->btn_lecturers->TabIndex = 5;
			this->btn_lecturers->Text = L"Викладачі";
			this->btn_lecturers->UseVisualStyleBackColor = true;
			this->btn_lecturers->Click += gcnew System::EventHandler(this, &Main::btn_lecturers_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(480, 298);
			this->Controls->Add(this->materialRaisedButton4);
			this->Controls->Add(this->btn_lecturers);
			this->Controls->Add(this->btn_disciplines);
			this->Controls->Add(this->btn_departments);
			this->Controls->Add(this->btn_students);
			this->Controls->Add(this->btn_faculties);
			this->Controls->Add(this->materialLabel1);
			this->Name = L"Main";
			this->Text = L"Система \"Університет\"";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void materialFlatButton1_Click(System::Object^ sender, System::EventArgs^ e) {
		/*db->clearAndDelete();
		AssociateProfessor^ LSM = gcnew AssociateProfessor("Lysenko", "Sergiy", "Mykolayovych");
		SeniorLecturer^ POO = gcnew SeniorLecturer("Pavlova", "Olga", "Oleksandrivna");
		Lecturer^ DDO = gcnew Lecturer("Denysiuk", "Dmytro", "Oleksandrovych");		
		Department^ KI = gcnew Department("KI");
		Discipline^ OOP = gcnew Discipline("OOP", KI, "exam", 5, 10, 10);
		KI->enrollLecturer(LSM);
		KI->enrollLecturer(DDO);
		KI->enrollLecturer(POO);
		Faculty^ FIT = gcnew Faculty("FIT", "FIT", "Savenko", 2020, 10,  "+380961234567", "fit@khnu.km.ua");
		FIT->addDepartment(KI);
		Student^ AVR = gcnew Student("Avsiievych", "Volodymyr", "Ruslanovych");
		FIT->enrollStudent(AVR);
		Exam^ ex = gcnew Exam(FIT, KI, AVR, LSM, OOP);
		db->alllecturers->Add(LSM);
		db->alllecturers->Add(POO);
		db->alllecturers->Add(DDO);
		db->lecturers->Add(DDO);
		db->seniorlecturers->Add(POO);
		db->associateprofessors->Add(LSM);
		db->departments->Add(KI);
		db->disciplines->Add(OOP);
		db->faculties->Add(FIT);
		db->students->Add(AVR);
		db->exams->Add(ex);
		db->saveChanges();
		delete db;*/
			
	}
private: System::Void materialFlatButton2_Click(System::Object^ sender, System::EventArgs^ e) {
	//db = gcnew DBContext();	
	
}
private: System::Void materialLabel1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void materialLabel2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void materialLabel3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btn_faculties_Click(System::Object^ sender, System::EventArgs^ e) {
	Faculties^ fac = gcnew Faculties(this);
	fac->Show();
	this->Hide();
}
private: System::Void btn_students_Click(System::Object^ sender, System::EventArgs^ e) {
	/*Students^ st = gcnew Students(this);
	st->Show();
	this->Hide();*/
	Students^ st = gcnew Students(this);
	st->ShowDialog();
}
private: System::Void btn_departments_Click(System::Object^ sender, System::EventArgs^ e) {
	Departments^ dep = gcnew Departments(this);
	dep->Show();
	this->Hide();
}
private: System::Void btn_disciplines_Click(System::Object^ sender, System::EventArgs^ e) {
	Disciplines^ lec = gcnew Disciplines(this);
	lec->Show();
	this->Hide();
}
private: System::Void btn_lecturers_Click(System::Object^ sender, System::EventArgs^ e) {
	Lecturers^ lec = gcnew Lecturers(this);
	lec->Show();
	this->Hide();
}
private: System::Void materialRaisedButton4_Click(System::Object^ sender, System::EventArgs^ e) {
	ExamsForm^ lec = gcnew ExamsForm(this);
	lec->Show();
	this->Hide();
}
};
}
